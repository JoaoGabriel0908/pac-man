#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO heroi;
int temPilula = 0;

int praOndeFastasmaVai(int xatual, int yatual, int* xdestino, int* ydestino){
  int opcoes[4][2] = {
    {xatual, yatual + 1},
    {xatual + 1, yatual},
    {xatual, yatual - 1},
    {xatual - 1, yatual}
  };

  srand(time(0));
  for(int i = 0; i < 10; i++){
    int pos = rand() % 4;

    if(podeAndar(&m, FANTASMA, opcoes[pos][0], opcoes[pos][1])){
      *xdestino = opcoes[pos][0];
      *ydestino = opcoes[pos][1];

      return 1;
    }
  }
  return 0;
}

int acabou() {
  POSICAO posicao;
  int fogefogemapa = encontraMapa(&m, &posicao, HEROI);
  printf("Foge foge mapa %d \n", fogefogemapa);
  return !fogefogemapa;
}

void fanstasmas() {

  MAPA copia;

  copiaMapa(&copia, &m);

  for(int i = 0; i < m.linhas; i++){
    for (int j = 0; j < m.colunas; j++)
    {
      if(copia.matriz[i][j] == FANTASMA){

        int xdestino;
        int ydestino;

        int encontrou = praOndeFastasmaVai(i, j, &xdestino, &ydestino);

        if(encontrou){
          andandoMapa(&m, i, j, xdestino, ydestino);
        }

        if(estaValido(&m,i, j+1) && ehvazio(&m, i, j+1)){
          andandoMapa(&m, i, j, i, j+1);
        }
      }
    }
  }

  liberarMapa(&copia);
}



int direcaoVerificada(char direcao) {
  return direcao == 'a' || direcao == 'w' || direcao == 's' || direcao == 'd';
}

void move(char direcao) {

  if(!direcaoVerificada(direcao)) {
    return;
  }

  int proximoX = heroi.x;
  int proximoY = heroi.y;

  switch (direcao)
  {
  case ESQUERDA:
    proximoY--;
    break;
  case CIMA:
    proximoX--;
    break;
  case BAIXO:
    proximoX++;
    break;
  case DIREITA:
    proximoY++;
    break;
  };

  if(!podeAndar(&m, HEROI, proximoX, proximoY)){
    return;
  }

  if(ehPersonagem(&m, PILULA, proximoX, proximoY)){
    temPilula = 1;
  }

  andandoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);
  heroi.x = proximoX;
  heroi.y = proximoY;
  
}

void explodePilula() {

  if(!temPilula) return;

  explodePilula2(heroi.x, heroi.y, 0, 1, 3);
  explodePilula2(heroi.x, heroi.y, 0, -1, 3);
  explodePilula2(heroi.x, heroi.y, 1, 0, 3);
  explodePilula2(heroi.x, heroi.y, -1, 0, 3);

  temPilula = 0;
}

// Função Recursiva, ela chama ela mesmo.
void explodePilula2(int x, int y, int somax, int somay, int qtd){

  if(qtd == 0) return;

  int novox = x + somax;
  int novoy = y + somay;

  if(!estaValido(&m, novox, novoy)) return;
  if(ehParede(&m, novox, novoy)) return;

  m.matriz[novox][novoy] = VAZIO;  
  explodePilula2(novox, novoy, somax, somay, qtd - 1);
}

int main()
{

  lerMapa(&m);
  encontraMapa(&m, &heroi, HEROI);

  do
  {
    printf("Tem pilula: %s\n", (temPilula ? "Sim" : "Nao"));
    imprimirMapa(&m);
    // Pegando a tecla do usuário
    char comando;
    scanf(" %c", &comando);
    move(comando);

    if(comando == BOMBA){
      explodePilula();
    }

    fanstasmas();
  } while (!acabou());


  liberarMapa(&m);

  // Alocando memória para um inteiro
  // int* v = malloc(sizeof(int) * 10);
  // v[0] = 10;
  // v[1] = 12;
  // printf("Inteiro alocado %d %d \n", v[0], v[1]);
  // // Liberando a memória alocada anteriormente
  // free(v);

  // // Alocando memória para uma matriz
  // int **matriz = malloc(sizeof(int*) * 5);
  // // Iterando em cada linha da matriz
  // for(int i = 0; i < 5; i++){
  //   matriz[i] = malloc(sizeof(int) * 10);
  // }
  // matriz[0][0] = 10;
  // matriz[1][2] = 12;
  // printf("Matriz alocada %d %d \n", matriz[0][0], matriz[1][2]);

  // Liberando a memória alocada anteriormente
  // for(int i = 0; i < 5; i++){
  //   free(matriz[i]);
  // }
  // free(matriz);

  // 2° MANEIRA DE FAZER O FOR ANINHADO
  // Imprimindo todas as linhas do mapa com um for aninhado
  // for(int i = 0; i < 5; i++){
  //   // Interando por todas as colunas
  //   for(int j = 0; j < 10; j++){
  //     printf("%c", mapa[i][j] );
  //   }
  //   printf("\n");
  // }

  // Fechando o arquivo mapa.txt

  // for(int i = 0; i < 20; i++){
  //   for(int j = 0; j < 10; j++){
  //     numeros[i][j] = i + j;
  //   }
  //   printf("\n");
  // }
}