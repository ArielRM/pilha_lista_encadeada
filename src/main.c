#include <stdio.h>
#include <stdlib.h>
#include "../include/pilha.h"
#include "../include/formula1.h"


int main(void) {
	
	pilha_t* temporadas = ler_arquivo("doc/formula1.csv");
	
	/**
		ÁREA DE OPERAÇÕES GERAIS
	**/
	
	libera_dados(temporadas);
	return 0;
}
