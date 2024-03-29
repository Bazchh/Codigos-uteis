#include "cidade.cpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024 //Tamanho para de posições da tabela hash

/* Neste codigo estou usando o conceito de tabela Hash aprendido em estrututras de dados II, onde usando um calculo do Hash inserimos em uma tabela 
algumas cidade com base em sua key*/

typedef dataItem *hash[SIZE]; //Definindo "apelido" para a struct que armazena a key, a cidade e as coordenas com struct "gps"

void init(hash &H) {   //Função que inicia uma tabela hash e esvazia as posições da tabela
    for (int i = 0; i < SIZE; i++) {
        H[i] = 0;
    }
}
int inserir(hash H, dataItem *d, int (*funcHash)(dataItem *)) { //função que retorna um inteiro e recebe uma tabela hash, uma tipo "dataItem"
// e uma função do tipo inteiro que tem como parametro do tipo "dataItem" usada para escolher a posição (exemplos: metodo da multiplicação e da divisão)
    int key = funcHash(d); //A key recebe o valor do resultado da função que foi passada
    dataItem *copy = (dataItem*)malloc(sizeof(dataItem)); //Criamos e alocamos esáço para uma variavel auxiliar para copiar os dados passados por parametro para o tipo "dataItem" 
    //passado na função 
    *copy = *d; //Copiando dados para variavel auxiliar
    if (H[key] == 0) { //Caso a posição dada pelo calculo da função do metodo escolhido esteja vazia, o novo elemento é inserido na tabela hash
        H[key] = copy;
        return 0;
    }
    return -1;
}

int remover(hash H, dataItem *d, int (*funcHash)(dataItem *)) {
    int key = funcHash(d);
    if (H[key] != 0) {
        dataItem *purge = H[key];
        delete purge;
        // purge = 0;
        H[key] = 0;
        return 0;
    }
    return -1;
}

dataItem *buscar(hash H, int key, int (*funcHash)(dataItem *)){
    dataItem *res = (dataItem*)malloc(sizeof(dataItem));
    res->key = key;
    int pos = funcHash(res);
    res = H[pos];
    return res;
}

int divisao(dataItem *d) {
    return d->key % SIZE;
}

typedef unsigned long long int bigNumber;

int multiplicacao(dataItem *d) {
    bigNumber key = (bigNumber)d->key;
    key *= key;
    int digits = ceil(log2((bigNumber)540000 * 540000));
    int signif = ceil(log2(SIZE - 1));
    int remover = digits - signif;
    int digitMask = (int)ceil(float(remover) / 2);
    bigNumber mask = ((SIZE-1) << digitMask);
    key = key & mask;
    key = (key >> digitMask);
    return key;
}

int hashCodeDobra(dataItem *d) {
    return d->key % SIZE;
}

int main() {
    dataItem *d = (dataItem *)malloc(sizeof(dataItem));
    d->city.cidade = (char *)"Pau dos Ferros";
    d->city.id = 340940;
    d->city.estado = (char *)"RN";
    d->key = 340940;
    d->GPS.id = 340940;
    d->GPS.la = -6.11;
    d->GPS.lo = -38.2;

    int res = multiplicacao(d);
    hash H;
    init(H);

    inserir(H, d, divisao);

    // Não faz sentido mudar a função Hash, mas coloquei aqui para mostrar que é possível
    inserir(H, d, multiplicacao);
    remover(H, d, multiplicacao);
    inserir(H, d, multiplicacao);
    dataItem* dt = buscar(H, 340940, multiplicacao);
}
