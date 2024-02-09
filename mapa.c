#include <stdlib.h>
#include <stdio.h>
#include "mapa.h"

// Acessando o conteudo do ponteiro m->
void liberarMapa(MAPA* m)
{
  for (int i = 0; i < m->linhas; i++)
  {
    free(m->matriz[i]);
  }
  free(m->matriz);
}
void alocarMapa(MAPA* m)
{
  // Alocando o mapa de forma dinamica
  m->matriz = malloc(sizeof(char *) * m->linhas);
  for (int i = 0; i < m->linhas; i++)
  {
    m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
  }
}
void lerMapa(MAPA* m)
{
  // Abrindo o arquivo mapa.txt pelo ponteiro da memória f
  FILE *f;
  f = fopen("mapa.txt", "r");

  if (f == 0)
  {
    printf("Erro na leitura do mapa\n");
    exit(1);
  }

  fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
  printf("linhas: %d, colunas: %d\n", m->linhas, m->colunas);

  alocarMapa(m);

  // Lendo o arquivo mapa.txt linha por linha
  for (int i = 0; i < 5; i++)
  {
    // Lendo a linha do arquivo e armazenando na matriz mapa
    // mapa[0] = Estou passando a primeira dimensão, ou seja, a linha inteira
    fscanf(f, "%s", m->matriz[i]);
  }
  fclose(f);
}
void imprimirMapa(MAPA* m){
  for(int i = 0; i < 5; i++){
    printf("%s\n", m->matriz[i]);
  }
}
