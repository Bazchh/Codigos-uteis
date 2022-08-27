#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*ESCREVA UM PROGRAMA QUE LEIA UM NUMERO N. ESSE NUMERO SERÁ A QUANTIDADE DE ALUNOS QUE SERÃO LIDOS EM SEGUIDA. CADA ESTUDANTE POSSUI
UMA MATRICULA, NOME E TRÊS NOTAS. AO FINAL, DEVE-SE APRESENTAR DUAS OPÇÕES PARA O USUARIO. AO SELECIONA A OPÇÃO DE PESQUISA, O USUARIO
DEVE INFORMAR A MATRICULA DO ALUNO QUE DESEJA ENCONTRAR, FORNECER UM PONTO A MAIS NA TERCEIRA UNIDADE E CALCULAR A SUA MEDIA*/

typedef struct {
	int mat;
	char nome[10];
	float n1;
	float n2;
	float n3;
}Estudante;

void menu(){
	
	printf("\n\nEscolha uma opção: ");
	printf("\n 1 - pesquisar");
	printf("\n 2 - sair \n\n");
}

void ler (Estudante *e){
	
	printf("\nInsira os dados do estudante: ");
	scanf("%i %s %f %f %f",&e->mat, e->nome, &e->n1, &e->n2, &e->n3);
	
}

int buscabinrecursiva(int mat, Estudante v[], int i, int f){
	if (i>f){
		
		return -1; //Caso inicio seja maior que o fim, não existe estudante com a matricula inserida
	}
	int meio = (i+f)/2;
	if(v[meio].mat==mat){
		
	return meio;
	}
	
	if (v[meio].mat < mat){
		//Caso não seja encontrado a matricula buscada, e seja menor que a matricula buscada será dividido ao meio os indices para diminuir os campos de busca
		//Dessa forma estamos realizando a busca somente dentro da função criada e não na função main. Nesta parte estamos buscando na parte superior
		return buscabinrecursiva(mat, v, meio+1, f); 
	}
	
	return buscabinrecursiva(mat,v,i,meio-1); //Busca na parte inferior do vetor
}

int main (){
	
	setlocale(LC_ALL,"");
	int n;
	printf("\nInforme a quantidade de estudantes: ");
	scanf("%i", &n);
	
	Estudante v[n];
	int i;
	
	for(i=0; i<n; i++){
		ler(&v[i]);
	}
	
	int op;
	menu();
	
	scanf("%i", &op);
	
	while(op!=2){
		if(op==1){
			int mat;
			printf("\nInforme uma matricula: ");
			scanf("%i", &mat);
		int idx = buscabinrecursiva(mat,v,0,n-1);
			
			if(idx!= -1){
			v[idx].n3 = v[idx].n3+1;
			
			float media = (v[idx].n1*2+v[idx].n2*3+v[idx].n3*4)/9;
			
			printf("\n%s: %.1f\n",v[idx].nome, media);
			}
		}
		menu();
		scanf("%i", &op);
	}
	
	printf("\n\n");
	return 0;
}

/*A recursividade é usada para resolver os subproblemas do mesmo tipo, os transformando em problemas menores dos menos complexo ao mais 
complexo. A recursividade também é um metodo a qual chama a função chama a si mesma dentro dela*/

