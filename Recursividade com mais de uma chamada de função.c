#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*A SEGUINTE SEQUENCIA DE NUMEROS 0 1 1 2 3 5 8 13 21... É CONHECIDA COMO SERIE DE FIBONACCI. NESSA SEQUENCIA, CADA NUMERO, DEPOIS DOS 2 
PRIMEIROS, É IGUAL A SOMA DOS 2 ANTERIORES. ESCREVA UM ALGORITMO QUE LEIA UM NUMERO N E MOSTRE O ENÉSIMO NUMERO DESSA SEQUENCIA.*/

int f (int n){
	
	if (n == 1){ //Caso n seja igual a 1, o usuario quer saber o primeiro numero da serie de fibonacci, que é 0
		
		return 0;
	} else if (n == 2){ // caso n seja 2, ele quer saber o segundo numero da serie de fibonacci, que é 1
		
		return 1;
	} else{
		
		return f(n-1) + f(n-2);
	}
	
}

int main (){
	
	setlocale(LC_ALL,"");
	int n;
	printf("\nInforme o valor de n: ");
	scanf("%i", &n);
	
	int r = f(n);
	
	printf("\n%i", r);
	
	return 0;
}
