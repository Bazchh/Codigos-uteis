#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

/*Exemplo de entrada e sa�da

Entrada-> "Isto � uma string"

Sa�da->   "157o 3 um4 57r1ng"

*/

//Escopo de fun��o
char leetspeak(char *l);


int main (){
	
	int i = 0; //Variavel contadora
	setlocale(LC_ALL,"");
	char *str; //Ponteiro que ser� alocado para armazenar a string inserida pelo usuario
	
	str = (char*)malloc(50*sizeof(char));//Alocando ponteiro
	
	//Recebendo string do usuario
	printf("\nInsira uma string: ");
	fgets(str,50,stdin);
	
	//Utilizei o la�o while neste codigo por ser melhor para desempenho neste exercicio, pois, se o usuario inserir uma string menor que o 
	//tamanho alocado, ele n�o percorrer� os 50*tamanho_char endere�os, que � o tamanho alocado neste exemplo
	while(str[i]!='\0'){
		
		str[i]=leetspeak(&str[i]); //Atribuindo a sua respectiva posi��o da string os caracteres que devem ser alterados de acordo com a 
								   //escrita leet
		i++;
	}
	
	//Imprimindo resultado em escrita leet
	printf("\nFrase em escrita leet: %s", str);
	
	printf("\n\n");
	system("pause");
	return 0;
}


//Fun��o que altera os caracteres de acordo a escrita leet
char leetspeak(char *l){
	
	char troca, frase; //Variavel 'troca' armazena os caracteres da escrita leet que correspondem aos caracteres a serem alterados
	frase = *l;	//Variavel frase serve como uma variavel temporaria que armazena a string passada por parametro em '*l', para 
				//usar a fun��o switch case
				
	//Fun��o switch case que altera os caracteres da string original para os caracteres correspondem para os caracteres da escrita leet
	//Enquanto o la�o while da fun��o main durar			
	switch(frase){
		
		case 'a':
		case 'A':
			
			troca = '4';
			break;
			
			case 'e':
			case 'E':
				
				troca = '3';
				break;
				
				case 's':
				case 'S':
					
					troca = '5';
				    break;
				    
				    case 't':
				    case 'T': 
				    
				    troca = '7';
				    break;
				    
				    case 'i':
				    case 'I':
				    	
				    	troca = '1';
						break;
						
						default:
						
						troca = frase; 
						break;	

	}
	
	return troca;
}
