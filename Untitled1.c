#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL,"");
	struct notaAluno //tipo de dado 
	{
		char nome[50];
		int matricula;
		float nota1;
		float nota2;
		float nota3;
	};//definição da struct

	struct notaAluno aluno[5];
	
	int i;
	fflush(stdin);
	fflush(stdout);
		for (i=0; i<5; i++){
		
			printf("\nDigite o nome do aluno: ");
			scanf("%s", aluno[i].nome);
			
	
	        printf("\nDigite o numero da matricula do aluno: ");
	        scanf(" %d", &aluno[i].matricula);
	
	        printf("\nDigite a nota da primeira prova: ");
	        scanf(" %f", &aluno[i].nota1);
	
	        printf("\nDigite a nota da segunda prova: ");
	        scanf(" %f", &aluno[i].nota2);
	
	        printf("\nDigite a nota da terceira prova: ");
	        scanf(" %f", &aluno[i].nota3);
        }
	
return 0;
}
