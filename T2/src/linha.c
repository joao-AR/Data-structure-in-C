#include "main.h"
#include "ponto_energia.h"
#include "linha.h"

typedef struct linha{
    char* id;
    char* x1;
    char* y1; 
    char* x2;
    char* y2;
    char* cor;
    Ponto_Energia ponto1;
    Ponto_Energia ponto2;
}linha;

Linha cria_linha(char* id,char* x1, char* y1,char* x2, char* y2, char* cor){

    linha *lin = (linha*) malloc(sizeof(linha));

   lin->id = (char*) malloc((strlen(id) + 1) * sizeof(char));
   lin->x1 = (char*) malloc((strlen(x1) + 1) * sizeof(char));
   lin->y1 = (char*) malloc((strlen(y1) + 1) * sizeof(char));
   lin->x2 = (char*) malloc((strlen(x2) + 1) * sizeof(char));
   lin->y2 = (char*) malloc((strlen(y2) + 1) * sizeof(char));
   lin->cor= (char*) malloc((strlen(cor) + 1) * sizeof(char));

    
    strcpy(lin->id, id);
    strcpy(lin->x1, x1);
    strcpy(lin->y1, y1);
    strcpy(lin->x2, x2);
    strcpy(lin->y2, y2);
    strcpy(lin->cor, cor);

    lin->ponto1 = cria_ponto_energia('l',lin,id, atof(x1), atof(y1), 0);
    lin->ponto2 = cria_ponto_energia('l',lin,id, atof(x2), atof(y2), 0);

    return lin;
}


Ponto_Energia pega_P1_linha(Linha Lin) {
    if(Lin == NULL) return NULL;
    linha *lin = (linha*) Lin;
    return lin->ponto1;
}

Ponto_Energia pega_P2_linha(Linha Lin) {
    if(Lin == NULL) return NULL;
    linha *lin = (linha*) Lin;
    return lin->ponto2;
}

char* pega_id_linha(Linha Lin){
    if(Lin == NULL)
        return NULL;
    linha *lin = (linha*) Lin;
    return lin->id;
}


char* pega_x1_linha(Linha Lin){
    if(Lin == NULL)
        return NULL; 
    linha *lin = (linha*) Lin;
    
    return lin->x1;
}

char* pega_x2_linha(Linha Lin){
    if(Lin == NULL)
        return NULL; 
    linha *lin = (linha*) Lin;
    
    return lin->x2;
}

char* pega_y1_linha(Linha Lin){
    if(Lin == NULL)
        return NULL; 
    linha *lin = (linha*) Lin;
    
    return lin->y1;
}

char* pega_y2_linha(Linha Lin){
    if(Lin == NULL)
        return NULL; 
    linha *lin = (linha*) Lin;
    
    return lin->y2;
}

void definir_x1_linha(Linha Lin, char* x1){
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    strcpy(lin->x1, x1);
}

void definir_x2_linha(Linha Lin, char* x2){
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    strcpy(lin->x2, x2);
}

void definir_y1_linha(Linha Lin, char* y1){
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    strcpy(lin->x1, y1);
}

void definir_y2_linha(Linha Lin, char* y2){
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    strcpy(lin->x2, y2);
}

char* pega_cor_linha(Linha Lin){
    if(Lin == NULL)
        return NULL;
    linha *lin = (linha*) Lin;
    return lin->cor;
}



void definir_cor_linha(Linha Lin, char* cor){
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    strcpy(lin->cor, cor);
}

void libera_linha (Linha Lin){
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    free(lin->id);    
    free(lin->x1); 
    free(lin->y1);
    free(lin->x2); 
    free(lin->y2); 
    free(lin->cor); 
    free(lin);
}

void seta_ponto_energia_linha(Linha Lin, double ponto_energia) {
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;

    double energia_distribuida = ponto_energia/2;
    definir_ponto_energia_energia(lin->ponto1, energia_distribuida);
    definir_ponto_energia_energia(lin->ponto2, energia_distribuida);
}
void aumenta_ponto_energia_linha(Linha Lin, double ponto_energia) {
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;

    double energia_distribuida = ponto_energia/2;
    aumenta_ponto_energia_energia(lin->ponto1, energia_distribuida);
    aumenta_ponto_energia_energia(lin->ponto2, energia_distribuida);
}

void imprimir_arvore_linha_aux(Linha Lin) {
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;

    printf("X1 %s |", lin->x1);
    printf("X2 %s |", lin->x2);
    printf("Y1 %s |", lin->y1);
    printf("Y2 %s |", lin->y2);
    
    printf("P1 %lf |", pega_ponto_energia_energia(lin->ponto1));
    printf("P2 %lf |\n", pega_ponto_energia_energia(lin->ponto2));

}

void imprime_txt_id_linha(Linha Lin, FILE* txt_qry) {
    if(Lin == NULL) return;
    linha *lin = (linha*) Lin;
    fprintf(txt_qry,"ID Figura: %s\n", lin->id);
}

void imprime_txt_dados_linha_q_interroga(Linha Lin, FILE* txt_qry){
    if(Lin == NULL) return;
    linha *lin= (linha*) Lin;
    
    fprintf(txt_qry,"Linha: %s\n",lin->id);
    fprintf(txt_qry,"X1  : %s\n",lin->x1);
    fprintf(txt_qry,"Y1  : %s\n",lin->y1);
    fprintf(txt_qry,"X2  : %s\n",lin->x2);
    fprintf(txt_qry,"Y2  : %s\n",lin->y2);
    fprintf(txt_qry,"Cor : %s\n\n",lin->cor);
}


void imprime_txt_dados_linha_sem_energia(Linha Lin, FILE* txt_qry){
    if(Lin == NULL) return;
    linha *lin= (linha*) Lin;
    
    fprintf(txt_qry,"Linha: %s\n",lin->id);
    fprintf(txt_qry,"X1  : %s\n",lin->x1);
    fprintf(txt_qry,"Y1  : %s\n",lin->y1);
    fprintf(txt_qry,"X2  : %s\n",lin->x2);
    fprintf(txt_qry,"Y2  : %s\n",lin->y2);
    fprintf(txt_qry,"Cor : %s\n\n",lin->cor);
    
    fprintf(txt_qry,"P1  : X->%lf Y->%lf\n",pega_X_ponto_energia(lin->ponto1),pega_Y_ponto_energia(lin->ponto1)); 
    fprintf(txt_qry,"P2  : X->%lf Y->%lf\n",pega_X_ponto_energia(lin->ponto2),pega_Y_ponto_energia(lin->ponto2));
}

void imprime_txt_dados_linha(Linha Lin, FILE* txt_qry){
    if(Lin == NULL) return;
    linha *lin= (linha*) Lin;
    
    fprintf(txt_qry,"Linha: %s\n",lin->id);
    fprintf(txt_qry,"X1  : %s\n",lin->x1);
    fprintf(txt_qry,"Y1  : %s\n",lin->y1);
    fprintf(txt_qry,"X2  : %s\n",lin->x2);
    fprintf(txt_qry,"Y2  : %s\n",lin->y2);
    fprintf(txt_qry,"Cor : %s\n\n",lin->cor);
    if(pega_ponto_energia_energia(lin->ponto1) > 0) 
        
        fprintf(txt_qry,"P1  : %lf X->%lf Y->%lf\n",pega_ponto_energia_energia(lin->ponto1),pega_X_ponto_energia(lin->ponto1),pega_Y_ponto_energia(lin->ponto1));
    
    if(pega_ponto_energia_energia(lin->ponto2) > 0) 
        fprintf(txt_qry,"P2  : %lf X->%lf Y->%lf\n",pega_ponto_energia_energia(lin->ponto2),pega_X_ponto_energia(lin->ponto2),pega_Y_ponto_energia(lin->ponto2));
}

void imprime_txt_dados_linha_todos(Linha Lin, FILE* txt_qry){
    if(Lin == NULL) return;
    linha *lin= (linha*) Lin;
    
    fprintf(txt_qry,"Linha: %s\n",lin->id);
    fprintf(txt_qry,"X1  : %s\n",lin->x1);
    fprintf(txt_qry,"Y1  : %s\n",lin->y1);
    fprintf(txt_qry,"X2  : %s\n",lin->x2);
    fprintf(txt_qry,"Y2  : %s\n",lin->y2);
    fprintf(txt_qry,"Cor : %s\n\n",lin->cor); 
        
        fprintf(txt_qry,"P1  : %lf X->%lf Y->%lf\n",pega_ponto_energia_energia(lin->ponto1),pega_X_ponto_energia(lin->ponto1),pega_Y_ponto_energia(lin->ponto1));

        fprintf(txt_qry,"P2  : %lf X->%lf Y->%lf\n",pega_ponto_energia_energia(lin->ponto2),pega_X_ponto_energia(lin->ponto2),pega_Y_ponto_energia(lin->ponto2));
}

void imprime_svg_dados_linha(Linha Lin, FILE* svg_qry) {
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    fprintf(svg_qry,"<circle cx=\"%s\" cy=\"%s\" r=\"1.0\" stroke=\"#008080\" stroke-width=\"3.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",lin->x1, lin->y1);
    fprintf(svg_qry,"<circle cx=\"%s\" cy=\"%s\" r=\"1.0\" stroke=\"#008080\" stroke-width=\"3.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",lin->x2, lin->y2);

}


int checar_id_linha(Linha Lin, char* id) {
    if(Lin == NULL)
        return 0;
    linha *lin = (linha*) Lin;

    if(id == NULL) return 1;

    if(!strcmp(lin->id, id)) return 1;

    return 0;
}

void normaliza_ponto_energia_linha(Linha Lin) {
    if(Lin == NULL) return;
    linha *lin = (linha*) Lin;

    double energia_distribuida = (pega_ponto_energia_energia(lin->ponto1)+pega_ponto_energia_energia(lin->ponto2))/2;
    definir_ponto_energia_energia(lin->ponto1, energia_distribuida);
    definir_ponto_energia_energia(lin->ponto2, energia_distribuida);

}


void Destroi_linha(Linha Lin){
    if(Lin == NULL)
        return;
    linha *lin = (linha*) Lin;
    free(lin->id);  
    free(lin->x1); 
    free(lin->y1);
    free(lin->x2); 
    free(lin->y2); 
    free(lin->cor);
    free(lin);
}

int checar_pontos_energia_zero_linha(Linha Lin) {
    if(Lin == NULL)
        return 0;
    linha *lin = (linha*) Lin;

    if(pega_ponto_energia_energia(lin->ponto1) == 0 && pega_ponto_energia_energia(lin->ponto2) == 0) return 1;

    return 0;

}


char* linha_para_string(Linha Lin){
    if(Lin == NULL) return NULL;
    linha *lin = (linha*) Lin;
    
    char* string = (char*) malloc(sizeof(char)*200);
    sprintf(string, "linha -> id: %s, x1 %s, y1 %s,  x2: %s, y2: %s, cor: %s",lin->id,lin->x1,lin->y1,lin->x2,lin->y2,lin->cor);
    
    return string;
}