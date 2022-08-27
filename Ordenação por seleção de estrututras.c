#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int mat;
	char nome[100];
}Estudante;


void ler(Estudante *e){

	printf("\nInforme o nome do estudante: ");
	scanf("%s", e->nome);
	printf("\nInforme a matricula do estudante: ");
	scanf("%i", &e->mat);
	
}

int main (){
	
	setlocale(LC_ALL,"");
	int n;
	printf("\nInforme a quantidade de estudantes: ");
	scanf("%i", &n);
	
	Estudante v[n];
	int i, j;
	
	for(i=0;i<n;i++){
		ler(&v[i]);
	} 
	
	for(i=0; i<n; i++){
		printf("\nNome: %s Matricula: %i", v[i].nome, v[i].mat);
	}
	
	for(i=0;i<n;i++){ //Ordena numeros inteiros de uma estrutura
		int menor = i;
		for(j=i+1; j<n; j++){
			if(v[j].mat<v[menor].mat){
				menor = j;
			}
		}
		
		Estudante temp = v[i];
		v[i] = v[menor];
		v[menor] = temp;
	}
	
	printf("\nLista ordenada:\n");
	for(i=0; i<n; i++){
		printf("\nNome: %s Matricula: %i", v[i].nome, v[i].mat);
	}
	
	printf("\n\n");
	return 0;
}

