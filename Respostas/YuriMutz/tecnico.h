#ifndef _TECNICO
#define _TECNICO

typedef struct Tecnico Tecnico;

Tecnico *criaTecnico(char *nome, char *cpf, int dia, int mes, int ano, char *numTelefone, char *genero, char *area, int temp, float salario);

Tecnico *lerTecnico();

char *getCpfTecnico(Tecnico *tec);

char *getAreaTecnico(Tecnico *tec);

char *getNomeTec(Tecnico *tec);

int getIdadetec(Tecnico *tec);

int getTempoTrabTec(Tecnico *tec);

int getTempoDispTec(Tecnico *tec);

void atualizaTemposTec(Tecnico *tec, int tempo);

void desalocaTecnico(Tecnico *tec);

int comparaTec(const void *tec1, const void *tec2);

void notificaTecnico(Tecnico *tec);

#endif