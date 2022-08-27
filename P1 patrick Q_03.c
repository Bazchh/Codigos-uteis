#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

/*ex de entrada e saida

entrada-> 12 5 1990 - 16 8 2025

saida-> dias decorridos: 12865 dias

*/

//Struct que contém os dias, meses e ano utilizados na implementação do programa
typedef struct data{
	
	int dia;
	int mes;
	int ano;
	
}Data;

//Escopo da função utilizada
int Diasdecorridos (Data *d1, Data *d2);

int main (){
	setlocale(LC_ALL,"");
	Data d1, d2; //Declaração do tipo criado para implementação das datas
	int R; //Armazena o valor retornado pela função
	
	//Recebendo uma data válida
	printf("\nInsira uma data (dia/mês/ano): ");
	scanf("%i%i%i", &d1.dia,&d1.mes,&d1.ano);
	
	//Verifica se o usuario inseriu uma data válida para dia e mês, não podendo ultrapassar 30 e nem 12, respectivamente
	if(d1.dia > 30 || d1.mes > 12){
		
		printf("\nErro. Quantidade de dias ou meses inválida!");
		exit(1);
		
	}
	
	printf("\nInsira uma segunda data (dia/mês/ano): ");
	scanf("%i%i%i", &d2.dia,&d2.mes,&d2.ano);
	//Verifica se o usuario inseriu uma data válida para dia e mês, não podendo ultrapassar 30 e nem 12, respectivamente
	if(d2.dia > 30 || d2.mes > 12){
		
		printf("\nErro. Quantidade de dias ou meses inválida!");
		exit(1);
		
	}
	
	//Armazena o valor retornado da função que calcula quantos dias se passou durante as datas
	R = Diasdecorridos(&d1,&d2);
	
	//Para evitar que o resultado dos dias decorridos seja negativo ou para quando o usuario inserir as datas de forma invertido,
	// uma data passada subtraida pela futura, por exemplo.
	if(R < 0){
		R = -1*R;
	}
	
	//Imprime a quantidade de dias decorridos entre as duas datas
	printf("\nQuantidade de dias decorridos entre as datas: %i dias", R);
	
	printf("\n\n");
	system("pause");
	return 0;
}

//Função que retorna a quantidade de dias decorridos entre as duas datas, com dois ponteiros passados por referencia do tipo da struct 'Data'
int Diasdecorridos (Data *d1, Data *d2){
	
	//variaveis que armazenaram resultados dos calculos para se chegar na quantidade de dias decorridos
	int Dias1, Dias2, ano,mes, R = 0;
	
	ano = d1->ano*365; // Transforma anos em dias
	mes = d1->mes*30; //Transforma meses em dias
	Dias1 = ano+mes+d1->dia; //A soma dos dias transformados dos meses e anos + dias das datas inseridas
	
	//Redefinição do valor das variaveis usadas para transformas anos e meses em dias para atribuição da quantidade de dias da segunda data
	ano = 0;
	mes = 0;
	
	//Repetindo o primeiro processo, mas para os dias da segunda data
	ano = d2->ano*365;
	mes = d2->mes*30;
	Dias2 = ano+mes+d1->dia;
	
	//Realizando subtração dos dias totais das duas data e armazenando em uma variavel que retornará o resultado
	R = Dias1 - Dias2;
	
	return R;
}
