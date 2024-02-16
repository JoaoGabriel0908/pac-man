// Declarando uma estrutura de dados
#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
struct mapa
{
  char **matriz;
  int linhas;
  int colunas;
};

typedef struct mapa MAPA;
struct posicao
{
  int x;
  int y;
};

typedef struct posicao POSICAO;

void liberarMapa(MAPA* m);
void alocarMapa(MAPA* m);
void lerMapa(MAPA* m);
void imprimirMapa(MAPA* m);
int encontraMapa(MAPA* m, POSICAO* p, char c);
int ehvazio(MAPA* m, int x, int y);
int estaValido(MAPA* mapa, int x, int y);
void andandoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiaMapa(MAPA* destino, MAPA* origem);
int podeAndar(MAPA* m, char personagem, int x, int y);
int ehParede(MAPA* m, int x, int y);
int ehPersonagem(MAPA*m, char personagem, int x, int y);