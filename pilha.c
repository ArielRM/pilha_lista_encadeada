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
	if(pilha == NULL) {
		fputs("pilha.c : ERR :: cria_pilha() sem espaço");
		exit(EXIT_FAILURE);
	}
	pilha->topo = NULL;
	pilha->tamanho = 0;
	return pilha;
}

void push(void* dado, pilha_t* pilha) {
	no_t* no = cria_no(dado);
	if(vazia(pilha) == 0)
		desliga_no(no);
	else
		liga_nos(no,pilha->topo);
	pilha->topo = no;
	pilha->tamanho++;
	printf("pilha.c : push() ---> no:%p\tdado:%p\tnovo tamanho: %d\n",no,dado,pilha->tamanho);
}

void * pop(pilha_t* pilha) {
	if(vazia(pilha) == 0) {
		fprintf(stderr,"pilha.c : ERR :: pop() em pilha vazia %d\n",vazia(pilha));
		exit(EXIT_FAILURE);
	}
	no_t* no = pilha->topo;
	pilha->topo = obtem_proximo(no);
	void* dado = obtem_dado(no);
	pilha->tamanho--;
	printf("pilha.c : pop() ---> no:%p\tdado:%p\tnovo tamanho: %d\n",no,dado,pilha->tamanho);
	free(no);
	return dado;
}

void * topo(pilha_t* pilha) {
	if(vazia(pilha) == 0) {
		fprintf(stderr,"pilha.c : ERR :: topo() em pilha vazia %d\n",vazia(pilha));
		exit(EXIT_FAILURE);
	}
	return obtem_dado(pilha->topo);
}

int tamanho(pilha_t* pilha) {
	return pilha->tamanho;
}

int vazia(pilha_t* pilha) {
	if(tamanho(pilha))
		return 1;
	else
		return 0;
}

