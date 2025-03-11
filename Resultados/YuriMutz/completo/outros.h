#ifndef _OUTROS_H
#define _OUTROS_H

#define MAX_TAM_DESCRICAO 500
#define MAX_TAM_LOCAL 25

/**
 * Estrutura de um Ticket Software contendo os parametros especificos de um ticket do tipo SOFTWARE
 */
typedef struct Outros Outros;

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Outros *criaOutros(char *descricao, char *local, int dificuldade);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Outros *lerOutros();

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoOutros(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'O' para Software
 */
char getTipoOutros();

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaOutros(void *s);

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaOutros(void *dado);

#endif