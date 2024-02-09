// Declarando uma estrutura de dados
struct mapa
{
  char **matriz;
  int linhas;
  int colunas;
};

typedef struct mapa MAPA;

void liberarMapa(MAPA* m);
void alocarMapa(MAPA* m);
void lerMapa(MAPA* m);
void imprimirMapa(MAPA* m);