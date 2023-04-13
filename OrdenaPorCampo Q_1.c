#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/*
Marcos Mikael Lima Vidal
Turma: 01
Matricula: 2021010988
*/


//Struct que armazena os dados necessarios para execução do programa
typedef struct pessoa{
	char nome[100];
	int mat;
	float nota;
}Pessoa;

//Escopo das funções utilizadas
void ImprimePessoas(int N, Pessoa* Vet);
Pessoa* AlocaPessoas(int N);
void ordenacampo(int N, Pessoa* Vet, char* campo);
void menu();

int main(){
	
	setlocale(LC_ALL,"");
	int n;//Variavel que armazena e define a quantidade de pessoas que serão cadastradas
	int i;//Variavel contadora
	printf("\nInforme a quantidade de pessoas a serem cadastradas: ");
	scanf("%i", &n);//Lendo a quantidade de pessoas que serão cadastradas
	//Criação de ponteiro do tipo da struct Pessoa. Chamada da função que é usada para alocar um vetor de Pessoas
	//Atribuição do valor que é retornado da função que aloca um vetor de Pessoas para o ponteiro da struct do tipo Pessoa
	Pessoa *p = AlocaPessoas(n); 
	
	printf("\nAntes da ordenação selecionada");
	ImprimePessoas(n,p); //Chamada da função usada para imprimir os dados das pessoas e impressão antes da ordenação selecionada pelo usuario
	
	
	char *op = (char*)malloc(n*sizeof(char)); //Criando e alocando uma variavel do tipo char para leitura da opção inserida pelo usuario
	menu();//Chamada da função que é usada para mostrar o menu de ordenação para o usuario
	scanf("%s", op); //Lendo do usuario como ele deseja ordenar os dados
	system("cls"); //Limpa tela
	ordenacampo(n,p,op); //Chamada da função que ordena os dados de acordo com o campo selecionado pelo usuario
	printf("\n\nLista ordenada por %s\n",op);
	
	ImprimePessoas(n,p);//Chamada da função usada para imprimir os dados das pessoas novamente, mostrando o resultado após ordenação do campo selecionado
	
	free(op); //Liberando espaço alocado dinamicamente
	free(p); //Liberando espaço alocado dinamicamente
	printf("\nPrograma finalizado!\n");
	system("pause");
	printf("\n\n");
	return 0;
}

//Função que aloca um vetor de pessoas que retorna um vetor de pessoa e recebe a quantidade N de pessoas como parametro
Pessoa* AlocaPessoas(int N){
	int i;//Variavel contadora
	Pessoa *p = (Pessoa*)malloc(N*sizeof(Pessoa)); //Criação de um ponteiro de pessoas e alocação de um vetor de pessoas
	//Laço de repetição que pede ao usuario os dados de cada pessoa para realizar o cadastro
	for( i = 0; i<N; i++){
		printf("\nInsira o nome, a matricula e a nota da %i pessoa: ", i+1);
		scanf("%s %i %f", p[i].nome, &p[i].mat, &p[i].nota);	
	}
	
	return p; //Retorna os dados inseridos pelo usuario
}

//Função que mostra o menu de ordenação para seleção do campo para o usuario
void menu(){
	printf("\n==========Escolha um campo para ordenar============");
	printf("\n 'Matricula' - Ordenar por matricula");
	printf("\n 'Nome' - Ordenar por nome");
	printf("\n 'Nota' - Ordenar por nota");
	printf("\n========================================\n");
}
//Função que não retorna nada e recebe como parametro uma quantidade N de pessoas a serem cadastradas e um vetor de pessoas como parametro
void ImprimePessoas(int N, Pessoa* Vet){
	
	int i;//Variavel contadora
	
	//Laço de repetição que imprime os dados das pessoas que foram cadastradas pelo usuario
	for(i = 0; i < N; i++){
		printf("\nNome: %s",Vet[i].nome);
		printf("\nMatricula: %i",Vet[i].mat);
		printf("\nNota: %.1f\n",Vet[i].nota);
	}
	
}

//Função que não retorna nada e recebe uma quantidade N de pessoas, um vetor de Pessoas e um campo a ordenar dentre os dados, todas passadas por parametro
void ordenacampo(int N, Pessoa* Vet, char* campo){
		
		int i,j; //Variaveis contadoras
		int menor;//Variavel que auxilia na troca e ordenação de valores inteiros e flutuantes
		int r;//Variavel utilizada para ordenar strings, quando o usuario deseja ordenar por nomes
		
		//Primeiro caso, quando o usuario deseja ordenar os dados atraves do campo MATRICULA
		if(strcmp("matricula",campo)==0)//estrutura de decisão e função que compara strings, usada para definir qual o campo selecionado pelo usuario para realizar a ordenação
		{ 
		//Laço de repetição usado para ordenar os dados de acordo com o campo selecionado
		for(i = 0; i < N; i++){
		menor = i; //Atribuição do indice da variavel contadora i para a variavel que auxilia na troca e ordenação de valores inteiros e flutuantes
		//Laço de repetição secundario, dentro do primeiro laço de repetição que verifica a cada rodada se o valor da posição a frente do vetor é 
		//menor que o anterior para posteriormente realizar a troca entre os mesmos e assim sucessivamente, até que acabe o processo de ordenação
				for(j = i + 1; j < N; j++){
			if(Vet[j].mat<Vet[menor].mat)//Caso o valor do vetor na posição j seja menor que o valor do vetor na posição da variavel auxiliar, ocorre uma atribuição 
			{
				menor = j;//Ocorrencia da atribuição, onde a variavel auxiliar recebe o valor de j caso este seja menor que o valor da variavel auxiliar
				}
			}
		}
		//Parte onde realmente ocorre a ordenação e troca de posições no indice do vetor dos valores e dados inseridos pelo usuario
		Pessoa temp = Vet[i]; //Criação e atribuição de variavel temporaria usada para realiar a troca das posições dos valores inseridos
		Vet[i] = Vet[menor]; //Atribuindo os dados as posições corretas e ordenadas ao vetor que será impresso 
		Vet[menor] = temp; //Finalizando a ordenação, atribuindo o valor que antes estava na posição 0 do vetor, por exemplo, e trocando pelo primeiro valor que foi 
		//encontrado como sendo o menor valor
	} 
	
	//Esta estrutura de decisão realiza o mesmo processo da anterior, porém, com numeros flutuantes em caso do usuario escolher a ordenação por NOTA
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
		//Esta estrutura realiaza a ordenação por strings, caso o usuario selecione o campo NOME
	} else if (strcmp("nome",campo)==0){
	
		char temp[60]; //Variavel temporaria, porém, criada como variavel do tipo CHAR
		//Laço de repetição usado para ordenar o vetor de acordo com o campo selecionado, neste caso, NOMES
		for(i = 0; i<N; i++){
			for(j = i+1; j < N; j++){
				r = strcmp(Vet[i].nome,Vet[j].nome);//Atribuindo o valor da função strcmp a variavel que auxilia na troca das strings
				//a função strcmp retorna 3 valores, 1, 0 e -1, mas neste caso não estamos comparando se as strings são maiores em questão 
				//de quantidade de caracteres, mas sim, em relação ao codigo ascii
				if(r > 0) //Estrutura de decisão que realiza a ordenação caso a comparação feita anteriormente retorne valores maiores que 0,
				//sinalizando que a primeira string é menor que a secunda em relação aos valores dos caracteres na tabela ascii
				{
					strcpy(temp,Vet[i].nome);
					strcpy(Vet[i].nome,Vet[j].nome);
					strcpy(Vet[j].nome,temp);
				}
			}
		}
	}
}
/*EXEMPLO DE ENTRADA E SAÍDA

ENTRADA 

Informe a quantidade de pessoas a serem cadastradas: 5

Insira o nome, a matricula e a nota da 1 pessoa: mikael 43 8,9

Insira o nome, a matricula e a nota da 2 pessoa: ana 45 8,4

Insira o nome, a matricula e a nota da 3 pessoa: joao 23 7,6

Insira o nome, a matricula e a nota da 4 pessoa: zequinha 21 7,2

Insira o nome, a matricula e a nota da 5 pessoa: beatriz 41 9,8

Antes da ordenação selecionada
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

SAÍDA 

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
