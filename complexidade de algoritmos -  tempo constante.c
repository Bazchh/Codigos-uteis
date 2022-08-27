#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*Escreva um programa que leia três notas de um estudante e imprima sua média*/


int main(){
	setlocale(LC_ALL,"");
	float n1, n2 ,n3;
	
	printf("Insira as notas: ");
	scanf("%f %f %f", &n1, &n2, &n3);
	
	float media = (n1+n2+n3)/3;
	
	printf("%.1f\n", media);
	
}

/*CONCEITO DE COMPLEXIDADE DE ALGORITMOS REFERENTE AO TEMPO CONSTANTE: 

Quantas vezes cada instrução é executada? Apenas uma vez, todas elas! Isso quer dizer que o programa é executado em tempo
constante, que é 1 neste caso!

*/
