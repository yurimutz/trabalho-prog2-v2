#include "bancoUsuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//typedef struct bancoUser bancoUser;

struct bancoUser{

    Usuario **dado;
    int tamAtual;
    int tamMax;

};

bancoUser *criabancoUser(){

    bancoUser *banco = malloc(sizeof(bancoUser));

    banco->tamAtual = 0;

    banco->tamMax = 10;

    banco->dado = malloc(banco->tamMax * sizeof(Usuario*));

    return banco;

}

void adicionaUserBanco(bancoUser *banco, void *user){

    if(banco->tamAtual == banco->tamMax){

        banco->tamAtual = banco->tamAtual * 2;

        banco->dado = realloc(banco->dado, banco->tamMax * sizeof(Usuario*));

    }

    banco->dado[banco->tamAtual] = user;

    banco->tamAtual++;

}

int getQtdUsuariosNoBanco(bancoUser *banco){

    return banco->tamAtual;

}

int getMediaIdadeUsuarios(bancoUser *banco){

    int idadeTotal = 0;

    for(int i = 0; i < banco->tamAtual; i++){

        idadeTotal += getIdadeUser(banco->dado[i]);

    }

    int media = 0;

    media = (int)trunc((idadeTotal / banco->tamAtual));


    return media;

}

char *retornaSetorDoUsuarioBanco(bancoUser *banco, char *cpf){

    for(int i = 0; i < banco->tamAtual; i++){

        if(comparaCPF(banco->dado[i], cpf)){

            return retornaUserSetor(banco->dado[i]);

        }

    }

    return 0;

}

int verificaUserCadastrado(bancoUser *banco, char *cpf){

    for(int i = 0; i < banco->tamAtual; i++){

        if(comparaCPF(banco->dado[i], cpf)){

            return 1;

        }

    }

    return 0;

}

Usuario* retornaUserBanco(bancoUser *banco, char *cpf){

    for(int i = 0; i < banco->tamAtual; i++){

        if(comparaCPF(banco->dado[i], cpf)){

            return banco->dado[i];

        }

    }

    return NULL;

}

void notificaRankingUser(bancoUser *banco){

    Usuario *userAux ;

    for(int i = 0; i < banco->tamAtual; i++){

        for(int j = 0; j < banco->tamAtual -1; j++){

            if(retornaNumTickets(banco->dado[j]) < retornaNumTickets(banco->dado[j+1])){

                userAux = banco->dado[j];
                banco->dado[j] = banco->dado[j+1];
                banco->dado[j+1] = userAux;

            } else if(retornaNumTickets(banco->dado[j]) == retornaNumTickets(banco->dado[j+1])){

                if(strcmp(retornaNomeUser(banco->dado[j]), retornaNomeUser(banco->dado[j+1])) > 0){

                    userAux = banco->dado[j];
                    banco->dado[j] = banco->dado[j+1];
                    banco->dado[j+1] = userAux;

                }

            }

        }

    }

    notificaBancoUser(banco);

}

void desalocaBancoUser(bancoUser *banco){

    for(int i = 0; i < banco->tamAtual; i++){

        desalocaUsuario(banco->dado[i]);

    }

    free(banco->dado);

    free(banco);

}

void notificaBancoUser(bancoUser *banco){

    for(int i = 0; i < banco->tamAtual; i++){

        notificaUsuario(banco->dado[i]);

    }

}