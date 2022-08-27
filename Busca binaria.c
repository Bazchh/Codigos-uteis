#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO. ESSE NUMERO SERÁ A QUANTIDADE DE ESTUDANTES QUE SERÃO LIDOS EM SEGUIDA. CADA ESTUDANTE
POSSUI UMA MATRICULA, NOME E TRÊS NOTAS, UMA PARA CADA UNIDADE. AO FINAL DEVE-SE APRESENTAR DUAS OPÇÕES PARA O USUARIO. AO SELECIONAR A
OPÇÃO PESQUISAR, O USUARIO DEVE INFORMAR A MATRICULA DO ESTUDANTE, FORNECER UM PONTO A MAIS NA TERCEIRA NOTA E IMPRIMIR A MEDIA DESSE
ESTUDANTE*/

typedef struct {
	
	int mat;
	char nome[100];
	float n1;
	float n2;
	float n3;
}estudante;

void menu (){
	
	printf("\nEscolha uma opção");
	printf("\n 1 - pesquisar");
	printf("\n 2 - sair\n");
	
}

void ler (estudante *E){
	
	printf("Insira os dados do estudante: ");
	
	scanf("%i %s %f %f %f", &E->mat, E->nome, &E->n1, &E->n2, &E->n3);
	
}

int buscabinaria (int mat, int n, estudante v[]){
	
	int i = 0; //Inicio da pesquisa
	int f = n - 1; //armazena o final do vetor, caso sejam 5 alunos, seu valor será 4 por exemplo
	
	while(i<=f){
		
		int meio = (i+f)/2; //Meio será igual inicio + fim dividido por dois
		if(v[meio].mat == mat){
			return meio;
		} else if (v[meio].mat < mat){ //Caso não encontre o dado buscado, será verificado se deve-se buscar o dados na parte de cima ou de baixo do vetor
			
			i = meio + 1;
		} else{
			
			f = meio  - 1;
			
		}
	}	
	
	return -1;
}
		
	int main (){
		
		setlocale(LC_ALL, "");
		
		int n;
		
		printf("\nInforme a quantidade de alunos: ");
		scanf("%i", &n);
		
		estudante v[n];
		
		int i;
		
		for (i = 0; i<n; i++){
			
			ler(&v[i]);
			
		}
		
		int op;
		
		menu();
		
		scanf("%i",&op);
		
		while (op!=2){
			
			if(op==1){
				int mat;
				printf("\nInforme a matricula do aluno: ");
				scanf("%i", &mat);
				
				int idx = buscabinaria(mat,n,v); //Armazena a posição a qual está o aluno buscado
				
				if (idx != 1){
					
					v[idx].n3 = v[idx].n3 + 1;
					float media = (v[idx].n1 * 2 + v[idx].n2 * 3 + v[idx].n3 * 4)/9;
					
					printf("\n %s: %.1f\n", v[idx].nome, media);
					
				}
				
			}
			
			menu();
			scanf("%i",&op);
			
		}

	return 0;
		}

