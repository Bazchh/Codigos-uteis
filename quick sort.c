#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA NUMERO. ESSE NUMERO SER� A QUANTIDADE DE VALORES LIDOS EM SEGUIDA. AO FINAL, DEVE-SE APRESENTAR OS VALORES ORDENADOS
DO MENOR PARA O MAIOR*/

int part (int n, int f, int v[]);
void quicksort (int i, int f, int v[]);

int main(){
	setlocale(LC_ALL,"");
	int n;
	printf("\nInforme uma valor para n: ");
	scanf("%i", &n);
	int i;
	int v[n];
	for(i = 0; i < n; i++){
		printf("\nInsira o %i elemento: ", i+1);
		scanf("%i", &v[i]);
	}
	
	quicksort(0, n - 1, v);
	
	for(i = 0; i < n; i++){
		printf(" %i ", v[i]);
	}

	printf("\n\n");
	return 0;
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
