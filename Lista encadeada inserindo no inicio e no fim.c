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
 
 //Função inserir que recebe um ponteiro pra lista e os dados dos alunos
 void inserir_inicio(list *lista, e dado){
 	
 	struct no *novo = (struct no*)malloc(sizeof(struct no));//criamos um novo nó 
 	novo->dado = dado; //esse novo nó receberá os dados passados por parametro, matricula e nome do estudante
 	novo->prox = lista->inicio;//proximo nó vai ser o inicio da lista, que é e o novo nó estará apontando para o nó que anteriormente era o inicio
 	lista->inicio = novo; //o inicio da lista não vai ser mais o elemento inicial, ela será igual ao novo dado inserido, e ao invés de apontar para NULL
 	//o ponteiro desse novo NÓ apontará para o inicio dessa lista
 }                                            
 
 //Função que insere um estudante no fim
 void inserir_fim(list *lista, e dado){
 	struct no *novo = (struct no*)malloc(sizeof(struct no)); //Criamos um novo nó
 	novo->dado = dado; //Esse novo nó recebe os dados inseridos, matricula e nome
 	novo->prox = NULL; //O proximo nó do novo ponteiro inserido na lista sempre apontará para o proximo nó, 
	 //no caso de quando inserimos um elemento no fim da lista, ele apontará sempre para NULL, ou ao menos é o que se espera
	 //Um nó não recebe os dados de um ponteiro, mas sim o endereço para qual ele deve apontar em que está o ponteiro desse nó, logo,
	 //O nó deste ponteiro deverá apontar para o proximo ponteiro ou para NULL em caso de não haver proximo ponteiro
 	
 	//Caso o inicio da lista não possua nenhum elemento, o inicio da lista será o novo nó
	 if(lista->inicio==NULL){
 		lista->inicio = novo;	
 		
 		//Caso contrario, caminharemos sobre a lista até encontrar um elemento com um nó que 
	 } else{
	 	struct no *pi;//Indice que caminha sobre a lista para encontrar um espaço NULL para inserir um novo elemento ao fim da lista encadeada
	 	//O indice recebe o inicio da lista e enquanto não encontrar um valor NULL, ele caminhará sobre a lista recebendo o endereço para qual o 'prox' nó aponta
	 	for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox);
	 	pi->prox = novo; //Quando encontrar o nó prox que aponta para NULL, ele insere a frente desse nõ o novo ponteiro para qual ele deve apontar, o novo valor inserido pelo usuario
		 }
	 }
                                                                      
 //mostra a lista
 void mostrar_lista(list lista){
 	struct no * pi = lista.inicio; //variavel que indica o indice dos nós
 	//caminha sobre os nós até que nó se torne nulo, ou seja, não possua mais nenhum elemento na lista encadeada ou nenhum elemento novo a ser inserido
 	while(pi!=NULL){ 
 		printf("\nNome: %s \nMatricula: %i\n",pi->dado.nome, pi->dado.mat);
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
