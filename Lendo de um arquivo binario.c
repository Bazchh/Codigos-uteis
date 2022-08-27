#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//Estrutura que armazena dados dos estudantes 
typedef struct {
	
	char nome[100];
	float n1;
	float n2;
	float n3;
	
}Estudante;

int main (){
	
	setlocale(LC_ALL,"");
	
	FILE *arch = fopen("estudantes.b", "rb"); //Abrindo arquivo para leitura	
	Estudante e;//Variavel do tipo da estrutura criada

	//Laço que lê o arquivo enquanto não encontrar o final do mesmo	
	while (fread(&e,sizeof(Estudante),1,arch)){
		
		float media = (e.n1 + e.n2 + e.n3)/3;//Variavel média que armazena a media das notas de cada estudante para verificar sua situação
		
		//Condições if que dizem a situação final do estudante
		if (media>= 7.0){
			
			printf("%s: aprovado\n", e.nome);
			
		} else if (media < 5.0){
			
			printf("%s: reprovado", e.nome);
		} else {
			
			float precisa = 10 - media; //Variavel que armazena a nota a qual o estudante precisa para que seja aprovado na nota final
			printf("%s: final - %f\n", e.nome, precisa);
			
		}
		
	} 
	
	printf("\nPrograma finalizado\n");
	//Fechamento de arquivo
	fclose(arch);
	
	system("pause");
	return 0;
}
