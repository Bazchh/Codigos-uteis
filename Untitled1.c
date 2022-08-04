#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
int algoritDemorado(int n);

int main (){
	clock_t t1;
	int n;
	scanf("%i", &n);
	t1 = clock ();
	algoritDemorado(n);
	t1 = clock () - t1;
	
	printf(" %f \n", (((float)t1)/10)/CLOCKS_PER_SEC);
	
	return 0;
}

int algoritDemorado(int n){
	int soma = 0;
	
	int i, j, k, l; 
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			for (k = 0; k < n; k++){
				for (l = 0; l < n;  l++){
						soma = i + j + k + l;
				}
			}
		}
	}
	return soma;
}
