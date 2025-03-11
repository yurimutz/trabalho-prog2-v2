#include "bancoTecnico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 //typedef struct bancoTec bancoTec;

struct bancoTec{

    void **dado;
    void **seq;
    int tamMax;
    int tamAtual;

};

bancoTec *criaBancoTecnico(){

    bancoTec *banco = malloc(sizeof(bancoTec));
    
    banco->tamMax = 10;

    banco->tamAtual = 0;

    banco->dado = malloc(banco->tamMax * sizeof(Tecnico*));

    banco->seq = malloc(banco->tamMax * sizeof(Tecnico*));

    return banco;

}

void adicionaTecBanco(bancoTec *banco, void *tec){

    if(banco->tamAtual == banco->tamMax){

        banco->tamMax = banco->tamMax * 2;

        banco->dado = realloc(banco->dado, banco->tamMax * sizeof(Tecnico*));

        banco->seq = realloc(banco->dado, banco->tamMax * sizeof(Tecnico*));

    }

    banco->dado[banco->tamAtual] = tec;

    banco->seq[banco->tamAtual] = tec;

    banco->tamAtual++;

}

int getQtdTecBanco(bancoTec *banco){

    return banco->tamAtual;

}

int getMediaIdadeTec(bancoTec *banco){

    int idadeTotal = 0;

    for(int i = 0; i < banco->tamAtual; i++){

        idadeTotal += getIdadetec(banco->dado[i]);
        
    }

    float media = 0;

    media = ((float)idadeTotal / (float)banco->tamAtual);

    int a = trunc(media);

    return a;

}

int getMediaTempTrabBanco(bancoTec *banco){

    int tempTotal = 0;

    for(int i = 0; i < banco->tamAtual; i++){

        tempTotal += getTempoTrabTec(banco->dado[i]);

    }

    

    int media = tempTotal / banco->tamAtual;

    //printf("%d %d\n", media, tempTotal);

    return media;

}

Tecnico *retornaTecBanco(bancoTec *banco, int i){

    return banco->dado[i];

}

void notificaRankingTec(bancoTec *banco){

    Tecnico *tecAux;

    for(int i = 0; i < banco->tamAtual; i++){

        for(int j = 0; j < banco->tamAtual-1; j++){

            if(getTempoTrabTec(banco->seq[j]) < getTempoTrabTec(banco->seq[j+1])){

                tecAux = banco->seq[j];
                banco->seq[j] = banco->seq[j+1];
                banco->seq[j+1] = tecAux;

            } else if(getTempoTrabTec(banco->seq[j]) == getTempoTrabTec(banco->seq[j+1])){

                if(strcmp(getNomeTec(banco->seq[j]), getNomeTec(banco->seq[j+1])) > 0){

                    tecAux = banco->seq[j];
                    banco->seq[j] = banco->seq[j+1];
                    banco->seq[j+1] = tecAux;

                }

            }

        }

    }

    notificaBancoTecnico(banco);

}

void atualizaSequenciaTec(bancoTec *banco, int indice){

    Tecnico *tecAux;

    tecAux = banco->dado[indice];

    for(int i = indice; i < banco->tamAtual - 1; i++){

        banco->dado[i] = banco->dado[i+1];

    }

    banco->dado[banco->tamAtual - 1] = tecAux;

}

int verificaTecCadastrado(bancoTec *banco, char *cpf){

    for(int i=0; i < banco->tamAtual; i++){

        if(strcmp(getCpfTecnico(banco->dado[i]), cpf) == 0){

            return 1;

        }

    }

    return 0;

}

void desalocaBancoTecnico(bancoTec *banco){

    for(int i = 0; i < banco->tamAtual; i++){

        desalocaTecnico(banco->dado[i]);

    }

    free(banco->seq);

    free(banco->dado);

    free(banco);

}

void notificaBancoTecnico(bancoTec *banco){

    for(int i = 0; i < banco->tamAtual; i++){

        notificaTecnico(banco->seq[i]);

    }

}