#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO N CORRESPONDENTE AO NUMERO DE ELEMENTOS NO VETOR E IMPRIMA A QUANTIDADE DE NUMEROS POSITOVOS NO VETOR*/
		
	
	int positivos (int i, int n, int v[]){
		
		if (i==n){
			return 0;
		} 
		
		if (v[i] > 0){
			return 1 + positivos (i+1,n,v); //Retorna verdadeiro para o indice se o valor for positivos e passa para o proximo indice
		}
		
		return positivos(i+1,n,v); //Passa para o proximo indice caso o valor seja negativo;
	}
		
	int main (){
		
		setlocale(LC_ALL, "");
		int n;
		int r;
		printf("\nInforme o valor de n: ");
		scanf("%i", &n);
		int v[n];
		int i;
		
		for (i = 0; i < n; i++){
			
			printf("\nInsira os valores para o vetor: ");
			
			scanf(" %i", &v[i]);
			
		}
		
		r = positivos(0,n,v);
		
		printf("\n%i numeros positivos no vetor\n", r);
		
		
	
	return 0;
	}

