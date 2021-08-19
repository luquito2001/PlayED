#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"

struct pessoa {
    char* nome;
    Playlist** playlists;
};

tPessoa* inicializa_pessoa (char* n)
{
    FILE* arquivo;

    arquivo = fopen("eletrica.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo!\n");
        exit(1);
    }

    tPessoa* p = malloc (sizeof(tPessoa));

    p->nome = strdup(n);
    p->playlists = malloc (sizeof(Playlist*));

    p->playlists[0] = inicializa_playlist(arquivo);

    p->playlists[1] = inicializa_playlist2();

    fclose(arquivo);

    return p;
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
    printf("nome: %s\n\n", get_nome_pessoa(p));

    //i < numero no arquivo de entrada    
    for(int i=0; i<2; i++) {
        printf("Playlist %d\n\n", i);
        imprime_playlist(p->playlists[i]);
    }
    
}

void destroi_pessoa (tPessoa* p)
{
    free(p->nome);
    //free playlists
    free(p);
}