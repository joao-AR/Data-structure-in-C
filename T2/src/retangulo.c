#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"

typedef struct retangulo {
    char* id;
    char* largura;
    char* altura;
    char* x;
    char* y;
    char* corb;
    char* corp;

    Ponto_Energia ponto1;
    Ponto_Energia ponto2;
    Ponto_Energia ponto3;
    Ponto_Energia ponto4;
}retangulo;

Retangulo cria_retangulo(char* id, char* largura, char* altura, char* x, char* y, char* corb, char* corp){
    retangulo *retan = (retangulo*) malloc(sizeof(retangulo));
    retan->id = (char*) malloc((strlen(id) + 1) * sizeof(char));
    retan->largura = (char*) malloc((strlen(largura) + 1) * sizeof(char));
    retan->altura = (char*) malloc((strlen(altura) + 1) * sizeof(char));
    retan->x = (char*) malloc((strlen(x) + 1) * sizeof(char));
    retan->y = (char*) malloc((strlen(y) + 1) * sizeof(char));
    retan->corb = (char*) malloc((strlen(corb) + 1) * sizeof(char));
    retan->corp = (char*) malloc((strlen(corp) + 1) * sizeof(char));

    strcpy(retan->id, id);
    strcpy(retan->largura, largura);
    strcpy(retan->altura, altura);
    strcpy(retan->x, x);
    strcpy(retan->y, y);
    strcpy(retan->corb, corb);
    strcpy(retan->corp, corp);

    //cima esquerda
    retan->ponto1 = cria_ponto_energia('r',retan,id,atof(x), atof(y), 0);
    //cima direita
    retan->ponto2 = cria_ponto_energia('r',retan,id,atof(x)+atof(largura), atof(y), 0);
    //baixo esquerda
    retan->ponto3 = cria_ponto_energia('r',retan,id,atof(x), atof(y)+atof(altura), 0);
    //baixo direita
    retan->ponto4 = cria_ponto_energia('r',retan,id,atof(x)+atof(largura), atof(y)+atof(altura), 0);

    return retan;
}

char* pega_id_retangulo(Retangulo Retan){
    if(Retan == NULL)
        return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->id;
}

char* pega_largura_retangulo(Retangulo Retan){
    if(Retan == NULL)
        return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->largura;
}

char* pega_Altura_retangulo(Retangulo Retan){
    if(Retan == NULL)
        return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->altura;
}

char* pega_X_retangulo(Retangulo Retan){
    if(Retan == NULL)
        return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->x;
}

char* pega_Y_retangulo(Retangulo Retan){
    if(Retan == NULL)
        return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->y;
}

char* pega_Corb_retangulo(Retangulo Retan) {
    if(Retan == NULL)
        return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->corb;
}

char* pega_Corp_retangulo(Retangulo Retan) {
    if(Retan == NULL)
        return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->corp;
}

Ponto_Energia pega_P1_retangulo(Retangulo Retan) {
    if(Retan == NULL) return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->ponto1;
}

Ponto_Energia pega_P2_retangulo(Retangulo Retan) {
    if(Retan == NULL) return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->ponto2;
}

Ponto_Energia pega_P3_retangulo(Retangulo Retan) {
    if(Retan == NULL) return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->ponto3;
}

Ponto_Energia pega_P4_retangulo(Retangulo Retan) {
    if(Retan == NULL) return NULL;
    retangulo *retan = (retangulo*) Retan;
    return retan->ponto4;
}

void definir_largura_retangulo(Retangulo Retan, char* largura){
    if(Retan == NULL)
        return;
    retangulo *retan = (retangulo*) Retan;
    strcpy(retan->largura, largura);
}

void definir_altura_retangulo(Retangulo Retan, char* altura){
    if(Retan == NULL)
        return;
    retangulo *retan = (retangulo*) Retan;
    strcpy(retan->altura, altura);
}


void definir_X_retangulo(Retangulo Retan, char* x){
    if(Retan == NULL)
        return;
    retangulo *retan = (retangulo*) Retan;
    strcpy(retan->x, x);
}

int ponto_dentro_retangulo(Retangulo Retan, double x, double y){
    if(Retan == NULL)
        return 0;
    retangulo *retan = (retangulo*) Retan;
    
    if(atof(retan->x) <= x && (atof(retan->x) + atof(retan->largura) >= x)){
        if(atof(retan->y) <= y && (atof(retan->y) + atof(retan->altura) >= y)){
            return 1;
        }
    }

    return 0;

}



void definir_Y_retangulo(Retangulo Retan, char* y){
    if(Retan == NULL)
        return;
    retangulo *retan = (retangulo*) Retan;
    strcpy(retan->y, y);
}



void imprimir_arvore_retangulo_aux(Retangulo Retan) {
    if(Retan == NULL) return;
    retangulo *retan = (retangulo*) Retan;

    printf("ID -> %s |", retan->id);
    printf("X -> %s |", retan->x);
    printf("Y -> %s |", retan->y);
    printf("L -> %s |", retan->largura);
    printf("A -> %s |\n", retan->altura);
    printf("Ponto energia p1 -> %f | ", pega_ponto_energia_energia(retan->ponto1));
    printf("Ponto energia p2 -> %f | ", pega_ponto_energia_energia(retan->ponto2));
    printf("Ponto energia p3 -> %f | ", pega_ponto_energia_energia(retan->ponto3));
    printf("Ponto energia p4 -> %f\n", pega_ponto_energia_energia(retan->ponto4));

}

void imprime_txt_id_retangulo(Retangulo Retan, FILE* txt_qry){
    if(Retan == NULL) return;
    retangulo *rect = (retangulo*) Retan;
    fprintf(txt_qry,"ID Figura: %s\n", rect->id);
}

void imprime_txt_dados_retangulo_qinterroga(Retangulo Retan, FILE* txt_qry) {
    if(Retan == NULL) return;
    retangulo *retan = (retangulo*) Retan;
    
    fprintf(txt_qry,"Retangulo: %s\n",retan->id);
    fprintf(txt_qry,"Largura %s\n",retan->largura);
    fprintf(txt_qry,"Altura  %s\n",retan->altura);
    fprintf(txt_qry,"X   %s\n",retan->x);
    fprintf(txt_qry,"Y   %s\n",retan->y);
    fprintf(txt_qry,"Corb   %s\n",retan->corb);
    fprintf(txt_qry,"Corp   %s\n\n",retan->corp);

}

void imprime_txt_dados_retangulo_sem_energia(Retangulo Retan, FILE* txt_qry) {
    if(Retan == NULL) return;
    retangulo *retan = (retangulo*) Retan;
    
    fprintf(txt_qry,"Retangulo: %s\n",retan->id);
    fprintf(txt_qry,"Largura %s\n",retan->largura);
    fprintf(txt_qry,"Altura  %s\n",retan->altura);
    fprintf(txt_qry,"X   %s\n",retan->x);
    fprintf(txt_qry,"Y   %s\n",retan->y);
    fprintf(txt_qry,"Corb   %s\n",retan->corb);
    fprintf(txt_qry,"Corp   %s\n\n",retan->corp);
    
    fprintf(txt_qry,"P1: X->%lf y->%lf\n",pega_X_ponto_energia(retan->ponto1),pega_Y_ponto_energia(retan->ponto1));
    fprintf(txt_qry,"P2: X->%lf y->%lf\n",pega_X_ponto_energia(retan->ponto2),pega_Y_ponto_energia(retan->ponto2));
    fprintf(txt_qry,"P3: X->%lf y->%lf\n",pega_X_ponto_energia(retan->ponto3),pega_Y_ponto_energia(retan->ponto3));
    fprintf(txt_qry,"P4: X->%lf y->%lf\n\n",pega_X_ponto_energia(retan->ponto4),pega_Y_ponto_energia(retan->ponto4));

}

void imprime_txt_dados_retangulo(Retangulo Retan, FILE* txt_qry) {
    if(Retan == NULL) return;
    retangulo *retan = (retangulo*) Retan;
    
    fprintf(txt_qry,"Retangulo: %s\n",retan->id);
    fprintf(txt_qry,"Largura %s\n",retan->largura);
    fprintf(txt_qry,"Altura  %s\n",retan->altura);
    fprintf(txt_qry,"X   %s\n",retan->x);
    fprintf(txt_qry,"Y   %s\n",retan->y);
    fprintf(txt_qry,"Corb   %s\n",retan->corb);
    fprintf(txt_qry,"Corp   %s\n\n",retan->corp);

    if(pega_ponto_energia_energia(retan->ponto1) > 0)  
        fprintf(txt_qry,"P1: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto1),pega_X_ponto_energia(retan->ponto1),pega_Y_ponto_energia(retan->ponto1));

    if(pega_ponto_energia_energia(retan->ponto2) > 0)
        fprintf(txt_qry,"P2: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto2),pega_X_ponto_energia(retan->ponto2),pega_Y_ponto_energia(retan->ponto2));

    if(pega_ponto_energia_energia(retan->ponto3) > 0)
        fprintf(txt_qry,"P3: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto3),pega_X_ponto_energia(retan->ponto3),pega_Y_ponto_energia(retan->ponto3));

    if(pega_ponto_energia_energia(retan->ponto4) > 0) 
        fprintf(txt_qry,"P4: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto4),pega_X_ponto_energia(retan->ponto4),pega_Y_ponto_energia(retan->ponto4));

}

void imprime_svg_dados_retangulo(Retangulo Retan, FILE* svg_qry) {
    if(Retan == NULL) return;
    retangulo *retan = (retangulo*) Retan;
    
    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#0000FF\" stroke-width=\"5.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(retan->ponto1),pega_Y_ponto_energia(retan->ponto1) );
    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#0000FF\" stroke-width=\"5.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(retan->ponto2),pega_Y_ponto_energia(retan->ponto2) );
    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#0000FF\" stroke-width=\"5.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(retan->ponto3),pega_Y_ponto_energia(retan->ponto3) );
    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#0000FF\" stroke-width=\"5.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(retan->ponto4),pega_Y_ponto_energia(retan->ponto4) );
    
}

void imprime_txt_dados_retangulo_todos(Retangulo Retan, FILE* txt_qry) { // até os ponto de energia = 0
    if(Retan == NULL) return;
    retangulo *retan = (retangulo*) Retan;
    
    fprintf(txt_qry,"Retangulo: %s\n",retan->id);
    fprintf(txt_qry,"Largura %s\n",retan->largura);
    fprintf(txt_qry,"Altura  %s\n",retan->altura);
    fprintf(txt_qry,"X   %s\n",retan->x);
    fprintf(txt_qry,"Y   %s\n",retan->y);
    fprintf(txt_qry,"Corb   %s\n",retan->corb);
    fprintf(txt_qry,"Corp   %s\n\n",retan->corp);

    fprintf(txt_qry,"P1: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto1),pega_X_ponto_energia(retan->ponto1),pega_Y_ponto_energia(retan->ponto1));
    
    fprintf(txt_qry,"P2: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto2),pega_X_ponto_energia(retan->ponto2),pega_Y_ponto_energia(retan->ponto2));

    fprintf(txt_qry,"P3: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto3),pega_X_ponto_energia(retan->ponto3),pega_Y_ponto_energia(retan->ponto3));

    fprintf(txt_qry,"P4: Energia->%lf X->%lf y->%lf\n",pega_ponto_energia_energia(retan->ponto4),pega_X_ponto_energia(retan->ponto4),pega_Y_ponto_energia(retan->ponto4));

}

void definir_ponto_energia_retangulo(Retangulo Rect, double ponto_energia) {
    if(Rect == NULL) return;
    retangulo *rect = (retangulo*) Rect;

    double energia_distribuida = ponto_energia/4;
    definir_ponto_energia_energia(rect->ponto1, energia_distribuida);
    definir_ponto_energia_energia(rect->ponto2, energia_distribuida);
    definir_ponto_energia_energia(rect->ponto3, energia_distribuida);
    definir_ponto_energia_energia(rect->ponto4, energia_distribuida);
}

void aumenta_ponto_energia_retangulo(Retangulo Rect, double ponto_energia) {
    if(Rect == NULL) return;
    retangulo *rect = (retangulo*) Rect;

    double energia_distribuida = ponto_energia/4;
    aumenta_ponto_energia_energia(rect->ponto1, energia_distribuida);
    aumenta_ponto_energia_energia(rect->ponto2, energia_distribuida);
    aumenta_ponto_energia_energia(rect->ponto3, energia_distribuida);
    aumenta_ponto_energia_energia(rect->ponto4, energia_distribuida);
}

void libera_retangulo(Retangulo Rect) {
    if(Rect == NULL) return;
    retangulo *rect = (retangulo*) Rect;

    free(rect->id);
    free(rect->x);
    free(rect->y);
    free(rect->largura);
    free(rect->altura);
    free(rect->corb);
    free(rect->corp);

    libera_ponto_energia(rect->ponto1);
    libera_ponto_energia(rect->ponto2);
    libera_ponto_energia(rect->ponto3);
    libera_ponto_energia(rect->ponto4);
    free(rect);
}


void normaliza_ponto_energia_retangulo(Retangulo Retan) {
    if(Retan == NULL) return;
    retangulo *retan = (retangulo*) Retan;

    double energia_distribuida = (pega_ponto_energia_energia(retan->ponto1)+pega_ponto_energia_energia(retan->ponto2)+pega_ponto_energia_energia(retan->ponto3)+pega_ponto_energia_energia(retan->ponto4))/4;
    definir_ponto_energia_energia(retan->ponto1, energia_distribuida);
    definir_ponto_energia_energia(retan->ponto2, energia_distribuida);
    definir_ponto_energia_energia(retan->ponto3, energia_distribuida);
    definir_ponto_energia_energia(retan->ponto4, energia_distribuida);
}

int checar_id_retangulo(Retangulo Rect, char* id) {
    if(Rect == NULL) return 0;
    retangulo *rect = (retangulo*) Rect;

    if(id == NULL) return 1;

    if(!strcmp(rect->id, id)) return 1;

    return 0;
}

int checar_pontos_energia_zero_retangulo(Retangulo Retan){
    retangulo *retan = (retangulo*) Retan;

    if(pega_ponto_energia_energia(retan->ponto1) == 0 && pega_ponto_energia_energia(retan->ponto2) == 0 && pega_ponto_energia_energia(retan->ponto3) == 0 && pega_ponto_energia_energia(retan->ponto4) == 0) return 1;

    return 0;
}

char* retangulo_para_string(Retangulo Retan){
    if(Retan == NULL) return NULL;
    retangulo *retan = (retangulo*) Retan;
    
    char* string = (char*) malloc(sizeof(char)*200);
    sprintf(string, "retangulo -> id: %s, largura: %s, altura: %s,  x: %s, y: %s, cor borda: %s, cor preenchimento: %s",retan->id,retan->largura,retan->altura, retan->x,retan->y,retan->corb,retan->corp);
    
    return string;
}