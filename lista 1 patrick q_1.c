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
	char c[7]; //variavel do tipo caractere criada para armazenar strings do arquivo
	
	//abertura do arquivo
	arch = fopen("C://Users//PC//Documents//arquivos//entrada_q1.txt", "r");
	
	//Verificando se o arquivo foi aberto corretamente, caso contrario o
	//programa é encerrado
	if (arch == NULL){
		
		printf("\nFalha ao tentar abrir o arquivo!");
		exit(1);
	}
	
	//Mostrando nomes que estão presentes no arquivo
	while(fgets(c,7,arch) != NULL){	
		printf("%s", c);
	
	}
	
	//Fechamento de arquivo
	fclose(arch);
	
	printf("\n");
	return 0;
}
