#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fib(int n, int k);

int main(){
	int n, k, r;
	
	printf("\n Insira um numero para calcular seu fibonacci: ");
	scanf("%i", &n);
	
	printf("\nInsira numero para ser avaliado durante o fibonacci de %i: ", n);
	scanf("%i", &k);
	
	r = fib(n, k);
	
	printf("\nO fibonacci de %i foi avaliado %i vezes durante a busca do fibonacci"
	" de %i \n", k, r, n);
	
	return 0;
}

int fib(int n, int k){
	int n1 = 0;
	int n2 = 1;
	int i, aux, cont = 0;
	
	for (i = 0; i  < n; i++){
		aux = n1+n2;
		n1 = n2;
		n2 = aux;
		
		if (n2 > k){
			fib (k, n);
			cont++;
		} 
		
	}
	
	return cont;
}
