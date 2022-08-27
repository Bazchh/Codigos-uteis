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
				  printf("\nMatricula n�o encontrada na lista!\n");
			  }
			  if(op==6){
				  int mat;
				  e estudante;
				  ler(&estudante);
				  printf("\nInforme a matricula do estudante que quer inserir ap�s: ");
				  scanf("%i", &mat);
				  struct no *pi = inserir_apos(&lista,estudante,mat);
			  } if (pi==NULL){
				  printf("\nN�o foi possivel inserir o estudante\n");
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
				  printf("\nA matricula inserida n�o existe na lista!\n");
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
	printf("\n====Escolha uma op��o===\n");
	printf("1 - inserir no inicio");
	printf("\n2 - inserir no fim");
	printf("\n3 - mostrar alunos");
	printf("\n4 - sair");
	printf("\n5 - pesquisar por matricula");
	printf("\n6 - inserir ap�s");
	printf("\n7 - inserir antes");
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

struct no *pesquisar(list lista, int mat){
	struct no *pi; //Criamos um indice para caminhar sobre a lista
	//O indice recebe o inicio da lista como ponto de partida. o indice continuar� caminhando at� encontrar um ponteiro de um n� de lista que aponte para um valor NULL
	//Ou um n� com a matricula que corresponde a inserida pelo usuario
	for(pi = lista.inicio; pi!=NULL && pi->dado.mat != mat; pi = pi->prox);
	return pi; //O la�o for se encerra com uma das condi��es e retorna um dos dois valores, NULL ou a matricula caso o dado conincida com o inserido
}

//Fun��o para inserir ap�s algum dado da lista
struct no *inserir_apos(list *lista, e dado, int mat){
	struct no *pi;//Indice usado para caminhar sobre a lista
	//O indice recebe o inicio da lista como ponto de partida. O indice continuar� caminhando enquanto ele for diferente de NULL
	//ou enquanto for diferente da matricula inserida
	for(pi = lista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
	if(pi ==NULL){
		return pi; //Caso o valor do indice seja NULL, ele retorna o indice pi
	} else
	{
		//Caso encontremos a matricula inserida criamos um novo n� a qual ser� inserido ap�s o n� com a matricula inserida. Este novo n� ser� apontado pelo n� que cont�m a matricula inserida
		struct no *novo = (struct no *)malloc(sizeof(struct no));
		
		novo->dado = dado; //O novo n� aponta para o n� que est� a frente do n� que cont�m a matricula buscada
	   	novo->prox = pi->prox;//O n� com a matricula encontrada recebe agora um novo n� para qual ele deve apontar, o dado que acabou de ser inserido e esse mesmo n� (o novo inserido) aponta para o n� que anteriormente era
		pi->prox = novo; //apontado pelo n� que cont�m a matricula buscada 
		return pi;
	}
}
struct no *inserir_antes(list *lista, e dado, int mat){
	
	//Caso o inicio da matricula seja NULL quando essa op��o for escolhida, ele automaticamente retorna NULL
	if(lista->inicio==NULL){
		return NULL;
	}
	//Caso o inicio da lista seja o valor buscado, utilizamos a fun��o de inserir no inicio
	else if(lista->inicio->dado.mat == mat){
		struct no *novo = (struct no *)malloc(sizeof(struct no));
		novo->dado = dado; //O novo n� recebe o dado inseridos
		novo->prox = lista->inicio; //Mostramos para o novo n� para qual proximo elemento ele deve apontar, neste caso muito especifico, ser� NULL
	 	lista->inicio = novo; //O inicio da lista ser� agora este novo n� inserido
		
	} else //Caso contrario as op��es acima, vamos inserir o novo n� ao na posi��o anterior ao n� com a matricula inserida
	{
	struct no *pi;//Indice que caiminhar� sobre a lista
	//O indice recebe o inicio da lista como ponto de partida. O indice continuar� caminhando enquanto ele for diferente de NULL 
	//Ou enquanto n�o encontrar o n� que aponta para o n� com a matricula buscada, ou seja,
	//Enquanto o proximo n� em rela��o ao n� a qual se encontra nosso indice n�o apontar para o dado buscado, ele continua caminhando
	for(pi = lista->inicio; pi->prox != NULL && pi->prox->dado.mat != mat; pi = pi->prox);
	if(pi->prox==NULL){
		return pi; //Caso n�o encontre nenhum n� que aponte para o dado buscado, ele retorna NULL
	}else
	{	//Sempre caminhamos na lista considerando o proximo n�
		//Caso encontremos um n� que aponta para o n� que possui a matricula buscada, criamos o novo n� para ser inserido ap�s o n� que aponta para aquele que possui a matricula buscada
	struct no *novo = (struct no*)malloc(sizeof(struct no));
		novo->dado = dado; //Inserimos os dados para o novo n�
		novo->prox = pi->prox; //Fazemos o novo n� apontar para onde pi apontava, pi parou no n� da lista a qual apontava para o n� com o dado buscado
		pi->prox = novo; //E agora fazemos o n� que apontava para o dado buscado, apontar para o novo n� inserido
		return pi;
		}     
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