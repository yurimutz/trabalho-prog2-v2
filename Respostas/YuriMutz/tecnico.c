#include <stdio.h>
#include "tecnico.h"
#include <stdlib.h>
#include <string.h>

//typedef struct Tecnico Tecnico;

struct Tecnico{

    char nome[100];
    char cpf[15];
    int dia;
    int mes;
    int ano;
    char numTelefone[50];
    char genero[50];
    char area[50];
    int tempDisponivel;
    int tempTrabalhado;
    float salario;

};


Tecnico *criaTecnico(char *nome, char *cpf, int dia, int mes, int ano, char *numTelefone, char *genero, char *area, int temp, float salario){

    Tecnico *tec = malloc(sizeof(Tecnico));

    strcpy(tec->nome, nome);
    strcpy(tec->cpf, cpf);
    strcpy(tec->numTelefone, numTelefone);
    strcpy(tec->genero, genero);
    strcpy(tec->area, area);

    tec->dia = dia;
    tec->mes = mes;
    tec->ano = ano;

    tec->tempDisponivel = temp; 

    tec->tempTrabalhado = 0;

    tec->salario = salario;

    return tec;

}

Tecnico *lerTecnico(){

    char nome[100];
    char cpf[15];
    int dia;
    int mes;
    int ano;
    char numTelefone[50];
    char genero[50];
    char area[50];
    int tempDisponivel;
    float salario;

    scanf("%[^\n]", nome);
    scanf("%*[\n]");

    scanf("%[^\n]", cpf);
    scanf("%*[\n]");

    scanf("%d/%d/%d\n", &dia, &mes, &ano);

    scanf("%[^\n]", numTelefone);
    scanf("%*[\n]");

    scanf("%[^\n]", genero);
    scanf("%*[\n]");

    scanf("%[^\n]", area);
    scanf("%*[\n]");

    scanf("%d\n", &tempDisponivel);

    scanf("%f\n", &salario);

    Tecnico *tec =  criaTecnico(nome, cpf, dia, mes, ano, numTelefone, genero, area, tempDisponivel, salario);

    return tec;

}

int getIdadetec(Tecnico *tec){
    
    int dia = 18, mes = 2, ano = 2025;

    int idade = 0;

    idade = ano - tec->ano;

    if(mes < tec->mes){

        idade--;

    } else if(mes == tec->mes){

        if(dia < tec->dia){

            idade--;

        }

    }
    
    return idade;

}

char *getCpfTecnico(Tecnico *tec){

    return tec->cpf;

}

char *getAreaTecnico(Tecnico *tec){

    return tec->area;

}

char *getNomeTec(Tecnico *tec){

    return tec->nome;

}

int getIdadeTec(Tecnico *tec){

    int dia = 18, mes = 2, ano = 2025;

    int idade = 0;

    idade = ano - tec->ano;

    if(mes > tec->mes){

        idade++;

    } else if(mes == tec->mes){

        if(dia > tec->dia){

            idade++;

        }

    }

    return idade;

}

int getTempoTrabTec(Tecnico *tec){

    return tec->tempTrabalhado;

}

int getTempoDispTec(Tecnico *tec){

    return tec->tempDisponivel;

}

void atualizaTemposTec(Tecnico *tec, int tempo){

    tec->tempDisponivel -= tempo;

    tec->tempTrabalhado += tempo;

}

void desalocaTecnico(Tecnico *tec){

    free(tec);

}

int comparaTec(const void *tec1, const void *tec2){

    Tecnico *tec1aux = *(Tecnico**)tec1; 
    Tecnico *tec2aux = *(Tecnico**)tec2;

    //printf("oi");

    if(tec1aux->tempTrabalhado != tec2aux->tempTrabalhado){

        return tec2aux->tempTrabalhado - tec1aux->tempTrabalhado;

    } else {

        return strcmp(tec1aux->nome, tec2aux->nome);

    }

}

void notificaTecnico(Tecnico *tec){

    printf("--------------------\n");
    printf("- Nome: %s\n", tec->nome);
    printf("- CPF: %s\n", tec->cpf);
    printf("- Data de Nascimento: %d/%d/%d\n", tec->dia, tec->mes, tec->ano);
    printf("- Telefone: %s\n", tec->numTelefone);
    printf("- Genero: %s\n", tec->genero);
    printf("- Area de Atuacao: %s\n", tec->area);
    printf("- Salario: %0.2f\n", tec->salario);
    printf("- Disponibilidade: %dh\n", tec->tempDisponivel);    
    printf("- Tempo Trabalhado: %dh\n", tec->tempTrabalhado);

}