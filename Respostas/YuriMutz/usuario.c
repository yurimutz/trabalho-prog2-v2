#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Usuario Usuario;

struct Usuario{

    char nome[100];
    char cpf[15];
    int dia;
    int mes;
    int ano;
    char numTelefone[50];
    char genero[50];
    char setor[50];
    int numTickets;

};

Usuario *criaUsuario(char *nome, char *cpf, int dia, int mes, int ano, char *numTelefone, char *genero, char *setor){

    Usuario *user = malloc(sizeof(Usuario));

    strcpy(user->nome, nome);
    strcpy(user->cpf, cpf);
    strcpy(user->numTelefone, numTelefone);
    strcpy(user->genero, genero);
    strcpy(user->setor, setor);

    user->dia = dia;
    user->mes = mes;
    user->ano = ano;

    user->numTickets = 0;

    return user;

}

Usuario *lerUsuario(){

    char nome[100];
    char cpf[15];
    int dia;
    int mes;
    int ano;
    char numTelefone[50];
    char genero[50];
    char setor[50];

    scanf("%[^\n]", nome);
    scanf("%*[\n]");

    scanf("%[^\n]", cpf);
    scanf("%*[\n]");

    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    scanf("%[^\n]", numTelefone);
    scanf("%*[\n]");

    scanf("%[^\n]", genero);
    scanf("%*[\n]");

    scanf("%[^\n]", setor);
    scanf("%*[\n]");

    Usuario *user = criaUsuario(nome, cpf, dia, mes, ano, numTelefone, genero, setor);

    return user;

}

int getIdadeUser(Usuario *user){

    int dia = 18, mes = 2, ano = 2025;

    int idade = 0;

    idade = ano - user->ano;

    if(mes < user->mes){

        idade--;

    } else if(mes == user->mes){

        if(dia < user->dia){

            idade--;

        }

    }

    return idade;

}

int comparaCPF(Usuario *user, char *cpf){

    if(strcmp(user->cpf, cpf) == 0){

        return 1;

    } else {

        return 0;

    }

}

char *retornaUserSetor(Usuario *user){

    return user->setor;

}

char *getCPFUser(Usuario *user){

    return user->cpf;

}

void atualizaNumTickets(Usuario *user){

    user->numTickets += 1;

}

int retornaNumTickets(Usuario *user){

    return user->numTickets;

}

char *retornaNomeUser(Usuario *user){

    return user->nome;

}

void desalocaUsuario(Usuario *user){

    free(user);

}

int comparaUser(const void *user1, const void *user2){

    Usuario *user1aux = *(Usuario**)user1; 
    Usuario *user2aux = *(Usuario**)user2;

    if(user1aux->numTickets != user2aux->numTickets){

        return user2aux->numTickets - user1aux->numTickets;

    } else {

        return strcmp(user1aux->nome, user2aux->nome);

    }

}

void notificaUsuario(Usuario *user){

    printf("--------------------\n");
    printf("- Nome: %s\n", user->nome);
    printf("- CPF: %s\n", user->cpf);
    printf("- Data de Nascimento: %d/%d/%d\n", user->dia, user->mes, user->ano);
    printf("- Telefone: %s\n", user->numTelefone);
    printf("- Genero: %s\n", user->genero);
    printf("- Setor: %s\n", user->setor);
    printf("- Tickets solicitados: %d\n", user->numTickets);

}