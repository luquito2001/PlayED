#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"

struct pessoa {
    char* nome;
    Playlist* playlists;
};

tPessoa* inicializa_pessoa (char* n)
{
    tPessoa* p = malloc (sizeof(tPessoa));

    p->nome = strdup(n);
    //playlists
}

char* get_nome_pessoa (tPessoa* p)
{
    return p->nome;
}

Playlist* get_playlist_pessoa (tPessoa* p)
{
    //playlists
}

void imprime_pessoa (tPessoa* p)
{
    printf("nome: %s\n", p->nome);
    //playlists
}

void destroi_pessoa (tPessoa* p)
{
    free(p->nome);
    //free playlists
    free(p);
}