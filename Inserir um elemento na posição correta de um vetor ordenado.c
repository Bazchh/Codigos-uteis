#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO N. ESSE NUMERO N SERÁ A QUANTIDADE DE VALORES LIDOS EM SEGUIDA. DEVE-SE INFORMAR
N VALORES ORDENADOS DO MENOR PARA O MAIOR. EM SEGUIDA, DEVE-SE LER UM NUMERO X E COLOCA-LO NA POSIÇÃO CORRETA DO VETOR*/

int main(){
	setlocale(LC_ALL,"");
	int n, m;
	printf("\nInforme uma valor para n: ");
	scanf("%i", &n);
	int i;
	int v[n+1];
	for(i = 0; i < n; i++){
		printf("\nInsira o valor para a posição %i: ", i+1);
		scanf("%i", &v[i]);
	}
	
	int x;
	printf("\nInsira o valor a ser inserido no vetor ordenado: ");
	scanf("%i",&x);
	
	for(i = n -1; i >= 0 && x < v[i]; i--){
		v[i+1] = v[i];
	}
	
	v[i+1] = x;
	printf("\n");
	for(i = 0; i < n + 1; i++){
		printf(" %i ", v[i]);
	}
	printf("\n\n");
	return 0;
}
