#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM ARQUIVO QUE LEIA UM NUMERO INTEIRO N DE UM ARQUIVO, REPRESENTANDO A QUANTIDADE DE ESTUDANTES
A SEREM LIDOS. EM SEGUIDA, DEVEM SER LIDOS OS DADOS DE N ESTUDANTES DE UM ARQUIVO. CADA ESTUDANTE POSSUI NOME, N1, N2, N3.
IMPRIMA NA TELA O NOME E A MAIOR NOTA DE CADA ESTUDANTE NAS UNIDADES*/


//Estrutura que armazena os dados dos estudantes 
typedef struct {
	
	char nome [100];
	float n1;
	float n2;
	float n3;
	
}Estudante;

int main (){
	
	setlocale(LC_ALL,"");
	
	//Realizando abertura e criação do arquivo 
	FILE *arch = fopen ("estudantes2.b", "wb");
	
	int n; //Variavel que armazena a quantidade de estudantes
	
	printf("\nInforme a quantidade de estudante: ");
	scanf ("%i", &n); //Armazenando a quantidade de alunos inseridos pelo usuario
	Estudante vet[n]; //Vetor do tipo da estrutura criada para armzenar varios dados dos alunos
	
	int i; //Variavel contadora
	
	//Laço de repetição criado para ler e armazenar dados no vetor da estrutura estudantes que são inseridos pelo usuario
	for (i=0; i<n; i++){
		
		printf("Informe os dados do estudante: ");
		scanf (" %s %f %f %f", vet[i].nome, &vet[i].n1, &vet[i].n2, &vet[i].n3);
		
	}
	
	//Escrevendo dados inseridos pelo usuario no arquivo
	fwrite (vet, sizeof(Estudante),1,arch);
	
	//Laço de repetição usado para verificar qual a maior nota de cada aluno cadastrado pelo usuario
	for (i=0; i<n; i++){
		
		if (vet[i].n1 >= vet[i].n2 && vet[i].n1 >= vet[i].n3){
			
			printf("\n%s: %.1f", vet[i].nome, vet[i].n1);
			
		} else if (vet[i].n2 >= vet[i].n1 && vet[i].n2 >= vet[i].n3){
		
			printf("\n%s: %.1f", vet[i].nome, vet[i].n2);
			
			}
				else {
		
			printf("\n%s: %.1f", vet[i].nome, vet[i].n3);
			
			}	
		}
		
	printf("\n\n");
	
	//Fechamento de arquivo
	fclose (arch);
	system("pause");
	return 0;
}
