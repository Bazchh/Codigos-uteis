#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Escreva um programa que leia tr�s notas de um estudante e imprima sua m�dia*/


int main(){
	setlocale(LC_ALL,"");
	float n1, n2 ,n3;
	
	printf("Insira as notas: ");
	scanf("%f %f %f", &n1, &n2, &n3);
	
	float media = (n1+n2+n3)/3;
	
	printf("%.1f\n", media);
	
}

/*CONCEITO DE COMPLEXIDADE DE ALGORITMOS REFERENTE AO TEMPO CONSTANTE: 

Quantas vezes cada instru��o � executada? Apenas uma vez, todas elas! Isso quer dizer que o programa � executado em tempo
constante, que � 1 neste caso!

*/
