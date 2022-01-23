#ifndef PONTO_ENERGIA
#define PONTO_ENERGIA

#include "main.h"

typedef void* Ponto_Energia;

Ponto_Energia cria_ponto_energia(char tipo_figira_de_origem, void* figura, char* id, double x,double y, double energia);// cria um novo ponto de energia para a forma passada no parametro

void   pega_ponto_energia_imprime(Ponto_Energia ponto);// recebe um ponto de energia e imprime no terminal 
char   pega_ponto_energia_figura_tipo_origem(Ponto_Energia ponto); // pega a figura de origem do ponto de energia passado 
double pega_X_ponto_energia(Ponto_Energia ponto);// pega o X do ponto de energia 
double pega_Y_ponto_energia(Ponto_Energia ponto);// pega o Y do ponto de energia 
double pega_ponto_energia_energia(Ponto_Energia ponto); // pega o valor do ponto de energia 
void*  pega_ponto_energia_figura(Ponto_Energia ponto); // pega a figura que tem esse ponto de energia passado  

void definir_X_ponto_energia(Ponto_Energia ponto, double x);// define um novo valor para  o x  do ponto de energia 
void definir_Y_ponto_energia(Ponto_Energia ponto, double y);// define um novo valor para  o Y  do ponto de energia 
void definir_ponto_energia_energia(Ponto_Energia ponto, double energia);// coloca o valor de energia passado no ponto de energia 
void aumenta_ponto_energia_energia(Ponto_Energia ponto, double energia);// aumenta o valor de energia do ponto em um determindado valor passado

double calcula_distancia_pontos(double x,double y,double x2,double y2);// calcula a distancia entre dois pontos passados 

int comparar_pontos_pela_coordenada_x(const void* ponto1, const void* ponto2);// compara o X dos dois pontos passados 
int comparar_pontos_pela_coordenada_y(const void* ponto1, const void* ponto2);// compara o Y dos dois pontos passados
void descontar_ponto_energia(Ponto_Energia ponto, double v);// subtrai em V o valor de energia do ponto de energia passado 

void libera_ponto_energia(Ponto_Energia ponto);// desaloca da memoria o ponto de energia passado 

#endif
