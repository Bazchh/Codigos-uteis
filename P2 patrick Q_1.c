#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/*
Marcos Mikael Lima Vidal
Turma: 01
Matricula: 2021010988
*/


//Struct que armazena os dados necessarios para execu��o do programa
typedef struct pessoa{
	char nome[100];
	int mat;
	float nota;
}Pessoa;

//Escopo das fun��es utilizadas
void ImprimePessoas(int N, Pessoa* Vet);
Pessoa* AlocaPessoas(int N);
void ordenacampo(int N, Pessoa* Vet, char* campo);
void menu();

int main(){
	
	setlocale(LC_ALL,"");
	int n;//Variavel que armazena e define a quantidade de pessoas que ser�o cadastradas
	int i;//Variavel contadora
	printf("\nInforme a quantidade de pessoas a serem cadastradas: ");
	scanf("%i", &n);//Lendo a quantidade de pessoas que ser�o cadastradas
	//Cria��o de ponteiro do tipo da struct Pessoa. Chamada da fun��o que � usada para alocar um vetor de Pessoas
	//Atribui��o do valor que � retornado da fun��o que aloca um vetor de Pessoas para o ponteiro da struct do tipo Pessoa
	Pessoa *p = AlocaPessoas(n); 
	
	printf("\nAntes da ordena��o selecionada");
	ImprimePessoas(n,p); //Chamada da fun��o usada para imprimir os dados das pessoas e impress�o antes da ordena��o selecionada pelo usuario
	
	
	char *op = (char*)malloc(n*sizeof(char)); //Criando e alocando uma variavel do tipo char para leitura da op��o inserida pelo usuario
	menu();//Chamada da fun��o que � usada para mostrar o menu de ordena��o para o usuario
	scanf("%s", op); //Lendo do usuario como ele deseja ordenar os dados
	system("cls"); //Limpa tela
	ordenacampo(n,p,op); //Chamada da fun��o que ordena os dados de acordo com o campo selecionado pelo usuario
	printf("\n\nLista ordenada por %s\n",op);
	
	ImprimePessoas(n,p);//Chamada da fun��o usada para imprimir os dados das pessoas novamente, mostrando o resultado ap�s ordena��o do campo selecionado
	
	free(op); //Liberando espa�o alocado dinamicamente
	free(p); //Liberando espa�o alocado dinamicamente
	printf("\nPrograma finalizado!\n");
	system("pause");
	printf("\n\n");
	return 0;
}

//Fun��o que aloca um vetor de pessoas que retorna um vetor de pessoa e recebe a quantidade N de pessoas como parametro
Pessoa* AlocaPessoas(int N){
	int i;//Variavel contadora
	Pessoa *p = (Pessoa*)malloc(N*sizeof(Pessoa)); //Cria��o de um ponteiro de pessoas e aloca��o de um vetor de pessoas
	//La�o de repeti��o que pede ao usuario os dados de cada pessoa para realizar o cadastro
	for( i = 0; i<N; i++){
		printf("\nInsira o nome, a matricula e a nota da %i pessoa: ", i+1);
		scanf("%s %i %f", p[i].nome, &p[i].mat, &p[i].nota);	
	}
	
	return p; //Retorna os dados inseridos pelo usuario
}

//Fun��o que mostra o menu de ordena��o para sele��o do campo para o usuario
void menu(){
	printf("\n==========Escolha um campo para ordenar============");
	printf("\n 'Matricula' - Ordenar por matricula");
	printf("\n 'Nome' - Ordenar por nome");
	printf("\n 'Nota' - Ordenar por nota");
	printf("\n========================================\n");
}
//Fun��o que n�o retorna nada e recebe como parametro uma quantidade N de pessoas a serem cadastradas e um vetor de pessoas como parametro
void ImprimePessoas(int N, Pessoa* Vet){
	
	int i;//Variavel contadora
	
	//La�o de repeti��o que imprime os dados das pessoas que foram cadastradas pelo usuario
	for(i = 0; i < N; i++){
		printf("\nNome: %s",Vet[i].nome);
		printf("\nMatricula: %i",Vet[i].mat);
		printf("\nNota: %.1f\n",Vet[i].nota);
	}
	
}

//Fun��o que n�o retorna nada e recebe uma quantidade N de pessoas, um vetor de Pessoas e um campo a ordenar dentre os dados, todas passadas por parametro
void ordenacampo(int N, Pessoa* Vet, char* campo){
		
		int i,j; //Variaveis contadoras
		int menor;//Variavel que auxilia na troca e ordena��o de valores inteiros e flutuantes
		int r;//Variavel utilizada para ordenar strings, quando o usuario deseja ordenar por nomes
		
		//Primeiro caso, quando o usuario deseja ordenar os dados atraves do campo MATRICULA
		if(strcmp("matricula",campo)==0)//estrutura de decis�o e fun��o que compara strings, usada para definir qual o campo selecionado pelo usuario para realizar a ordena��o
		{ 
		//La�o de repeti��o usado para ordenar os dados de acordo com o campo selecionado
		for(i = 0; i < N; i++){
		menor = i; //Atribui��o do indice da variavel contadora i para a variavel que auxilia na troca e ordena��o de valores inteiros e flutuantes
		//La�o de repeti��o secundario, dentro do primeiro la�o de repeti��o que verifica a cada rodada se o valor da posi��o a frente do vetor � 
		//menor que o anterior para posteriormente realizar a troca entre os mesmos e assim sucessivamente, at� que acabe o processo de ordena��o
				for(j = i + 1; j < N; j++){
			if(Vet[j].mat<Vet[menor].mat)//Caso o valor do vetor na posi��o j seja menor que o valor do vetor na posi��o da variavel auxiliar, ocorre uma atribui��o 
			{
				menor = j;//Ocorrencia da atribui��o, onde a variavel auxiliar recebe o valor de j caso este seja menor que o valor da variavel auxiliar
				}
			}
		}
		//Parte onde realmente ocorre a ordena��o e troca de posi��es no indice do vetor dos valores e dados inseridos pelo usuario
		Pessoa temp = Vet[i]; //Cria��o e atribui��o de variavel temporaria usada para realiar a troca das posi��es dos valores inseridos
		Vet[i] = Vet[menor]; //Atribuindo os dados as posi��es corretas e ordenadas ao vetor que ser� impresso 
		Vet[menor] = temp; //Finalizando a ordena��o, atribuindo o valor que antes estava na posi��o 0 do vetor, por exemplo, e trocando pelo primeiro valor que foi 
		//encontrado como sendo o menor valor
	} 
	
	//Esta estrutura de decis�o realiza o mesmo processo da anterior, por�m, com numeros flutuantes em caso do usuario escolher a ordena��o por NOTA
	else if(strcmp("nota",campo)==0){
		for(i = 0; i < N; i++){
		menor = i;
		for(j = i + 1; j < N; j++){
			if(Vet[j].nota<Vet[menor].nota){
				menor = j;
			}
		}
		
		Pessoa temp = Vet[i];
		Vet[i] = Vet[menor];
		Vet[menor] = temp;
		}
		//Esta estrutura realiaza a ordena��o por strings, caso o usuario selecione o campo NOME
	} else if (strcmp("nome",campo)==0){
	
		char temp[60]; //Variavel temporaria, por�m, criada como variavel do tipo CHAR
		//La�o de repeti��o usado para ordenar o vetor de acordo com o campo selecionado, neste caso, NOMES
		for(i = 0; i<N; i++){
			for(j = i+1; j < N; j++){
				r = strcmp(Vet[i].nome,Vet[j].nome);//Atribuindo o valor da fun��o strcmp a variavel que auxilia na troca das strings
				//a fun��o strcmp retorna 3 valores, 1, 0 e -1, mas neste caso n�o estamos comparando se as strings s�o maiores em quest�o 
				//de quantidade de caracteres, mas sim, em rela��o ao codigo ascii
				if(r > 0) //Estrutura de decis�o que realiza a ordena��o caso a compara��o feita anteriormente retorne valores maiores que 0,
				//sinalizando que a primeira string � menor que a secunda em rela��o aos valores dos caracteres na tabela ascii
				{
					strcpy(temp,Vet[i].nome);
					strcpy(Vet[i].nome,Vet[j].nome);
					strcpy(Vet[j].nome,temp);
				}
			}
		}
	}
}
/*EXEMPLO DE ENTRADA E SA�DA

ENTRADA 

Informe a quantidade de pessoas a serem cadastradas: 5

Insira o nome, a matricula e a nota da 1 pessoa: mikael 43 8,9

Insira o nome, a matricula e a nota da 2 pessoa: ana 45 8,4

Insira o nome, a matricula e a nota da 3 pessoa: joao 23 7,6

Insira o nome, a matricula e a nota da 4 pessoa: zequinha 21 7,2

Insira o nome, a matricula e a nota da 5 pessoa: beatriz 41 9,8

Antes da ordena��o selecionada
Nome: mikael
Matricula: 43
Nota: 8,9

Nome: ana
Matricula: 45
Nota: 8,4

Nome: joao
Matricula: 23
Nota: 7,6

Nome: zequinha
Matricula: 21
Nota: 7,2

Nome: beatriz
Matricula: 41
Nota: 9,8

nota

SA�DA 

Lista ordenada por nota

Nome: zequinha
Matricula: 21
Nota: 7,2

Nome: joao
Matricula: 23
Nota: 7,6

Nome: ana
Matricula: 45
Nota: 8,4

Nome: mikael
Matricula: 43
Nota: 8,9

Nome: beatriz
Matricula: 41
Nota: 9,8

*/
