#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct estudante{
	char nome[100];
	int mat;
}e;

//N�o podemos definir typedef no no, porque h� outro no dentro de outro no, pois o mesmo ainda n�o foi definido, sendo necessario defini-lo como struct tradicional
struct no{
	e dado; //variavel dos dados dos estudantes
	struct no * prox; //ponteiro n� para o proximo elemento
	//Cada n�, ter� os novos dados de um aluno e o ponteiro do proximo n�
};
//Estrutura que representa uma lista que vai indicar onde est� o inicio
typedef struct lista{
	struct no * inicio;
}list;

void menu(){
	printf("\n====Escolha uma op��o===\n");
	printf("1 - inserir no inicio");
	printf("\n2 - inserir no fim");
	printf("\n3 - mostrar alunos");
	printf("\n4 - sair");
	printf("\n============\n");
}
 
 void ler(e *v){
 	printf("\nInsira os dados do estudante:");
 	scanf("%s %i", v->nome, &v->mat);
 }
 
 //Fun��o inserir que recebe um ponteiro pra lista e os dados dos alunos
 void inserir_inicio(list *lista, e dado){
 	
 	struct no *novo = (struct no*)malloc(sizeof(struct no));//criamos um novo n� 
 	novo->dado = dado; //esse novo n� receber� os dados passados por parametro, matricula e nome do estudante
 	novo->prox = lista->inicio;//proximo n� vai ser o inicio da lista, que � e o novo n� estar� apontando para o n� que anteriormente era o inicio
 	lista->inicio = novo; //o inicio da lista n�o vai ser mais o elemento inicial, ela ser� igual ao novo dado inserido, e ao inv�s de apontar para NULL
 	//o ponteiro desse novo N� apontar� para o inicio dessa lista
 }                                            
 
 //Fun��o que insere um estudante no fim
 void inserir_fim(list *lista, e dado){
 	struct no *novo = (struct no*)malloc(sizeof(struct no)); //Criamos um novo n�
 	novo->dado = dado; //Esse novo n� recebe os dados inseridos, matricula e nome
 	novo->prox = NULL; //O proximo n� do novo ponteiro inserido na lista sempre apontar� para o proximo n�, 
	 //no caso de quando inserimos um elemento no fim da lista, ele apontar� sempre para NULL, ou ao menos � o que se espera
	 //Um n� n�o recebe os dados de um ponteiro, mas sim o endere�o para qual ele deve apontar em que est� o ponteiro desse n�, logo,
	 //O n� deste ponteiro dever� apontar para o proximo ponteiro ou para NULL em caso de n�o haver proximo ponteiro
 	
 	//Caso o inicio da lista n�o possua nenhum elemento, o inicio da lista ser� o novo n�
	 if(lista->inicio==NULL){
 		lista->inicio = novo;	
 		
 		//Caso contrario, caminharemos sobre a lista at� encontrar um elemento com um n� que 
	 } else{
	 	struct no *pi;//Indice que caminha sobre a lista para encontrar um espa�o NULL para inserir um novo elemento ao fim da lista encadeada
	 	//O indice recebe o inicio da lista e enquanto n�o encontrar um valor NULL, ele caminhar� sobre a lista recebendo o endere�o para qual o 'prox' n� aponta
	 	for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox);
	 	pi->prox = novo; //Quando encontrar o n� prox que aponta para NULL, ele insere a frente desse n� o novo ponteiro para qual ele deve apontar, o novo valor inserido pelo usuario
		 }
	 }
                                                                      
 //mostra a lista
 void mostrar_lista(list lista){
 	struct no * pi = lista.inicio; //variavel que indica o indice dos n�s
 	//caminha sobre os n�s at� que n� se torne nulo, ou seja, n�o possua mais nenhum elemento na lista encadeada ou nenhum elemento novo a ser inserido
 	while(pi!=NULL){ 
 		printf("\nNome: %s \nMatricula: %i\n",pi->dado.nome, pi->dado.mat);
 		pi = pi->prox;
	 }
 }
 
 int main(){
 	setlocale(LC_ALL,"");
 	 list lista; //Criamos a lista
 	 lista.inicio = NULL; //O inicio da lista ser� nulo
 	 int op; //Variavel para selecionar a op��o
 		menu(); //chamada do menu para sele��o
 	 scanf("%i", &op); //lendo op��o escolhida
 	 while(op!=4){
 	 	//Se a op for igual a 1, leremos um dado para a lista
		  if(op==1){ 
 	 		e aluno; //Criando variavel para inserir dados para a lista
			  ler(&aluno);//Lendo dados a serem inseridos na lista
			  inserir_inicio(&lista,aluno);
		  }
		  if(op==2){
		  	e aluno;
		  	ler(&aluno);
		  	inserir_fim(&lista, aluno);
		  }
		  if(op==3){
		  	mostrar_lista(lista);
		  }
		  	
		  }
 	 	
 	 	menu();
 	 	scanf("%i", &op);
 	 	
	  }
 	
 	return 0;
 }
