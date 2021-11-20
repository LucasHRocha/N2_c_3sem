#include <stdio.h>
#include <stdlib.h>
//lista duplamente encadeada
typedef struct lista2 {
       lista2* ant;
	   int info;//conteúdo é inteiro
       lista2* prox;
}Lista2;

Lista2* lista_cria(){
    return NULL;
}

int lista_vazia(Lista2* l){
    if(l==NULL) return 1;
    return 0;
}

Lista2* lista_busca(Lista2* l, int dado){     
    Lista2 *a; //variável usada para percorrer a lista
    for(a=l;a!=NULL;a=a->prox) { 
         if(a->info == dado) return a;
     }         
    return NULL;
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
          
//programa principal
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------\n");
     printf("1. Insere na lista\n");  //insere sem repetir     
     printf("2. Retira da lista\n");
     printf("3. Mostra a lista\n");
     printf("4. Busca item na lista\n");//mostrar os vizinhos (antes e depois)
   	 printf("9. Fim\n");
     printf("==> ");
}
             
main(){
  int opmenu, item;
  Lista2 *li=lista_cria();
  Lista2 *aux;//para a função de busca
  do{
     menu();   
     scanf("%d",&opmenu);
     switch(opmenu){
        case 1: 
               printf("Informe o item que deseja adicionar: ");
               scanf("%d",&item);
               li=lista_ordenada(li,item);
               //li=lista_insere(li,item);
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
             printf("Informe o item que deseja procurar: ");
             scanf("%d",&item);
             //ponteiro auxiliar para não perder a referencia
             //da lista
             aux=lista_busca(li,item); 
             if(aux==NULL)
                printf("Item %d nao localizado na lista\n",item);
             else{
			        printf("Item %d localizado\n",aux->info);
	        	}
             break;
                             
        }//fim switch
   printf("\n");
   system("pause");
   }while(opmenu!=9);
   lista_libera(li);
   
   /*Lista *aux;
	for(aux=l;aux!=NULL;aux=aux->prox){
		
	}
	printf("%d\t", aux->prox);
	
void lista_reversa(Lista *li){//percurso reverso
	if(li!=NULL){
		lista_reversa(li->prox);
		printf("%d\t",li->info);
	}
}*/
}

                          
