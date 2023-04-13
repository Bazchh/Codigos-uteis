#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

/*Questão 1: pedia para que fosse alocado dinamicamente uma matriz de atamanho n*n e que fossem atribuidos valores para todas as posições, em seguida,
pedia-se para que fossem mostrados somente valores da diagonal principal*/

/*Por ser uma questão que possui um enunciado bem especifico em questão do que se quer, preferi não inserir um
exemplo de entrada e saída, mas caso o professor deseje posso enviar via email
*/
int main (){
	setlocale(LC_ALL,"");
	
	int **mat = (int**)malloc(10*sizeof(int*)); //Ponteiro de um ponteiro de inteiros que é alocado dinamicamente para armazenar os valores de uma matriz
	int i, j, v = 0; //variaveis contadoras
	
	//Alocando posições da matriz. Caso este procedimento não seja feito, o programa apresenta erro durante a compilação
	for (i=0; i < 10; i++){
		mat[i] =  (int*) malloc(10*sizeof(int));
	}
	
	//Atribuindo valores para cada posição na matriz de 1 a 10
	for (j=0; j < 10; j++){
		for (i=0; i < 10; i++){	 
			mat[i][j] = v++;
			}	
	}
	//Imprimindo a matriz normalmente e todos os seus valores
	printf("\nMatriz 10x10: \n");
	
		for (i=0; i < 10; i++){
			for (j=0; j < 10; j++){
			printf("%5i", mat[i][j]);}
	
	
		printf("\n");
	}
	//Imprimindo somente os endereços da diagonal secundaria da matriz ()
	printf("\nEndereço dos elementos da diagonal secundaria: \n\n");
	for (i=0; i < 10; i++){
		for (j=0; j < 10; j++){
	//Quando a soma de i+j forem iguais a 9 (no caso de uma matriz 10x10. Em outros casos menos especificos utiliza-se n-1),
	// será o numero de um dos elementos da diagonal secundaria				
				if (i+j==9){	
			printf("%i ", &mat[i][j]);}
	}
		
	}
	
	printf("\n\n");
	
	//libera memoria alocada
	free(mat);
	system("pause");
	return 0;
}
