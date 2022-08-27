#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

/*ex entrada e saida

entrada-> ** DADOS DO ATLETA N� 1 **

Insira o nome do 1 atleta: mikael

Insira o esporte do 1 atleta: basquete

Insira a idade do 1 atleta: 20

Insira a altura do 1 atleta: 1,74


** DADOS DO ATLETA N� 2 **

Insira o nome do 2 atleta: marcos

Insira o esporte do 2 atleta: futebol

Insira a idade do 2 atleta: 18

Insira a altura do 2 atleta: 1,70


** DADOS DO ATLETA N� 3 **

Insira o nome do 3 atleta: Patrick

Insira o esporte do 3 atleta: nata��o

Insira a idade do 3 atleta: 38

Insira a altura do 3 atleta: 1,76


** DADOS DO ATLETA N� 4 **

Insira o nome do 4 atleta: Jo�o

Insira o esporte do 4 atleta: Roquei

Insira a idade do 4 atleta: 17

Insira a altura do 4 atleta: 1,62


** DADOS DO ATLETA N� 5 **

Insira o nome do 5 atleta: V� Antonio

Insira o esporte do 5 atleta: futsal

Insira a idade do 5 atleta: 67

Insira a altura do 5 atleta: 1,80


saida-> Atleta com a maior idade: V" Antonio

		Atleta com a maior altura: V" Antonio

*/

//Struct que cont�m os dados dos atletas
typedef struct atleta{
	
	char nick[30];
	char sport[30];
	int age;
	float alt;
	
}Atlet;

int main (){
	setlocale(LC_ALL,"");
	
	int i, j; //Variaveis contadoras
	int maiorA; //Variavel que servir� para armazenar a idade do atleta mais velho
	float altH;//Variavel que servir� armazenar a altura do atleta mais alto
	char nick1[30],nick2[30]; //Variaveis que serviram para armazenar o nome do atleta mais velho e o nome do atleta mais alto
	
	Atlet data [5];//Definindo variavel que armazenar� dados dos 5 atletas
	
	//Inserindo dados dos 5 atletas
	for(i=0;i < 5;i++){
		
	printf("\n***** DADOS DO ATLETA N� %i *****\n",i+1);	
			
	printf("\nInsira o nome do %i atleta: ", i+1);
	fgets(data[i].nick,30,stdin);
	printf("\nInsira o esporte do %i atleta: ",i+1);
	fgets(data[i].sport,30,stdin);
	printf("\nInsira a idade do %i atleta: ",i+1);
	scanf("%i", &data[i].age);
	printf("\nInsira a altura do %i atleta: ",i+1);
	scanf("%i",&data[i].alt);	
		printf("\n");
		fflush(stdin);
	}
	
	//Definindo um ponto inicial para as variaveis de idade e altura
	maiorA = data[0].age;

	altH = data[0].alt;
	
	//La�o que verifica qual atleta mais velho e mais alto e armazena seu nome em uma variavel char que ser� impressa como resultado
	for(i=0;i<5;i++){	
		if(data[i].age >= maiorA){	
			maiorA = data[i].age;
			
			strcpy(nick1,data[i].nick);
		}
		
		if(data[i].alt >= altH){	
			altH = data[i].alt;
			strcpy(nick2,data[i].nick);
		}		
	}
	
	//Imprimindo nome do atleta mais velho e do atleta mais alto
	printf("\nAtleta com a maior idade: %s", nick1);
	printf("\nAtleta com a maior altura: %s", nick2);
	
	printf("\n\n");
	system("pause");
	return 0;
}


