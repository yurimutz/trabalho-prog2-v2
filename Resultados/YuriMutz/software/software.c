#include "software.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Software Software;

struct Software{

    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    int impacto;
    char motivo[MAX_TAM_MOTIVO];
    int tempoTicket;

};

Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo){

    Software *soft = malloc(sizeof(Software));

    strcpy(soft->nome, nome);

    strcpy(soft->categoria, categoria);

    strcpy(soft->motivo , motivo);

    soft->impacto = impacto;

    soft->tempoTicket = 0;

    return soft;
}

Software *lerSoftware(){

    char nome[101];
    char categoria[15];
    int impacto;
    char motivo[201];

    scanf("%[^\n]", nome);
    scanf("%*[\n]");

    scanf("%[^\n]", categoria);
    scanf("%*[\n]");

    scanf("%d\n", &impacto);

    scanf("%[^\n]", motivo);
    scanf("%*[\n]");

    Software * soft = criaSoftware(nome, categoria, impacto, motivo);

    return soft;

}

void setTempoEstimadoSoftware(Software *s){

    if(strcmp(s->categoria, "BUG") == 0){

        s->tempoTicket = s->impacto + TEMPO_ESTIMADO_BUG;

    } else if(strcmp(s->categoria, "OUTROS") == 0){

        s->tempoTicket = s->impacto + TEMPO_ESTIMADO_OUTROS;

    } else {

        s->tempoTicket = s->impacto + TEMPO_ESTIMADO_DUVIDA;

    }

}

int getTempoEstimadoSoftware(void *dado){

    Software *soft = (Software*)dado;

    //setTempoEstimadoSoftware(soft);

    return soft->tempoTicket;

}

char getTipoSoftware(){

    return 'S';

}

void desalocaSoftware(void *s){

    Software *soft = (Software*)s;

    free(soft);

}

void notificaSoftware(void *dado){

    Software *soft = (Software*)dado;
    
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n", soft->nome);
    printf("- Categoria: %s\n", soft->categoria);
    printf("- Nível do impacto: %d\n", soft->impacto);
    printf("- Motivo: %s\n", soft->motivo);
    printf("- Tempo estimado: %dh\n", getTempoEstimadoSoftware((Software*)soft));

}
