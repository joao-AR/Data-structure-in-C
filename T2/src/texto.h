#ifndef TEXT_H
#define TEXT_H
#include "main.h"
#include "ponto_energia.h"
typedef void* Text;



Text cria_texto(char* id, char* x, char* y, char* corb, char* corp, char* conteudo_texto);// cria um novo texto
Ponto_Energia pega_P1_txt(Text Txt);// pega o ponto de energia do texto 

char* pega_id_txt(Text Txt);// pega o id do txt passado
char* pega_X_txt(Text Txt);// pega o x do txt passado
char* pega_Y_txt(Text Txt);// pega o y do txt passado
char* pega_Corb_txt(Text Txt);// pega cor borda txt
char* pega_Corp_txt(Text Txt);// pega cor preenchimento txt
char* pega_Conteudo_txt(Text Txt);// pega o conteudo dentro do txt



void definir_Corb_txt(Text Txt, char* corb);// difinir uma nova cor
void definir_Corp_txt(Text Txt, char* corb);// difinir uma nova cor
void definir_ponto_energia_texto(Text Txt, double ponto_energia);// define o valor do ponto de enrgia do texto

void imprime_txt_id_texto(Text Txt, FILE* txt_qry);// imprime no .txt passo o id do txt
void imprime_txt_dados_texto(Text Txt, FILE* txt_qry);// imprime no .txt os dados do txt e pontos de energia maior que zero 
void imprime_txt_dados_texto_todos(Text Txt, FILE* txt_qry);// imprime no .txt os dados do txt e pontos de energia
void imprimir_arvore_texto_aux(Text Txt);// imprime a arvore de txt no terminal

int checar_id_texto(Text Txt, char* id);// checa se o id do txt é igual ao do id passado 

void aumenta_ponto_energia_texto(Text Txt, double ponto_energia);// aumenta o valor do ponto de energia do texto em um determinado valor passado
int checar_pontos_energia_zero_texto(Text Txt);// cheacar se todos os pontos de energia do txt estão zerados 
char* txt_para_string(Text Txt);// converte todos os dados do txt para uma string 

void libera_txt(Text Txt);// desaloca o txt da memoria 

void imprime_svg_dados_txt(Text Txt, FILE* svg_qry);// imprime todos os dados do txt e seus pontos  de enrgia 

void imprime_txt_dados_texto_sem_energia(Text Txt, FILE* txt_qry);
void imprime_txt_dados_texto_q_interroga(Text Txt, FILE* txt_qry);

#endif