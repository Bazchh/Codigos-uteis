#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO. ESSE NUMERO SER� A QUANTIDADE DE ESTUDANTES QUE SER�O LIDOS
EM SEGUIDA. CADA ESTUDANTE POSSUI UMA MATRICULA, UM NOME E TR�S NOTAS, UMA PARA CADA UNIDADE. AO FINAL
DEVE-SE APRESENTAR DUAS OP��ES PARA O USUARI (1 - PESQUISAR. 2 - SAIR). AO SELECIONAR A OP��O PESQUISAR
O USUARIO DEVE INFORMAR A MATRICULA DO ESTUDANTE E IMPRIMIR A M�DIA DO ESTUDANTE COM A MATRICULA INFORMADA*/


//Estrutura com os dados de um estudante
typedef struct{
	
	char nome[100];
	int mat;
	float n1;
	float n2;	
	float n3;
}Estudante;

//Fun��o usada para ler os dados dos estudantes inseridos pelo usuario
void ler(Estudante *e){
	
	printf("\nInsira os dados do estudante: ");
	scanf("%i %s %f %f %f", &e->mat, e->nome, &e->n1, &e->n2, &e->n3);
	
}

//Fun��o usada para o menu de op��es
void menu(){
	
	printf("\nEscolha uma op��o\n");
	printf("\n1 - pesquisar\n");
	printf("\n2 - sair\n");
	
}


//Fun��o da pesquisa linear que retorna um inteiro e recebe dois inteiros e uma variavel da estrutura Estudante
int pesquisar (int mat, int n, Estudante v[]){
	
	int i;
	
	//La�o for que verifica o indice de cada estudante e se corresponde a matricula inserida na pesquisa pelo usuario
	for(i=0;i<n; i++){
		
		//Caso a matricula aluno do indice que est� em determinada posi��o � igual a matricula buscada, ent�o a fun��o
		//retornar� o indice i a qual est� o estudante 
		if(v[i].mat == mat){
		
		return i;
		}
	}
	
	//Caso a matricula pesquisada n�o esteja presente nos dados � retornado -1, o que corresponde a inexistencia da matricula buscada
	return -1;
}

int main(){
	setlocale(LC_ALL,"");
	int n;
	
	printf("\nInforme um valor para n: ");
	scanf("%i", &n); //Recebendo o numero de estudantes
	
	Estudante v[n]; //Criando vetor da struct dos dados dos estudantes
	int i;//Variavel contadora
	
	//L� os dados inseridos pelo usuario que s�o dos estudantes
	for(i=0; i<n;i++){
		
		ler(&v[i]);
		
	}
	
	//Variavel de op��es
	int op;
	
	//chamada do menu de op��es
	menu();
	
	//Leitura do indice de op��o
	scanf("%i", &op);
	
	//La�o que repete o menu e a pesquisa de acordo com o que o usuario desejar
	while(op!=2){
		
		//Caso o indice de op seja 1, ser� realizado uma pesquisa com os dados da matricula que o usuario inserir
		if(op==1){
			int mat; //Criando variavel do tipo inteira que ser� usada para ler e comprar matricular dos indices em que est�o os alunos
			printf("\nInforme a matricula: ");
			scanf("%i", &mat); //Leitura da matricula do usuario
			
			//Variavel que armazenar� o valor retornado pela fun��o PESQUISAR
			int index = pesquisar (mat,n,v);
			
			//caso INDEX seja diferente de -1, ser�o impressos a m�dia ponderada do aluno que corresponde a matricula inserida pelo
			//usuario e o seu nome
			if(index != -1){
				
				float media = (v[index].n1*2 + v[index].n2*3 + v[index].n3*4)/9; //M�dia ponderada!
				printf("\n%s: %f\n", v[index].nome, media);
				
			}
			
			
		}
		
		menu();
		scanf("%i", &op);
		
	}
	
	printf("\nPrograma finalizado!");	
	
	printf("\n\n");
	
}


