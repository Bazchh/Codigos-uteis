#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
//Escopo das funções
void menu();
void ler(e *v);
void inserir_inicio(list *lista, e dado);
void inserir_fim(list *lista, e dado);
struct no *pesquisar(list lista, int mat);
void alterar_dados(list *lista, int mat, char nome[]);
struct no *inserir_apos(list *lista, e dado, int mat);
struct no *inserir_antes(list *lista, e dado, int mat);
void mostrar_lista(list lista);
void deletar_inicio(list *lista);
void deletar_fim(list *lista);
void deletar_matricula(list *lista, int mat);
void deletar_lista(list *lista);
int tamanho(list *lista);
 void Bubble_sort(list *lista);
 void salvar_lista(list lista);
list criar_lista(int n);
 list ler_arquivo();

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
			  	  }
			  if(op==6){
				  e aluno;
				  ler(&aluno);
                  int mat;
				  printf("\nInforme a matricula do estudante para ser inserida após: ");
				  scanf("%i", &mat);
				  struct no *pi = inserir_apos(&lista, aluno, mat);
			   if (pi==NULL){
				  printf("\nNão foi possivel inserir o estudante\n");
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
		  
		  if(op==8){
			  deletar_inicio(&lista);
		  }
		  if(op==9){
			  deletar_fim(&lista);
		  } 
		  if(op==10){
			  int mat;
			  printf("\nInsira a matricula do estudante a ser deletada: ");
			  scanf("%i", &mat);
			  deletar_matricula(&lista, mat);
		  } if(op==11){
			  deletar_lista(&lista);
			  printf("\nLista deletada com sucesso!\n");
		  } if(op==12){
			  int mat;
			  printf("\nInsira a matricula do aluno a ter o nome alterado: ");
			  scanf("%i", &mat);
			  char nome[20];
			  printf("\nInsira o novo nome: ");
			  scanf("%s", nome);
			  alterar_dados(&lista,mat,nome);
			  printf("\nSucesso na operação!\n");
			  
		  }if(op==13){
			  int i = tamanho(&lista);
			  
			  printf("\nA lista possui %i elementos.\n", i);
		  }if(op==14){
			  int n;
			  printf("\nInsira a quantidade de elementos a serem criados: ");
			  scanf("%i", &n);
			  lista = criar_lista(n);
		  }if(op==15){
			  
			  Bubble_sort(&lista);
			  
			  if(lista.inicio != NULL){
			  printf("\nLista ordenada com sucesso!\n");
			  }
		  }if(op==16){
			  salvar_lista(lista);
			  printf("\nLista salva com sucesso!\n");
		  }if(op==17){
			  lista = ler_arquivo();
		  }
 	 	
 	 	menu();
 	 	scanf("%i", &op);
 	 	
	  }
 	
 	return 0;
 }

void deletar_lista(list *lista){
	struct no *pi;
	while(lista->inicio!=NULL)
	{
		pi = lista->inicio; //Colocamos pi na mesma posição do inicio da lista
		lista->inicio = pi->prox; //fazemos o inicio apontar para a proxima posição a qual pi aponta(pi aponta para o proximo elemento da lista após o inicio), ou seja,
		// o inicio da lista agora será o valor posterior ao inicio
		free(pi); //Liberamos o valor de pi, a qual era o inicio da lista
		
		//O processo se repete até que o inicio da lista seja NULL
	}
} 
  
void deletar_inicio(list *lista){
	if(lista->inicio==NULL){
		printf("\nA lista está vazia!\n");
	}else
	{
		struct no *pi = lista->inicio;//Caso exista algo na lista, criamos um novo nó e atribuios o inicio a ele
		lista->inicio = pi->prox; //Atribuimos o proximo nó para qual o pi aponta ao inicio da lista
		free(pi); //Liberamos a memoria alocada em pi e consequentemente o valor contido nela
	}
}

void deletar_matricula(list *lista, int mat){
	if(lista->inicio==NULL){
		printf("\nA lista está vazia!\n");
	} 
	//Caso o nó esteja no inicio
	else if(lista->inicio->dado.mat==mat){
		struct no *pi = lista->inicio;
		lista->inicio = pi->prox;
		free(pi);
		
		printf("\nEstudante deletado com sucesso!\n");
	}
	//Caso exista um unico nó na lista. Valor existe 
	else if(lista->inicio->prox==NULL && lista->inicio->dado.mat == mat){
		struct no *pi = lista->inicio;
		lista->inicio = pi->prox;
		free(pi);
		printf("\nEstudante deletado com sucesso!\n");
	}//Caso exista um unico nó na lista. Valor não existe
	else if(lista->inicio->prox==NULL && lista->inicio->dado.mat != mat){
		printf("\nO valor inserido não existe na lista!\n");
	} 
	//Nó com multiplos itens. Valor existe
	else if(lista->inicio->prox!=NULL){
		struct no *pi;
		struct no *pa;
		for(pi = lista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox){
			pa = pi; //pa é igual ao antigo valor de pi
		}
		if(pi==NULL){
			printf("\nO estudante não pode ser removido pois não foi encontrad\n");
		} else
		{
			pa->prox = pi->prox; //pa agora a ponta para o proximo elemento a qual pi apontava
			free(pi); //deletamos o item da lista selecionado
			printf("\nEstudante deletado com sucesso!\n");
		}
	}
}

void deletar_fim(list *lista){
	if(lista->inicio==NULL){
		printf("\nA lista está vazia!");
	}else if(lista->inicio->prox == NULL){
		struct no *pi = lista->inicio; //Atribuimos o valor inicial ao indice do inicio da lista
		lista->inicio = pi->prox; //Atribuimos o valor do proximo nó para o nó a qual o inicio apontava para o inicio da lista (o indice agora possui o valor inicial)
		free(pi); //liberamos o valor inicial que agora estava em pi
	} else
	{
		struct no *pi; //Criamos o indice que caminhará sobre a lista
		struct no *pa;//criamos outro indice que recebe o valor anterior a pi
		//pi inicia no inicio da lista, enquanto for diferente de null caminhamos sob a lista
		//enquanto for diferente, pi estará recebendo o proximo valor para qual ele mesmo aponta
		//Pa recebe o valor atual, ou seja, valor anterior ao proximo
		for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox){
		pa = pi;
		}
		//Quando o laço for se encerrar, significa que encontramos o fim da lista
		//Ao sair do laço, atribuimos NULL ao valor que é o proximo a pa e que é o fim da lista
		pa->prox = NULL;
		free(pi); 
	}
}

void menu(){
	printf("\n======Escolha uma opção========\n");
	printf("1 - inserir no inicio");
	printf("\n2 - inserir no fim");
	printf("\n3 - mostrar alunos");
	printf("\n4 - sair");
	printf("\n5 - pesquisar por matricula");
	printf("\n6 - inserir após");
	printf("\n7 - inserir antes");
	printf("\n8 - deletar inicio");
	printf("\n9 - deletar fim");
	printf("\n10 - deletar por matricula");
	printf("\n11 - deletar lista");
	printf("\n12 - alterar dados");
	printf("\n13 - tamanho da lista");
	printf("\n14 - criar lista");
	printf("\n15 - Ordenar lista");
	printf("\n16 - Salvar em arquivo");
	printf("\n17 - Ler de um arquivo");
	printf("\n===============================\n");
}
 
 list ler_arquivo(){
 	list lista;
 	lista.inicio = NULL;
	 FILE *arch = fopen("lista encadeada estudantes.b","rb");
	 e estudante;
	 while(fread(&estudante,sizeof(e),1,arch)){
		 inserir_fim(&lista,estudante);
	 }
	 fclose(arch);
	 return lista;
 }
 
 void salvar_lista(list lista){
	 FILE *arch = fopen("lista encadeada estudantes.b", "wb");
	 struct no *pi;
	 
	 for(pi = lista.inicio; pi != NULL; pi = pi->prox){
		 fwrite(&pi->dado,sizeof(e),1,arch);
	 }
	 
	 fclose(arch);
 }
 
 void ler(e *v){
 	printf("\nInsira os dados do estudante: ");
 	scanf("%s %i", v->nome, &v->mat);
 }
 //Função que ordena por bubble sort
 void Bubble_sort(list *lista){
	 if(lista->inicio == NULL){
		 printf("\nA lista está vazia\n");
	 }else
	 {
		 struct no *pi = lista->inicio; //criamos 2 indices, i e j (pi e pj) para realizar a ordenação
		 struct	no *pj = lista->inicio;
		 struct no *pfim = NULL; //Sinaliza o fim da lista
		 for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox){
			 for (pj = lista->inicio; pj->prox != pfim; pj = pj->prox){
				//Caso o valor de pj atual seja maior que o proximo valor de pj (valor da matricula) realizamos uma troca
				 if(pj->dado.mat> pj->prox->dado.mat){
					 e temp = pj->dado; //criamos uma variavel estudante temporaria e inseridos os dados do pj atual nele
					 pj->dado = pj->prox->dado;//Depois de atribuir o valor dos dados maiores em uma variavel temporaria, pegamos os valores menores que estão a frente e passamos para a posição anterior
				 	 pj->prox->dado = temp; //Agora pegamos o maior valor encontrado e passamos para a posição a frente que era do menor valor encontrado nesta rodada
				 }
			 }
		 }
		 	 pfim = pj; //Sinalizamos um novo fim da lista que é o maior valor que está no final da lista
	 }
 }
 
 list criar_lista(int n){
	 list lista;
	 lista.inicio = NULL;
	 int i;
	 for (i=0; i<n; i++){
		 e estudante;
		 ler(&estudante);
		 inserir_fim(&lista,estudante);
	 }
	 return lista;
 }
 
 //função que verifica e retorna o tamanho da lista
 int tamanho(list *lista){
	 
	 //Caso o unicio da lista seja NULL, significa que ela possui 0 elementos
	 if(lista->inicio==NULL){
		 return 0;
		 //Caso o proximo elemento para qual o inicio aponta seja NULL, ele possui somente 1 elemento
	 } else if(lista->inicio->prox==NULL){
		 return 1;
		 
	 }
	 //Caso o proximo elemento para qual ele aponta seja diferente de NULL, existe mais de 1 elemento
	  else if(lista->inicio->prox!=NULL){
		 //criamos um indice pi que caminhará sobre a lista e verifica quantos nós existem
		 struct no *pi = lista->inicio;
		 int i = 1; //Variavel contadora que inicia em 1, pois, como o inicio da lista é diferente de NULL, já temos um elemento para contar
		 for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox){
			 i++;//Incrementa o 1 quanto encontra um valor diferente de NULL no proximo elemento apontado po pi->prox
		 }
		 return i;
	 }
	 return 0;
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

void alterar_dados(list *lista, int mat, char nome[]){
	   
	   //Utilizamos a função de pesquisa para pesquisar o item a ser alterado na lista
	   struct no *pi = pesquisar(*lista, mat);
	   //Caso o valor retornado seja NULL, quer dizer que não encontrou-se a matricula buscada
	   if(pi==NULL){
	   	printf("\nEstudante não existe!\n");
	   	
	   }else
	   {	
	   		//Caso contrario, copiamos o nome inserido pelo usuario ao nó com a matricula buscada com o mesmo campo
		   strcpy(pi->dado.nome,nome);
	   }
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
		novo->dado = dado; //Atribuindo dados ao novo nó criado
		novo->prox = pi->prox ; //O novo nó aponta para o nó que está a frente do nó que contém a matricula buscada
	   	pi->prox = novo;//O nó com a matricula encontrada recebe agora um novo nó para qual ele deve apontar, o dado que acabou de ser inserido e esse mesmo nó (o novo inserido) aponta para o nó que anteriormente era
		 //apontado pelo nó que contém a matricula buscada 
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
	
	return 0;
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