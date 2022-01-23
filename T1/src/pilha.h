#ifndef PILHA_H
#define PILHA_H

#include "main.h"

typedef void* retangulo_void;
typedef struct elemento Elem;
typedef struct elemento* Pilha;
typedef struct retangulo Rect;

Pilha* cria_Pilha();
Elem* consulta_pilha_por_id (Pilha* pi, char id[]);

int insere_Pilha(char tipo_forma[],Pilha* pi, void* forma);
void imprime_Pilha(Pilha* pi);
void libera_Pilha(Pilha* pi);
void remove_Pilha(Pilha* pi);
Elem* pega_primeiro_elemento_pilha (Pilha *pi);

#endif