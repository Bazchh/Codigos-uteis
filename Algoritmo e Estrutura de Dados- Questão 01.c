// Algoritmo e Estrutura de Dados- Prof. Patrick Terrematte
// Aluna: Neilla Maria de Souza Bezerra 2021011118
// Questão 01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct pilha {
   int qnt;
   int dados[MAX];

} Pilha;

Pilha* cria() {
  Pilha *p = malloc(sizeof(Pilha));
  if (p != NULL) p->qnt = 0;
 return p;

}
// inserir valor para inversão
void insere(Pilha *p, int valor) {
  p->dados[p->qnt] = valor;
  p->qnt++;

}
// exibir valor
void exibe(Pilha *p) {
 int i;
 for ( i = 0; i < p->qnt; i++) printf("%3d", p->dados[i]);

}
// fazer inversão
   Pilha* inverte(Pilha *p) {
   Pilha *outra = cria();
  while (p->qnt > 0) {

   outra->dados[outra->qnt] = p->dados[p->qnt - 1];
  p->qnt--;
 outra->qnt++;
}
 return outra;

}

int main() {
  Pilha *p = cria();
 insere(p, 32);
 insere(p, 45);
 insere(p, 78);
 exibe(p);
   p = inverte(p);
   printf("\n"); 
   exibe(p);

   return 0;
}