#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
Marcos Mikael Lima Vidal
Matricula: 2021010988
*/

typedef struct alunos{
	
	char nome [50];
	float n1;
	float n2;
	float n3;
	
}Als;

int main()
{
	setlocale(LC_ALL,"");	
	
	Als vet[8];
	int i = 0;
	FILE *arch; //Viariavel do tipo arquivo
	
	
	//abertura do arquivo
	arch = fopen("C://Users//PC//Documents//arquivos//entrada_q3.txt", "r");
	
	if(arch != NULL){
		
		printf("\nO arquivo foi aberto com sucesso!\n");
		
	} else{ exit(1);
	}
	
	for (i=0; i<8; i++){
		
		fscanf(arch,"%s %f %f %f",vet[i].nome, &vet[i].n1,&vet[i].n2,&vet[i].n3);
		
	}

	//Fechamento de arquivo
	fclose(arch);
	
	float media[8];
	
	for (i=0; i<8; i++){
		
		media [i] = (vet[i].n1+vet[i].n2+vet[i].n3)/3;
		
	}
		
		arch = fopen("C://Users//PC//Documents//arquivos//saida_q3.txt", "w");
		
			if(arch != NULL){
		
		printf("\nO arquivo foi criado com sucesso!\n");
		
	} else {	exit(1);
	}
		
		for (i=0;i<8;i++){
			
			fprintf(arch,"%s\t %.1f \t",vet[i].nome,media[i]);
			if(media[i]>=7.0){
				
				fprintf(arch,"Aprovado\n");
				
			}else if(media[i]<7.0){
				
				fprintf(arch,"Reprovado\n");
			}
		}
		
		fclose(arch);
		
		
	printf("\n");
	return 0;
}
