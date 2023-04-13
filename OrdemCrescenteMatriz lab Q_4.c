#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
       
/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/                                      
/*Ex de entrada e saída

Entrada-> tamanho da matriz: 4 (a matriz terá 16 elementos, pois, como é uma matriz quadrada ficará linhaxcoluna (4x4))

saída->  	 1  5  9   13
		 2  6  10  14
		 3  7  11  15
		 4  8  12  16
		 
		 Insere elementos na matri de forma crescente
*/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
int main()
{
	setlocale(LC_ALL,"");
	int T, i, j,k, v = 1;//Variavel usada para armazenar o tamanho da matriz e variaveis contadoras
	
	//recebe o tamanho da matriz
	printf("\nInsira o tamanho da matriz: ");
	scanf("%i",&T);
	
	//Aloca o tamanho da matriz de acordo com o tamanho inserido
	int **mat = (int**) malloc(T*sizeof(int*));
	
	
	//Atribui elementos a cada posição da matriz de forma crescente por linha 
	for (i=0; i < T; i++){
		mat[i] =  (int*) malloc(T*sizeof(int));
	}
	
		for (j=0; j < T; j++){
			for (i=0; i < T; i++){	 
		
			mat[i][j] = v++;
		
				}
			}	
	
	
	//Imprime os elementos inseridos na matriz
	for (i=0; i < T; i++){
		for (j=0; j < T; j++){
			printf("%5i", mat[i][j]);
		}	
		printf("\n");
	}
	
	//libera memoria alocada
	free(mat);
	system("pause");
	return 0;
}
    
