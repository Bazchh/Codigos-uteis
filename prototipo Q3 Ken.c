#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

int main (){
	setlocale(LC_ALL,"");
	char *n;
	int i = 0, pos = 0;
	n = (char*)malloc(20*sizeof(char));
	
	fgets(n,20,stdin);
	
	for(i = 0, pos = 0; i < strlen(n); i++, pos++){
		if(n[pos]==32 || n[pos]==44){
			pos++;
		}
		if(n[pos]==44 || n[pos]==32){
			pos++;
		}
		n[i] = n[pos];
	}
	
	char *aux = (char*)malloc((strlen(n))*sizeof(char));
	
	strrev(n);
	
	printf("\n%s\n\n", n);
	return 0;
}
