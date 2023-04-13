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
    setlocale(LC_ALL, "");

    char *frase; //ponteiro que armazenará a frase inserida pelo usuario
	char palavra[50][50], AUX[50][50]; // matriz 'palavra' serve para armazenar cada palavra em uma linha diferente da matriz
									   //matriz 'AUX' serviria para criar uma copia da matriz 'palavra' e usar para comparar quantas
									   //vezes cada palavra se repete
									   	
    int i = 0,k = 0, palavras = 1,j = 0; //variaveis contadoras

	frase = (char*)malloc(sizeof(char)*30); //utilizando alocação dinamica na variavel char '*frase'
    
	printf("\nInsira uma frase: ");
    fgets(frase,100,stdin);
    
    //laço utilizado para armazenar as palavras na matriz 'palavra'. Eu utilizei a função strlen para determinar o tamanho da frase, pois, ela
    //Já identifica o caractere final de cada string (\0) e encerra o laço quando chega até ele, que determina o fim da string
    //Como a variavel 'i' já estava sendo usada para percorrer toda a frase, precisei de mais duas variaveis diferentes para percorrer as linhas e 
    //colunas para armazenar cada palavra e utilizei 'j' e 'k'. Ele percorre toda a frase até que encontre um espaço, quando encontra o espaço
    //É incrementado uma linha e redefinido o numero de colunas para zero
    for (i=0; i<strlen(frase);i++){	 
    	 if(frase[i] != 32){
            palavra[j][k] = frase[i];
            AUX[j][k] = frase[i];
            k++;
        }else
		{ 
			k = 0;
			j++;
		}			
    }
    
    //Este laço determina a quantidade de palavras presentes na frase com base na quantidade de espaços
    //Eu utilizei também a expressão (frase[i+1]==32) para se caso o usuario digitar mais de 1 espaço seguido e não seja contado como uma palavra
    // por exemplo se o usuario inserir: isto é'323232'uma string, ele vai pular a posição onde está o 32 verificar o espaço atual e o proximo
    //OBS: 32 na frase representa o espaço, para que fique claro quantos espaços foram dados :P
      for (i=0; i < strlen(frase); i++){
 
        if(frase[i]!=32 && frase[i+1]==32){
            palavras++;
        }
    }
    
    //libera memoria alocada
    free(frase);
    
    //Utilizando agora a quantidade de palavras que foram armazenadas na variavel 'palavras', criei um laço para percorrer
    //somente até onde haja a linha com as palavras que foram inseridas na matriz 'palavra'
    for(i = 0; i < palavras; i++){

        printf("\n%s", palavra[i]);
    }
	
	   printf("\n\n");
    system("pause");
    return 0;
}

//Infelizmente acabei por deixar o codigo incompleto, mas como o codigo atual temos a seguinte entrada e saída:


/*
Entrada -> Essa questão me deu um trabalhinho

Saída ->  

Essa
questão
me
deu
um
trabalhinho
*/
