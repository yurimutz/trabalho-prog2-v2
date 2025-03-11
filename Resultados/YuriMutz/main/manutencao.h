

#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

#define MAX_TAM_NOME_MAN 100
#define MAX_TAM_ESTADO 25
#define MAX_LOCAL 100

#define TEMPO_ESTIMADO_RH 2
#define TEMPO_ESTIMADO_FINANCEIRO 3
#define TEMPO_ESTIMADO_PD 1
#define TEMPO_ESTIMADO_VENDAS 1
#define TEMPO_ESTIMADO_MKT 1

/**
 * Estrutura de um Ticket Software contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
typedef struct Manutencao Manutencao;

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Manutencao *criaManutencao(char *nome, char *estado, char *local);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Manutencao *lerManutencao();

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoManutencao(Manutencao *s, char *area);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Software
 */
char getTipoManutencao();

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaManutencao(void *s);

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaManutencao(void *dado);

#endif