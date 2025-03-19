#include "bancoGenerico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//typedef struct bancoGen bancoGen;

struct bancoGen{

    void **dado;
    void **seq;
    int tamAtual;
    int tamMax;
    char tipo;
    func_notifica notifica;
    func_desaloca desaloca;

};

bancoGen *criaBanco(char tipo, func_notifica notifica, func_desaloca desaloca){

    bancoGen *banco = malloc(sizeof(bancoGen));
    
    banco->tamMax = 10;

    banco->tamAtual = 0;

    banco->dado = malloc(banco->tamMax * sizeof(void*));

    banco->seq = malloc(banco->tamMax * sizeof(void*));

    banco->notifica = notifica;

    banco->desaloca = desaloca;

    banco->tipo = tipo;

    return banco;

}

void adicionaAtorBanco(bancoGen *banco, void *ator){

    if(banco->tamAtual == banco->tamMax){

        banco->tamMax = banco->tamMax * 2;

        banco->dado = realloc(banco->dado, banco->tamMax * sizeof(void*));

        banco->seq = realloc(banco->dado, banco->tamMax * sizeof(void*));

    }

    banco->dado[banco->tamAtual] = ator;

    banco->seq[banco->tamAtual] = ator;

    banco->tamAtual++;

}

int getSize(bancoGen *banco){

    return banco->tamAtual;

}

int getMediaIdade(bancoGen *banco){

    int idadeTotal = 0;

    for(int i = 0; i < banco->tamAtual; i++){

        if(banco->tipo == 'T'){

            idadeTotal += getIdadetec(banco->dado[i]);

        } else {

            idadeTotal += getIdadeUser(banco->dado[i]);

        }
        
    }

    float media = 0;

    media = ((float)idadeTotal / (float)banco->tamAtual);

    int a = trunc(media);

    return a;

}

int getMediaTempTrab(bancoGen *banco){

    int tempTotal = 0;

    for(int i = 0; i < banco->tamAtual; i++){

        tempTotal += getTempoTrabTec(banco->dado[i]);

    }

    int media = tempTotal / banco->tamAtual;

    return media;

}

void *retornaAtorBanco(bancoGen *banco, int i){

    return banco->dado[i];

}

void *retornaAtorPeloCPF(bancoGen *banco, char *cpf){

    for(int i = 0; i < banco->tamAtual; i++){

        if(banco->tipo == 'T'){

            for(int i=0; i < banco->tamAtual; i++){
    
                if(strcmp(getCpfTecnico(banco->dado[i]), cpf) == 0){
        
                    return banco->dado[i];
        
                }
        
            }
    
        } else if(banco->tipo == 'U'){
    
            for(int i = 0; i < banco->tamAtual; i++){
    
                if(comparaCPF(banco->dado[i], cpf)){
        
                    return banco->dado[i];
        
                }
        
            }
    
        }
    
        return 0;

    }

    return NULL;

}

void notificaRanking(bancoGen *banco){

    if(banco->tipo == 'T'){

        qsort(banco->dado, banco->tamAtual, sizeof(Tecnico*), comparaTec);

        printaRanking(banco);

    } else if(banco->tipo == 'U'){\
    
        qsort(banco->dado, banco->tamAtual, sizeof(Usuario*), comparaUser);

        printaRanking(banco);
        
    }

}

void atualizaSequencia(bancoGen *banco, int indice){

    void *tecAux;

    tecAux = banco->dado[indice];

    for(int i = indice; i < banco->tamAtual - 1; i++){

        banco->dado[i] = banco->dado[i+1];

    }

    banco->dado[banco->tamAtual - 1] = tecAux;

}

int verificaAtorCadastrado(bancoGen *banco, char *cpf){

    if(banco->tipo == 'T'){

        for(int i=0; i < banco->tamAtual; i++){

            if(strcmp(getCpfTecnico(banco->dado[i]), cpf) == 0){
    
                return 1;
    
            }
    
        }

    } else if(banco->tipo == 'U'){

        for(int i = 0; i < banco->tamAtual; i++){

            if(comparaCPF(banco->dado[i], cpf)){
    
                return 1;
    
            }
    
        }

    }

    return 0;

}

char *retornaSetorDoUsuario(bancoGen *banco, char *cpf){

    for(int i = 0; i < banco->tamAtual; i++){

        if(comparaCPF(banco->dado[i], cpf)){

            return retornaUserSetor(banco->dado[i]);

        }

    }

    return NULL;

}

void desalocaBanco(bancoGen *banco){

    for(int i = 0; i < banco->tamAtual; i++){

        banco->desaloca(banco->dado[i]);

    }

    free(banco->seq);

    free(banco->dado);

    free(banco);

}

void notificaBanco(bancoGen *banco){

    for(int i = 0; i < banco->tamAtual; i++){

        banco->notifica(banco->seq[i]);

    }

}

void printaRanking(bancoGen *banco){

    for(int i = 0; i < banco->tamAtual; i++){

        banco->notifica(banco->dado[i]);

    }

}