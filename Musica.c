#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Musica.h"

struct musica {
    char* autor;
    char* descricao;
};

tMusica* inicializa_musica (char* a, char* d)
{
    tMusica* m = malloc (sizeof(tMusica));

    m->autor = strdup(a);
    m->descricao = strdup(d);

    return m;

    /*
    ler dados de entrada para preencher

    m->autor
    m->descricao
    */
}

char* get_autor_musica (tMusica* m) {
    return m->autor;
}

char* get_descricao_musica (tMusica* m) {
    return m->descricao;
}

void imprime_musica (tMusica* m)
{
    printf("autor: %s\n", get_autor_musica(m));
    printf("descricao: %s\n", get_descricao_musica(m));
    printf("\n");
}

void destroi_musica (tMusica* m) {
    free(m->autor);
    free(m->descricao);
    free(m);
}

char* copia_string (char* destino, char* origem, int tam)
{
    destino = malloc (tam*sizeof(char));

    for(int i=0; i<tam; i++) {
        destino[i] = origem[i];
    }

    return destino;
}

char* zera_string (char* str)
{
    int tam = strlen(str);

    for (int i=0; i<tam; i++) {
        str[i] == '\0';
    }

    return str;
}