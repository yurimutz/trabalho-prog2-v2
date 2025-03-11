#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Manutencao Manutencao;

struct Manutencao{

    char nome[MAX_TAM_NOME_MAN];
    char estado[MAX_TAM_ESTADO];
    char local[MAX_LOCAL];
    int tempoTicket;

};

Manutencao *criaManutencao(char *nome, char *estado, char *local){

    Manutencao *man = malloc(sizeof(Manutencao));

    strcpy(man->nome, nome);

    strcpy(man->estado, estado);

    strcpy(man->local, local);

    man->tempoTicket = 0;

    return man;

}

Manutencao *lerManutencao(){

    char nome[MAX_TAM_NOME_MAN];
    char estado[MAX_TAM_ESTADO];
    char local[MAX_LOCAL];

    scanf("%[^\n]", nome);
    scanf("%*[\n]");

    scanf("%[^\n]", estado);
    scanf("%*[\n]");

    scanf("%[^\n]", local);
    scanf("%*[\n]");

    Manutencao *man = criaManutencao(nome, estado, local);

    return man;

}

void setTempoEstimadoManutencao(Manutencao *m, char *area){

    int fator = 0;

    if(strcmp(area , "RH") == 0){

        fator = TEMPO_ESTIMADO_RH;

    } else if(strcmp(area , "FINANCEIRO") == 0){

        fator = TEMPO_ESTIMADO_FINANCEIRO;

    } else {

        fator = TEMPO_ESTIMADO_PD;

    }

    if(strcmp(m->estado, "RUIM") == 0){

        m->tempoTicket = fator * 3;

    } else if(strcmp(m->estado, "REGULAR") == 0){

        m->tempoTicket = fator * 2;

    } else {

        m->tempoTicket = fator * 1;

    }

}

int getTempoEstimadoManutencao(void *dado){

    Manutencao *aux = (Manutencao*)dado;

    //setTempoEstimadoManutencao(aux, area);

    return aux->tempoTicket;

}

char getTipoManutencao(){

    return 'M';

}

void desalocaManutencao(void *m){

    Manutencao *aux = (Manutencao*)m;

    free(aux);

}

void notificaManutencao(void *dado){

    Manutencao *aux = (Manutencao*)dado;

    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n", aux->nome);
    printf("- Estado de conservacao: %s\n", aux->estado);
    printf("- Local: %s\n", aux->local);
    printf("- Tempo estimado: %dh\n", getTempoEstimadoManutencao((Manutencao*)aux));

}