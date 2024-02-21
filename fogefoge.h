#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

#define CIMA 'w'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BAIXO 's'

void move(char direcao);
int acabou();
int praOndeFastasmaVai(int xatual, int yatual, int* xdestino, int* ydestino);
int direcaoVerificada(char direcao);
void fanstasmas();
void explodePilula();

void explodePilula2(int x, int y, int somax, int somay, int qtd);

#endif