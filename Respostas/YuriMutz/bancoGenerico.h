#ifndef _BANCOTECGEN
#define _BANCOTECGEN

#include "tecnico.h"
#include "usuario.h"

/**
 * Estrutura de um Ticket contendo os parametros comuns entre todos os tipos de Tickets e um tipo genérico.
 */
typedef struct bancoGen bancoGen;

typedef void (*func_notifica)(void *dado);

typedef void (*func_desaloca)(void *dado);

bancoGen *criaBanco(char tipo, func_notifica notifica, func_desaloca desaloca);

void adicionaAtorBanco(bancoGen *banco, void *tec);

int getSize(bancoGen *banco);

int getMediaIdade(bancoGen *banco);

int getMediaTempTrab(bancoGen *banco);

void *retornaAtorBanco(bancoGen *banco, int i);

void *retornaAtorPeloCPF(bancoGen *banco, char *cpf);

void notificaRanking(bancoGen *banco);

void atualizaSequencia(bancoGen *banco, int indice);

int verificaAtorCadastrado(bancoGen *banco, char *cpf);

char *retornaSetorDoUsuario(bancoGen *banco, char *cpf);

void desalocaBanco(bancoGen *banco);

void notificaBanco(bancoGen *banco);

void printaRanking(bancoGen *banco);

#endif