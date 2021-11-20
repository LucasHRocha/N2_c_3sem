#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lista duplamente encadeada
typedef struct lista {
	   char nome[21];
	   char nasc[11];
       lista* ant;
       lista* prox;
}Lista;

Lista* lista_cria(){
    return NULL;
}
void lista_libera(Lista *li){ //libera cada item da lista individualmente
	 Lista *p,*t;//ponteiros auxiliares
     p=li;
     while(p!=NULL){
       t=p->prox;
       free(p);
       p=t;
     }                          
}   

Lista* lista_insere( Lista* l, char nome[21], char nasc[11]){
	Lista *novo= (Lista*) malloc (sizeof(Lista));
	strcpy(novo->nome,nome);
	strcpy(novo->nasc,nasc);
	novo->prox = l;
	novo->ant = NULL;
	if(l!= NULL)
         l->ant=novo;
    
	return novo;
}

void busca(Lista *last, char *n) {
	if(last!=NULL){
		if(!strcmp(last->nome,n))// comparacao entre string
			printf("%s\t",last->nasc); // printa a data 
		else 
			busca(last->prox,n); // vai pro proximo
	}
	else
		printf("nome nao encontrado");// se não encontrar nada printa a mensagem
}	
int main(){
  int opmenu, x; 
  char nome[21],nasc[11];
  Lista *li=lista_cria();
  Lista *aux;//para a função de busca
  li=lista_insere(li,"maria","05/05/2000");
  li=lista_insere(li,"carlos","18/04/1997");
  printf("Informe o nome da pessoa que deseja buscar : ");
  scanf(" %20[^\n]",nome);
  busca(li,nome);
  printf("\n");
  system("pause");
  lista_libera(li);
}
