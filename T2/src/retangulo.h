#ifndef __RETANGULO_H
#define __RETANGULO_H

#include "ponto_energia.h"

typedef void* Retangulo;
Retangulo cria_retangulo(char* id, char* largura, char* altura, char* x, char* y, char* corb, char* corp);// cria um  novo retangulo 

char* pega_id_retangulo(Retangulo Retan); // pega o id do retangulo passado
char* pega_largura_retangulo(Retangulo Retan);// pega a largura do retangulo passado
char* pega_Altura_retangulo(Retangulo Retan);//  pega a altura  do retangulo  passado
char* pega_X_retangulo(Retangulo Retan);// pega o X do retangulo  passado 
char* pega_Y_retangulo(Retangulo Retan);// pega o Y do retangulo passado 
char* pega_Corb_retangulo(Retangulo Retan); // pega cor de borada do retanglo passado 
char* pega_Corp_retangulo(Retangulo Retan); // pega cor de preenchimento do retangulo passado 

Ponto_Energia pega_P1_retangulo(Retangulo Retan);// pega o ponto(1)
Ponto_Energia pega_P2_retangulo(Retangulo Retan);// pega o ponto(2)
Ponto_Energia pega_P3_retangulo(Retangulo Retan);// pega o ponto(3)
Ponto_Energia pega_P4_retangulo(Retangulo Retan);// pega o ponto(4)

void definir_largura_retangulo(Retangulo Retan, char* largura);// definir um novo valor para a largura do retangulo
void definir_altura_retangulo(Retangulo Retan, char* altura);// definir um novo valor para a altura do retangulo
void definir_X_retangulo(Retangulo Retan, char* x);// definir um novo valor para o X do retangulo
void definir_Y_retangulo(Retangulo Retan, char* y);// definir um novo valor para o Y do retangulo
void definir_ponto_energia_retangulo(Retangulo Retan, double ponto_energia);// definir um novo valor para o ponto de enrgia do retangulo

void imprime_txt_dados_retangulo(Retangulo Retan, FILE* txt_qry);// imprime no txt todos os dados do retangulo poŕem não imprime os pontos de energia que tem valor zero 
void imprime_txt_dados_retangulo_todos(Retangulo Retan, FILE* txt_qry);// imprime todos os dados do retangulo e seus pontos de energia 
void imprimir_arvore_retangulo_aux(Retangulo Retan);// imprime a arvore de retangulo passada no terminal
void imprime_txt_id_retangulo(Retangulo Retan, FILE* txt_qry);//imprime no txt o id do retangulo passado

void normaliza_ponto_energia_retangulo(Retangulo Retan);// vai normalizar os pontos de energia do retangulo
int checar_id_retangulo(Retangulo Retan, char* id);// verifica se o id do retangulo é igual o id passado 
void aumenta_ponto_energia_retangulo(Retangulo Retan, double ponto_energia);// aumenta o valor do ponto de energia do retangulo em um determinado valor 
int checar_pontos_energia_zero_retangulo(Retangulo Retan);// checa se todos os pontos de energia do retangulo é zero 
int ponto_dentro_retangulo(Retangulo Retan, double x, double y);
void libera_retangulo(Retangulo Retan);// desaloca o retangulo da memoria 
char* retangulo_para_string(Retangulo Retan);// pega os dados do retangulo e tranforma em um string 

void imprime_svg_dados_retangulo(Retangulo Retan, FILE* svg_qry);// imprime os dodados do retangulo em um SVG
void imprime_txt_dados_retangulo_sem_energia(Retangulo Retan, FILE* txt_qry);
void imprime_txt_dados_retangulo_qinterroga(Retangulo Retan, FILE* txt_qry);


#endif