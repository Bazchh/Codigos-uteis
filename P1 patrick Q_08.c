#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/ 

/*Ex de entrada e saida

entrada-> 1st0 3 um4 57r1ng

saída-> inteiro presente na string: 1034571

*/

int retorna (char*s);

int main (){
	
	setlocale(LC_ALL,"");
	
	char *str; //Ponteiro que será alocado para armazenar a string inserida pelo usuario
	int i = 0, j = 0;//Variavel contadora
	str = (char*)malloc(50*sizeof(char));//Alocando o ponteiro de vetor
	
	//Recebe uma string inserida pelo usuario
	printf("\nInsira uma string: ");
	fgets(str,50,stdin);
	
	//Utilizei o laço while neste codigo por ser melhor para desempenho neste exercicio, assim como no exercicio 7, pois, se o usuario inserir uma string menor que o 
	//tamanho alocado, ele não percorrerá os 50*tamanho_char endereços, que é o tamanho alocado neste exemplo
	while(str[i]!='\0'){
		
		str[i]=retorna(&str[i]); //Atribuindo as posições do vetor somente os inteiros
		i++;
								   	
	}
	
	char *str1; //Declarando um vetor de char que organizará corretamente os valores inteiros
	
	str1 = (char*)malloc(50*sizeof(char));//Alocando o ponteiro de vetor que armazenará somente os inteiros de forma organizada
	
	//Laço para armazenar somente os inteiros na variavel 'str1'
	for(i=0; i<strlen(str) || str[i]=='\0';i++){
		
		//Esta condição pega somente os valores inteiros da string e os armazena dentro da outra string de forma que fiquem juntos
		//em posições consecutivas do vetor
		if(str[i]!=32){
			
			str1[j] = str[i];
			
			j++;
		} 
		
	}
	
	//Imprime SOMENTE os inteiros presentes na strin, porém, como tive pouco tempo 	
	printf("\nInteiro presente na string: %s", str1);
	
	//Libera a memoria
	free(str);
	printf("\n\n");
	system("pause");
	return 0;
}

int retorna(char *r){
	
	char troca, frase; //Variavel para troca de caracteres na string original e variavel temporaria para armazenar string do ponteiro
	//passado por parametro para ser usado no switch case
	int R; //Variavel que armazena os inteiros da frase e os retorna
	
	frase = *r;	//Atribuindo string original a variavel char temporaria
				
			
	switch(frase){
		
		case '0':
			
			troca = '0';
			break;
			
			case '1':
				
				troca = '1';
				break;
				
				case '2':
					
					troca = '2';
				    break;
				    
				    case '3':
				    
				    troca = '3';
				    break;
				    
				    case '4':
				    
						 troca = '4';   	
						break;
						
						case '5':
				    
						 troca = '5';   	
						break;
						
						case '6':
				    
						 troca = '6';   	
						break;
						
						case '7':
				    
						 troca = '7';   	
						break;
						case '8':
				    
						 troca = '8';   	
						break;
						case '9':
				    
						 troca = '9';   	
						break;
						
						default:
						troca = 32;
						break;	

	}
	
	//armazena a inteiro que foi encontrado na string
	R = troca;

	return R;
}
