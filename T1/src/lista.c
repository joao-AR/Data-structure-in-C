
#include "lista.h" //inclui os Protótipos


struct retangulo
{   
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char i[20];
    char w[20];
    char h[20];
    
};

struct circulo {

    char i[20];
    char r[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    
};

struct linha{

    char i[20];
    char x1[20];
    char y1[20];
    char x2[20];
    char y2[20];
    char cor[20];

};

struct texto
{
    char i[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char txto[400];
};

//Definição do tipo lista
struct elemento{

    Rect retan;
    Circ circulo;
    Linha linha;
    Text texto;

    char tipo_forma[20];
    struct elemento *prox;
    struct elemento *ant;
};

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

int insere_lista_final(char tipo_forma[], Lista* li, void* forma){

    Rect* retan;
    Circ* circ;
    Linha* _linha;
    Text* txt;


    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

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

        circ = (Circ*) forma;

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
    

    if((*li) == NULL){//lista vazia: insere início
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(char tipo_forma[],Lista* li, void* forma){
    
    Rect* retan;
    Circ* circ;
    Linha* _linha;
    Text* txt;

    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

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

        circ = (Circ*) forma;

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
    
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(char tipo_forma[],Lista* li, void* forma){

    Rect* retan;
    Circ* circ;
    Linha* _linha;
    Text* txt;


    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

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

        circ = (Circ*) forma;

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

    if((*li) == NULL){//lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        
        while(atual != NULL && atoi(atual->retan.i) < atoi(retan->i)){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

void insere_lista_antes_posi (char tipo_forma[], Lista* li, void* forma,void* registradores[],int posi_registrador,int posi){
    Rect* retan;
    Circ* circ;
    Linha* _linha;
    Text* txt;

    int posicao = 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

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
        registradores[posi_registrador] = &no->retan.i;

    }else if(strcmp(tipo_forma,"c")==0){

        circ = (Circ*) forma;

        strcpy(no->tipo_forma,"c");
        strcpy(no->circulo.i,circ->i);
        strcpy(no->circulo.r,circ->r);
        strcpy(no->circulo.x,circ->x);
        strcpy(no->circulo.y,circ->y);
        strcpy(no->circulo.corb,circ->corb);
        strcpy(no->circulo.corp,circ->corp);
        no->prox = NULL;
        registradores[posi_registrador] = &no->circulo.i;
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
        registradores[posi_registrador] = &no->texto.i;
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
        registradores[posi_registrador] = &no->linha.i;
    }

    if((*li) == NULL){//lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return ;
    }
    else{
        Elem *ant, *atual = *li;
        
        while(atual != NULL && posicao < (posi-1)){
            ant = atual;
            atual = atual->prox;
            ++posicao;
        }
        if(atual == *li){//insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return;
    }
}

void insere_lista_depois_posi(char tipo_forma[], Lista* li, void* forma,void* registradores[],int posi_registrador,int posi){

    Rect* retan;
    Circ* circ;
    Linha* _linha;
    Text* txt;

    int posicao = 0;


    Elem *no = (Elem*) malloc(sizeof(Elem));


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
        registradores[posi_registrador] = &no->retan.i;

    }else if(strcmp(tipo_forma,"c")==0){

        circ = (Circ*) forma;

        strcpy(no->tipo_forma,"c");
        strcpy(no->circulo.i,circ->i);
        strcpy(no->circulo.r,circ->r);
        strcpy(no->circulo.x,circ->x);
        strcpy(no->circulo.y,circ->y);
        strcpy(no->circulo.corb,circ->corb);
        strcpy(no->circulo.corp,circ->corp);
        no->prox = NULL;
        registradores[posi_registrador] = &no->circulo.i;
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
        registradores[posi_registrador] = &no->texto.i;
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
        registradores[posi_registrador] = &no->linha.i;
    }

    if((*li) == NULL){//lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return ;
    }
    else{
        Elem *ant, *atual = *li;
        
        while(atual != NULL && posicao < (posi+1)){
            ant = atual;
            atual = atual->prox;
            ++posicao;
        }
        if(atual == *li){//insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return;
    }

}

Elem* pega_forma_com_id(char id[],Lista* li){

    Elem* no =  *li;
    
    while (no != NULL){

        if (strcmp(no->retan.i,id  )==0){
                return no;
        }else if (strcmp(no->circulo.i,id)==0){
            return no;
        }else if (strcmp(no->linha.i,id)==0){
            return no;
        }else if(strcmp(no->texto.i,id)==0){
            return no;
        }
        no = no->prox;
    }    
    
    
}

Elem* pega_primeiro_elemento_lista(Lista* li){

    Elem* no = *li;
    return no;

}

Elem* pega_forma_na_posicao (char posi[],Lista* li){

    Elem* no = *li;
    int posicao =  atoi(posi);
    int aux = 1;
    while (aux < (posicao-1)){
        
        aux++;
        no = no->prox;

    }
    return no;

}

int pega_posicao_elemento_registrador (Lista* li,void* registrador[],int n_registrador){
    
    int posicao = 1;
    Elem* no =  *li;
    
    while (no != NULL){
        if (registrador[n_registrador]== &no->retan.i){
            
            return posicao;
        }else if (registrador[n_registrador]== &no->circulo.i){
            
            return posicao;
        }else if (registrador[n_registrador]== &no->linha.i){
            return posicao;
        }else if (registrador[n_registrador]== &no->texto.i){
            return posicao;
        }else{
            posicao++;
            no = no->prox;
        }
        
    } 

}

void remove_lista_id (char id[], Lista* li){

     Elem* no =  *li;
     Elem *ant;
    if(li == NULL)   return;
    if((*li) == NULL)return;//lista vazia
        
    
    while (no != NULL){
        
        
        if (strcmp(no->retan.i,id )==0 || 
        strcmp(no->circulo.i,id)==0    || 
        strcmp(no->texto.i,id)==0      || 
        strcmp(no->linha.i,id)==0)     {
            
            if(no == (*li)){
            *li = no->prox;    
            }else{ 
                ant->prox = no->prox;
            }
            
            free(no);
            return;
        }
        ant = no;
        no = no ->prox;
    
    } 



}

void remove_lista_inicio(Lista* li){
    
    if(li == NULL) return;
    if((*li) == NULL)return;//lista vazia

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return;
}

void remover_lista_ants_registrador (Lista* li,int posi){

        Elem* no = *li;
        Elem *ant, *atual = *li;
        int posicao = 0;
        while(atual != NULL && posicao < (posi)){
            ant = atual;
            atual = atual->prox;
            no = no->prox;
            ++posicao;
        }

        if (no!= NULL){
            ant->prox = no->prox;
            free(no);
        }else if (no == NULL){
            printf ("ERRO!!! nao ha nunhum elemento anterior\n");
            return;
        }
        
        
        


}

void remover_lista_dps_registrador (Lista* li,int posi){
        Elem* no = *li;
        Elem *ant, *atual = *li;
        int posicao = 0;
        while(atual != NULL && posicao < (posi-2)){
            ant = atual;
            atual = atual->prox;
            no = no->prox;
            ++posicao;
        }
        
        if(no == *li){
            printf ("ERRO!!! nao ha nunhum elemento depois\n");
            return;
        }
        if (no != NULL ){
            ant->prox = no->prox;
            free(no);
        }
        
        
}

void imprime_lista(Lista* li){

    if(li == NULL)
        return;
    Elem* no = *li;
    
    while(no != NULL){

        if(strcmp(no->tipo_forma,"r")==0){

        printf ("-------------------\n");
        printf("LISTA-i: %s\n",no->retan.i);
        printf("LISTA-w: %s\n",no->retan.w);
        printf("LISTA-h: %s\n",no->retan.h);
        printf("LISTA-x: %s\n",no->retan.x);
        printf("LISTA-y: %s\n",no->retan.y);
        printf("LISTA-corb: %s\n",no->retan.corb);
        printf("LISTA-corp: %s\n",no->retan.corp);
        printf ("-------------------\n");
        printf ("\n");
    }else if (strcmp(no->tipo_forma,"c")==0){

        printf ("-------------------\n");
        printf("LISTA-i: %s\n",no->circulo.i);
        printf("LISTA-r: %s\n",no->circulo.r);
        printf("LISTA-x: %s\n",no->circulo.x);
        printf("LISTA-y: %s\n",no->circulo.y);
        printf("LISTA-corb: %s\n",no->circulo.corb);
        printf("LISTA-corp: %s\n",no->circulo.corp);
        printf ("-------------------\n");
        printf ("\n");



    }else if(strcmp(no->tipo_forma,"t")==0){

        printf ("-------------------\n");
        printf("LISTA-i: %s\n",no->texto.i);
        printf("LISTA-x: %s\n",no->texto.x);
        printf("LISTA-y: %s\n",no->texto.y);
        printf("LISTA-corb: %s\n",no->texto.corb);
        printf("LISTA-corp: %s\n",no->texto.corp);
        printf("LISTA-txt: %s\n",no->texto.txto);
        printf ("-------------------\n");
        printf ("\n");



    }else if (strcmp(no->tipo_forma,"l")==0){
        
        printf ("-------------------\n");
        printf("LISTA-i: %s\n",no->linha.i);
        printf("LISTA-x1: %s\n",no->linha.x1);
        printf("LISTA-y1: %s\n",no->linha.y1);
        printf("LISTA-x2: %s\n",no->linha.x2);
        printf("LISTA-y2: %s\n",no->linha.y2);
        printf("LISTA-cor: %s\n",no->linha.cor);
        printf ("-------------------\n");
        printf ("\n");

    }

        

        no = no->prox;
    }
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
        
    }
}

void esvazia_lista (Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }

        printf("lista esvaziada\n");
        
    }
}