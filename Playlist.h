#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_

#include "Musica.h"

//tipo playlist (lista de músicas)
typedef struct playlist Playlist;

/*
 * inputs:
 * output:
 * pré-condição: 
 * pós-condição:
 */

/*Inicializa uma lista encadeada com sentinela
 * inputs: nenhum
 * output: ponteiro para a lista inicializada
 * pre-condicao: nenhuma
 * pos-condicao: lista de retorno existe
 */
Playlist* inicializa_playlist (FILE* arquivo);

Playlist* inicializa_playlist2 ();

/*Insere uma música na playlist (lista encadeada com sentinela)
 * inputs: playlist p, musica m
 * output: nenhum
 * pré-condição: playlist p e musica m existem
 * pós-condição: a música m é inserida na playlist p
 */
void insere_playlist (Playlist* p, tMusica* m);

/*Retira uma música da playlist
 * inputs: playlist p, autor da música a ser retirada
 * output: música m, cujo autor é igual a string chave
 * pré-condição: playlist p existe
 * pós-condição: a primeira música com o autor usado como chave é retirada da playlist
 */
tMusica* retira_playlist (Playlist* p, char* chave);

/*Imprime a playlist de música(s) no seguinte formato
    autor: ...
    descricao: ...
 * inputs: playlist p
 * output: nenhum
 * pré-condição: playlist p existe
 * pós-condição: nenhuma
 */
void imprime_playlist (Playlist* p);

/*Libera a memória alocada para a playlist
 * inputs: playlist p
 * output: nenhum
 * pré-condição: playlist p existe
 * pós-condição: TODA(!?) a memória alocada para a playlist foi liberada
 */
void destroi_playlist (Playlist* p);

#endif