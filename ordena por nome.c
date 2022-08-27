#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaPessoa{
    char nome[30];
    char endereco[20];
    int tel; 
    
}Lista;

void ordenanome(int N, Lista Vet[]);

int main (void){
	
	int i, n, nome; 
	
	printf("\nDeseja cadastrar quantas pessoas? " );
    scanf("%i", &n);
    fflush(stdin);
    
    Lista v[5];

    
    
    for(i=0; i<5; i++){
    printf("\nDigite o nome da %i pessoa a ser cadastrada: ", i+1);
    scanf("%s", v[i].nome);
    printf("\nDigite o endereço da %i pessoa a ser cadastrada: ", i+1);
    scanf(" %s", v[i].endereco);
    printf("\nDigite o telefone da %i pessoa a ser cadastrada: ", i+1);
    scanf("%i", &v[i].tel);
    };
	printf("\nLista antes de ser ordenada: ");
    for(i = 0; i<5; i++){
	printf("\nNome: %s", v[i].nome);	
    }
	

	ordenanome(5,v);

    	printf("\nLista depois de ser ordenada: ");

    for(i=0; i< 5; i++){
	printf("\nNome: %s", v[i].nome);
    }		

    for(i=0; i<n; i++){
    printf("\nNome da pessoa %i cadastrada: %s", i+1,v[i].nome);
    printf("\nEndereço da pessoa %i cadastrada: %s", i+1, v[i].endereco);
    printf("\nO telefone da pessoa %i cadastrada: %i", i+1, v[i].tel);
    }
}

void ordenanome(int N, Lista Vet[]){
int i,j, r;	
		char temp[60]; //Variavel temporaria, porém, criada como o variavel do tipo CHAR
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
