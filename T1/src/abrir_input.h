#ifndef ABRIR_INPUT_H
#define ABRIR_INPUT_H

#include "main.h"
#include "parametros.h"
#include "formas.h"

FILE* abrir_arquivo_input(parametro_void Param, char* fileType);
char* constroi_path_arquivo_input(char* diretorio_input, char* nome_arquivo_input);
void closeInputFile(FILE* file);

#endif