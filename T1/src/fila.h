#ifndef FILA_H
#define FILA_H

#include "main.h"
#include "formas.h"
typedef struct fila Fila;

Fila* cria_Fila();
void imprime_Fila(Fila* fi);
int insere_Fila(char tipo_forma[],Fila* fi, void* forma);
int remove_Fila(Fila* fi);
void libera_Fila(Fila* fi);

#endif