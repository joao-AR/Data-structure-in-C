#ifndef SVG_H
#define SVG_H

#include "main.h"
#include "abrir_input.h"
#include "lista.h"
#include "formas.h"
FILE* cria_path_svg_geo (void* parametros);
void imprime_no_svg (Lista* li,FILE* file);

#endif