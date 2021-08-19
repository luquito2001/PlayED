#ifndef _PESSOA_H_
#define _PESSOA_H_

#include "Playlist.h"

typedef struct pessoa tPessoa;

/*
 * inputs:
 * output:
 * pré-condição: 
 * pós-condição:
 */

/*Inicializa uma pessoa a partir dos dados presentes no arquivo de entrada
 * inputs: nome
 * output: ponteiro para uma pessoa inicializada
 * pré-condição: arquivo de entrada válido
 * pós-condição: pessoa de retorno existe e está devidamente preenchida
 */
tPessoa* inicializa_pessoa (char* n);

/*Retorna uma string que representa o nome da pessoa
 * inputs: pessoa p
 * output: nome da pessoa
 * pré-condição: pessoa p existe e possui o campo nome preenchido
 * pós-condição: p não é modificada
 */
char* get_nome_pessoa (tPessoa* p);

Playlist* get_playlist_pessoa (tPessoa* p);

/*Imprime as informações da pessoa
 * inputs: pessoa p
 * output: nenhum
 * pré-condição: pessoa p existe
 * pós-condição: nenhuma
 */
void imprime_pessoa (tPessoa* p);

/*Libera a memória alocada para a pessoa
 * inputs: pessoa p
 * output: nenhum
 * pré-condição: pessoa p existe
 * pós-condição: TODA(!?) a memória alocada para a pessoa foi liberada
 */
void destroi_pessoa (tPessoa* p);

#endif
