#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Playlist.h"

int main ()
{
    Playlist* p = inicializa_playlist();

    imprime_playlist(p);

    tMusica* mus = retira_playlist(p, "Yoasobi");
    destroi_musica(mus);

    printf("2.0\n");

    imprime_playlist(p);

    destroi_playlist(p);
    
    return 0;
}