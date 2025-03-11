#include "outros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Outros Outros;

struct Outros{

    char descricao[MAX_TAM_DESCRICAO];
    char local[MAX_TAM_LOCAL];
    int dificuldade;

};

Outros *criaOutros(char *descricao, char *local, int dificuldade){

    Outros *o = malloc(sizeof(Outros));

    strcpy(o->descricao, descricao);

    strcpy(o->local, local);

    o->dificuldade = dificuldade;

    return o;

}

Outros *lerOutros(){

    char descricao[MAX_TAM_DESCRICAO];
    char local[MAX_TAM_LOCAL];
    int dificuldade;

    scanf("%[^\n]", descricao);
    scanf("%*[\n]");

    scanf("%[^\n]", local);
    scanf("%*[\n]");

    scanf("%d", &dificuldade);
    scanf("%*[\n]");

    Outros *o = criaOutros(descricao, local, dificuldade);

    return  o;

}

int getTempoEstimadoOutros(void *dado){

    Outros *aux = (Outros*)dado;

    return aux->dificuldade;

}

char getTipoOutros(){

    return 'O';

}

void desalocaOutros(void *o){

    Outros *aux = (Outros*)o;

    free(aux);

}

void notificaOutros(void *dado){

    Outros *aux = (Outros*)dado;

    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n", aux->descricao);
    printf("- Local: %s\n", aux->local);
    printf("- Nivel de Dificuldade: %d\n", aux->dificuldade);
    printf("- Tempo Estimado: %dh\n", getTempoEstimadoOutros((Outros*)aux));

}