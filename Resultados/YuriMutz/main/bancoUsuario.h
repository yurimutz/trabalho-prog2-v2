#ifndef _BANCOUSER
#define _BANCOUSER

#include "usuario.h"

typedef struct bancoUser bancoUser;

bancoUser *criabancoUser();

void adicionaUserBanco(bancoUser *banco, void *user);

int getQtdUsuariosNoBanco(bancoUser *banco);

int getMediaIdadeUsuarios(bancoUser *banco);

char *retornaSetorDoUsuarioBanco(bancoUser *banco, char *cpf);

int verificaUserCadastrado(bancoUser *banco, char *cpf);

Usuario* retornaUserBanco(bancoUser *banco, char *cpf);

void notificaRankingUser(bancoUser *banco);

void desalocaBancoUser(bancoUser *banco);

void notificaBancoUser(bancoUser *banco);


#endif