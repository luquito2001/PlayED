#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_

#include "Musica.h"

//tipo playlist
typedef struct playlist Playlist;

/*
 * inputs:
 * output:
 * pré-condição: 
 * pós-condição:
 */

Playlist* inicializa_playlist ();

void insere_playlist (Playlist* p, tMusica* m);

tMusica* retira_playlist (Playlist* p, char* chave);

void imprime_playlist (Playlist* p);

void destroi_playlist (Playlist* p);

#endif