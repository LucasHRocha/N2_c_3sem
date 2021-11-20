#include <stdio.h>
#include <stdlib.h>
//lista duplamente encadeada
typedef struct lista2 {
	   char nome[21];
	   char nasc[11];
       lista2* ant;
       lista2* prox;
}Lista2;

Lista2* lista_cria(){
    return NULL;
}

int lista_vazia(Lista2* l){
    /*if(l==NULL) return 1;
    return 0;*/
    return(l==NULL);//retorna o resultado da comparação do ponteiro l com NULL
}

Lista2* lista_busca(Lista2* l, int dado){     
    Lista2 *a; //variável usada para percorrer a lista
    for(a=l;a!=NULL;a=a->prox) { 
         if(a->info == dado) return a;
     }         
    return NULL;//caso não tenha encontrado¹
}
    
//insere novos elementos no inicio da lista
Lista2* lista_insere( Lista2* l, int dado){
      Lista2 *novo= (Lista2*) malloc (sizeof(Lista2));
      novo->info=dado;
      novo->prox=l;
      novo->ant=NULL;
      //verifica se a lista não esta vazia
      if(l!= NULL)
         l->ant=novo;
         
      return novo;
}

void lista_mostra(Lista2* l){
     Lista2 *aux;//variável usada para percorrer a lista
     for(aux=l;aux!=NULL;aux=aux->prox)
         printf("%d\t", aux->info);
	 printf("\n");
}    
 
Lista2* lista_retira(Lista2* l, int dado){
      //procura o elemento na lista usando a função busca
      Lista2* aux=lista_busca(l, dado);
      if (aux==NULL) //não achou o elemento
          return l; 
      //retira o elemento encadeado
      if(l==aux) //verifica se é o primeiro da lista
        l=aux->prox;
      else
        aux->ant->prox=aux->prox;
      //testa para ver se é o ultimo da lista
      if (aux->prox!=NULL)        
          aux->prox->ant=aux->ant;
      free(aux);
      return l;
}

//Opcionalmente pode-se inserir na lista de forma ordenada
Lista2* lista_ordenada(Lista2* l, int v){
    Lista2* novo;
    Lista2* anterior=NULL;
    Lista2* p=l;
    
    //cria novo elemento
    novo=(Lista2*)malloc(sizeof(Lista2));
    novo->info=v;
          
    //procura posição de inserção
    while (p!=NULL && p->info < v) {
          anterior=p;
          p=p->prox;
    }     
    //encadeia o elemento
    if(anterior==NULL) {//insere no inicio
         if(l!=NULL) l->ant=novo;
         novo->prox=l;
         novo->ant=NULL;
         
         l=novo;
    }      
    else { //insere no meio ou no fim da lista
    
         novo->prox=anterior->prox;
         novo->ant=anterior;
         if (anterior->prox!=NULL)
             anterior->prox->ant=novo;
         anterior->prox=novo;
    	}
     return l;
}  
  
void lista_libera(Lista2 *li){ //libera cada item da lista individualmente
	 Lista2 *p,*t;//ponteiros auxiliares
     p=li;
     while(p!=NULL){
       t=p->prox;
       free(p);
       p=t;
     }                           
}                     
Lista2 *lista_semRepetir(Lista2 *li, int dado){
	Lista2 *aux;
	aux=lista_busca(li,dado);
	if(aux==NULL)
		li=lista_ordenada(li,dado);
	else{
		printf("Item repetido tente novamente\n");
	}
	return li;
}
void vizinhos(Lista2 *item){
	if(item->ant==NULL)
	   printf("Nao tem anterior\n");
	else
	   printf("Anterior: %d\n", item->ant->info);
	   
	if(item->prox==NULL)
	   printf("Nao tem proximo\n");
	else
	   printf("Proximo: %d\n", item->prox->info);
}   
void lista_reversa(Lista2 *ls){
	Lista2 *a;//ponteiro auxiliar do tipo lista
	/*for(a=ls;a!=NULL;a=a->prox)
	    if (a->prox==NULL) 
	         break;*/
	for(a=ls;a->prox!=NULL;a=a->prox);//descubro o ultimo da lista (a)
	//mostrar em ordem reversa
	for(;a!=NULL;a=a->ant){
		printf("%d\t", a->info);
	}
	printf("\n");
}  
Lista2 *lista_par(Lista2 *ls){
	Lista2 *par=lista_cria();
	Lista2 *a;//ponteiro auxiliar
	a=ls;
	while(a!=NULL){ //percorrer a lista a procura de pares
	   if(a->info %2==0)
	     par=lista_ordenada(par,a->info);
	   a=a->prox;
	}
	return par;
}  
int primeiro(Lista2 *li){
	
}
int ultimo(Lista2 *li){
	
}
void busca(Lista *last, char *n) {
	Lista *a
	
}
//programa principal
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------\n");
     printf("1. Insere nome e data\n");  //insere sem repetir     
     printf("2. Retira da lista\n");
     printf("3. Mostra a lista\n");
     printf("4. Busca o nome da pessoa\n");//mostrar os vizinhos (antes e depois)
     //mostre também o primeiro da lista e o ultimo da lista
     printf("5. Mostra lista em ordem reversa\n");//void lista_reversa(Lista2 *ls)
     printf("6. Cria uma lista de elementos pares\n");//Lista2 *lista_par(Lista2 *ls)
   	 printf("9. Fim\n");
     printf("==> ");
}
             
main(){
  int opmenu, item, nomet[20];
  Lista2 *li=lista_cria();
  Lista2 *aux;//para a função de busca
  do{
     menu();   
     scanf("%d",&opmenu);
     switch(opmenu){
        case 1: 
               printf("\nInforme o nome da pessoa: ");
               scanf(" %20[^\n]",lista2->nome);
               printf("\nInforme a data da pessoa: ");
               scanf(" %10[^\n]",lista2->nasc);
               //scanf("%c",&item);
               //li=lista_ordenada(li,item);
               //li=lista_insere(li,item);
               //li=lista_semRepetir(li, item);//Lista2 *lista_semRepetir(li,item);
               break;
        case 2:  
             printf("Informe o item que deseja retirar: ");
             scanf("%d",&item);
             li=lista_retira(li,item); 
             break;
        case 3:
		    if(lista_vazia(li))
			   printf("Lista vazia\n");
			else {
		  		  printf("Lista:\n");
		          lista_mostra(li);
		      }
            break;
        case 4:  
        	printf("Informe o nome da pessoa r: ");
        	scanf(" %20[^\n]",nome);
        	busca(aux,nome);
             /*scanf("%d",&item);
             //ponteiro auxiliar para não perder a referencia
             //da lista
             aux=lista_busca(li,item); 
             if(aux==NULL)
                printf("Item %d nao localizado na lista\n",item);
             else{
			        printf("Item %d localizado\n",aux->info);
			        vizinhos(aux);
			        //primeiro e ultimo
	        	}
             break;*/
        case 5: //mostra reverso
        		if(lista_vazia(li))
			   		printf("Lista vazia\n");
				else {
		  		  printf("Lista Reversa:\n");
              	  lista_reversa(li);
              	}
              	break;
        case 6://gera lista de pares
              aux=lista_par(li);//temporária
              if(aux!=NULL){
			        printf("Lista de pares\n");
              		lista_mostra(aux);
              		lista_libera(aux);
            	}
            	else
            	   printf("Lista vazia\n");
            	break;
              		
                             
        }//fim switch
   printf("\n");
   system("pause");
   }while(opmenu!=9);
   lista_libera(li);
}
                          
