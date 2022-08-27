#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
Nome: Marcos Mikael Lima Vidal
Turma: 01
Matricula: 2021010988
*/

//Escopo de fun��es
void insertionsort(int n, int v[]);
int part (int n, int f, int v[]);
void quicksort(int i, int f, int v[]);
int *Ler(int n);

int main(){
	
	setlocale(LC_ALL,"");
	clock_t tempos[2]; //Varial que armazena os tempos
	tempos[0] = clock(); //Atribuindo tempo atual as variaveis de tempo
	tempos[1] = clock();
	int n; //Variavel que define o tamanho dos vetores 
	
	//Lendo valores de todos os 10 vetores
	printf("\nInforme um valor para a quantidade de elementos: ");
	scanf("%i", &n);
	printf("\nVetor 1:\n");
	int *v1 = Ler(n);
	printf("\nVetor 2:\n");
	int *v2 = Ler(n);
	printf("\nVetor 3:\n");
	int *v3 = Ler(n);
	printf("\nVetor 4:\n");
	int *v4 = Ler(n);
	printf("\nVetor 5:\n");
	int *v5 = Ler(n);
	printf("\nVetor 6:\n");
	int *v6 = Ler(n);
	printf("\nVetor 7:\n");
	int *v7 = Ler(n);
	printf("\nVetor 8:\n");
	int *v8 = Ler(n);
	printf("\nVetor 9:\n");
	int *v9 = Ler(n);	
	printf("\nVetor 10:\n");
	int *v0 = Ler(n);
	int i;
	
	//Abertura de arquivo para inser��o de tempos de execu��o
	FILE *arch = fopen("./benchmark.tsv","w");
	
	//Chamada e ordena��o por quicksort
	
	//Chamada de fun��o que ordena por quicksort
	printf("\n=======QUICKSORT EXECUTADO=====\n");
	quicksort(0, n - 1, v1);
	quicksort(0, n - 1, v2);
	quicksort(0, n - 1, v3);
	quicksort(0, n - 1, v4);
	quicksort(0, n - 1, v5);
	quicksort(0, n - 1, v6);
	quicksort(0, n - 1, v7);
	quicksort(0, n - 1, v8);
	quicksort(0, n - 1, v9);
	quicksort(0, n - 1, v0);
	
	double T[3]; //Cria��o de variavel para armazenar os tempos de execu��o de cada fun��o
	
	T[0] = (tempos[0] - tempos[1])*1000.0/CLOCKS_PER_SEC; //Atribuindo o tempo decorrido a uma variavel
	
	fprintf(arch,"\nTempo de execu��o do quicksort: %.7f ms.\n", T[0]); //Escrevendo tempo no arquivo .tsv
	printf("\n======INSERTIONSORT EXECUTADO======\n");
	//Chamada de fun��o que ordena por insertionsort
	insertionsort(n,v1);
	insertionsort(n,v2);
	insertionsort(n,v3);
	insertionsort(n,v4);
	insertionsort(n,v5);
	insertionsort(n,v6);
	insertionsort(n,v7);
	insertionsort(n,v8);
	insertionsort(n,v9);
	insertionsort(n,v0);
	
	T[1] = (tempos[0] - tempos[1])*1000.0/CLOCKS_PER_SEC; //Atribuindo o tempo decorrido a uma variavel
	
	fprintf(arch,"\nTempo de execu��o do insertionsort: %.7f ms.\n", T[1]); //Escrevendo tempo no arquivo .tsv
	
	//Liberando todos os espa�os alocados
	free (v1);
	free (v2);
	free (v3);
	free (v4);
	free (v5);
	free (v6);
	free (v7);
	free (v8);
	free (v9);
	free (v0);
	printf("\nPrograma finalizado!\n");
	//fechando arquivo
	fclose(arch);
	system("pause");
	printf("\n\n");
	return 0;
}
//Fun��o usada para ler os valores dos vetores
int *Ler(int n){
	int i;
	int *v = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++){
		printf("\nInsira o valor da posi��o %i do vetor: ", i+1);
		scanf("%i", &v[i]);
	}
	
	return v;
}

void insertionsort(int n, int v[n]){

	int i, j;
	//Ordena��o por inser��o
	//O indice i inicia na posi��o 1 do vetor, ou seja, a segunda posi��o do vetor. J� j inicia no indice i - 1, ou seja, inicialmente na primeira
	//posi��o do nosso vetor
	for(i = 1; i < n; i++){
		int x = v[i]; //Pegamos o valor atual a qual vai ser ordenado do vetor na posi��o i e o guardamos em uma variavel auxiliar
		
		//j sempre estar� na posi��o atr�s do indice i
		for(j = i - 1; j>= 0 && x < v[j]; j--){
			v[j+1] = v[j]; //aqui � onde ocorre uma parte da ordena��o, onde trocamos o valor de j = i - 1 pelo valor de i, caso este seja menor que o valor de j
		}
		v[j+1] = x; //Para que n�o fiquemos com valores iguais em duas posi��es do vetor, atribuimos o valor de i guardado em x a posi��o que 
					//anteriormente foi do menor valor encontrado
	}
}

int part (int n, int f, int v[]){
	
	int piv = v[f]; //atribuindo o valor que est� na posi��o final do vetor a variavel que serve para compara��o de valores
	int j = n - 1; // atribuindo o valor inicial a variavel contadora - 1, por termos de posi��o de vetor
	int i; //variavel contadora
	for(i = n; i < f; i++){
		if (v[i]<= piv){
			j++;
			int temp = v[j]; //Guardando valor que foi encontrado a qual � menor que piv em uma variavel temporaria
			v[j] = v[i]; //Atribuindo ao valor inicial, na posi��o correta o menor valor encontrado comparado ao valor na posi��o final do vetor (piv) 
			v[i] = temp; //Atribuindo o valor que foi trocado de posi��o, o valor que anteriormente foi o menor valor encontrado na posi��o j
		}
	}
	//Aqui realizamos a troca do valor que estava na posi��o final do vetor,
	//a qual ser� inserido na sua posi��o correta, onde todos os elementos a sua direita s�o maiores e a esquerda est�o os menores que ele
	int temp = v[j + 1];  
	v [j+1] = v[f];
	v[f] = temp;
	return j+1; //Retornando a posi��o do piv
}

void quicksort (int i, int f, int v[]){
	//caso o inicio seja menor que o final, realizamos o quick sort
	if (i < f){
		int p = part(i, f, v); //Recebendo valor retornado da fun��o que realiza a ordena��o. A cada rodada ele inicia ordena do inicio para o meio e do meio para o fim
		quicksort(i, p-1, v); //Ordenando os valores do inicio ao meio
		quicksort(p+1, f, v); //Ordenando os valores do meio ao fim
	}
}

