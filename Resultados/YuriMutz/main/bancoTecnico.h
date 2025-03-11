#ifndef _BANCOTEC
#define _BANCOTEC

#include "tecnico.h"

/**
 * Estrutura de um Ticket contendo os parametros comuns entre todos os tipos de Tickets e um tipo genérico.
 */
typedef struct bancoTec bancoTec;

bancoTec *criaBancoTecnico();

void adicionaTecBanco(bancoTec *banco, void *tec);

int getQtdTecBanco(bancoTec *banco);

int getMediaIdadeTec(bancoTec *banco);

int getMediaTempTrabBanco(bancoTec *banco);

Tecnico *retornaTecBanco(bancoTec *banco, int i);

void notificaRankingTec(bancoTec *banco);

void atualizaSequenciaTec(bancoTec *banco, int indice);

int verificaTecCadastrado(bancoTec *banco, char *cpf);

void desalocaBancoTecnico(bancoTec *banco);

void notificaBancoTecnico(bancoTec *banco);


#endif