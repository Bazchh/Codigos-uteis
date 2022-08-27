#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

/* Ex entrada e sa�da

Entrada-> tamanho do vetor: 4 e valores 1, 5, -2 e 8

Sa�da-> o ponto min � -2 e o ponto max � 8

*/

int main (){
	setlocale(LC_ALL,"");
	int max, min; //Armazena o valor minimo e maximo
	int *Vet;  // Ponteiro que eu usei para alocar um vetor de ponteiros. Achei que a implementa��o ficou mais facil neste caso por eu n�o ter 
	//Um valor definido para o tamanho do vetor
	int t; //Armazena o tamanho do vetor
	i = 0; //Variavel contadora
	
	//Recebe o tamanho que ser� utilizado para definir o tamanho do vetor de ponteiro
	printf("\nInsira o tamanho do vetor: ");
	scanf("%i", &t);
	
	//Alocando tamanho do vetor de ponteiro
	Vet = (int*)malloc(t*sizeof(int));
	
	//Recebe os valores para cada posi��o do vetor de ponteiros
	for (i=0; i < t; i++){
		printf("\nInsira o valor para a posi��o %i: ", i+1);
		scanf("%i",&Vet[i]);
	}
	
	//Chamada da fun��o que calcula o valor min e maximo inseridos pelo usuario
	mm(Vet,min,max,t);
	
	//Libera memoria alocada
	free(Vet);
	printf("\n\n");
	system("pause");
	return 0;
}

//Fun��o que calcula o valor min e maximo inseridos pelo usuario
void mm (int Vet[], int min, int max, int t){
		int i = 0;//Variavel contadora
		//Atribuindo valores inicias as variaveis que armazenaram os valores min e max 
		min = Vet[0];
		max = Vet[0];
		
		//La�o for que verifica e armazena os valores min e max inseridos
		for (i=0;i<t;i++){	
			if(Vet[i]>max){
				max=Vet[i];
			}
			if(Vet[i]<min){
				min=Vet[i];
				}	
		}
		
		//Imprime os valores das variaveis min e max
		printf("\nO valor min � %i e o valor max � %i ",min,max);
		
	}
	
