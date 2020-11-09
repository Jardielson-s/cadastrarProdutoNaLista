#include<stdio.h>
#include "func.c"

int main(){
    
    C *c;

    int op,id = 0,findId;
    float v,p;
    char s[100];
    char s1[50];

    c = inicializa();
   
    do{
        menu();

        printf("\n\t escolha a opcao:\t");
        scanf("%d",&op);
        switch (op)
        {

          case 1:
              printf("\n\t digite um valor:\t");
              scanf("%f",&v);
              printf("\n\t digite um peso:\t");
              scanf("%f",&p);
              printf("\n\t digite o nome:\t");
              setbuf(stdin,NULL);
              scanf("%[^\n]s",(char*)&s);
              c = inserir(c,v,p,s,id);
              id++;
              break;
          case 2:
              if(vazia(c) == 1)
              {
                  printf("\n\t LISTA VAZIA");
              }
              else 
              {  
                 printf("\n\t digite o nome a ser removido:\t");
                 scanf("%d",&findId);
                 c = remover(c,findId);
              }
              break;
          case 3:
              if(vazia(c) == 1)
              {
                  printf("\n\t LISTA VAZIA");
              }
              else 
              {
                 printf("\n\t digite o id  que encontrar:\t");
                 scanf("%d",&findId);
                 
                 buscar(c,findId);
              }      
              break;
          case 4:
              if(vazia(c) == 1)
              {
                  printf("\n\t LISTA VAZIA");
              }
              else 
              {
                  imprimir(c);
              }
              break;
          case 5:
              liberar(c);
              break;
        
        
        }
    }while (op != 0);
    
    return 0;
}