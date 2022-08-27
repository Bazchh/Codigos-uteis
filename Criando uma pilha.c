#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct estudante{
	
	char nome[100];
	int mat;
	
}Estudante;

struct no{
	   Estudante dado;
	   	struct no *prox;
};

typedef struct {
	struct no *topo;
}Pilha;

void menu(){
	printf("\n========Escolha uma opção=========");
	printf("\n1 - Adicionar pilha");
	printf("\n2 - Mostrar pilha");
	printf("\n3 - Remover elemento");
	printf("\n4 - Verificar pilha");
	printf("\n5 - Pegar topo");
	printf("\n6 - Invertet");
	printf("\n7 - Sair\n");
}

void ler(Estudante *e){
	printf("\nInsira os dados do estudante: ");
	scanf("%s %i", e->nome, &e->mat);
}

void inserir(Pilha *p, Estudante dado){
	struct no *novo = (struct no*)malloc(sizeof(struct no));
	novo->dado = dado; //Recebe os dados passados
	novo->prox = p->topo; //Fazemos os novos dados apontarem para onde o topo apontava
	p->topo = novo; //Agora fazemos o topo da pilha apontar para os novos dados
	//exe: topo->novo->antigo_topo após o uso da função
}

void imprime(Pilha p){
	struct no *pi;
	for(pi = p.topo; pi != NULL; pi = pi->prox){
		printf("\nNome: %s\n Matricula: %i \n", pi->dado.nome, pi->dado.mat);
	}
	
}

void remover(Pilha *p){
	if(p->topo==NULL){
		printf("\nA pilha está vazia\n");
	}else if(p->topo!=NULL)
	{
    struct no*pi = p->topo;	
	p->topo = pi->prox;
	free(pi);
	printf("\nElemento removido com sucesso!\n");
	}	
}

int vazia(Pilha p){
	if(p.topo==NULL){
		return 1;
	} else
	{
		return 0;
	}
}

struct no*topo(Pilha p){
	return p.topo;
}

void inverter(Pilha *p){
	struct no *pi = p->topo; //Criamos um nó para nos auxiliar
	Pilha aux; //Pilha auxiliar
	aux.topo = NULL;
	for(pi = p->topo; pi != NULL; pi = p->topo){
		inserir(&aux, pi->dado); //Inserir o elemento do topo da pilha original a cada rodada
		//Na pilha auxiliar
		remover(p); //Removemos o elemento do topo da pilha original a cada rodada
	}
	p->topo = aux.topo; //Ao fim da função, copiamos a pilha auxiliar a qual é a pilha invertida de volta para a pilha original
}

int main()
{
	setlocale(LC_ALL,"");
	Pilha p;
	p.topo = NULL;
	int op;
	menu();
	scanf("%i", &op);
	while(op!=7)
	{
		if(op==1){
			Estudante e;
			ler(&e);
			inserir(&p,e);
		}if(op==2){
			imprime(p);
		} 
		if(op==3){
			remover(&p);
		}
		if(op==4){
			int r = vazia(p);
			if(r != 0){
				printf("\nA pilha está vazia\n");
			}else
			{
				printf("\n pilha contém elementos\n");
			}
		}
		if(op==5){
			struct no *pi = topo(p);
			if(pi==NULL){
				printf("\nPilha vazia!");
			}else
			{
				printf("\n%s %i\n", pi->dado.nome, pi->dado.mat);
			}
		}
		if(op==6){
			inverter(&p);
			printf("\nPilha invertida com sucesso!\n");
		}
   	
		menu();
		scanf("%i", &op);
	}
	return 0;
}