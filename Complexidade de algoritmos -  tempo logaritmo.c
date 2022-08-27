#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO N. EM SEGUIDA, A CADA RODADA IMPRIMA A METADE DO VALOR CORRENTE DE N
ENQUANTO O VALOR CORRENTE FOR MAIOR QUE 1*/


int main(){
	setlocale(LC_ALL,"");
	
	int n;
	
	printf("Insira um valor para dividir até que seja menor ou igual a 1: ");
	scanf("%i", &n);
	
	while (n > 1){
		
		
		printf("\n%i", n);
		
		n = n/2;
		
	}
	
	printf("\n\n");
	
}


/*
CONCEITO DE COMPLEXIDADE DE ALGORITMOS - TEMPO LOGARITMO


*/
