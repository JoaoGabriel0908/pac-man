#define CIMA 'w'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BAIXO 's'

void move(char direcao);
int acabou();
int praOndeFastasmaVai(int xatual, int yatual, int* xdestino, int* ydestino);
int direcaoVerificada(char direcao);
void fanstasmas();