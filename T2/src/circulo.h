#ifndef CIRCLE_H
#define CIRCLE_H

#include "main.h"
#include "retangulo.h"

typedef void* Circulo;

Circulo cria_circulo(char* id, char* raio, char* x, char* y, char* corb, char* corp);//cria um crculo

char* pega_id_circulo(Circulo Circ);    //recebe um circulo e pega o id
char* pega_Raio_circulo(Circulo Circ);  //recebe um circulo e pega o raio
char* pega_X_circulo(Circulo Circ);     //recebe um circulo e pega o x
char* pega_Y_circulo(Circulo Circ);     //recebe um circulo e pega o y
char* pega_Corb_circulo(Circulo Circ);  //recebe um circulo e pega  a corda da borda
char* pega_Corp_circulo(Circulo Circ);  //recebe um circulo e pega a cor de preenchimento


Ponto_Energia pega_P1_circulo(Circulo Circ); // pega o ponto(1) de energia do circulo
Ponto_Energia pega_P2_circulo(Circulo Circ); // pega o ponto(2) de energia do circulo
Ponto_Energia pega_P3_circulo(Circulo Circ); // pega o ponto(3) de energia do circulo

void Definir_raio_circulo(Circulo Circ, char* raio);    // define um novo valor para o raio do circulo
void definir_X_circulo(Circulo Circ, char* x);          // define um novo valor para o x do circulo
void definir_Y_circulo(Circulo Circ, char* y);          // define um novo valor para o y do circulo
void definir_corb_circulo(Circulo Circ, char* corb);    // define um novo valor para a cor da borda do circulo
void definir_corp_circulo(Circulo Circ, char* corp);    // define um novo valor para a cor de preenchimento do circulo


void imprime_txt_id_circulo(Circulo Circ, FILE* txt_qry);           // imprime em um arquivo .txt o id do circulo
void imprime_txt_dados_circulo(Circulo Circ, FILE* txt_qry);        // imprime em um arquivo .txt todos os dados do circulo porém so imprime os pontos de energia maior que zero
void imprime_txt_dados_circulo_todos(Circulo Circ, FILE* txt_qry);  // imprime em um arquivo .txt todos os dados e pontos de energia independente do valor 
void imprimir_circ_aux(Circulo Circ ); // imprime os dados do circulo no terminal              
void imprimir_arvore_circulo_aux(Circulo Circ);// imprime a arvore de circulo no terminal

void definir_ponto_energia_circulo(Circulo Circ, double ponto_energia);// define o valor dos pontos energia do circulo 
int checar_id_circulo(Circulo Circ, char* id);// verifica se o ID do circulo é igual ao id passado 
void aumenta_ponto_energia_circulo(Circulo Circ, double ponto_energia);// aumenta o valor dos pontos de energia em um determinado valor passado 

void normaliza_ponto_energia_circulo(Circulo Circ);// pega um circulo e normaliza todos os seus pontos de enrgia

int checar_pontos_energia_zero_circulo(Circulo Circ);// verifica se todos os pontos de energia do circulo tem o valor zero 


char* circulo_para_string(Circulo Circ); // pega os dados do circulo e converte em uma string 
void libera_circulo(Circulo Circ); // desaloca o circulo da memoria 
void imprime_svg_dados_circulo(Circulo Circ, FILE* svg_qry);// imprime os dados do circulo no SVG
void imprime_txt_dados_circulo_sem_energia(Circulo Circ, FILE* txt_qry);
void imprime_txt_dados_circulo_q_interroga(Circulo Circ, FILE* txt_qry);


#endif