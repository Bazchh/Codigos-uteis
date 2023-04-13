#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

/*Ex de entrada e saida

Entrada-> 3 pontos: (3,1),(9,1),(5,6)

Saída-> Os pontos mais distantes entre sí são (3,1) e (5,6)

*/

//Não consegui fazer com que o codigo RETORNE de forma correta os pontos, mas 
//Imprimi-los foi bastante facil com o metodo que utilizei na função
//'maisDistante'. O programa acaba me retornando um valor aleatorio algumas vezes
//no primeiro ponto

//Tipo que define os pontos compostos por x e y no plano cartesiano
typedef struct pontos {
	float x;
	float y;
}Pontos;

 float *maisDistante(Pontos *Vet, int tamanho);

 int main()
 {
	 setlocale(LC_ALL, "");
	 
	 Pontos *Vet; //Ponteiro do tipo 'Pontos' que armazenará os pontos 
	 //x e y inseridos pelo usuário e que será alocado dinamicamente
	 
	 int Pts = 0; //Variavel do tipo inteiro que define a quantidade 
	 //de pontos desejados pelo usuario 
	 
	 int i = 0;//Variavel contadora
	 
	 printf("\nInsira a quantidade de pontos: "); 
	 scanf("%i", &Pts); //Atribuindo valor a variavel que define a quantidade
	 //de pontos
	 
	Vet = (Pontos*) malloc(Pts*sizeof(Pontos)); //Alocando tamanho do vetor
	
	 //Atribuindo valores aos pontos
	 for (i = 0; i < Pts;i++){
		printf("\nInsira as coordenadas x e y do ponto %i: ", i+1); 
		scanf("%f",&Vet[i].x);
		scanf("%f",&Vet[i].y);
		 
	 }
	 
	 printf("\n");
	
	float *doisdistantes = maisDistante(Vet,Pts);
	
	printf("\nOs pontos mais distantes entre si são (%.1f, %.1f) e (%.1f, %.1f)\n", Vet[(int)doisdistantes[0]].x, Vet[(int)doisdistantes[0]].y
	 ,Vet[(int)doisdistantes[1]].x, Vet[(int)doisdistantes[1]].y);
	 
	
	 
	 printf("\n\n");
	free(Vet);//Libera o espaço alocado pelo vetor
	 system("pause");
	 return 0;
 }
 //Função que retorna os dois pontos mais distantes entre si
 float *maisDistante(Pontos *Vet, int tamanho){

 int i = 0;
 
static float doisdistantes[2] = {0,0};
//atribuindo valores iniciais de x e y ao vetor
//que armazenará os menores e maiores valores de x e y
doisdistantes [0]=Vet[0].x;
doisdistantes [1]=Vet[0].y;	

	//Laço que verifica quais os maiores e menores valores de x e y em suas 
	//respectivas posições de acordo com o indice 'i' e compara o valores dos
	//pontos
	for (i = 0; i < tamanho; i++){
		
		if(Vet[i].x >= Vet[0].x && Vet[i].y >= Vet[0].y){
	
			doisdistantes [0]=Vet[i].x; //armazenando os maiores valores encontrados de
			doisdistantes [0]=Vet[i].y; //x e y
			    	
		}	
                 else if(Vet[i].x <= doisdistantes[1] && Vet[i].y <= doisdistantes[1]){
		   			
					   	doisdistantes [1] = Vet[i].x;//armazenando os maiores valores 
					   	doisdistantes [1] = Vet[i].y;//encontrados de x e y
					}
	}	

		return doisdistantes;
}
 
