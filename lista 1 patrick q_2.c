#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

int main()
{
	setlocale(LC_ALL,"");
	
	FILE *arch; //Viariavel do tipo arquivo
	int i = 0, maior, menor, vet[11]; //Variavel contadora e variaveis utilizar para armazenar dados requisitados na quest�o
	float media = 0; //variavel que armazenar� a m�dia dos valores do arquivo
	
	//abertura do arquivo
	arch = fopen("C://Users//PC//Documents//arquivos//entrada_q2.txt", "r");
	
	//Pegando valores inteiros presentes no arquivo e armazenando em um vetor do tipo inteiro
	for (i = 0; i<10;i++){	
		fscanf(arch,"%i",&vet[i]);
	}
	
	//Fechamento de arquivo
	fclose(arch);
	
	//Atribui��o de valor inicial as variaveis que v�o armazenar o maior e menor valor presentes no arquivo
	maior = vet[0];
	menor = vet[0];
	
	//La�o que verifica o maior e menor numero entre os presentes no arquivo e que realiza a soma dos numeros para realizar o calculo da m�dia
	for (i=0; i<10; i++){	
		media = media+vet[i];
		
		if(vet[i] >= maior){
			maior = vet[i];
		}
		
		if(vet[i] <= menor){
			menor = vet[i];
		}
			
	}
	
	//Realizando calculo da m�dia dos valores
	media = media/10;
	
	//Exibindo resultados
	printf("\nM�dia dos valores: %.1f", media);
	printf("\nMaior valor � %i e o menor valor � %i", maior, menor);
	printf("\n");
	return 0;
}
