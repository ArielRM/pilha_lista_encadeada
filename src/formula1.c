#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/formula1.h"
#include "../include/pilha.h"

#define TAM_BUFFER 1000

struct temporada {
	short ano;
	char* pais;
	char* piloto;
	short idade;
	int numero;
	char* equipe;
	char* motor; //?
	char* pneus;
	int poles;
	short vitorias;
	short podiums;
	int voltas_mais_rapidas;
	float pontos;
	char* encerradas;
	char* corrida;
	float PM;
};

pilha_t * ler_arquivo(char *nome) {
	char buffer[TAM_BUFFER];
	
	FILE* arquivo = fopen(nome,"r");
	if(arquivo == NULL) {
		perror("formula1.c :: ler_arquivo()");
		exit(EXIT_FAILURE);
	}
	
	//Ignora o cabeçalho
	fgets(buffer,TAM_BUFFER,arquivo);
	
	//Cria pilha
	pilha_t* pilha = cria_pilha();
	//Empilha
#ifdef DEBUG
printf("\n\nEmpilhando\n");
#endif
	while(fgets(buffer,TAM_BUFFER,arquivo)) {
		temporada_t* temp = novaTemporada(buffer);
		push(temp,pilha);
	}
	//Não precisamos mais do arquivo
	fclose(arquivo);
	return(pilha);
}

void libera_dados(pilha_t* pilha) {
	if(pilha == NULL) {
		fprintf(stderr,"formula1 :: libera_dados: ponteiro inválido!\n");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
printf("\n\nDesalocando espaço da memória\n");
#endif
	while(!vazia(pilha)) {
		temporada_t* t = pop(pilha);
		free(obtemPais(t));
		free(obtemPiloto(t));
		free(obtemEquipe(t));
		free(obtemMotor(t));
		free(obtemPneus(t));
		free(obtemEncerradas(t));
		free(obtemCorrida(t));
		free(t);
	}
	free(pilha);
}
	

temporada_t * novaTemporada(char* record) {
    temporada_t* temp = (temporada_t*) malloc(sizeof(temporada_t));
    if(temp == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp");
        exit(EXIT_FAILURE);
    }

    char pais[TAM_BUFFER];
	char piloto[TAM_BUFFER];
	char equipe[TAM_BUFFER];
	char motor[TAM_BUFFER];
	char pneus[TAM_BUFFER];
    char encerradas[TAM_BUFFER];
    char corrida[TAM_BUFFER];

    int hold = sscanf(record,"%hd;%1000[^;];%1000[^;];%hd;%d;%1000[^;];%1000[^;];%1000[^;];%d;%hd;%hd;%d;%f;%1000[^;];%1000[^;];%f",
           &temp->ano,pais,piloto,&temp->idade,&temp->numero,equipe,motor,pneus,&temp->poles,&temp->vitorias,&temp->podiums,
           &temp->voltas_mais_rapidas,&temp->pontos,encerradas,corrida,&temp->PM);
    if(hold != 16){
        fprintf(stderr,"Arquivo inválido em:\n>>%s<<",record);
        exit(EXIT_FAILURE);
    }

    temp->pais = (char*) malloc(strlen(pais) + 1);
    if(temp->pais == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp->pais");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->pais,pais,strlen(pais)+1);

    temp->piloto = (char*) malloc(strlen(piloto) + 1);
    if(temp->piloto == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp->piloto");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->piloto,piloto,strlen(piloto)+1);

    temp->equipe = (char*) malloc(strlen(equipe) + 1);
    if(temp->equipe == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp->equipe");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->equipe,equipe,strlen(equipe)+1);

    temp->motor = (char*) malloc(strlen(motor) + 1);
    if(temp->motor == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp->motor");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->motor,motor,strlen(motor)+1);


    temp->pneus = (char*) malloc(strlen(pneus) + 1);
    if(temp->pneus == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp->pneus");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->pneus,pneus,strlen(pneus)+1);

    temp->encerradas= (char*) malloc(strlen(encerradas) + 1);
    if(temp->encerradas == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp->encerradas");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->encerradas,encerradas,strlen(encerradas)+1);

    temp->corrida= (char*) malloc(strlen(corrida) + 1);
    if(temp->corrida == NULL) {
        perror("novaTemp: Erro ao alocar memória para temp->corrida");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->corrida,corrida,strlen(corrida)+1);

    return temp;
}

char * obtemPais(temporada_t *temp) {
    return temp->pais;
}
char * obtemPiloto(temporada_t *temp) {
    return temp->piloto;
}
char * obtemEquipe(temporada_t *temp) {
    return temp->equipe;
}
char * obtemMotor(temporada_t *temp) {
    return temp->motor;
}
char * obtemPneus(temporada_t *temp) {
    return temp->pneus;
}
char * obtemEncerradas(temporada_t *temp) {
    return temp->encerradas;
}
char * obtemCorrida(temporada_t *temp) {
    return temp->corrida;
}


void printTemporada(temporada_t *temp) {
    printf("Ano: %hd\n\
Pais: %s\n\
Piloto: %s\n\
Idade: %hd\n\
Num. Car.: %d\n\
Equipe: %s\n\
Motor: %s\n\
Pneus: %s\n\
Poles: %d\n\
Volt. Mais Rapidas: %d\n\
Pontos: %.1f\n\
Encerradas: %s\n\
Point Margin: %.2f\n",
           temp->ano,temp->pais,temp->piloto,temp->idade,temp->numero,temp->equipe,temp->motor,temp->pneus,temp->poles,
           temp->voltas_mais_rapidas,temp->pontos,temp->encerradas,temp->PM);
}
