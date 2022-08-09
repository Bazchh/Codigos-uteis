#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int contfib(int n1, int n2, int aux, int n);

int main(){
	int n1, n2, aux, n, r;
	
	printf("\n Insira um numero para calcular seu fibonacci: ");
	scanf("%i", &n);
	
	contfib(n1, n2, aux, n, k);
	
	return 0;
}


int contfib(int n1, int n2, int aux, int n, int k){
	n1 = 0;
	n2 = 1;
	int i;
	
	for (i = 0; i  < n; i++){
		aux = n1+n2;
		n1 = n2;
		n2 = aux;
		
		printf(" %i ", n2);
	}
	
	return n2;
}
