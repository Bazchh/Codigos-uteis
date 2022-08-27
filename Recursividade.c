#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE RECEBA UM NUMERO E IMPRIMA A SOMA DOS ELEMENTOS DE 1 ATÉ N*/
		
		
		
	int soma (int n){
		
		if (n == 1){	
			return 1;
		} 
		
		return n + soma(n-1); //A soma do proximo numero será ele mesmo + a soma do anterior. Por exemplo, a soma de 1 a 5 será 5 + a soma de 1 a 4, que é 10 + 5
	}	
		
	int main (){
		
		setlocale(LC_ALL, "");
		int n;
		printf("\nInforme o valor de n: ");
		scanf("%i", &n);
		
		int r = soma(n);
		
		printf("%i", r);
	
	return 0;
	}

