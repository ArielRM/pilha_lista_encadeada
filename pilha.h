#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "no.h"

typedef struct pilhas pilha_t;

pilha_t * cria_pilha();
void push(void* dado, pilha_t* pilha);
void * pop(pilha_t* pilha);
void * topo(pilha_t* pilha);
int tamanho(pilha_t* pilha);
int vazia(pilha_t* pilha);


#endif //PILHA_H
