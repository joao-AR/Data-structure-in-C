#ifndef GEO_H
#define GEO_H

#include "main.h"
#include "variaveis.h"

// Esta função tem como objetivo receber as formas do .geo e uma struct que contem todas as arvores, as formas que foram recebidas do .geo seram salvas em suas respectivas arvores 
void salva_formas_nas_arvores(FILE* geo, Variaveis arvores_listas);
#endif