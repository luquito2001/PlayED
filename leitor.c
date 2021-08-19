#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"

int main ()
{
    FILE* arquivo;

    arquivo = fopen("nacional.txt", "r");
    
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

        //zerando as variáveis auxiliares
        i=0;
        j=0;
    }
    
    fclose(arquivo);

    return 0;
}