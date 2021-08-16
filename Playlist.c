#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Playlist.h"

typedef struct celula tCelula;

struct celula {
    tMusica* musica;
    tCelula* prox;
};

struct playlist {
    tCelula* prim;
    tCelula* ult;
};

Playlist* inicializa_playlist ()
{
    Playlist* p = malloc(sizeof(Playlist));
    p->prim = NULL;
    p->ult = NULL;

    tMusica* m1 = inicializa_musica("Driver's High", "Porno Grafiti");
    tMusica* m2 = inicializa_musica("Yoasobi", "Kaibutsu");

    insere_playlist(p, m1);
    insere_playlist(p, m2);

    return p;
}

void insere_playlist (Playlist* p, tMusica* m)
{
    tCelula* nova = malloc(sizeof(tCelula));

    nova->musica = m;

    nova->prox = p->prim;

    p->prim = nova;

    if(p->ult == NULL){
        p->ult = nova;
    }
}

tMusica* retira_playlist (Playlist* p, char* chave)
{
    tCelula* aux = p->prim;
    tCelula* ant = NULL;
    tMusica* m;
    int pos = 0;

    //faz a busca
    while (aux != NULL && strcmp(get_autor_musica(aux->musica), chave)){
        ant = aux;
        aux = aux->prox;
    }

    //lista vazia ou não encontrou o aluno
    if (aux == NULL) return NULL;

    //atribui a musica de retorno
    m = aux->musica;

    //se for o único
    if (aux == p->prim && aux == p->ult) {
        p->prim = NULL;
        p->ult = NULL;
    //se for o primeiro
    } else if (aux == p->prim) {
        p->prim = aux->prox;
    //se for o último
    } else if (aux == p->ult) {
        p->ult = ant;
        ant->prox = NULL;
    //caso comum
    } else {
        ant->prox = aux->prox;
    }

    free(aux);

    return m;
}

void imprime_playlist (Playlist* p)
{
    tCelula* aux;

    for(aux = p->prim; aux != NULL; aux = aux->prox){
        imprime_musica(aux->musica);
    }
}

void destroi_playlist (Playlist* p)
{
    tCelula* x = p->prim;
    tCelula* y;

    while (x != NULL) {
        y = x->prox;
        destroi_musica(x->musica);
        free(x);
        x = y;
    }

    free(p);
}