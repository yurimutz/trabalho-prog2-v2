#include "fila.h"
#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Fila Fila;

struct Fila{

    Ticket **dado;
    int tamAtual;
    int tamMax;

};

/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila(){

    Fila *fila = malloc(sizeof(Fila));

    fila->tamAtual = 0;

    fila->tamMax = 10;

    fila->dado = malloc(fila->tamMax * sizeof(Ticket*));

    return fila;

}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
void desalocaFila(Fila *f){

    for(int i = 0; i < f->tamAtual; i++){

        desalocaTicket(f->dado[i]);

    }

    free(f->dado);

    free(f);

}

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                      func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){

    Ticket *aux = criaTicket(cpfSol, dado, getTempo,
        getTipo, notifica, desaloca);

    char tickAux[50] = "Tick-";

    char indiceAux[50];

    sprintf(indiceAux, "%d", f->tamAtual+1);

    strcat(tickAux, indiceAux);

    setIDTicket(aux, tickAux);

    if(f->tamAtual == f->tamMax){

        f->tamMax = f->tamMax * 2;

        f->dado = realloc(f->dado, f->tamMax * sizeof(void*));

        f->dado[f->tamAtual] = aux;

    } else {

        f->dado[f->tamAtual] = aux;;

    }

    f->tamAtual++;

}

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f){

    return f->tamAtual;

}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status){

    int contador = 0;

    for(int i = 0; i < f->tamAtual; i++){

        if(getStatusTicket(f->dado[i]) == status){

            contador++;

        }

    }

    return contador;

}

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i){

    return f->dado[i];

}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f){

    for(int i = 0; i < f->tamAtual; i++){

        notificaTicket(f->dado[i]);

    }

}