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

Playlist* inicializa_playlist (FILE* arquivo)
{
    Playlist* p = malloc(sizeof(Playlist));
    p->prim = NULL;
    p->ult = NULL;

    for (int a=0; a<4; a++) {

        char linha[100], autor[100], descricao[100], aux[100];
        int i=0, j=0, x=0, tam1, tam2;

        //lendo o arquivo
        while (fgets(linha, sizeof(linha), arquivo)) {

            while (linha[i] != '-') {
                aux[i] = linha[i];
                i++;
            }

            //reiniciando a string autor
            for(x=0; x<100; x++) {
                autor[x] = '\0';
            }

            //atribuindo a string aux à string autor
            for(x=0; x<(i-1); x++) {
            autor[x] = aux[x];
            }

            //pulando o '-' e o ' '
            i += 2;

            //zerando a string descricao
            for(x=0; x<100; x++) {
                descricao[x] = '\0';
            }

            //preenchendo a string descricao
            while (linha[i] != '\n') {
                descricao[j] = linha[i];
                j++;
                i++;
            }

            //string autor
            tam1 = strlen(autor);
            printf("%s", autor);
            printf(" %d\n", tam1);

            //string descricao
            tam2 = strlen(descricao);
            printf("%s", descricao);
            printf(" %d\n", tam2);

            tMusica* m = inicializa_musica(autor, descricao);
            insere_playlist(p, m);

            //zerando as variáveis auxiliares
            i=0;
            j=0;
        }

        //tMusica* m = inicializa_playlist(autor, descricao);
        //insere_playlist(p, m);

    }
    /*
    tMusica* m1 = inicializa_musica("U2", "Beautiful Day");
    tMusica* m2 = inicializa_musica("Yoasobi", "Kaibutsu");

    insere_playlist(p, m1);
    insere_playlist(p, m2);
    */
    return p;
}

Playlist* inicializa_playlist2 ()
{
    Playlist* p = malloc(sizeof(Playlist));
    p->prim = NULL;
    p->ult = NULL;

    tMusica* m1 = inicializa_musica("Dire Straits", "Sultans of Swing");
    tMusica* m2 = inicializa_musica("Dio", "Holy Diver");

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