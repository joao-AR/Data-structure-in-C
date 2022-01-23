#ifndef LISTA_H
#define LISTA_H

#include "main.h"
#include "formas.h"
typedef void* retangulo_void;
typedef struct elemento* Lista;
typedef struct elemento Elem;
typedef struct circulo Circ;
typedef struct retangulo Rect;
typedef struct linha Linha;
typedef struct texto Text;

Lista* cria_lista();
int insere_lista_final(char tipo_forma[], Lista* li, void* forma);
int insere_lista_inicio(char tipo_forma[],Lista* li, void* forma);
int insere_lista_ordenada(char tipo_forma[],Lista* li, void* forma);
void insere_lista_antes_posi (char tipo_forma[], Lista* li, void* forma,void* registradores[],int posi_registrador,int posi);
void insere_lista_depois_posi(char tipo_forma[], Lista* li, void* forma,void* registradores[],int posi_registrador,int posi);
void imprime_lista(Lista* li);

Elem* pega_forma_com_id(char id[],Lista* li);
Elem* pega_forma_na_posicao (char posi[],Lista* li);
Elem* pega_primeiro_elemento_lista(Lista* li);
int pega_posicao_elemento_registrador (Lista* li,void* registrador[],int n_registrador);

void remove_lista_id (char id[], Lista* li);
void remove_lista_inicio(Lista* li);
void remover_lista_ants_registrador (Lista* li,int posi);
void remover_lista_dps_registrador (Lista* li,int posi);

void libera_lista(Lista* li);
void esvazia_lista (Lista* li);

#endif