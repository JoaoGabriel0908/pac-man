#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"

void copiaMapa(MAPA* destino, MAPA* origem) {
  destino->linhas = origem->linhas;
  destino->colunas = origem->colunas;

  alocarMapa(destino);
  for (int i = 0; i < origem->linhas; i++)
  {
    strcpy(destino->matriz[i], origem->matriz[i]);
    // Cópia do jeito antigo
    // for(int j = 0; j < origem->colunas; j++){
    //   destino->matriz[i][j] = origem->matriz[i][j];
    // } 
  }
  
}

int podeAndar(MAPA* m, char personagem, int x, int y) {
  return estaValido(m, x, y) && 
  !ehParede(m, x, y) && 
  !ehPersonagem(m, personagem, x, y);
}

int ehPersonagem(MAPA*m, char personagem, int x, int y){
  return m->matriz[x][y] == personagem;
}

int ehParede(MAPA* m, int x, int y) {
  return m->matriz[x][y] == PAREDE_VERTICAL || m->matriz[x][y] == PAREDE_HORIZONTAL;
}
void andandoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {
  char personagem = m->matriz[xorigem][yorigem];
  m->matriz[xdestino][ydestino] = personagem;
  m->matriz[xorigem][yorigem] = VAZIO;
}

int estaValido(MAPA* m, int x, int y){
  if(x >= m->linhas){
    return 0;
  }

  if(y >= m->colunas){
    return 0 ;
  }

  return 1;
}

int ehvazio(MAPA* m, int x, int y) {
  return m->matriz[x][y] == VAZIO;
}

// Encontrando a posição do foge foge no mapa
int encontraMapa(MAPA* m, POSICAO* p, char c){
  // Achando a posição do foge foge
  for (int i = 0; i < m->linhas; i++)
  {
    for(int j = 0; j < m->colunas; j++){
      if(m->matriz[i][j] == c){
        p->x = i;
        p->y = j;
        return 1;
      }
    }
  }

  return 0;
}

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
