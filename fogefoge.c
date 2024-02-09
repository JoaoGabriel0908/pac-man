#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;

int acabou() {
  return 0;
}

void move(char direcao) {
  int x;
  int y;

  // Achando a posição do foge foge
  for (int i = 0; i < m.linhas; i++)
  {
    for(int j = 0; j < m.colunas; j++){
      if(m.matriz[i][j] == '@'){
        x = i;
        y = j;
        break;
      }
    }
  }

  switch (direcao)
  {
  case 'a':
    m.matriz[x][y-1] = '@';
    break;
  case 'w':
    m.matriz[x-1][y] = '@';
    break;
  case 's':
    m.matriz[x+1][y] = '@';
    break;
  case 'd':
    m.matriz[x][y+1] = '@';
    break;
  }

  // Tenho 2 pacman no mapa
  m.matriz[x][y] = '.';
}

int main()
{

  lerMapa(&m);

  do
  {
    imprimirMapa(&m);
    // Pegando a tecla do usuário
    char comando;
    scanf(" %c", &comando);
    move(comando);
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