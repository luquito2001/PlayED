#ifndef _MUSICA_H_
#define _MUSICA_H_

//tipo musica
typedef struct musica tMusica;

/*
 * inputs:
 * output:
 * pré-condição: 
 * pós-condição:
 */

/*Inicializa uma música a partir dos dados presentes no arquivo de entrada
 * inputs: autor e descrição
 * output: ponteiro para a música inicializada
 * pré-condição: arquivo de entrada válido
 * pós-condição: música de retorno existe e está devidamente preenchida
 */
tMusica* inicializa_musica (char* a, char* d);

/*Retorna uma string que representa o autor da música
 * inputs: música m
 * output: autor da música
 * pré-condição: música m existe e possui o campo autor preenchido
 * pós-condição: m não é modificada
 */
char* get_autor_musica (tMusica* m);

/*Retorna uma string que representa a descrição da música
 * inputs: música m
 * output: descrição da música
 * pré-condição: música m existe e possui o campo descrição preenchido
 * pós-condição: m não é modificada
 */
char* get_descricao_musica (tMusica* m);

/*Imprime os dados da música
 * inputs: música m
 * output: nenhum
 * pré-condição: música m existe
 * pós-condição: nenhuma
 */
void imprime_musica (tMusica* m);

/*Libera a memória alocada para a música
 * inputs: música m
 * output: nenhum
 * pré-condição: música m existe
 * pós-condição: TODA(!?) a memória alocada para a música foi liberada
 */
void destroi_musica (tMusica* m);

char* copia_string (char* destino, char* origem, int tam);

char* zera_string (char* str);

#endif