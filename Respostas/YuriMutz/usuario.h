#ifndef _USUARIO
#define _USUARIO

typedef struct Usuario Usuario;

Usuario *criaUsuario(char *nome, char *cpf, int dia, int mes, int ano, char *numTelefone, char *genero, char *area);

Usuario *lerUsuario();

int getIdadeUser(Usuario *user);

int comparaCPF(Usuario *user, char *cpf);

char *retornaUserSetor(Usuario *user);

char *getCPFUser(Usuario *user);

void atualizaNumTickets(Usuario *user);

int retornaNumTickets(Usuario *user);

char *retornaNomeUser(Usuario *user);

void desalocaUsuario(Usuario *user);

int comparaUser(const void *user1, const void *user2);

void notificaUsuario(Usuario *user);

#endif