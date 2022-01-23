#ifndef PARAMETROS_H
#define PARAMETROS_H

#include "main.h"

typedef void* parametro_void;

int tem_qry(void* param);// verifica se foi passado o arquivo .qry 

parametro_void cria_parametros();// cria os nomes do geo e qry diretorio de entrada  e de saido, todos recebem NULL
void define_parametros (parametro_void Param, char* argv[], int argc); // verifica quais parametros estão sendo passados(-e -f -o -q) e salva nos locais adequados


char* pega_diretorio_input(parametro_void Param); // pega o diretorio de input(entrada)
char* pega_diretorio_output(parametro_void Param); // pega o diretorio de output(saida) 
char* pega_nome_geo (parametro_void Param);// pega o nome do arquivo .geo
char* pega_nome_qry(parametro_void Param); // pega o nome do arquivo .qry

#endif