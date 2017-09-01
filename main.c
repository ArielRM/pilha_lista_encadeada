#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {
	int x[] = {5,10,33,60};
	pilha_t *pilha = cria_pilha();

	push(&x[0],pilha);

	push(&x[1],pilha);

	push(&x[2],pilha);

	push(&x[3],pilha);

	int y = *(int*)pop(pilha);
	printf("main: pop() ---> %d\n", y);

	y = *(int*)pop(pilha);
	printf("main: pop() ---> %d\n", y);

	y = *(int*)pop(pilha);
	printf("main: pop() ---> %d\n", y);

	y = *(int*)pop(pilha);
	printf("main: pop() ---> %d\n", y);

	free(pilha);

	return 0;
}
