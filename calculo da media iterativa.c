#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

float *gerador (size_t n);

int main () {
	setlocale(LC_ALL,"");	
	printf ("Sequencia aleatoria: \n");
		clock_t t1;
		t1 = clock();
		int n = 10000,i;
 		float*res = gerador (n);
 		int media = 0;
		  for (i = 0; i < n ; i ++) {
 			printf ("res [%i] %.2f\n", i, res[i]);
            media += res[i];
 		}
		
		
 		t1 = clock () - t1;
 		printf("\n\nA media dos numeros é: %i\n\n", media/n);
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
