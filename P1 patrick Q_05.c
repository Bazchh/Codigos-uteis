#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

/*Programa para verificar o tamanho de uma struct em bytes*/

/*Exemplo de entrada e saída

A entrada do programa é a quantidade de variaveis de cada tipo

a saída é a multiplicação do tamanho dessas variaveis, mas caso exista mais de uma variavel do mesmo tipo, após a multiplicação
da primeira variavel daquele tipo pelas outras variaveis de tipos diferentes, será executado apenas uma soma com o valor da varaivel a ser somada

ex: a struct contém int, char e float. Será impresso 48 bytes, mas caso seja inserido mais uma variavel do tipo int, será somado +4

*/

//Struct com matricula, nome e provas do aluno
typedef struct data{
	
	int matricula;
	char nome[30];
	float Provas[3];
	
}Data;



int main (){
	setlocale(LC_ALL,"");
	Data Aluno; //Variavel do tipo da struct que contém os dados dos aluno
	
	//Atribuição de dados para cada variavel da struct
	Aluno.matricula = 2021010988;
	Aluno.nome [30] = "Marcos Mikael Lima Vidal";
	Aluno.Provas[0] = 7,5;
	Aluno.Provas[1] = 6,7;
	Aluno.Provas[2] = 8,8;
	
	//Imprime tamanho da struct
	printf("tamanho da struct em bytes: %i bytes", sizeof(Data));

	printf("\n\n");
	system("pause");
	return 0;
}


