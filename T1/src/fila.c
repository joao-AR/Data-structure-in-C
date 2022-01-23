#include "fila.h"


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

typedef struct elemento{
    retangulo retan;
    circulo circulo;
    Linha linha;
    Text texto;

    char tipo_forma[20];
    struct elemento *prox;

}elemento;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

int insere_Fila(char tipo_forma[],Fila* fi, void* forma){
    if(fi == NULL) return 0;
    elemento *no = (elemento*) malloc(sizeof(elemento));

    if(no == NULL) return 0;

    retangulo* retan;
    circulo* circ;
    Linha* _linha;
    Text* txt;

    if (strcmp(tipo_forma,"r")==0){
        
        retan = (retangulo*) forma;

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

    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    elemento *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    
    return 1;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL) return;

    elemento* no = fi->inicio;

    while(no != NULL){

        if(strcmp(no->tipo_forma,"r")==0){

        printf ("-------------------\n");
        printf("FILA-i: %s\n",no->retan.i);
        printf("FILA-w: %s\n",no->retan.w);
        printf("FILA-h: %s\n",no->retan.h);
        printf("FILA-x: %s\n",no->retan.x);
        printf("FILA-y: %s\n",no->retan.y);
        printf("FILA-corb: %s\n",no->retan.corb);
        printf("FILA-corp: %s\n",no->retan.corp);
        printf ("-------------------\n");
        printf ("\n");
    }else if (strcmp(no->tipo_forma,"c")==0){

        printf ("-------------------\n");
        printf("FILA-i: %s\n",no->circulo.i);
        printf("FILA-r: %s\n",no->circulo.r);
        printf("FILA-x: %s\n",no->circulo.x);
        printf("FILA-y: %s\n",no->circulo.y);
        printf("FILA-corb: %s\n",no->circulo.corb);
        printf("FILA-corp: %s\n",no->circulo.corp);
        printf ("-------------------\n");
        printf ("\n");



    }else if(strcmp(no->tipo_forma,"t")==0){

        printf ("-------------------\n");
        printf("FILA-i: %s\n",no->texto.i);
        printf("FILA-x: %s\n",no->texto.x);
        printf("FILA-y: %s\n",no->texto.y);
        printf("FILA-corb: %s\n",no->texto.corb);
        printf("FILA-corp: %s\n",no->texto.corp);
        printf("FILA-txt: %s\n",no->texto.txto);
        printf ("-------------------\n");
        printf ("\n");



    }else if (strcmp(no->tipo_forma,"l")==0){
        
        printf ("-------------------\n");
        printf("FILA-i: %s\n",no->linha.i);
        printf("FILA-x1: %s\n",no->linha.x1);
        printf("FILA-y1: %s\n",no->linha.y1);
        printf("FILA-x2: %s\n",no->linha.x2);
        printf("FILA-y2: %s\n",no->linha.y2);
        printf("FILA-cor: %s\n",no->linha.cor);
        printf ("-------------------\n");
        printf ("\n");

    }
        no = no->prox;
    }
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        elemento* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
        
    }
}