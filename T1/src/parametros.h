#ifndef PARAMETROS_H
#define PARAMETROS_H
#include "formas.h"
#include "main.h"

typedef void* parametro_void;
int tem_qry(void* param);
parametro_void cria_parametros();
void define_parametros (parametro_void Param, char* argv[], int argc);
void define_parametro_atual(char** parametro_atual, char* argv_atual);

char* pega_diretorio_input(parametro_void Param);
char* pega_diretorio_output(parametro_void Param);
char* pega_nome_geo (parametro_void Param);
char* pega_nome_qry(parametro_void Param);

#endif