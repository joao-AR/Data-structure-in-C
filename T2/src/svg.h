#ifndef SVG_H
#define SVG_H

#include "main.h"
#include "abrir_input.h"
#include "kdtree.h"


FILE* cria_path_svg_geo (void* parametros);// cria o path onde o svg do geo vai ser salvo 

void imprime_svg(KDTree retangulos, KDTree Circ, KDTree Txt, KDTree Lin,FILE* file);// imprime todos os elementos/formas no svg

#endif