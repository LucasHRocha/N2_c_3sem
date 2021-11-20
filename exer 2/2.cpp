#include <stdio.h>
#include <stdlib.h>



void gravaNumeros (double *num, int tam){
    int i;
	FILE *fp;
	fp=fopen("Reais.bin","w+b"); // abre o arquivo
	fwrite(num, sizeof(int),tam,fp); /// grava o arquivo 
	for(i=0;i<=tam;i++){
	 	printf("\n %.lf", num[i]); // printa oq ta no arquivo
	 }
	fclose(fp);
}


int main(){
    double numero[4];
	int tam=4, cont;
	for(cont=0;cont<=tam;cont++){
		printf("Escolha um numero do vetor[%d] :",cont);
		scanf("%lf", & numero[cont]);
	}
	gravaNumeros(numero,tam);
}
