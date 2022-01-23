#ifndef QRY_H
#define QRY_H


#include "main.h"
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "parametros.h"
#include "formas.h"


typedef struct elemento Elem;

void cria_path_qry_txt(void* parametros);
FILE* cria_path_svg_qry (void* parametros);
FILE* cria_path_txt (void* parametros);

void funcoes_qry (FILE* qry,FILE* svg_qry,FILE* txt_qry,Lista* listas[],Fila* filas[],Pilha* pilhas[], void* registradores[]);


void sobreposicao_de_formas(char j[],char k[],char id[],char cor1[],char cor2[],Lista* li,FILE* txt,FILE* svg_qry);
void eh_iterno (char j[],char x[],char y[],Lista *li,FILE* txt,FILE* svg);
void muda_corb_corp (char j[],char corb[],char corp[],Lista* li, FILE* txt);
void Remove_elemento_id_j (char j[],Lista* li,FILE* txt);
void empilha_pilha_p (Pilha* pi, char id[],Lista* li);

void remove_insere_Fila_modificado (Lista* li,Fila* fi,char id[],char dx[],char dy[],char prop[],FILE* txt);
void insere_na_fila_id(Lista* li, Fila* fi,char id[]);
void remove_empilha_modificado (Pilha* pi,char id[],char dx[],char dy[],char prop[],FILE* txt);
void remove_insere_lista_modificado (Lista* li,Fila* fi,char id[],char dx[],char dy[],char prop[],FILE* txt);

void insere_inicio_lista_registrador (Lista* li,char id[],void* registrador[],int n_registrador);
void insere_fim_lista_registrador (Lista* li,char id[],void* registrador[],int n_registrador);
void insere_lista_antes_registrador (Lista* li,char id[],void* registradores[],int ro,int rd);
void insere_lista_depois_registrador(Lista* li,char id[],void* registradores[],int ro,int rd);
void remove_lista_antes_registrador (Lista* li, void* registradores[],int n_registrador);
void remove_lista_depois_registrador(Lista* li, void* registradores[],int n_registrador);
void percorre_lista_cria_elementos_esvazia(Lista* li,int n_lista,int id,char dx[],char dy[],float _prop, float _incprop,Lista* listas[],Pilha* pilhas[],Fila* filas[]);

#endif