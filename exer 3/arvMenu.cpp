#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
	int info;
	struct arv *esq;//ponteiro para a esquerda
	struct arv *dir;//ponteiro para a direita
}Arv;
//------------------------------------
Arv *abb_cria(){
	return NULL; //inicializa a árvore
}
//------------------------------------
int  abb_vazia(Arv *a){
	return (a==NULL);
}
//------------------------------------
Arv* abb_insere(Arv *a, int v){ //recursivo
    if (a==NULL){
       a=(Arv*) malloc(sizeof(Arv));
	   a->info=v;
       a->esq=a->dir=NULL;
     } 
     else if (v< a->info)
                   a->esq=abb_insere(a->esq,v);
             else    
                   a->dir=abb_insere(a->dir,v);
     return a;
} 
//------------------------------------
Arv *abb_busca(Arv *a, int v){//retorna o elemento ou NULL se não encontrado
     if(a==NULL)  return NULL;
     if(a->info < v)
    	 printf("b\n");
        return abb_busca(a->dir, v);
     if(a->info > v)
     	printf("a\n");
        return abb_busca(a->esq,v);
     return a;
}
//------------------------------------
void abb_emOrdem(Arv *a){ //esq - raiz - dir
	if(a!=NULL){
		abb_emOrdem(a->esq);
		printf("%d\t",a->info);
		abb_emOrdem(a->dir);
	}
}
//------------------------------------
void abb_preOrdem(Arv *a){ //raiz - esq - dir
	if(a!=NULL){
		printf("%d\t",a->info);
		abb_preOrdem(a->esq);
		abb_preOrdem(a->dir);
	}
}
//------------------------------------
void abb_posOrdem(Arv *a){ // esq - dir - raiz
	if(a!=NULL){
		abb_posOrdem(a->esq);
		abb_posOrdem(a->dir);
		printf("%d\t",a->info);
	}
}
//------------------------------------
Arv* abb_retira(Arv *r, int v) {
     if (r==NULL) return NULL;
     if(r->info > v) r->esq = abb_retira(r->esq, v);
     else if (r->info < v) r->dir = abb_retira(r->dir, v);
          else {      //achou o elemento 
                if ( r->esq ==NULL && r->dir ==NULL) { // no sem filhos
                     free(r);
                     r=NULL;   } 
                else  if (r->esq ==NULL) { //filho a direita            
                          Arv *t = r;
                          r=r->dir;
                          free(t);      }
                      else if( r->dir ==NULL) { //filho a esquerda
                                 Arv *t=r;
                                 r=r->esq;
                                 free(t);     }
                               else { //tem 2 filhos     
                                      Arv *f=r->esq;
                                      while (f->dir != NULL)f=f->dir;
                                      r->info =f->info;
                                      f->info=v;
                                      r->esq=abb_retira(r->esq,v);    }
                    }
                    return r;                           
}
//altura da arvore---------------------------------------------
int max2 (int a, int b){
       return (a>b)?a:b;//if ternário como no excel
}       

int abb_altura(Arv *a){
       if (abb_vazia(a))
           return -1;
       return 1+ max2(abb_altura(a->esq),abb_altura(a->dir));   
}
//------------------------------------------------------------------      
int contaNos(Arv *a){ //usando o percurso em ordem raiz=esq-dir
	int tot=0;
	if(a!=NULL){
		//printf("%d\t",a->info);
		tot=tot+1;
		//abb_preOrdem(a->esq);
		tot=tot+contaNos(a->esq);
		//abb_preOrdem(a->dir);
		tot=tot+contaNos(a->dir);
	}
	return tot;
	}
//---------------------------------------------------------------        
 int somaElementos(Arv *a){
 	int x=0;
 		if(a!=NULL){
		printf("%d\t",a->info);
		x=x+a->info; // soma os elementos
		x=x+somaElementos(a->esq);
		x=x+somaElementos(a->dir);
	}
	return x;// retorna a variavel pra função principal
 }
//----------------------------------------------------------------
 void elementosSemfilhos(Arv *a){// tipo void 
 	int x;
 	if(a!=NULL){
		if (a->esq==NULL && a->dir==NULL){ // se o da elemento da esqueda e da direita for vazio 
				printf("%d\t",a->info); // então o elemento não tem filhos
		}
		elementosSemfilhos(a->esq);
		elementosSemfilhos(a->dir);
	}
 }
//----------------------------------------------------------------
void menu(){
	system("cls");
	printf("*******************\n");
	printf("*Escolha uma opcao*\n");
	printf("*******************\n");
	printf(" 1 - Insere\n");
	printf(" 2 - Retira\n");
	printf(" 3 - Mostra\n");
	printf(" 4 - Busca\n");
	printf(" 5 - Altura da arvore\n");
	printf(" 6 - Conta a quantidade de nos\n");
	printf(" 7 - Somar os elementos da arvore\n");
	printf(" 8 - Mostrar os nos sem filhos\n");
	//--------------------------
	printf(" 9 - Fim\n");
	printf(" ==> ");
}
//------------------------------------
int main(){
	Arv *a,*aux;
	a=abb_cria();
	int dado, op;
	do{
		menu();
		scanf("%d",&op);
		switch(op){
			case 1: //insere
			     printf("Digite um valor: ");
			     scanf("%d",&dado);
			     a=abb_insere(a,dado);
			     break;
			case 2: //retira
			     printf("Digite um valor: ");
			     scanf("%d",&dado);
			     a=abb_retira(a,dado);
			     break;
			case 3: //mostra
			     printf("Percurso em ordem\n");
			     abb_emOrdem(a);
			     printf("\n\nPercurso em pre_ordem\n");
			     abb_preOrdem(a);
			     printf("\n\nPercurso em pos_ordem\n");
			     abb_posOrdem(a);
			     printf("\n");
			     break;
			case 4: //busca
			     printf("Digite um valor a ser procurado: ");
			     scanf("%d",&dado);
			     aux=abb_busca(a,dado);
			     if(aux==NULL)
			        printf("%d NAO encontrado\n",dado);
			     break;
			case 5://altura da árvore
				 printf("\nAltura da arvore: %d\n",abb_altura(a));
				 break;
			case 6: //quantidades des nos
				 printf("\nA quantidade de nos: %d\n",contaNos(a));
				 break;
			case 7:
				 printf("\nA soma os elementos da arvore: %d\n",somaElementos(a));
				 break;
			case 8:
				 printf("\nOs nos sem filhos\n");
				 elementosSemfilhos(a);
				 break;
		}
		printf("\n");
		system("pause");
		
	}while(op!=9);
}




