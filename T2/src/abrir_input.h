#ifndef ABRIR_INPUT_H
#define ABRIR_INPUT_H

#include "main.h"
#include "parametros.h"


FILE* abrir_arquivo_input(parametro_void Param, char* tipo_arquivo); // abre um arquivo geo ou qry 

char* constroi_path_arquivo_input(char* diretorio_input, char* nome_arquivo_input);//essa função vai construir o local onde o arquivo input vai estar

#endif