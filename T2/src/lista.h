#ifndef LIST_H
#define LIST_H

typedef void* Info;
typedef void* No;
typedef void* Lista;


Lista cria_lista(); // cria uma lista nova 


No inserir(Lista Li, Info info);// isere um novo dado na lista 
No insere_antes(Lista Li, No Posi, Info Informacao);// insere em uma posição anterior da lista 
No insere_depois(Lista Li, No Posi, Info Informacao);// insere em um posição posterior da lista 


No pega_primeiro_lista(Lista Li);// pega o primeiro elemento da lista
No pega_ultimo_lista(Lista Li);// pega o ultimo elemento da lista 
No pega_anterior_lista(Lista Li, No Posi);// pega o elemento anterior da lista 
No pega_proximo_lista(Lista Li, No Posi);// pega o proximo elemento da lista 

int tamanho_lista(Lista Li);// pega o tamanho da lista 

void imprime_lista(Lista Li, void (*printInformation)(void*));// imprime a lista no terminal 
void imprime_lista_no_txt(Lista Li, FILE* txt, void (*send_to_txt)(void*, FILE*));// imprime a lista no txt passado 

void Esvazia_lista(Lista Li, void (*libera_TAD)(void*)); // esvazia a lista
int remove_NO_lista(Lista Li, No No_remover, void (*libera_TAD)(void*)); // remove um NO da lista 
void libera_lista(Lista Li, void (*libera_TAD)(void*)); // desaloca a lista da memoria 

void insere_lista_completamente_dentro(Lista Li, Lista lista_nova, int (*checa_figura_contida)(void*, void*), void* retangulo_qry); // insere na lista passada apenas os elementos que estão completamente dentro da região especificada

void imprime_lista_no_svg(Lista Li, FILE* svg, void (*manda_svg)(void*, FILE*));// vai imprimir a lista no svg

#endif