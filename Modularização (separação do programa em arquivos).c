#include <stdio.h>
#include "calculadora.h"
#include <stdlib.h>
#include <locale.h>

/*Escreva um programa que leia dois numeros. Em seguida, deve-se realizar as quatro opera��es basicas sobre eles*/

int main(){
	setlocale(LC_ALL,"");
	int n1,n2;
	printf("Escreva o valor do primeiro numero: ");
	scanf("%i", &n1);
	
	printf("\nInsira o valor do segundo numero: ");
	scanf("%i", &n2);
	
	printf("\n Adi��o: %i + %i = %i", n1, n2, adiciona(n1, n2));
	printf("\n Subtra��o: %i - %i = %i", n1, n2, subtracao(n1, n2));
	printf("\n Multiplica��o: %i * %i = %i", n1, n2, multiplica(n1, n2));
	printf("\n Divis�o: %i/%i = %i", n1, n2, divide(n1, n2));
	
	return 0;
}
