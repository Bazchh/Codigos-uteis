#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO. ESSE NUMERO SERÁ A QUANTIDADE DE ESTUDANTES QUE SERÃO LIDOS
EM SEGUIDA. CADA ESTUDANTE POSSUI UMA MATRICULA, UM NOME E TRÊS NOTAS, UMA PARA CADA UNIDADE. AO FINAL
DEVE-SE APRESENTAR DUAS OPÇÕES PARA O USUARI (1 - PESQUISAR. 2 - SAIR). AO SELECIONAR A OPÇÃO PESQUISAR
O USUARIO DEVE INFORMAR A MATRICULA DO ESTUDANTE E IMPRIMIR A MÉDIA DO ESTUDANTE COM A MATRICULA INFORMADA*/


//Estrutura com os dados de um estudante
typedef struct{
	
	char nome[100];
	int mat;
	float n1;
	float n2;	
	float n3;
}Estudante;

//Função usada para ler os dados dos estudantes inseridos pelo usuario
void ler(Estudante *e){
	
	printf("\nInsira os dados do estudante: ");
	scanf("%i %s %f %f %f", &e->mat, e->nome, &e->n1, &e->n2, &e->n3);
	
}

//Função usada para o menu de opções
void menu(){
	
	printf("\nEscolha uma opção\n");
	printf("\n1 - pesquisar\n");
	printf("\n2 - sair\n");
	
}


//Função da pesquisa linear que retorna um inteiro e recebe dois inteiros e uma variavel da estrutura Estudante
int pesquisar (int mat, int n, Estudante v[]){
	
	int i;
	
	//Laço for que verifica o indice de cada estudante e se corresponde a matricula inserida na pesquisa pelo usuario
	for(i=0;i<n; i++){
		
		//Caso a matricula aluno do indice que está em determinada posição é igual a matricula buscada, então a função
		//retornará o indice i a qual está o estudante 
		if(v[i].mat == mat){
		
		return i;
		}
	}
	
	//Caso a matricula pesquisada não esteja presente nos dados é retornado -1, o que corresponde a inexistencia da matricula buscada
	return -1;
}

int main(){
	setlocale(LC_ALL,"");
	int n;
	
	printf("\nInforme um valor para n: ");
	scanf("%i", &n); //Recebendo o numero de estudantes
	
	Estudante v[n]; //Criando vetor da struct dos dados dos estudantes
	int i;//Variavel contadora
	
	//Lê os dados inseridos pelo usuario que são dos estudantes
	for(i=0; i<n;i++){
		
		ler(&v[i]);
		
	}
	
	//Variavel de opções
	int op;
	
	//chamada do menu de opções
	menu();
	
	//Leitura do indice de opção
	scanf("%i", &op);
	
	//Laço que repete o menu e a pesquisa de acordo com o que o usuario desejar
	while(op!=2){
		
		//Caso o indice de op seja 1, será realizado uma pesquisa com os dados da matricula que o usuario inserir
		if(op==1){
			int mat; //Criando variavel do tipo inteira que será usada para ler e comprar matricular dos indices em que estão os alunos
			printf("\nInforme a matricula: ");
			scanf("%i", &mat); //Leitura da matricula do usuario
			
			//Variavel que armazenará o valor retornado pela função PESQUISAR
			int index = pesquisar (mat,n,v);
			
			//caso INDEX seja diferente de -1, serão impressos a média ponderada do aluno que corresponde a matricula inserida pelo
			//usuario e o seu nome
			if(index != -1){
				
				float media = (v[index].n1*2 + v[index].n2*3 + v[index].n3*4)/9; //Média ponderada!
				printf("\n%s: %f\n", v[index].nome, media);
				
			}
			
			
		}
		
		menu();
		scanf("%i", &op);
		
	}
	
	printf("\nPrograma finalizado!");	
	
	printf("\n\n");
	
}


