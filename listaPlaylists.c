#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "listaPlaylists.h"

typedef struct celula tCelula;

struct celula {
    tCelula* tListaPlaylists;
    tCelula* prox;
};

struct listaPlaylists {
    tCelula* prim;
    tCelula* ult;
};