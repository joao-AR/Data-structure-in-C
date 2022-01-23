#include "main.h"
#include "lista.h"
#include "retangulo.h"

typedef struct no {
    struct no *anterior;
    Info informacao;
    struct no *proximo;
}no;

typedef struct lista {
    no *primeiro;
    no *ultimo;
}lista;


Lista cria_lista(){
    lista *li = (lista*) malloc(sizeof(lista));

    if(li == NULL)
        return NULL;
    

    li->primeiro = NULL;
    li->ultimo = NULL;
    return li;
}


int tamanho_lista(Lista Li){
    if(Li == NULL)
        return -1;
    
    lista *li = (lista*) Li;
    if(li->primeiro == NULL){
        return 0;
    }else{
        no *NO = li->primeiro;
        int nodeAmount = 0;
        while(NO != NULL){
            nodeAmount++;
            NO = NO->proximo;
        }
        return nodeAmount;
    }
}


No inserir(Lista Li, Info informacao){
    if(Li == NULL || informacao == NULL )
        return NULL;
        
    lista *li = (lista*) Li;

    no *NO = (no*) malloc(sizeof(no));
    NO->informacao = informacao;

    if(li->primeiro == NULL){ //lista vazia
        li->primeiro = NO;
        NO->anterior = NULL;
    }else{
        NO->anterior = li->ultimo;
        NO->anterior->proximo = NO;
    }
    li->ultimo = NO;
    NO->proximo = NULL;

    return NO;
}

No insere_antes(Lista Li, No Posi, Info Informacao){
    if(Li == NULL || Posi == NULL || Informacao == NULL)
        return NULL;

    lista *li = (lista*) Li;
    no *NO = (no*) Posi;
    
    no *No_anterior = (no*) malloc(sizeof(no));
    No_anterior->informacao = Informacao;

    if(NO->anterior == NULL){
        No_anterior->anterior = NULL;
        No_anterior->proximo = NO;

        li->primeiro = No_anterior;
        NO->anterior = No_anterior;
    }else{
        No_anterior->proximo = NO;
        No_anterior->anterior = NO->anterior; 

        No_anterior->anterior->proximo = No_anterior;
        NO->anterior = No_anterior;
    }

    return No_anterior;
}

No insere_depois(Lista Li, No Posi, Info Informacao){   
    
    if(Li == NULL || Posi == NULL || Informacao == NULL)
        return NULL;
        
    lista *li = (lista*) Li;
    no *NO = (no*) Posi;

    no *No_posterior = (no*) malloc(sizeof(no));
    No_posterior->informacao = Informacao;

    if(NO->proximo == NULL){
        No_posterior->proximo = NULL;
        No_posterior->anterior = NO;

        NO->proximo = No_posterior;
        li->ultimo = No_posterior;
    }else{
        No_posterior->proximo = NO->proximo;
        No_posterior->anterior = NO;

        NO->proximo->anterior = No_posterior;
        NO->proximo = No_posterior;
    }

    return No_posterior;
}

No pega_primeiro_lista(Lista Li){
    if(Li == NULL || tamanho_lista(Li) == 0)
        return NULL;
    
    lista *li = (lista*) Li;
    return li->primeiro;
}

No pega_ultimo_lista(Lista Li){
    if(Li == NULL || tamanho_lista(Li) == 0)
        return NULL;

    lista *li = (lista*) Li;
    return li->ultimo;
}

No pega_proximo_lista(Lista Li, No Posi){
    if(Li == NULL || Posi == NULL)
        return NULL;

    no *NO = (no*) Posi;
    return NO->proximo;
}

No pega_anterior_lista(Lista Li, No Posi){ 
    if(Li == NULL || Posi == NULL)
        return NULL;

    no *NO = (no*) Posi;
    return NO->anterior;
}


void imprime_lista(Lista Li, void (*imprime_informacao)(void*)){
    if(Li == NULL)
        return;
    
    lista *li = (lista*) Li;
    if(li->primeiro == NULL)
        return;
    
    no *NO = li->primeiro; 
    while(NO != NULL){
        (*imprime_informacao)(NO->informacao);
        NO = NO->proximo;
    }
}

void insere_lista_completamente_dentro(Lista Li, Lista lista_nova, int (*checa_figura_contida)(void*, void*), void* retangulo_qry){
    if(Li == NULL)
        return;
    
    lista *li = (lista*) Li;
    if(li->primeiro == NULL)
        return;
    
    no *NO = li->primeiro; 
    while(NO != NULL){
        if((*checa_figura_contida)(NO->informacao, retangulo_qry)) {
            inserir(lista_nova, NO->informacao);
        }

        NO = NO->proximo;
    }

    return;
}


void imprime_lista_no_txt(Lista Li, FILE* txt, void (*manda_para_txt)(void*, FILE*)){
    if(Li == NULL)
        return;
    
    lista *li = (lista*) Li;
    if(li->primeiro == NULL)
        return;
    
    no *NO = li->primeiro; 
    while(NO != NULL){
        (*manda_para_txt)(NO->informacao, txt);
        NO = NO->proximo;
    }
}

void imprime_lista_no_svg(Lista Li, FILE* svg, void (*manda_svg)(void*, FILE*)){
    if(Li == NULL)
        return;
    
    lista *li = (lista*) Li;
    if(li->primeiro == NULL)
        return;
    
    no *NO = li->primeiro; 
    while(NO != NULL){
        (*manda_svg)(NO->informacao, svg);
        NO = NO->proximo;
    }
}

void Esvazia_lista(Lista Li, void (*libera_TAD)(void*)){
    if(Li == NULL)
        return;

    lista *li = (lista*) Li;
    
    if(li->primeiro != NULL){
        no *NO = li->primeiro;
        no *No_aux = NO->proximo;
        while(1){
            if(libera_TAD != NULL)
                (*libera_TAD)(NO->informacao);
            
            free(NO);
            NO = No_aux;
            if(NO == NULL){
                break;
            }
            No_aux = No_aux->proximo;
        }
    }

    li->primeiro = NULL; li->ultimo = NULL;
    
}

int remove_NO_lista(Lista Li, No No_remover, void (*libera_TAD)(void*)){
    if(Li == NULL || No_remover == NULL)
        return 0;
        
    lista *li = (lista*) Li;
    no *No = li->primeiro;

    while(No != NULL){

        if(No == No_remover){

            if(libera_TAD != NULL)
                (*libera_TAD)(No->informacao);

            if(No->anterior == NULL){ //remocao no inicio
                li->primeiro = No->proximo;

                if(li->primeiro != NULL) //if (lista resultante tem mais de um elemento) 
                    li->primeiro->anterior = NULL; 

            }else if(No->proximo == NULL){ //remocao no final
                li->ultimo = No->anterior;
                li->ultimo->proximo = NULL;

            }else{ //remocao no meio
                No->anterior->proximo = No->proximo;
                No->proximo->anterior = No->anterior;
            }

            free(No);
            return 1; //no encontrado e removido.
        }
        No = No->proximo;
    }
    
    return 0; //no nao encontrado.
}

void libera_lista(Lista Li, void (*libera_TAD)(void*)){
    if(Li == NULL)
        return;

    lista *li = (lista*) Li;
    
    if(li->primeiro != NULL){
        no *NO = li->primeiro;
        no *No_aux = NO->proximo;
        while(1){
            if(libera_TAD != NULL)
                (*libera_TAD)(NO->informacao);
            
            free(NO);
            NO = No_aux;
            if(NO == NULL){
                break;
            }
            No_aux = No_aux->proximo;
        }
    }

    li->primeiro = NULL; li->ultimo = NULL;
    free(li);
}