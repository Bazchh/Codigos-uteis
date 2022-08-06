#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

float *gerador (size_t n);
int Calculo_da_media_rec(int n, float *v, int soma, int qnt);

int main () {
	setlocale(LC_ALL,"");	
	printf ("Sequencia aleatoria: \n");
		clock_t t1;
		t1 = clock();
		size_t n = 5,i, qnt = n;
 		float*res = gerador (n);
 		int media;
		  for (i = 0; i < n ; i ++) {
 			printf ("res [%i] %.2f\n", i, res[i]);
 
 		}
		media = Calculo_da_media_rec(n,res,0, qnt);
		
 		t1 = clock () - t1;
 		printf("\n\nA media dos numeros é: %i\n\n", media);
 		printf("\nO tempo de exeução foi %f 's\n\n", (((float)t1)/CLOCKS_PER_SEC));
 		return 0;
 }
 		
 
 float *gerador (size_t n) {
    size_t i;
	srand (time(NULL));
	float *res = (float*) malloc (n*sizeof(float));
	for (i = 0; i < n ; i ++) {
	res [i] = rand()%1000;
		}
 				return res ;
}

int Calculo_da_media_rec(int n,float *v, int soma, int qnt){
	
	if (n==0){
		return soma/qnt;
	} else{
		return (Calculo_da_media_rec(n-1, v, soma+v[n-1],qnt));
	}
	
}
