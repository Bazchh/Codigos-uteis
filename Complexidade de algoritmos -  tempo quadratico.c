#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA O PROGRAMA QUE LEIA UM NUMERO N, REFERENTE AO NUMERO DE LINHAS E COLUNAS DE UMA MATRIZ N X N. EM SEGUIDA, LEIA OS DADOS
DA MATRIZ E INFORME A SOMA DOS VALORES QUE ESTÃO ACIMA DA DIAGONAL PRINCIPAL*/


int main(){
	setlocale(LC_ALL,"");
	
	int n;
	
	printf("Informe o tamanho da matriz: ");
	scanf("%i", &n);
	
	int m[n][n];
	int i, j;
	
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			
			scanf("%i", m[i][j]);//Essa instrução será executada n x n vezes (caso n = 4, será 4 x 4 = 16 vezes)
			
		}
	}
	
	int soma = 0;
	
	for(i=0; i<n; i++){
		for(j=0;j<n;j++){
			
			if (i<j){
				
				soma = soma + m[i][j];
				
			}
			
		}
	}
	
	printf("\n\n");
	
	printf("soma = %i\n", soma);
	
}


/*
CONCEITO DE COMPLEXIDADE DE ALGORITMOS - TEMPO QUADRATICO

Está relacionada a instruções que são executadas n x n vezes, ou seja, um valor ao quadrado!


*/
