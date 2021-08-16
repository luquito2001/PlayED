#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Playlist.h"

int main ()
{
    FILE* pont_arq;
    FILE* arquivo;
    char texto_str[20];
  
    //abrindo o arquivo_frase em modo "somente leitura"
    pont_arq = fopen("nacional.txt", "r");

    char c, str[100], str2[100];
    char* autor;
    char* descricao;
    int i=0, j=0, k=0, x=0, espaco=0;

    do {  
      c = fgetc(pont_arq);

      if(c == '-') {
          autor = copia_string(autor, str, (i-1));

          do {
              c = fgetc(pont_arq);

              if (c == ' ') {
                  espaco++;
                  if(espaco > 1){
                      str[j] = c;
                      j++;
                  }
              } else if(c == '\n') {
                descricao = copia_string(descricao, str, j);
                x++;
                espaco=0;

                /*
                k = strlen(autor);
                printf("%s ", autor);
                printf("%d\n", k);

                k = strlen(descricao);
                printf("%s ", descricao);
                printf("%d\n", k);

                i=0;
                j=0;
                */

                break;
              } else {
                  str[j] = c;
                  j++;
              }
              

          } while (c != EOF);
          

      } else {
          str[i] = c;
          i++;
      }

    } while (c != EOF && x == 0);//enquanto não for final de arquivo 

    //fechando o arquivo
    fclose(pont_arq);

    //printf("%s", str);
    //printf("%d\n", i);

    //strcpy(str,"");
    //printf("ola %s\n", str);

    //strcpy(str,autor);
    //printf("oba %s\n", str);

    //i = strlen(autor);
    //printf("%s ", autor);
    //printf("%d\n", i);

    //j = strlen(descricao);
    //printf("%s ", descricao);
    //printf("%d\n", j);

    //printf("\n");
  

    tMusica* m1 = inicializa_musica(autor, descricao);

    tMusica* m2 = inicializa_musica("Yaosobi", "Subarashi");

    Playlist* p = inicializa_playlist();

    insere_playlist(p, m1);

    insere_playlist(p, m2);

    imprime_playlist(p);

    retira_playlist(p, "Yaosobi");

    printf("2.0\n");

    imprime_playlist(p);

    destroi_musica(m1);

    return 0;
}