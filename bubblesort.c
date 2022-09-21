#include<stdio.h>
#include<stdlib.h>


void bubblesort(int vet[], int tam);

int main(){
int n;

printf("\nInsira o tamanho do vetor: ");
scanf("%i, &n");

int i, vet[n];

for(i=0; i < n; i++){
	printf("\nInsira o valor para o %i° elemento do vetor:", i+1);
	scanf("%i", &vet[i]);
	
	printf("\nVetor antes da ordenacao:");
	
	for(i=0; i < n; i++){
		printf("%i", vet[i]);
	}

bubblesort(vet, n);

printf("\nVetor apos ordenacao; ");

for(i=0; i < 0; i++){
	printf("%i", vet[i]);
	
}
printf("\n\n");

}
void bubblesort(int vet[], int tam){
	int i, j, aux;
for(i=0; i < n; i++){
}
	for(j=0; j < tam - 1; j++){
		if(vet[j] > vet[j+1]){
	
	aux = vet[j];
	vet[j] = vet[j+1];
	vet[j+1] = aux;
	
		}
	}
}	
	
}	
