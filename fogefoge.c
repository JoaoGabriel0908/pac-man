#include <stdio.h>
#include <stdlib.h>

char **mapa;
int linhas;
int colunas;

void alocarMapa()
{
  // Alocando o mapa de forma dinamica
  mapa = malloc(sizeof(char *) * linhas);
  for (int i = 0; i < linhas; i++)
  {
    mapa[i] = malloc(sizeof(char) * (colunas + 1));
  }
}
void lerMapa()
{
  // Abrindo o arquivo mapa.txt pelo ponteiro da memória f
  FILE *f;
  f = fopen("mapa.txt", "r");

  if (f == 0)
  {
    printf("Erro na leitura do mapa\n");
    exit(1);
  }

  fscanf(f, "%d %d", &linhas, &colunas);
  printf("linhas: %d, colunas: %d\n", linhas, colunas);

  alocarMapa();

  // Lendo o arquivo mapa.txt linha por linha
  for (int i = 0; i < 5; i++)
  {
    // Lendo a linha do arquivo e armazenando na matriz mapa
    // mapa[0] = Estou passando a primeira dimensão, ou seja, a linha inteira
    fscanf(f, "%s", mapa[i]);
  }
  fclose(f);
}
void liberarMapa()
{
  for (int i = 0; i < 5; i++)
  {
    free(mapa[i]);
  }
  free(mapa);
}

int main()
{
  // Criando uma matriz que representa o mapa do jogo
  // Há 5 linhas e 10 colunas
  // int numeros[20][10];

  // mapa[0][0] = '|';
  // mapa[4][9] = '@';

  // printf("%c %c\n", mapa[0][0], mapa[4][9]);

  lerMapa();

  // Imprimindo todas as linhas do mapa
  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", mapa[i]);
  }

  liberarMapa();

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