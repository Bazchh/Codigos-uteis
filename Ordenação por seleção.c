#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO. ESSE NUMERO SERÁ A QUANTIDADE DE VALORES LIDOS EM SEGUIDA. AO FINAL, DEVE-SE APRESENTAR OS VALORES
ORDENADOS DO MENOR PARA O MAIOR*/

int main (){
	
	setlocale(LC_ALL,"");
	int n;
	printf("\nInforme a quantidade de numeros que serão inseridos: ");
	scanf("%i", &n);
	int v[n];
	int i,j;
	
	for(i=0;i<n;i++){
		printf("\nInsira o valor do %i numero: ", i+1);
		scanf("%i", &v[i]);
	}
	//Ordenação por seleção
	//por exe: 9 8 7 6 5 0 1 2 3 4
	//por exe: 0 8 7 6 5 9 1 2 3 4
	//por exe: 0 1 7 6 5 9 8 2 3 4
	
	for(i=0;i<n;i++){
		int menor = i; //O menor elemento recebe o primeiro elemento de i como referencia inicial
		for( j = i+1;j<n;j++){ 
			if(v[j]<v[menor]){ //Caso o elemento seguinte de i (que é onde j inicia) seja maior que o primeiro elemento que está armazenado em "menor"
							  // será feito uma troca, armazenando o valor de j (que é menor), na variavel "menor"
				menor = j;
			}
		}	
			int temp = v[i]; //Variavel usada para realizar a troca dos valores e ordena-los
			v[i] = v[menor]; //Será armazenada aqui de forma ordenada o menor valor que foi encontrado dentro do vetor através da variavel 'menor'
			v[menor] = temp; //O valor do menor elemento agora será aquele que era o primeiro valor de i antes de iniciarmos a ordenação por seleção
	}
	
	printf("\nLista ordenada\n");
	
	for(i=0;i<n;i++){
		printf(" %i ", v[i]);
	}
	
	printf("\n\n");
	return 0;
}



