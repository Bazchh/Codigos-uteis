#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct estudante{
	char nome[100];
	int mat;
}e;

//Não podemos definir typedef no no, porque há outro no dentro de outro no, pois o mesmo ainda não foi definido, sendo necessario defini-lo como struct tradicional
struct no{
	e dado; //variavel dos dados dos estudantes
	struct no * prox; //ponteiro nó para o proximo elemento
	//Cada nó, terá os novos dados de um aluno e o ponteiro do proximo nó
};
//Estrutura que representa uma lista que vai indicar onde está o inicio
typedef struct lista{
	struct no * inicio;
}list;

void menu(){
	printf("\n====Escolha uma opção===\n");
	printf("1 - add aluno");
	printf("\n2 - mostrar alunos");
	printf("\n3 - sair\n");
	printf("\n============\n");
}
 
 void ler(e *v){
 	printf("\nInsira os dados do estudante:");
 	scanf("%s %i", &v->nome, &v->mat);
 }
 
 //Função inserir que recebe um ponteiro pra lista e os dados dos alunos
 void inserir_inicio(list *lista, e dado){
 	
 	struct no *novo = (struct no*)malloc(sizeof(struct no));//criamos um novo nó 
 	novo->dado = dado; //esse novo nó receberá os dados passados por parametro, matricula e nome do estudante
 	novo->prox = lista->inicio;//proximo nó vai ser o inicio da lista, que é e o novo nó estará apontando para o nó que anteriormente era o inicio
 	lista->inicio = novo; //o inicio da lista não vai ser mais o elemento inicial, ela será igual ao novo dado inserido, e ao invés de apontar para NULL
 	//o ponteiro desse novo NÓ apontará para o inicio dessa lista
 }                                                                                                                  
 //mostra a lista
 void mostrar_lista(list lista){
 	struct no * pi = lista.inicio; //variavel que indica o indice dos nós
 	//caminha sobre os nós até que nó se torne nulo, ou seja, não possua mais nenhum elemento na lista encadeada ou nenhum elemento novo a ser inserido
 	while(pi!=NULL){ 
 		printf("\nNome: %s \nMatricula: %i",pi->dado.nome, pi->dado.mat);
 		pi = pi->prox;
	 }
 }
 
 int main(){
 	setlocale(LC_ALL,"");
 	 list lista; //Criamos a lista
 	 lista.inicio = NULL; //O inicio da lista será nulo
 	 int op; //Variavel para selecionar a opção
 	 menu(); //chamada do menu para seleção
 	 scanf("%i", &op); //lendo opção escolhida
 	 while(op!=3){
 	 	//Se a op for igual a 1, leremos um dado para a lista
		  if(op==1){ 
 	 		e aluno; //Criando variavel para inserir dados para a lista
			  ler(&aluno);//Lendo dados a serem inseridos na lista
			  inserir_inicio(&lista,aluno);
		  }
		  
		  if(op==2){
		  	mostrar_lista(lista);
		  }
 	 	
 	 	menu();
 	 	scanf("%i", &op);
 	 	
	  }
 	
 	return 0;
 }
