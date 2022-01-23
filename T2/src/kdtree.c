#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "kdtree.h"
#include "circulo.h"


struct no{
    double x, y;
    Dado dado;
    struct no *esquerda,*direita;
};

typedef struct arv{
    int quantidade;
    NO* raiz;
}kdtree;

void inserir_direita(NO* no,  Dado dado, double x, double y, int profundidade);
void inserir_esquerda(NO* no, Dado dado, double x, double y, int profundidade);
void percorre_rec(NO* raiz, double valor_energia, void (*seta_pontos_energia)(void*, double), int (*checar)(void*, char*), char* id);
void percorre_rec_nf(NO* raiz,void (*seta_pontos_energia)(void*),void (*imprimir)(void*,FILE*),FILE* txt_qry);




KDTree cria_kdtree(void){
    kdtree* tree = (kdtree*) malloc(sizeof(kdtree));
    if (tree == NULL) return NULL;
    tree->raiz = NULL;
    tree->quantidade = 0;
    return tree;
}

int pega_quantidade_KDTree(KDTree Tree){
    kdtree* tree = (kdtree*) Tree;
    return tree->quantidade;
}

KDTree pega_Raiz_KDTreee(KDTree Tree ) {
    kdtree* tree = (kdtree*) Tree;
    return tree->raiz;
}

KDTree pega_Direita_KDTree(KDTree Tree ) {
    NO* tree = (NO*) Tree;
    return tree->direita;
}

KDTree pega_Esquerda_KDTree(KDTree Tree ) {
    NO* tree = (NO*) Tree;
    return tree->esquerda;
}

KDTree pega_Dado_KDTree(KDTree Tree ) {
    NO* tree = (NO*) Tree;
    return tree->dado;
}

double pega_X_KDTree(KDTree Tree) {
    NO* tree = (NO*) Tree;
    return tree->x;
}

double pega_Y_KDTree(KDTree Tree) {
    NO* tree = (NO*) Tree;
    return tree->y;
}

typedef struct {
    NO* no;
    double distancia;
}vizinho;

void encontrar_vizinho_mais_proximo_recursivo(int profundidade, double x, double y, NO* no_Atual, vizinho* melhor_Vizinho){
    if(no_Atual == NULL) return;

    double distancia = calcula_distancia_pontos(x, y, no_Atual->x, no_Atual->y);

    if(distancia < melhor_Vizinho->distancia){
        melhor_Vizinho->no = no_Atual;
        melhor_Vizinho->distancia = distancia;
    } 

    NO* lado_Provavel;
    NO* lado_Improvavel;
    double coordenada_No_Atual, coordenada_Busca;

    if (profundidade%2 == 1){ //usa a coordenada X.

        if(x < no_Atual->x){
            lado_Provavel = no_Atual->esquerda;
            lado_Improvavel = no_Atual->direita;
        }else{
            lado_Provavel = no_Atual->direita;
            lado_Improvavel = no_Atual->esquerda;
        }

        coordenada_No_Atual = no_Atual->x;
        coordenada_Busca = x;

    }else{ //usa a coordenada Y.


        if(y < no_Atual->y){
            lado_Provavel = no_Atual->esquerda;
            lado_Improvavel = no_Atual->direita;
        }else{
            lado_Provavel = no_Atual->direita;
            lado_Improvavel = no_Atual->esquerda;
        }

        coordenada_No_Atual = no_Atual->y;
        coordenada_Busca = y;
        
    }

    encontrar_vizinho_mais_proximo_recursivo(profundidade+1, x, y, lado_Provavel, melhor_Vizinho);

    if((abs(coordenada_No_Atual-coordenada_Busca) < melhor_Vizinho->distancia) && lado_Improvavel)
        encontrar_vizinho_mais_proximo_recursivo(profundidade+1, x, y, lado_Improvavel, melhor_Vizinho);

}

Dado encontrar_vizinho_mais_proximo_kdtree(KDTree Tree, double x, double y){
    if (Tree == NULL) return NULL;
    kdtree* arvb = (kdtree*) Tree;
    vizinho melhor_Vizinho;
    melhor_Vizinho.no = NULL;
    melhor_Vizinho.distancia = __INT_MAX__;
    int profundidade = 1;
    encontrar_vizinho_mais_proximo_recursivo(profundidade, x, y, arvb->raiz, &melhor_Vizinho);
    return (melhor_Vizinho.no)->dado;
}


void inserir_kdtree(KDTree Tree, Dado dado, double x, double y){
    
    if (Tree == NULL || dado == NULL) return;
    
    kdtree* arvb = (kdtree*) Tree;
    int profundidade = 1;
    
    if (arvb->raiz == NULL){ // primeira inserção
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->dado = dado;
        novo->x = x;
        novo->y = y;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arvb->raiz = novo;
        
        
    }else if((profundidade%2 != 0)){

        if(x < arvb->raiz->x){
            inserir_esquerda(arvb->raiz, dado, x, y, profundidade+1);
        }else{
            inserir_direita(arvb->raiz, dado, x, y, profundidade+1);
        }
        

        

    }else if (profundidade%2 == 0){

        if(y < arvb->raiz->y ){
            inserir_esquerda(arvb->raiz, dado, x, y, profundidade+1);
        }else{
            inserir_direita(arvb->raiz, dado, x, y, profundidade+1);
        }

    }

    arvb->quantidade++;
}

void inserir_esquerda(NO* no, Dado dado, double x, double y, int profundidade){
    if(no->esquerda == NULL){// não tem ngm a esquerda
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->dado = dado;
        novo->x = x;
        novo->y = y;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }else{
    
        if(profundidade%2 != 0){
            
            if(x < no->esquerda->x){
                
                inserir_esquerda(no->esquerda, dado, x, y, profundidade+1);
            }else{
                inserir_direita(no->esquerda, dado, x, y, profundidade+1);
            }

        }else if(profundidade%2 == 0){

            if(y < no->esquerda->y){
                
                inserir_esquerda(no->esquerda, dado, x, y, profundidade+1);
            }else{
                inserir_direita(no->esquerda, dado, x, y, profundidade+1);
            }
        }
    

    }
}

void inserir_direita(NO* no,  Dado dado, double x, double y, int profundidade){
    if(no->direita == NULL){
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->dado = dado;
        novo->x = x;
        novo->y = y;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }else{
        
        if(profundidade%2 != 0){
            
            if(x < no->direita->x){
                
                inserir_esquerda(no->direita,dado, x, y,profundidade+1);
            }else{
                inserir_direita(no->direita,dado, x, y,profundidade+1);
            }

        }else if(profundidade%2 == 0){
            if(y < no->direita->y){
                
                inserir_esquerda(no->direita,dado, x, y,profundidade+1);
            }else{
                inserir_direita(no->direita,dado, x, y,profundidade+1);
            }
        }
    }
}  




void copia_No(NO* no1, NO* no2){
    no1->dado = no2->dado;
    no1->x = no2->x;
    no1->y = no2->y;
}

NO* no_minimo(NO* x, NO* y, NO* z, int dimensao){
    
    NO *res = x;

    double yC, resC, zC;

    if(dimensao == 1){ //x
       if(y != NULL) yC = y->x;
       resC = res->x;
        if(z != NULL) zC = z->x;

    }else if(dimensao == 0){ //y

         if(y != NULL) yC = y->y;
        resC = res->y;
         if(z != NULL) zC = z->y;
    }

    if (y != NULL && yC < resC) res = y;
    if (z != NULL && zC < resC) res = z;

    return res;

}

NO* encontrar_minimo_recursivo(NO* no, int dimensaoPai, int profundidade){
    if(no == NULL) return NULL;

    int dimensaoFilho = profundidade%2;

    if(dimensaoFilho == dimensaoPai){
        if(no->esquerda == NULL)
            return no;
        return encontrar_minimo_recursivo(no->esquerda, dimensaoPai, profundidade+1);

    }
    
    return no_minimo(no, 
                      encontrar_minimo_recursivo(no->esquerda, dimensaoPai, profundidade+1),
                      encontrar_minimo_recursivo(no->direita, dimensaoPai, profundidade+1),
                      dimensaoPai); 
}

NO* encontrar_minimo(NO* no, int dimensao){
    return encontrar_minimo_recursivo(no, dimensao, 0);
}

int pontos_iguais(double x1, double y1, double x2, double y2){
    if(x1 == x2 && y1 == y2) return 1;
    return 0;
}


NO* deletar_no_recursivo(NO* no_Atual, double x, double y, int profundidade){
    if(no_Atual == NULL) return NULL;

    int dimensao = profundidade % 2;

    if(pontos_iguais(no_Atual->x, no_Atual->y, x, y)){

        if(no_Atual->direita != NULL){

            NO* min = encontrar_minimo(no_Atual->direita, dimensao);

            copia_No(no_Atual, min);

            no_Atual->direita = deletar_no_recursivo(no_Atual->direita, min->x, min->y, profundidade+1);

        }else if(no_Atual->esquerda != NULL){

            NO* min = encontrar_minimo(no_Atual->esquerda, dimensao);

            copia_No(no_Atual, min);

            no_Atual->esquerda = deletar_no_recursivo(no_Atual->esquerda, min->x, min->y, profundidade+1);

        }else{
            free(no_Atual);
            return NULL;
        }

        return no_Atual;
    }

    if(dimensao == 1){

        if(x < no_Atual->x){
            no_Atual->esquerda = deletar_no_recursivo(no_Atual->esquerda, x, y, profundidade+1);
        }else{
            no_Atual->direita = deletar_no_recursivo(no_Atual->direita, x, y, profundidade+1);
        }

    }else if(dimensao == 0){

        if(y < no_Atual->y ){
            no_Atual->esquerda = deletar_no_recursivo(no_Atual->esquerda, x, y, profundidade+1);
        }else{
            no_Atual->direita = deletar_no_recursivo(no_Atual->direita, x, y, profundidade+1);
        }

    }

    return no_Atual;
}

void deletar_no_kdtree(KDTree Tree, double x, double y){
    if (Tree == NULL) return;
    kdtree* arvb = (kdtree*) Tree;
    arvb->raiz = deletar_no_recursivo(arvb->raiz, x, y, 1);
} 


//Percorre arvore fazendo uma função pré determinada
void percorre_rec_q_interroga(NO* raiz, void (*printa_dados_da_figura)(void*, FILE*), int (*checar)(void*, char*), char* id, FILE* txt_qry){

    if(raiz != NULL){
        percorre_rec_q_interroga(raiz->esquerda, printa_dados_da_figura, checar, id, txt_qry);
        if((*checar)(raiz->dado, id)) (*printa_dados_da_figura)(raiz->dado, txt_qry);
        percorre_rec_q_interroga(raiz->direita, printa_dados_da_figura, checar, id, txt_qry);

    }

    return;
}

void percorre_arvore_q_interroga(KDTree tree, void (*printa_dados_da_figura)(void*,FILE*), int (*checar)(void*, char*), char* id, FILE* txt_qry){
    if (tree == NULL) return;
    kdtree* arvb = (kdtree*) tree;
    percorre_rec_q_interroga(arvb->raiz, printa_dados_da_figura, checar, id, txt_qry);
}

//-----------------------------------------------------
void percorre_rec_nf(NO* raiz, void (*seta_pontos_energia)(void*),void (*printa_dados_da_figura)(void*, FILE*), FILE* txt_qry){

    if(raiz != NULL){
        percorre_rec_nf(raiz->esquerda,seta_pontos_energia,printa_dados_da_figura,  txt_qry);
        fprintf (txt_qry,"Antes da normalização\n");
        (*printa_dados_da_figura)(raiz->dado, txt_qry);
        (*seta_pontos_energia)(raiz->dado);
        fprintf (txt_qry,"Depois da normalização\n");
        (*printa_dados_da_figura)(raiz->dado, txt_qry);
        percorre_rec_nf(raiz->direita,seta_pontos_energia, printa_dados_da_figura,  txt_qry);

    }

    return;
}

void percorre_arvore_nf(KDTree tree, void (*seta_pontos_energia)(void*), void (*printa_dados_da_figura)(void*,FILE*), FILE* txt_qry){
    if (tree == NULL) return;
    kdtree* arvb = (kdtree*) tree;
    percorre_rec_nf(arvb->raiz, seta_pontos_energia, printa_dados_da_figura, txt_qry);
}

//-------------------------
void percorre_rec(NO* raiz, double valor_energia, void (*seta_pontos_energia)(void*, double), int (*checar)(void*, char*), char* id){

    if(raiz != NULL){
        percorre_rec(raiz->esquerda, valor_energia, seta_pontos_energia, checar, id);
        if((*checar)(raiz->dado, id)) (*seta_pontos_energia)(raiz->dado, valor_energia);
        percorre_rec(raiz->direita, valor_energia, seta_pontos_energia, checar, id);

    }

    return;
}


//Andar na arvore
void percorre_arvore(KDTree tree, double valor_energia,void (*seta_pontos_energia)(void*, double), int (*checar)(void*, char*), char* id){
    if (tree == NULL) return;
    kdtree* arvb = (kdtree*) tree;
    percorre_rec(arvb->raiz, valor_energia, seta_pontos_energia, checar, id);
}

void imprimirRec(NO* raiz, void (*print)(void*)){

    if(raiz != NULL){
        imprimirRec(raiz->esquerda, print);
        (*print)(raiz->dado);
        imprimirRec(raiz->direita, print);

    }

    return;
}



void imprimir(KDTree Tree, void (*imprimir)(void*)){
    if (Tree == NULL) return;
    kdtree* arvb = (kdtree*) Tree;
    imprimirRec(arvb->raiz, imprimir);
}



void percorre_kdtree_generico_recursivo(NO* raiz, void (*funcao)(void*, void*), void* DadoExtra){

    if(raiz != NULL){
        percorre_kdtree_generico_recursivo(raiz->esquerda, funcao, DadoExtra);
        (*funcao)(raiz->dado, DadoExtra);
        percorre_kdtree_generico_recursivo(raiz->direita, funcao, DadoExtra);

    }

    return;
}

void percorre_kdtree_generico(KDTree Tree, void (*funcao)(void*, void*), void* DadoExtra){
    if (Tree == NULL || funcao == NULL) return;
    kdtree* arvb = (kdtree*) Tree;
    percorre_kdtree_generico_recursivo(arvb->raiz, funcao, DadoExtra);
}