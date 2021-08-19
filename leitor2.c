#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"

int main () {
    FILE* entrada;

    entrada = fopen("playlists.txt", "r");

    if (entrada == NULL) {
        printf("Erro ao tentar abrir o arquivo!\n");
        exit(1);
    }

    char lixo[100], linha[100];
    int numPlaylists, j=0;
    char nomePlaylist[100];

    while(fgets(linha, 100, entrada) != NULL) j++;;

    rewind(entrada);

    for(int i=0; i<j; i++) {

        fscanf(entrada, "%[^;]", lixo);
        fscanf(entrada, ";%d", &numPlaylists);

        printf("%s\n", lixo);
        printf("%d\n", numPlaylists);
        //printf("%s\n", nomePlaylist);

        for(int k=0; k<numPlaylists; k++) {
            fscanf(entrada,";%[^;\n]", nomePlaylist);
            printf("%s\n", nomePlaylist);
        }

        //fscanf(entrada, "\n");

        //printf("\n");
        //fscanf(entrada, "%[^\n]", nomePlaylist);

        //printf("%s\n%d\n%s\n", lixo, numPlaylists, nomePlaylist);

        

    }






    fclose(entrada);

    return 0;
}