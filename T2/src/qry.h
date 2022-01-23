#ifndef QRY_H
#define QRY_H


#include "main.h"
#include "parametros.h"
#include "variaveis.h"
#include "retangulo.h"
#include "circulo.h"
#include "texto.h"
#include "linha.h"

typedef struct elemento Elem;

//void cria_path_qry_txt(void* parametros);// cria o local onde o .txt gerado pelo arquivo qry vai ser salvo
FILE* cria_path_svg_qry (void* parametros);// cria o local onde o .svg gerado pelo arquivo qry vai ser salvo
FILE* cria_path_txt (void* parametros);// cria o local onde o .txt gerado pelo arquivo qry vai ser salvo

void funcoes_qry (FILE* qry,FILE* svg_qry,FILE* txt_qry, Variaveis variaveis);// essa função  recebe o arquivo svg e txt do qry, o arquivo .qry e a estrutura que contem todas as arvores  


#endif