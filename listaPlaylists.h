#ifndef _LISTAPLAYLISTS_H_
#define _LISTAPLAYLISTS_H_

#include "Playlist.h"

typedef struct listaPlaylists tListaPlaylists;

tListaPlaylists* inicializa_lista_playlists ();

void insere_lista_playlists (tListaPlaylists* lp, Playlist* p);

#endif