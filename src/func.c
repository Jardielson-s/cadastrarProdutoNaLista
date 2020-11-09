#include<stdlib.h>
#include<string.h>
#include "prototype.h"


void menu(void){
  printf("\n\t ---------- menu ----------\n");
  printf("\n\t 1- inserir elemento");
  printf("\n\t 2- remover elemento");
  printf("\n\t 3- buscar elemento");
  printf("\n\t 4- imprimir lista");
  printf("\n\t 5- liberar lista \n");
  printf("\n\t ---------- menu ----------\n");

}

int vazia(C *c){
   if(c == NULL)
     return 1;
   else 
     return 0;
}


C *inicializa(void){
  return NULL;
}



C *inserir(C *c,float v,float p,char *s,int id){
   
   C *new = (C*)malloc(sizeof(C));
 
   new->id = id;
   new->value = v;
   strcpy(new->name,s);
   new->peso = p;
   new->next = c;
   return new;
}

C *remover(C *c,int id){
  
  C *ant;
  C *p = c;

  while (p != NULL && p->id != id)
  {
     ant = p;
     p = p->next;
  }
  
  if(p == NULL)
  { 
    printf("\n\t elemento nao localizado");
    return c;
  }

  if(ant == NULL)
  {
      c = p->next;
  }
  else 
  {
      ant->next = p->next;
  }

  free(p);
  return c;
}

void buscar(C *c,int id){
    C *aux = c;
    int achei = 0;
    for(aux = c;aux != NULL;aux = aux->next)
    {
       if(aux->id == id)
       {
         achei++;
         break;
       }
    }
    if(achei == 1)
       {
          printf("\n\t-------------------");
          printf("\n\t id = %d",aux->id);
          printf("\n\t nome = %s",aux->name);
          printf("\n\t valor = %.2f",aux->value);
          printf("\n\t peso = %.2f",aux->peso);
          printf("\n\t-------------------\n");
       }
    else
       { 
        printf("\n\t id informado nao encontrado");
       }

    
}

void imprimir(C *c){
  C *aux;

  for(aux = c;aux != NULL;aux = aux->next)
  { 
     printf("\n\t--------------------");
     printf("\n\t id = %d",aux->id);
     printf("\n\t nome = %s",aux->name);
     printf("\n\t preco = %.2f",aux->value);
     printf("\n\t peso = %.2f",aux->peso);
     printf("\n\t---------------------");
     printf("\n");
  }
}
void liberar(C *c){
  
  C *p = c;

  while(p != NULL)
  {
     C *aux = p->next;
     
     free(p);
     p = aux;
  }
}