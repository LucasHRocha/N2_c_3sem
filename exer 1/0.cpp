#include <stdio.h>
#include <stdlib.h>
// linguagem c

void selection_sort(int num[], int tam) {
	int i, j, min;
	for (i = 0; i < (tam-1); i++) {
		min = i;
		for (j = (i+1); j < tam; j++) {
			if(num[j] < num[min]) {
				min = j; 
			}
		}
		if (i != min) { 
			int swap = num[i];
			num[i] = num[min];
			num[min] = swap; 
		}
	}
}
int main(){
	int v[20]={19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0}, tam=20,i;
	selection_sort(v,tam);
	for(i=0;i<tam;i++){
		printf("%d\t",v[i]);
	}
}






