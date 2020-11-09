typedef struct content
{
    int id;
    char name[200];
    float peso;
    float value;
    struct content *next;
}C;

void menu(void);
int vazia(C *c);
C *inicializa(void);
C *inserir(C *c,float v,float p,char *s,int id);
void buscar(C *c,int id);
void imprimir(C *c);
C *remover(C *c,int id);
void liberar(C *c);
