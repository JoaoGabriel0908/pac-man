#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

void fanstasmas() {

  MAPA copia;

  copiaMapa(&copia, &m);

  for(int i = 0; i < m.linhas; i++){
    for (int j = 0; j < m.colunas; j++)
    {
      if(copia.matriz[i][j] == FANTASMA){
        if(estaValido(&m,i, j+1) && ehvazio(&m, i, j+1)){
          andandoMapa(&m, i, j, i, j+1);
        }
      }
    }
  }

  liberarMapa(&copia);
}

int acabou() {
  return 0;
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

  if(!estaValido(&m, proximoX, proximoY)){
    return;
  }

  if(!ehvazio(&m, proximoX, proximoY)){
    return;
  }

  andandoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);
  heroi.x = proximoX;
  heroi.y = proximoY;
  
}

int main()
{

  lerMapa(&m);
  encontraMapa(&m, &heroi, HEROI);

  do
  {
    imprimirMapa(&m);
    // Pegando a tecla do usuário
    char comando;
    scanf(" %c", &comando);
    move(comando);
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