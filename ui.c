#include <stdio.h>
#include "ui.h"
#include "mapa.h"
#include <stdlib.h>

char desenhoparede[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char desenhofantasma[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char desenhoheroi[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

void imprimirParte(char desenho[4][7], int parte){
  printf("%s", desenho[parte]);
}

void imprimirMapa(MAPA *m)
{
  for (int i = 0; i < m->linhas; i++)
  {
    for (int parte = 0; parte < 4; parte++)
    {
      for (int j = 0; j < m->colunas; j++)
      {
        switch (m->matriz[i][j])
        {
        case FANTASMA:
          imprimirParte(desenhofantasma, parte);
          break;
        case HEROI:
          imprimirParte(desenhoheroi, parte);
          break;
        case PILULA:
          imprimirParte(desenhopilula, parte);
          break;
        case VAZIO:
          imprimirParte(desenhovazio, parte);
          break;
        case PAREDE_VERTICAL:
        case PAREDE_HORIZONTAL:
          imprimirParte(desenhoparede, parte);
          break;
        default:
          break;
        }
      }

      printf("\n");
    }
  }
}