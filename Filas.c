#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Neste codigo estava a trabalhar com filas, inserção*/

typedef struct 
{
	char nome[100];
	int mat;
	
}estudante;

struct no {
	estudante dado;
	struct no *prox;
};

typedef struct Fila{
	
	struct no *inicio;
	struct no *fim;
	
}fila;

void menu(){
	printf("\n========Escolha uma opção=========");
	printf("\n1 - inserir");
	printf("\n2 - Imprimir fila");
	printf("\n3 - Remover elemento");
	printf("\n4 sair\n");
}

void ler(estudante *e){
	printf("\nInsira os dados do estudante: ");
	scanf("%s %i", e->nome, &e->mat);
}

void inserir(fila *f, estudante dado){
	struct no* novo = (struct no*)malloc(sizeof(struct no));
	novo->dado = dado; //insere os novos dados á um nó
	novo->prox = NULL;//o proximo nó ao novo dado inserido é null
	if(f->inicio == NULL){
		f->inicio = novo;
		f->fim = novo;
	}else
	{
		f->fim->prox = novo; //Fazemos o fim anterior apontar para o novo nó inserido
		f->fim = novo; //Fazemos o nosso fim ser o novo nó inserido
	}
}

void imprime(fila f){
	struct no *pi;
	for(pi = f.inicio; pi != NULL; pi = pi->prox){
		printf("\nNome: %s\nMatricula: %i\n", pi->dado.nome, pi->dado.mat);
	}
}

void remover(fila *f){
	
	if(f->inicio==NULL){
		printf("\nFila vazia\n");
	}else {
	struct no *pi = f->inicio;
	f->inicio = pi->prox;
	free(pi);
	}
}

int main()
{
	setlocale(LC_ALL,"");
	fila f;
	f.inicio = NULL;
	f.fim = NULL;
	int op;
	menu();
	scanf("%i", &op);
	
	while(op!=4)
	{
		if(op==1){
			estudante e;
			ler(&e);
			inserir(&f, e);
		}
		if(op==2){
			imprime(f);
		}
		if(op==3){
			remover(&f);
		}
		menu();
		scanf("%i", &op);
	}
	return 0;
}
