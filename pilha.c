#include "no.h"
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

struct pilhas {
	no_t* topo;
	int tamanho;
};

pilha_t * cria_pilha() {
	pilha_t* pilha = (pilha_t*) malloc(sizeof(pilha_t));
	pilha->topo = NULL;
	pilha->tamanho = 0;
	return pilha;
}

void push(void* dado, pilha_t* pilha) {
	no_t* no = cria_no(dado);
	liga_nos(no,pilha->topo);
	pilha->topo = no;
	pilha->tamanho++;
	printf("pilha.c : push() ---> novo tamanho: %d\n",pilha->tamanho);
}

void * pop(pilha_t* pilha) {
	if(vazia(pilha)) {
		fprintf(stderr,"pilha.c : ERR :: pop() em pilha vazia\n");
		exit(EXIT_FAILURE);
	}
	no_t* no = pilha->topo;
	pilha->topo = obtem_proximo(no);
	void* dado = obtem_dado(no);
	pilha->tamanho--;
	free(no);
	printf("pilha.c : pop() ---> novo tamanho: %d\n",pilha->tamanho);
	return dado;
}

void * topo(pilha_t* pilha) {
	if(vazia(pilha)) {
		fprintf(stderr,"pilha.c : ERR :: topo() em pilha vazia\n");
		exit(EXIT_FAILURE);
	}
	return obtem_dado(pilha->topo);
}

int tamanho(pilha_t* pilha) {
	return pilha->tamanho;
}

int vazia(pilha_t* pilha) {
	return pilha->tamanho > 0 ? 1 : 0;
}

