#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA NUMERO. ESSE NUMERO SERÁ A QUANTIDADE DE VALORES LIDOS EM SEGUIDA. AO FINAL, DEVE-SE APRESENTAR OS VALORES ORDENADOS
DO MENOR PARA O MAIOR*/

int main(){
	setlocale(LC_ALL,"");
	int n;
	printf("\nInforme uma valor para n: ");
	scanf("%i", &n);
	
	int v[n];
	int i, j;
	printf("\n");
	for(i = 0; i < n; i++){
		scanf("%i", &v[i]);
	}
	//Ordenação por inserção
	
	for(i = 1; i < n; i++){
		int x = v[i];
		for(j = i - 1; j>= 0 && x < v[j]; j--){
			v[j+1] = v[j];
		}
		v[j+1] = x;
	}
	
	for(i = 0; i < n; i++){
		printf(" %i ", v[i]);
	}
	printf("\n\n");
	return 0;
}
