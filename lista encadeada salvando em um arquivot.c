#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
//Escopo das fun��es
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
			  	  }
			  if(op==6){
				  e aluno;
				  ler(&aluno);
                  int mat;
				  printf("\nInforme a matricula do estudante para ser inserida ap�s: ");
				  scanf("%i", &mat);
				  struct no *pi = inserir_apos(&lista, aluno, mat);
			   if (pi==NULL){
				  printf("\nN�o foi possivel inserir o estudante\n");
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
			  printf("\nSucesso na opera��o!\n");
			  
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
		pi = lista->inicio; //Colocamos pi na mesma posi��o do inicio da lista
		lista->inicio = pi->prox; //fazemos o inicio apontar para a proxima posi��o a qual pi aponta(pi aponta para o proximo elemento da lista ap�s o inicio), ou seja,
		// o inicio da lista agora ser� o valor posterior ao inicio
		free(pi); //Liberamos o valor de pi, a qual era o inicio da lista
		
		//O processo se repete at� que o inicio da lista seja NULL
	}
} 
  
void deletar_inicio(list *lista){
	if(lista->inicio==NULL){
		printf("\nA lista est� vazia!\n");
	}else
	{
		struct no *pi = lista->inicio;//Caso exista algo na lista, criamos um novo n� e atribuios o inicio a ele
		lista->inicio = pi->prox; //Atribuimos o proximo n� para qual o pi aponta ao inicio da lista
		free(pi); //Liberamos a memoria alocada em pi e consequentemente o valor contido nela
	}
}

void deletar_matricula(list *lista, int mat){
	if(lista->inicio==NULL){
		printf("\nA lista est� vazia!\n");
	} 
	//Caso o n� esteja no inicio
	else if(lista->inicio->dado.mat==mat){
		struct no *pi = lista->inicio;
		lista->inicio = pi->prox;
		free(pi);
		
		printf("\nEstudante deletado com sucesso!\n");
	}
	//Caso exista um unico n� na lista. Valor existe 
	else if(lista->inicio->prox==NULL && lista->inicio->dado.mat == mat){
		struct no *pi = lista->inicio;
		lista->inicio = pi->prox;
		free(pi);
		printf("\nEstudante deletado com sucesso!\n");
	}//Caso exista um unico n� na lista. Valor n�o existe
	else if(lista->inicio->prox==NULL && lista->inicio->dado.mat != mat){
		printf("\nO valor inserido n�o existe na lista!\n");
	} 
	//N� com multiplos itens. Valor existe
	else if(lista->inicio->prox!=NULL){
		struct no *pi;
		struct no *pa;
		for(pi = lista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox){
			pa = pi; //pa � igual ao antigo valor de pi
		}
		if(pi==NULL){
			printf("\nO estudante n�o pode ser removido pois n�o foi encontrad\n");
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
		printf("\nA lista est� vazia!");
	}else if(lista->inicio->prox == NULL){
		struct no *pi = lista->inicio; //Atribuimos o valor inicial ao indice do inicio da lista
		lista->inicio = pi->prox; //Atribuimos o valor do proximo n� para o n� a qual o inicio apontava para o inicio da lista (o indice agora possui o valor inicial)
		free(pi); //liberamos o valor inicial que agora estava em pi
	} else
	{
		struct no *pi; //Criamos o indice que caminhar� sobre a lista
		struct no *pa;//criamos outro indice que recebe o valor anterior a pi
		//pi inicia no inicio da lista, enquanto for diferente de null caminhamos sob a lista
		//enquanto for diferente, pi estar� recebendo o proximo valor para qual ele mesmo aponta
		//Pa recebe o valor atual, ou seja, valor anterior ao proximo
		for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox){
		pa = pi;
		}
		//Quando o la�o for se encerrar, significa que encontramos o fim da lista
		//Ao sair do la�o, atribuimos NULL ao valor que � o proximo a pa e que � o fim da lista
		pa->prox = NULL;
		free(pi); 
	}
}

void menu(){
	printf("\n======Escolha uma op��o========\n");
	printf("1 - inserir no inicio");
	printf("\n2 - inserir no fim");
	printf("\n3 - mostrar alunos");
	printf("\n4 - sair");
	printf("\n5 - pesquisar por matricula");
	printf("\n6 - inserir ap�s");
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
 //Fun��o que ordena por bubble sort
 void Bubble_sort(list *lista){
	 if(lista->inicio == NULL){
		 printf("\nA lista est� vazia\n");
	 }else
	 {
		 struct no *pi = lista->inicio; //criamos 2 indices, i e j (pi e pj) para realizar a ordena��o
		 struct	no *pj = lista->inicio;
		 struct no *pfim = NULL; //Sinaliza o fim da lista
		 for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox){
			 for (pj = lista->inicio; pj->prox != pfim; pj = pj->prox){
				//Caso o valor de pj atual seja maior que o proximo valor de pj (valor da matricula) realizamos uma troca
				 if(pj->dado.mat> pj->prox->dado.mat){
					 e temp = pj->dado; //criamos uma variavel estudante temporaria e inseridos os dados do pj atual nele
					 pj->dado = pj->prox->dado;//Depois de atribuir o valor dos dados maiores em uma variavel temporaria, pegamos os valores menores que est�o a frente e passamos para a posi��o anterior
				 	 pj->prox->dado = temp; //Agora pegamos o maior valor encontrado e passamos para a posi��o a frente que era do menor valor encontrado nesta rodada
				 }
			 }
		 }
		 	 pfim = pj; //Sinalizamos um novo fim da lista que � o maior valor que est� no final da lista
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
 
 //fun��o que verifica e retorna o tamanho da lista
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
		 //criamos um indice pi que caminhar� sobre a lista e verifica quantos n�s existem
		 struct no *pi = lista->inicio;
		 int i = 1; //Variavel contadora que inicia em 1, pois, como o inicio da lista � diferente de NULL, j� temos um elemento para contar
		 for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox){
			 i++;//Incrementa o 1 quanto encontra um valor diferente de NULL no proximo elemento apontado po pi->prox
		 }
		 return i;
	 }
	 return 0;
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

void alterar_dados(list *lista, int mat, char nome[]){
	   
	   //Utilizamos a fun��o de pesquisa para pesquisar o item a ser alterado na lista
	   struct no *pi = pesquisar(*lista, mat);
	   //Caso o valor retornado seja NULL, quer dizer que n�o encontrou-se a matricula buscada
	   if(pi==NULL){
	   	printf("\nEstudante n�o existe!\n");
	   	
	   }else
	   {	
	   		//Caso contrario, copiamos o nome inserido pelo usuario ao n� com a matricula buscada com o mesmo campo
		   strcpy(pi->dado.nome,nome);
	   }
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
		novo->dado = dado; //Atribuindo dados ao novo n� criado
		novo->prox = pi->prox ; //O novo n� aponta para o n� que est� a frente do n� que cont�m a matricula buscada
	   	pi->prox = novo;//O n� com a matricula encontrada recebe agora um novo n� para qual ele deve apontar, o dado que acabou de ser inserido e esse mesmo n� (o novo inserido) aponta para o n� que anteriormente era
		 //apontado pelo n� que cont�m a matricula buscada 
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
	
	return 0;
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