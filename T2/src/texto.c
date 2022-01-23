#include "main.h"
#include "texto.h"


typedef struct texto {
    char* id;
    char* x;
    char* y;
    char* corb;
    char* corp;
    char* conteudo_texto;
    Ponto_Energia ponto1;

}texto;

Text cria_texto(char* id, char* x, char* y, char* corb, char* corp, char* conteudo_texto){
    texto *txt = (texto*) malloc(sizeof(texto));
    txt->id = (char*) malloc((strlen(id) + 1) * sizeof(char));
    txt->x = (char*) malloc((strlen(x) + 1) * sizeof(char));
    txt->y = (char*) malloc((strlen(y) + 1) * sizeof(char));
    txt->corb = (char*) malloc((strlen(corb) + 1) * sizeof(char));
    txt->corp = (char*) malloc((strlen(corp) + 1) * sizeof(char));
    txt->conteudo_texto = (char*) malloc((strlen(conteudo_texto) + 1) * sizeof(char));

    strcpy(txt->id, id);
    strcpy(txt->x, x);
    strcpy(txt->y, y);
    strcpy(txt->corb, corb);
    strcpy(txt->corp, corp);
    strcpy(txt->conteudo_texto, conteudo_texto);

    txt->ponto1 = cria_ponto_energia('t',txt,id,atof(x), atof(y), 0);

    return txt;
}

void imprime_svg_dados_txt(Text Txt, FILE* svg_qry) {
    if(Txt == NULL) return;
    texto *txt = (texto*) Txt;
    fprintf(svg_qry,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1.0\" stroke=\"#FF00FF\" stroke-width=\"2.0\" fill=\"none\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",pega_X_ponto_energia(txt->ponto1), pega_Y_ponto_energia(txt->ponto1));

}

Ponto_Energia pega_P1_txt(Text Txt) {
    if(Txt == NULL) return NULL;
    texto *txt = (texto*) Txt;
    return txt->ponto1;
}

char* pega_id_txt(Text Txt){
    if(Txt == NULL)
        return NULL;

    texto *txt = (texto*) Txt;
    return txt->id;
}

char* pega_X_txt(Text Txt){
    if(Txt == NULL)
        return NULL;

    texto *txt = (texto*) Txt;
    return txt->x;
}

char* pega_Y_txt(Text Txt){
    if(Txt == NULL)
        return NULL;
    texto *txt = (texto*) Txt;
    return txt->y;
}



char* pega_Corb_txt(Text Txt){
    if(Txt == NULL)
        return NULL;
    texto *txt = (texto*) Txt;
    return txt->corb;
}

char* pega_Corp_txt(Text Txt){
    if(Txt == NULL)
        return NULL;
    texto *txt = (texto*) Txt;
    return txt->corp;
}

char* pega_Conteudo_txt(Text Txt){
    if(Txt == NULL)
        return NULL;
    texto *txt = (texto*) Txt;
    return txt->conteudo_texto;
}

void definir_Corb_txt(Text Txt, char* corb){
    if(Txt == NULL)
        return;
    texto *txt = (texto*) Txt;
    strcpy(txt->corb, corb);
}


void definir_Corp_txt(Text Txt, char* corp){
    if(Txt == NULL)
        return;
    texto *txt = (texto*) Txt;
    strcpy(txt->corp, corp);
}


void imprime_txt_id_texto(Text Txt, FILE* txt_qry) {
    if(Txt == NULL) return;
    texto *txt = (texto*) Txt;
    fprintf(txt_qry,"ID Figura: %s\n", txt->id);
}

void imprime_txt_dados_texto_q_interroga(Text Txt, FILE* txt_qry) {
    if(Txt == NULL) return;
    texto *txt= (texto*) Txt;
    
    fprintf(txt_qry,"Txt: %s\n",txt->id);
    fprintf(txt_qry,"X : %s\n",txt->x);
    fprintf(txt_qry,"Y : %s\n",txt->y);
    fprintf(txt_qry,"Corb : %s\n",txt->corb);
    fprintf(txt_qry,"Corp : %s\n",txt->corp);
    fprintf(txt_qry,"Texto: %s\n\n",txt->conteudo_texto);
    
}

void imprime_txt_dados_texto_sem_energia(Text Txt, FILE* txt_qry) {
    if(Txt == NULL) return;
    texto *txt= (texto*) Txt;
    
    fprintf(txt_qry,"Txt: %s\n",txt->id);
    fprintf(txt_qry,"X : %s\n",txt->x);
    fprintf(txt_qry,"Y : %s\n",txt->y);
    fprintf(txt_qry,"Corb : %s\n",txt->corb);
    fprintf(txt_qry,"Corp : %s\n",txt->corp);
    fprintf(txt_qry,"Texto: %s\n\n",txt->conteudo_texto);
    
    fprintf(txt_qry,"P1 : X-> %lf Y-> %lf\n\n",pega_X_ponto_energia(txt->ponto1),pega_Y_ponto_energia(txt->ponto1));
    
}

void imprime_txt_dados_texto(Text Txt, FILE* txt_qry) {
    if(Txt == NULL) return;
    texto *txt= (texto*) Txt;
    
    fprintf(txt_qry,"Txt: %s\n",txt->id);
    fprintf(txt_qry,"X : %s\n",txt->x);
    fprintf(txt_qry,"Y : %s\n",txt->y);
    fprintf(txt_qry,"Corb : %s\n",txt->corb);
    fprintf(txt_qry,"Corp : %s\n",txt->corp);
    fprintf(txt_qry,"Texto: %s\n\n",txt->conteudo_texto);
    if(pega_ponto_energia_energia(txt->ponto1) > 0) fprintf(txt_qry,"P1 : %lf X-> %lf Y-> %lf\n\n",pega_ponto_energia_energia(txt->ponto1),pega_X_ponto_energia(txt->ponto1),pega_Y_ponto_energia(txt->ponto1));
    
}

void imprime_txt_dados_texto_todos(Text Txt, FILE* txt_qry) {
    if(Txt == NULL) return;
    texto *txt= (texto*) Txt;
    
    fprintf(txt_qry,"Txt: %s\n",txt->id);
    fprintf(txt_qry,"X : %s\n",txt->x);
    fprintf(txt_qry,"Y : %s\n",txt->y);
    fprintf(txt_qry,"Corb : %s\n",txt->corb);
    fprintf(txt_qry,"Corp : %s\n",txt->corp);
    fprintf(txt_qry,"Texto: %s\n\n",txt->conteudo_texto);

    fprintf(txt_qry,"P1 : %lf X-> %lf Y-> %lf\n\n",pega_ponto_energia_energia(txt->ponto1),pega_X_ponto_energia(txt->ponto1),pega_Y_ponto_energia(txt->ponto1));
    
}

void definir_ponto_energia_texto(Text Txt, double ponto_energia) {
    if(Txt == NULL) return;
    texto *txt= (texto*) Txt;

    double energia_distribuida = ponto_energia;
    definir_ponto_energia_energia(txt->ponto1, energia_distribuida);
}

void aumenta_ponto_energia_texto(Text Txt, double ponto_energia) {
    if(Txt == NULL) return;
    texto *txt= (texto*) Txt;

    double energia_distribuida = ponto_energia;
    aumenta_ponto_energia_energia(txt->ponto1, energia_distribuida);
}


void imprimir_arvore_texto_aux(Text Txt) {
    if(Txt == NULL) return;
    texto *txt= (texto*) Txt;

    printf("X txt  : %s\n",txt->x);
    printf("Y txt  : %s\n",txt->y);
    printf("Corp txt  : %s\n",txt->corp);
    printf("Texto txt : %s\n",txt->corb);
    printf("P1 txt  : %lf\n",pega_ponto_energia_energia(txt->ponto1));

}

int checar_id_texto(Text Txt, char* id) {
    if(Txt == NULL) return 0;
    texto *txt= (texto*) Txt;

    if(id == NULL){
        return 1;
    } 
        

    if(!strcmp(txt->id, id)){
        return 1;
    }

    return 0;
}


void libera_txt(Text Txt){
    if(Txt == NULL)
        return;

    texto *txt = (texto*) Txt;
    free(txt->id);   
    free(txt->x); 
    free(txt->y);
    free(txt->corb); 
    free(txt->corp);
    free(txt->conteudo_texto);
    free(txt);
}

int checar_pontos_energia_zero_texto(Text Txt) {
    if(Txt == NULL) return 0;
    texto *txt = (texto*) Txt;

    if(pega_ponto_energia_energia(txt->ponto1) == 0) return 1;

    return 0;

}

char* txt_para_string(Text Txt){
    if(Txt == NULL) return NULL;
    texto *txt = (texto*) Txt;
    
    char* string = (char*) malloc(sizeof(char)*500);
    sprintf(string, "texto -> id: %s, x: %s, y: %s, cor borda: %s, cor preenchimento: %s,conteudo: %s",txt->id, txt->x,txt->y,txt->corb,txt->corp,txt->conteudo_texto);
    
    return string;
}