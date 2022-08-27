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
void menu();
void ler(e *v);
void inserir_inicio(list *lista, e dado);
void inserir_fim(list *lista, e dado);
struct no *pesquisar(list lista, int mat);
struct no *inserir_apos(list *lista, e dado, int mat);
struct no *inserir_antes(list *lista, e dado, int mat);
void mostrar_lista(list lista);
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
		  
		  if(op==5){
		  	int mat;
		  	printf("\nInsira a matricula a ser pesquisada: ");
		  	scanf("%i", &mat);
		  	struct no *pi = pesquisar(lista,mat);
		  	
		  	if(pi!=NULL){
		  		printf("\nMatricula encontrada: %i", pi->dado.mat);
		  		printf("\nAluno: %s", pi->dado.nome);
			  } else
			  {
				  printf("\nMatricula não encontrada na lista!\n");
			  }
			  if(op==6){
				  int mat;
				  e estudante;
				  ler(&estudante);
				  printf("\nInforme a matricula do estudante que quer inserir após: ");
				  scanf("%i", &mat);
				  struct no *pi = inserir_apos(&lista,estudante,mat);
			  } if (pi==NULL){
				  printf("\nNão foi possivel inserir o estudante\n");
			  } else
			  {		
				  printf("\nDados inseridos com sucesso na lista!\n");
			  }
		  	
		  }
		  
		  if(op==7){
			  e aluno;
			  ler(&aluno);
			  int mat;
			  printf("\nInsira a qual matricula o dado deve ser inserido antes: ");
			  scanf("%i", &mat);
			  struct no *pi = inserir_antes(&lista, aluno, mat);
			  if(pi==NULL){
				  printf("\nA matricula inserida não existe na lista!\n");
			  }else
			  {
				  printf("\nDados inseridos com sucesso na lista!\n");
			  }
		  }
 	 	
 	 	menu();
 	 	scanf("%i", &op);
 	 	
	  }
 	
 	return 0;
 }
 


void menu(){
	printf("\n====Escolha uma opção===\n");
	printf("1 - inserir no inicio");
	printf("\n2 - inserir no fim");
	printf("\n3 - mostrar alunos");
	printf("\n4 - sair");
	printf("\n5 - pesquisar por matricula");
	printf("\n6 - inserir após");
	printf("\n7 - inserir antes");
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

struct no *pesquisar(list lista, int mat){
	struct no *pi; //Criamos um indice para caminhar sobre a lista
	//O indice recebe o inicio da lista como ponto de partida. o indice continuará caminhando até encontrar um ponteiro de um nó de lista que aponte para um valor NULL
	//Ou um nó com a matricula que corresponde a inserida pelo usuario
	for(pi = lista.inicio; pi!=NULL && pi->dado.mat != mat; pi = pi->prox);
	return pi; //O laço for se encerra com uma das condições e retorna um dos dois valores, NULL ou a matricula caso o dado conincida com o inserido
}

//Função para inserir após algum dado da lista
struct no *inserir_apos(list *lista, e dado, int mat){
	struct no *pi;//Indice usado para caminhar sobre a lista
	//O indice recebe o inicio da lista como ponto de partida. O indice continuará caminhando enquanto ele for diferente de NULL
	//ou enquanto for diferente da matricula inserida
	for(pi = lista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
	if(pi ==NULL){
		return pi; //Caso o valor do indice seja NULL, ele retorna o indice pi
	} else
	{
		//Caso encontremos a matricula inserida criamos um novo nó a qual será inserido após o nó com a matricula inserida. Este novo nó será apontado pelo nó que contém a matricula inserida
		struct no *novo = (struct no *)malloc(sizeof(struct no));
		
		novo->dado = dado; //O novo nó aponta para o nó que está a frente do nó que contém a matricula buscada
	   	novo->prox = pi->prox;//O nó com a matricula encontrada recebe agora um novo nó para qual ele deve apontar, o dado que acabou de ser inserido e esse mesmo nó (o novo inserido) aponta para o nó que anteriormente era
		pi->prox = novo; //apontado pelo nó que contém a matricula buscada 
		return pi;
	}
}
struct no *inserir_antes(list *lista, e dado, int mat){
	
	//Caso o inicio da matricula seja NULL quando essa opção for escolhida, ele automaticamente retorna NULL
	if(lista->inicio==NULL){
		return NULL;
	}
	//Caso o inicio da lista seja o valor buscado, utilizamos a função de inserir no inicio
	else if(lista->inicio->dado.mat == mat){
		struct no *novo = (struct no *)malloc(sizeof(struct no));
		novo->dado = dado; //O novo nó recebe o dado inseridos
		novo->prox = lista->inicio; //Mostramos para o novo nó para qual proximo elemento ele deve apontar, neste caso muito especifico, será NULL
	 	lista->inicio = novo; //O inicio da lista será agora este novo nó inserido
		
	} else //Caso contrario as opções acima, vamos inserir o novo nó ao na posição anterior ao nó com a matricula inserida
	{
	struct no *pi;//Indice que caiminhará sobre a lista
	//O indice recebe o inicio da lista como ponto de partida. O indice continuará caminhando enquanto ele for diferente de NULL 
	//Ou enquanto não encontrar o nó que aponta para o nó com a matricula buscada, ou seja,
	//Enquanto o proximo nó em relação ao nó a qual se encontra nosso indice não apontar para o dado buscado, ele continua caminhando
	for(pi = lista->inicio; pi->prox != NULL && pi->prox->dado.mat != mat; pi = pi->prox);
	if(pi->prox==NULL){
		return pi; //Caso não encontre nenhum nó que aponte para o dado buscado, ele retorna NULL
	}else
	{	//Sempre caminhamos na lista considerando o proximo nó
		//Caso encontremos um nó que aponta para o nó que possui a matricula buscada, criamos o novo nó para ser inserido após o nó que aponta para aquele que possui a matricula buscada
	struct no *novo = (struct no*)malloc(sizeof(struct no));
		novo->dado = dado; //Inserimos os dados para o novo nó
		novo->prox = pi->prox; //Fazemos o novo nó apontar para onde pi apontava, pi parou no nó da lista a qual apontava para o nó com o dado buscado
		pi->prox = novo; //E agora fazemos o nó que apontava para o dado buscado, apontar para o novo nó inserido
		return pi;
		}     
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