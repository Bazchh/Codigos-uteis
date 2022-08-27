#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVENDO PARA UM ARQUIVO BINARIO*/


//Estrutura que armazena dados de estudantes
typedef struct {
	
	char nome[100];
	float n1;
	float n2;
	float n3;
}Estudante;

//Fun��o void que mostra um menu usado para o cadastro dos estudantes
void menu (){
	
	printf ("Escolha uma op��o\n");
	printf("1 - cadastrar novo estudante\n");
	printf("2 - sair\n");
	
}


int main () {

	setlocale(LC_ALL,"");
	
	FILE *arch = fopen("estudantes.b","wb"); //Realizando abertura do arquivo binario para execu��o do programa
	menu();//Chamada da fun��o do menu
	int op;//Variavel que ser� usada para definir a op��o selecionada pelo usuario no menu
	scanf("%i", &op);
	
	//La�o de repeti��o que mostrar� o menu e armazenar� os dados inseridos pelo usuario de acordo com suas necessidades
	while(op!=2){
		
		if(op==1){
			Estudante e;
			printf("Informe os dados do estudante\n");
			scanf(" %s %f %f %f", e.nome, &e.n1, &e.n2, &e.n3);//Lendo dados dos estudantes inseridos pelo usuario
			fwrite(&e,sizeof(Estudante),1,arch);//Escrevendo os dados inseridos pelo usuario no arquivo binario
			
		}
		
		menu();
		scanf("%i",&op);
	}
	
	printf("\nPrograma finalizado\n");
	
	fclose(arch);//Fechamento de arquivo
	
	
	system("pause");
	return 0;
}
