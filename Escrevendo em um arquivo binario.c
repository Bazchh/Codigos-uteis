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

//Função void que mostra um menu usado para o cadastro dos estudantes
void menu (){
	
	printf ("Escolha uma opção\n");
	printf("1 - cadastrar novo estudante\n");
	printf("2 - sair\n");
	
}


int main () {

	setlocale(LC_ALL,"");
	
	FILE *arch = fopen("estudantes.b","wb"); //Realizando abertura do arquivo binario para execução do programa
	menu();//Chamada da função do menu
	int op;//Variavel que será usada para definir a opção selecionada pelo usuario no menu
	scanf("%i", &op);
	
	//Laço de repetição que mostrará o menu e armazenará os dados inseridos pelo usuario de acordo com suas necessidades
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
