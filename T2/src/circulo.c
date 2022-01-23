#include "main.h"
#include "circulo.h"

typedef struct circulo{
    char* id;
    char* raio;
    char* x;
    char* y;
    char* corb;
    char* corp;

    Ponto_Energia ponto1;
    Ponto_Energia ponto2;
    Ponto_Energia ponto3;

}circulo;

Circulo cria_circulo(char* id, char* raio, char* x, char* y, char* corb, char* corp){

    circulo *circ = (circulo*) malloc(sizeof(circulo));

    circ->id = (char*) malloc((strlen(id) + 1) * sizeof(char));
    circ->raio = (char*) malloc((strlen(raio) + 1) * sizeof(char));
    circ->x = (char*) malloc((strlen(x) + 1) * sizeof(char));
    circ->y = (char*) malloc((strlen(y) + 1) * sizeof(char));
    circ->corb = (char*) malloc ((strlen(corb) + 1) * sizeof(char));
    circ->corp = (char*) malloc((strlen(corp) + 1) * sizeof(char));
    
    strcpy(circ->id, id);
    strcpy(circ->raio, raio);
    strcpy(circ->x, x);
    strcpy(circ->y, y);
    strcpy(circ->corb, corb);
    strcpy(circ->corp, corp);
    
    circ->ponto1 = cria_ponto_energia('c',circ,id,atof(x) - atof(raio), atof(y), 0);
    circ->ponto2 = cria_ponto_energia('c',circ,id,atof(x), atof(y)-atof(raio) , 0);
    circ->ponto3 = cria_ponto_energia('c',circ,id,atof(x) + atof(raio), atof(y), 0);

    return circ;
}

Ponto_Energia pega_P1_circulo(Circulo Circ) {
    if(Circ == NULL) return 0;
    circulo *circ = (circulo*) Circ;
    return circ->ponto1;
}

Ponto_Energia pega_P2_circulo(Circulo Circ) {
    if(Circ == NULL) return 0;
    circulo *circ = (circulo*) Circ;
    return circ->ponto2;
}

Ponto_Energia pega_P3_circulo(Circulo Circ) {
    if(Circ == NULL) return 0;
    circulo *circ = (circulo*) Circ;
    return circ->ponto3;
}


char* pega_id_circulo(Circulo Circ){
    if(Circ == NULL)
        return NULL;
    circulo *circ = (circulo*) Circ;
    return circ->id;
}

char* pega_Raio_circulo(Circulo Circ){
    if(Circ == NULL)
        return NULL;
    circulo *circ = (circulo*) Circ;
    return circ->raio;
}

void Definir_raio_circulo(Circulo Circ, char* raio){
    if(Circ == NULL || raio == NULL)
        return;
    circulo *circ = (circulo*) Circ;
    strcpy(circ->raio, raio);
}

char* pega_X_circulo(Circulo Circ){
    if(Circ == NULL)
        return NULL; 
    circulo *circ = (circulo*) Circ;
    
    return circ->x;
}

void definir_X_circulo(Circulo Circ, char* x){
    if(Circ == NULL)
        return;
    circulo *circ = (circulo*) Circ;
    strcpy(circ->x, x);
}

char* pega_Y_circulo(Circulo Circ){
    if(Circ == NULL)
        return NULL;
    circulo *circ = (circulo*) Circ;
    return circ->y;
}

void definir_Y_circulo(Circulo Circ, char* y){
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    strcpy(circ->y, y);
}

char* pega_Corb_circulo(Circulo Circ){
    if(Circ == NULL)
        return NULL;
    circulo *circ = (circulo*) Circ;
    return circ->corb;
}

void definir_corb_circulo(Circulo Circ, char* corb){
    if(Circ == NULL)
        return;
    circulo *circ = (circulo*) Circ;
    strcpy(circ->corb, corb);
}

char* pega_Corp_circulo(Circulo Circ){
    if(Circ == NULL)
        return NULL;
    circulo *circ = (circulo*) Circ;
    return circ->corp;
}

void definir_corp_circulo(Circulo Circ, char* corp){
    if(Circ == NULL)
        return;
    circulo *circ = (circulo*) Circ;
    strcpy(circ->corp, corp);
}

void libera_circulo(Circulo Circ){
    if(Circ == NULL)
        return;
    circulo *circ = (circulo*) Circ;
    free(circ->id);  
    free(circ->raio);    
    free(circ->x); 
    free(circ->y); 
    free(circ->corb); 
    free(circ->corp);  
    free(circ);
}



void imprimir_circ_aux(Circulo Circ ) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;

    printf("ID -> %s |", circ->id);
    printf("X -> %s  |", circ->x);
    printf("Y -> %s  |\n", circ->y);
}

void imprime_txt_id_circulo(Circulo Circ, FILE* txt_qry) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    fprintf(txt_qry,"ID Figura: %s\n", circ->id);
}

void imprime_txt_dados_circulo_sem_energia(Circulo Circ, FILE* txt_qry) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    
    fprintf(txt_qry,"Circulo: %s\n", circ->id);
    fprintf(txt_qry,"Raio : %s\n", circ->raio);
    fprintf(txt_qry,"X : %s\n", circ->x);
    fprintf(txt_qry,"Y : %s\n", circ->y);
    fprintf(txt_qry,"Corb : %s\n", circ->corb);
    fprintf(txt_qry,"Corp : %s\n\n", circ->corp);

    fprintf(txt_qry,"P1 : X-> %lf Y->%lf\n",pega_X_ponto_energia(circ->ponto1),pega_Y_ponto_energia(circ->ponto1));
    fprintf(txt_qry,"P2 : X-> %lf Y->%lf\n",pega_X_ponto_energia(circ->ponto2),pega_Y_ponto_energia(circ->ponto2));
    fprintf(txt_qry,"P3 : X-> %lf Y->%lf\n\n",pega_X_ponto_energia(circ->ponto3),pega_Y_ponto_energia(circ->ponto3));

}

void imprime_txt_dados_circulo_q_interroga(Circulo Circ, FILE* txt_qry) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    
    fprintf(txt_qry,"Circulo: %s\n", circ->id);
    fprintf(txt_qry,"Raio : %s\n", circ->raio);
    fprintf(txt_qry,"X : %s\n", circ->x);
    fprintf(txt_qry,"Y : %s\n", circ->y);
    fprintf(txt_qry,"Corb : %s\n", circ->corb);
    fprintf(txt_qry,"Corp : %s\n", circ->corp);

}

void imprime_txt_dados_circulo(Circulo Circ, FILE* txt_qry) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    
    fprintf(txt_qry,"Circulo: %s\n", circ->id);
    fprintf(txt_qry,"Raio : %s\n", circ->raio);
    fprintf(txt_qry,"X : %s\n", circ->x);
    fprintf(txt_qry,"Y : %s\n", circ->y);
    fprintf(txt_qry,"Corb : %s\n", circ->corb);
    fprintf(txt_qry,"Corp : %s\n", circ->corp);
    
    if(pega_ponto_energia_energia(circ->ponto1) > 0)
        fprintf(txt_qry,"P1 : Energia->%lf X-> %lf Y->%lf\n",pega_ponto_energia_energia(circ->ponto1),pega_X_ponto_energia(circ->ponto1),pega_Y_ponto_energia(circ->ponto1));

    if(pega_ponto_energia_energia(circ->ponto2) > 0)
        fprintf(txt_qry,"P2 : Energia->%lf X-> %lf Y->%lf\n",pega_ponto_energia_energia(circ->ponto2),pega_X_ponto_energia(circ->ponto2),pega_Y_ponto_energia(circ->ponto2));

    if(pega_ponto_energia_energia(circ->ponto3) > 0)
        fprintf(txt_qry,"P3 : Energia->%lf X-> %lf Y->%lf\n",pega_ponto_energia_energia(circ->ponto3),pega_X_ponto_energia(circ->ponto3),pega_Y_ponto_energia(circ->ponto3));

}

void imprime_txt_dados_circulo_todos(Circulo Circ, FILE* txt_qry) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    
    fprintf(txt_qry,"Circulo: %s\n", circ->id);
    fprintf(txt_qry,"Raio : %s\n", circ->raio);
    fprintf(txt_qry,"X : %s\n", circ->x);
    fprintf(txt_qry,"Y : %s\n", circ->y);
    fprintf(txt_qry,"Corb : %s\n", circ->corb);
    fprintf(txt_qry,"Corp : %s\n", circ->corp);
    
    fprintf(txt_qry,"P1 : Energia->%lf X-> %lf Y->%lf\n",pega_ponto_energia_energia(circ->ponto1),pega_X_ponto_energia(circ->ponto1),pega_Y_ponto_energia(circ->ponto1));

    fprintf(txt_qry,"P2 : Energia->%lf X-> %lf Y->%lf\n",pega_ponto_energia_energia(circ->ponto2),pega_X_ponto_energia(circ->ponto2),pega_Y_ponto_energia(circ->ponto2));

    fprintf(txt_qry,"P3 : Energia->%lf X-> %lf Y->%lf\n",pega_ponto_energia_energia(circ->ponto3),pega_X_ponto_energia(circ->ponto3),pega_Y_ponto_energia(circ->ponto3));

}

void imprimir_arvore_circulo_aux(Circulo Circ) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    
    printf("Raio : %s\n", circ->raio);
    printf("X Circulo  : %s\n", circ->x);
    printf("Y Circulo  : %s\n", circ->y);
    printf("Corb Circulo  : %s\n", circ->corb);
    printf("Corp Circulo  : %s\n\n", circ->corp);
    printf("P1 Circulo  : %lf\n",pega_ponto_energia_energia(circ->ponto1));
    printf("P2 Circulo  : %lf\n",pega_ponto_energia_energia(circ->ponto2));
    printf("P2 Circulo  : %lf\n",pega_ponto_energia_energia(circ->ponto3));

}

void imprime_svg_dados_circulo(Circulo Circ, FILE* svg_qry) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;
    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#FF0000\" stroke-width=\"1.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(circ->ponto1), pega_Y_ponto_energia(circ->ponto1));
    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#FF0000\" stroke-width=\"1.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(circ->ponto2),pega_Y_ponto_energia(circ->ponto2) );

    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#FF0000\" stroke-width=\"1.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(circ->ponto3),pega_Y_ponto_energia(circ->ponto3) );

}


void definir_ponto_energia_circulo(Circulo Circ, double ponto_energia) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;

    double energia_distribuida = ponto_energia/3;
    definir_ponto_energia_energia(circ->ponto1, energia_distribuida);
    definir_ponto_energia_energia(circ->ponto2, energia_distribuida);
    definir_ponto_energia_energia(circ->ponto3, energia_distribuida);
}

void normaliza_ponto_energia_circulo(Circulo Circ) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;

    double energia_distribuida = (pega_ponto_energia_energia(circ->ponto1)+pega_ponto_energia_energia(circ->ponto2)+pega_ponto_energia_energia(circ->ponto3))/3;
    definir_ponto_energia_energia(circ->ponto1, energia_distribuida);
    definir_ponto_energia_energia(circ->ponto2, energia_distribuida);
    definir_ponto_energia_energia(circ->ponto3, energia_distribuida);
}


void aumenta_ponto_energia_circulo(Circulo Circ, double ponto_energia) {
    if(Circ == NULL) return;
    circulo *circ = (circulo*) Circ;

    double energia_distribuida = ponto_energia/3;
    aumenta_ponto_energia_energia(circ->ponto1, energia_distribuida);
    aumenta_ponto_energia_energia(circ->ponto2, energia_distribuida);
    aumenta_ponto_energia_energia(circ->ponto3, energia_distribuida);
}


int checar_id_circulo(Circulo Circ, char* id) {
    if(Circ == NULL) return 0;
    circulo *circ = (circulo*) Circ;

    if(id == NULL) return 1;

    if(!strcmp(circ->id, id)) return 1;

    return 0;
}

int checar_pontos_energia_zero_circulo(Circulo Circ) {
    if(Circ == NULL) return 0;
    circulo *circ = (circulo*) Circ;

    if(pega_ponto_energia_energia(circ->ponto1) == 0 && pega_ponto_energia_energia(circ->ponto2) == 0 && pega_ponto_energia_energia(circ->ponto3) == 0) return 1;

    return 0;

}

char* circulo_para_string(Circulo Circ){
    if(Circ == NULL) return NULL;
    circulo *circ = (circulo*) Circ;
    
    char* string = (char*) malloc(sizeof(char)*200);
    sprintf(string, "circulo -> id: %s, raio: %s, x: %s, y: %s, cor borda: %s, cor preenchimento: %s",circ->id,circ->raio,circ->x,circ->y,circ->corb,circ->corp);
    
    return string;
}