#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*ESCREVA O PROGRAMA QUE LEIA UM NUMERO N REFERENTE A QUANTIDADE DE ESTUDANTES. EM SEGUIDA, LEIA OS DADOS DE N ESTUDANTES E INFORME O NOME E A MÉDIA
DE CADA ESTUDANTE. CADA ESTUDANTE POSSUI UM NOME, E TRÊS NOTAS, REFERENTES A CADA UNIDADE*/

typedef struct { 

char nome [100];
float n1;
float n2;
float n3;
}Estudantes;

int main(){
	setlocale(LC_ALL,"");
	int n, i;
	
	printf("\nInforme o numero de estudantes: ");
	scanf("%i", &n);
	
	float media [n];
	
	Estudantes e[n];
	
	//As instruções dentro do laço for serão executadas n vezes, que é definida pela quantidade de alunos inserida pelo usuario
	for (i=0; i < n; i++){
		
		printf("\nInforme os dados do estudante %i: ", i+1);
		scanf("%s %f %f %f",e[i].nome, &e[i].n1, &e[i].n2, &e[i].n3);
		
		media[i] = (e[i].n1 + e[i].n2 + e[i].n3)/3;
		
	}
	
	for (i=0; i < n; i++){
		
		printf("\n %s: %.1f", e[i].nome, media[i]);	
	
	}
	
	printf("\n\n");
	
}

/*CONCEITO DE COMPLEXIDADE DE ALGORITMOS - TEMPO LINEAR:

Caso o n seja 4, 5 ou 6 (cada um em uma execução diferente do programa) o programa executará as instruções de acordo com o valor de n, 
isso pode ser visto como uma caracterisca linear, onde o numero de execução de uma instrução pode ser alterada dentro do programa

*/

