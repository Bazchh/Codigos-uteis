// Algoritmo e Estrutura de Dados- Prof. Patrick Terrematte
// Aluna: Neilla Maria de Souza Bezerra 2021011118
// Questão 07

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura Funcionario
typedef struct Funcionario {
    char depto[10]; 
    int mat;
    char nome[81];
    float salario;
}funcionario;
//Estrutura No
struct no {
	funcionario dado;
	struct no *prox;	
};
//Estrutura Lista
typedef struct lista {
	struct no *inicio;
}Lista;

// Função Void para leitura dos dados inseridos pelo usuário;
void ler(funcionario *pe){
	printf("*Insira o nome do departamento \n");
	scanf("%s", pe->depto); 
	printf("*Matricula:\n"); 
	scanf(" %d", &pe->mat);
	printf("*Nome do funcionario:\n");
	scanf(" %s", pe->nome);
	printf("*Salario deste funcionario eh: \n");
	scanf(" %f", &pe->salario);
	
}

// Função Ist Void para inserir a lista e retornar ao inicio de forma ordenada;
void lst_insere(Lista *plista, funcionario dado){
	struct no * novo = (struct no*) malloc(sizeof(struct no));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
}

// Função cria a lista, que retorna NULL caso seja falso.
Lista lst_cria(int n){
	Lista lista;
	lista.inicio = NULL;
	int i;
	//Laço For que chama a função insere a lista os dados inseridos pelo usuário;
	for(i = 0; i < n ; i++){
		funcionario e;
		ler(&e);
		lst_insere(&lista, e);
   }
   //retorno
	return lista;
}

// Função retirar um funcionário da lista.
void lst_retira(Lista *plista, int mat){
   //Inicializando == NULL -> RETORNO;
	if(plista->inicio == NULL){
		printf("!!!Lista Vazia!!!\n");
	}
	//O No se localiza-se no inicio a lista;
	else if(plista->inicio->dado.mat == mat){
		struct no* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
		printf("Funcionario excluido com sucesso!!\n");
	}
	//A Lista tem um unico No, onde a Matricula não é existente;
	else if(plista->inicio->prox == NULL){
		if(plista->inicio->dado.mat != mat){
			printf("!!O funcionario não deve ser removido!!!\n");
		}
	}
	//A Lista CONTÉM  multiplos No, sendo um valor não existente;
	//A Lista CONTÉM  multiplos No, sendo um valor existente;
	else{
		struct no* pa;
		struct no* pi;
		for(pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox){
			pa = pi;
		}
		//pi == NULL
		if(pi == NULL){
			printf("!!O funcionario não deve ser removido!!!\n");
		}
		else{
			pa->prox = pi->prox;
			free(pi);
			printf("!!Funcionario Excluido com SUcesso!!!\n");
		}
	}
}

// Função Void para deletar a lista completa, e incializando a NULL com o parametro auxiliar proximo;
void deletar_lista_completa(Lista *plista){
	struct no* pi;
	while(plista->inicio != NULL){
		pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
		
	}
}

// Função de busca/pesquisa de um funcionário;
struct no* lst_busca(Lista lista, int mat){
	struct no* pi;
	for(pi = lista.inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
	
  return pi;
}

// Função para impressão da lista de funcionário, dados inseridos pelos usuarios.
void lst_imprime(Lista lista, char s1[]){
	struct no * pi;
	for(pi = lista.inicio; pi != NULL ; pi = pi->prox){
	     if(strcmp(pi->dado.depto, s1) == 0){
	        printf("|Nome: %s| Matricula %d| Salario %2.f|\n", pi->dado.nome, pi->dado.mat,
			 pi->dado.salario);
	      }
    }       
}

// Dado da lista para identificar o valor da folha de pagamento de cada funcionário;
void lstfunc_folha_pagto(Lista lista, char* s1){
  float totalGasto = 0;
  struct no * pi;
	for(pi = lista.inicio; pi != NULL ; pi = pi->prox){
	     if(strcmp(pi->dado.depto, s1) == 0){
		      totalGasto += pi->dado.salario;
        }
	}
	printf("!!O custo total do departamento %s eh de: %.2f\n",s1,totalGasto);
}    

// Função Void MENU;
void menu(){
	printf("|>>          Menu de USUARIO           <<|\n");
	printf("|1  - Inserir novo                     	 |\n");
	printf("|2  - Imprimir lista                     |\n");
	printf("|3  - Busca por funcionario              |\n");
	printf("|4  - Deletar funcionario                |\n");
	printf("|5  - Deletar lista                   < |\n");
	printf("|6  - Criar lista completa               |\n");
	printf("|7  - Mostrar folha de pagamento         |\n");
	printf("|8  - Sair                               |\n");
	printf("|>>                                    <<|\n");
	printf("*Insira a opcao desejada:                |\n");
}

// Função que auxilia no Menu principal com as devidas condições, para controle e acesso do usuario;
void main_empresa(){
	Lista lista;
	lista.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 8){
		if(op == 1){
			funcionario e;
			ler(&e);
			lst_insere(&lista, e);
			printf("\n");
		}
		else if(op == 2){
			char s1[10];
			printf("*Insira o departamento:\n");
			scanf("%s", s1);
			lst_imprime(lista, s1);
			printf("\n");
		}

		else if(op == 3){
			int mat;
			printf("*Insira a matricula do funcionario:\n");
			scanf("%d", &mat);
			struct no * pi = lst_busca(lista, mat);
			if(pi != NULL){
				printf(">>Nome: %s Matricula %d\n", pi->dado.nome, pi->dado.mat);
			}
			else{
				printf("Funcionario nao localizado!!!\n");
			}
			printf("\n");
		}

		else if(op == 4){
			int mat;
			printf("*Insira a matricula para DELETAR:\n");
			scanf("%d", &mat);
			lst_retira(&lista, mat);
			printf("\n");
		}

		else if(op == 5){
			deletar_lista_completa(&lista);
			printf("Lista Excluida com sucesso!!\n");
			printf("\n");
		}
		else if(op == 6){
			int n;
			printf("*Digite a quantidade de elementos que deseja:\n");
			scanf("%d", &n);
			lista = lst_cria(n);
			printf("\n");
		}
		else if(op == 7){
			char s1[10];
			printf("*Informe o departamento:\n");
			scanf("%s", s1);
			//Chamada da função lstfunc_folha_pagto para imprimir;
			lstfunc_folha_pagto(lista, s1);
      
			printf("\n");
		} 
		menu();
		scanf("%d", &op);
	}
}