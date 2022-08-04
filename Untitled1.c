#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Escopo de funções
int algoritDemorado(int n);

int main (){
	clock_t t1; //Criando uma variavel que armazena o tempo do relogio
	int n; //Variavel do tipo int
	scanf("%i", &n); //Leitura de variavel do tipo int
	t1 = clock (); //Atribuindo tempo atual do relogio a variavel de tempo criada anteriormente
	algoritDemorado(n); //Chamada de uma função
	t1 = clock () - t1; //Atribuindo novo valor de tempo a variavel de tempo criada anteriormente, neste caso, subtraimos o tempo atual do tempo antigo que estava armazenado na variavel de tempo "t1"
	
	printf(" %f \n", (((float)t1)/10)/CLOCKS_PER_SEC); //Mostra o tempo em segundos que levou parar executar o algoritmo
	
	return 0;
}
//Função usada para teste de execução e complexidade
int algoritDemorado(int n){
	int soma = 0;
	
	int i, j, k, l; 
	//Soma numero de cada variavel de 0 até n
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			for (k = 0; k < n; k++){
				for (l = 0; l < n;  l++){
						soma = i + j + k + l;
				}
			}
		}
	}
	return soma; //Retorna a soma de todos os valores de 0 até n
}
