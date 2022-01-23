#include "pilha.h"


typedef struct retangulo
{
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char i[20];
    char w[20];
    char h[20];
}retangulo;

typedef struct circulo {

    char i[20];
    char r[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    
}circulo;

typedef struct linha{

    char i[20];
    char x1[20];
    char y1[20];
    char x2[20];
    char y2[20];
    char cor[20];

}Linha;

typedef struct texto
{
    char i[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char txto[400];
}Text;

struct elemento{
    Rect retan;
    circulo circulo;
    Linha linha;
    Text texto;

    char tipo_forma[20];
    struct elemento *prox;

};



Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));// Pilha* pi = topo da pilha
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int insere_Pilha(char tipo_forma[],Pilha* pi, void* forma){

    Rect* retan;
    circulo* circ;
    Linha* _linha;
    Text* txt;

    if(pi == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL) return 0;

    if (strcmp(tipo_forma,"r")==0){
        
        retan = (Rect*) forma;

        strcpy(no->tipo_forma,"r");
        strcpy(no->retan.i,retan->i);
        strcpy(no->retan.w,retan->w);
        strcpy(no->retan.h,retan->h);
        strcpy(no->retan.x,retan->x);
        strcpy(no->retan.y,retan->y);
        strcpy(no->retan.corb,retan->corb);
        strcpy(no->retan.corp,retan->corp);
        no->prox = NULL;

    }else if(strcmp(tipo_forma,"c")==0){

        circ = (circulo*) forma;

        strcpy(no->tipo_forma,"c");
        strcpy(no->circulo.i,circ->i);
        strcpy(no->circulo.r,circ->r);
        strcpy(no->circulo.x,circ->x);
        strcpy(no->circulo.y,circ->y);
        strcpy(no->circulo.corb,circ->corb);
        strcpy(no->circulo.corp,circ->corp);
        no->prox = NULL;

    }else if(strcmp(tipo_forma,"t")==0){

        txt = (Text*) forma;
        strcpy(no->tipo_forma,"t");
        strcpy(no->texto.i,txt->i);
        strcpy(no->texto.x,txt->x);
        strcpy(no->texto.y,txt->y);
        strcpy(no->texto.corb,txt->corb);
        strcpy(no->texto.corp,txt->corp);
        strcpy(no->texto.txto,txt->txto);
        no->prox = NULL;

    }else if(strcmp(tipo_forma,"l")==0){

        _linha = (Linha*) forma;
        strcpy(no->tipo_forma,"l");
        strcpy(no->linha.i,_linha->i);
        strcpy(no->linha.x1,_linha->x1);
        strcpy(no->linha.y1,_linha->y1);
        strcpy(no->linha.x2,_linha->x2);
        strcpy(no->linha.y2,_linha->y2);
        strcpy(no->linha.cor,_linha->cor);
        no->prox = NULL;
    }


    

    no->prox = (*pi);
    *pi = no;
    return 1;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    int i = 1;
    while(no != NULL){
        if(strcmp(no->tipo_forma,"r")==0){

        printf ("---------%d---------\n",i);
        printf("PILHA-i: %s\n",no->retan.i);
        printf("PILHA-w: %s\n",no->retan.w);
        printf("PILHA-h: %s\n",no->retan.h);
        printf("PILHA-x: %s\n",no->retan.x);
        printf("PILHA-y: %s\n",no->retan.y);
        printf("PILHA-corb: %s\n",no->retan.corb);
        printf("PILHA-corp: %s\n",no->retan.corp);
        printf ("-------------------\n");
        printf ("\n");
    }else if (strcmp(no->tipo_forma,"c")==0){

         printf ("---------%d---------\n",i);
        printf("PILHA-i: %s\n",no->circulo.i);
        printf("PILHA-r: %s\n",no->circulo.r);
        printf("PILHA-x: %s\n",no->circulo.x);
        printf("PILHA-y: %s\n",no->circulo.y);
        printf("PILHA-corb: %s\n",no->circulo.corb);
        printf("PILHA-corp: %s\n",no->circulo.corp);
        printf ("-------------------\n");
        printf ("\n");



    }else if(strcmp(no->tipo_forma,"t")==0){

         printf ("---------%d---------\n",i);
        printf("PILHA-i: %s\n",no->texto.i);
        printf("PILHA-x: %s\n",no->texto.x);
        printf("PILHA-y: %s\n",no->texto.y);
        printf("PILHA-corb: %s\n",no->texto.corb);
        printf("PILHA-corp: %s\n",no->texto.corp);
        printf("PILHA-txt: %s\n",no->texto.txto);
        printf ("-------------------\n");
        printf ("\n");



    }else if (strcmp(no->tipo_forma,"l")==0){
        
        printf ("---------%d---------\n",i);
        printf("PILHA-i: %s\n",no->linha.i);
        printf("PILHA-x1: %s\n",no->linha.x1);
        printf("PILHA-y1: %s\n",no->linha.y1);
        printf("PILHA-x2: %s\n",no->linha.x2);
        printf("PILHA-y2: %s\n",no->linha.y2);
        printf("PILHA-cor: %s\n",no->linha.cor);
        printf ("-------------------\n");
        printf ("\n");

    }
        ++i;
        no = no->prox;
    }

}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }

        free(pi);

        
    }
}

void remove_Pilha(Pilha* pi){
    
    if(pi == NULL) return ;
    
    if((*pi) == NULL)return;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return;
}

Elem* pega_primeiro_elemento_pilha (Pilha *pi){
    Elem* no = *pi;
    return no;
}
