#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Pessoa.h"

int main ()
{
    /*
    FILE* arquivo;

    arquivo = fopen("eletrica.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao tentar abrir o arquivo!\n");
        exit(1);
    }
    */
    
    printf("\n");

    //Playlist* p = inicializa_playlist();

    tPessoa* pessoa = inicializa_pessoa("Lucas");

    imprime_pessoa(pessoa);

    //imprime_pessoa(pessoa);

    //imprime_playlist(p);

    //tMusica* mus = retira_playlist(p, "Yoasobi");
    //destroi_musica(mus);

    //printf("2.0\n");

    //imprime_playlist(p);

    //destroi_playlist(p);

    //fclose(arquivo);
    
    return 0;
}