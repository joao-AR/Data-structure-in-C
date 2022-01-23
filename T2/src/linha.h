
#include "main.h"
typedef void* Linha;

Linha cria_linha(char* id,char* x1, char* y1,char* x2, char* y2, char* cor);// cria uma linha 

Ponto_Energia pega_P1_linha(Linha Lin); // pega o ponto de energia (1) da linha 
Ponto_Energia pega_P2_linha(Linha Lin); // pega o ponto de energia (2) da linha 

char* pega_id_linha(Linha Lin); // recebe uma linha e pega o seu id
char* pega_x1_linha(Linha Lin); // recebe uma linha e pega o seu x1
char* pega_x2_linha(Linha Lin); // recebe uma linha e pega o seu x2
char* pega_y1_linha(Linha Lin); // recebe uma linha e pega o seu y1
char* pega_y2_linha(Linha Lin); // recebe uma linha e pega o seu y2
char* pega_cor_linha(Linha Lin);// recebe uma linha e pega o sua cor 

void definir_x1_linha(Linha Lin, char* x1); // define um novo valor para o X1
void definir_x2_linha(Linha Lin, char* x2); // define um novo valor para o X2
void definir_y1_linha(Linha Lin, char* y1); // define um novo valor para o Y1
void definir_y2_linha(Linha Lin, char* y2); // define um novo valor para o Y2
void definir_cor_linha(Linha Lin, char* cor); // define uma nova cor para a linha


void libera_linha (Linha Lin);// desaloca da memoria a linha que foi passada 
void normaliza_ponto_energia_linha(Linha Lin); // normaliza os ponto de enegia da linha  

void imprime_txt_id_linha(Linha Lin, FILE* txt_qry); // imprime em um arquivo .txt o ID da linha passada como parametro
void imprime_txt_dados_linha(Linha Lin, FILE* txt_qry);// imprime em um arquivo .txt os dados da linha passada como parametro e os pontos de energia que são maiores que zero
void imprime_txt_dados_linha_todos(Linha Lin, FILE* txt_qry);//imprime em um arquivo .txt os dados da linha passada e todos os pontos de energia independente do valor 

void imprimir_arvore_linha_aux(Linha Lin);// imprime a arvore de linhas nos terminal 
void seta_ponto_energia_linha(Linha Lin, double ponto_energia);// define os valores dos pontos de energia da linha 
int checar_id_linha(Linha Lin, char* id); // verifica se o id passado é igual ao id da linha 
void aumenta_ponto_energia_linha(Linha Lin, double ponto_energia); // aumenta o ponto de energia da linha em um determindado valor passado 
char* linha_para_string(Linha Lin);
int checar_pontos_energia_zero_linha(Linha Lin);// verifica se todos os pontos da linha são igual a zero 

void Destroi_linha(Linha Lin); // desaloca a linha da memoria 
void imprime_svg_dados_linha(Linha Lin, FILE* svg_qry);

void imprime_txt_dados_linha_sem_energia(Linha Lin, FILE* txt_qry);

void imprime_txt_dados_linha_q_interroga(Linha Lin, FILE* txt_qry);