#ifndef __KDTREE_H_
#define __KDTREE_H_

typedef void* Dado;

typedef void* KDTree;

typedef struct no NO; 

KDTree cria_kdtree(void);// cria uma arvore 

int pega_quantidade_KDTree(KDTree Tree);   // recebe uma arvore e retorna a quamtidade ne nós que ela tem
KDTree pega_Raiz_KDTreee(KDTree Tree );    // recebe uma arvore e retorna a sua raiz
KDTree pega_Direita_KDTree(KDTree Tree );  // recebe uma arvore e retorna o ramo a direita da arvore 
KDTree pega_Esquerda_KDTree(KDTree Tree ); // recebe uma arvore e retorna o ramo a esquerda da arvore 
KDTree pega_Dado_KDTree(KDTree Tree );     // recebe uma arvore e retorna o dado/forma dela 


void inserir_kdtree(KDTree Tree, Dado dado, double x, double y);//recebe uma arvore, um dado/forma, e o x e y da forma/dado e insere a forma/dado na arvore 
double pega_X_KDTree(KDTree Tree);// Recebe uma arvore  e pega o seu X 
double pega_Y_KDTree(KDTree Tree);// Recebe uma arvore  e pega o seu Y

void imprimir (KDTree Tree, void (*imprimir)(void*));//recebe uma arvore e a imprime no terminal


// Essa função tem como objetivo receber uma arvore , um valor de energia e definir os valores do ponto de energia da forma com a função que foi passada para definir os pontos de energia, também recebe uma função que checa se vai ser definidos em todos(*) os só na na forma com um id especifico  
void percorre_arvore(KDTree tree, double valor_energia,void (*seta_pontos_energia)(void*, double), int (*checar)(void*, char*), char* id);

//Essa função tem como objetivo imprimir os dados da arvore que foi passada, usando uma função passada como parametro, no entanto essa função vai imprimir todos os dados/formas caso (*) ou apenas a de uma forma com um id especifico essa verificação ocorre na função passada por parametro (*checar)
void percorre_arvore_q_interroga(KDTree tree, void (*printa_dados_da_figura)(void*,FILE*), int (*checar)(void*, char*), char* id, FILE* txt_qry);

// recebe uma arvore e verifica qual vai ser o vizinho mais proximo do X e Y passados como parametro 
Dado encontrar_vizinho_mais_proximo_kdtree(KDTree Tree, double x, double y);

//Essa função tem como objetivo normalizar os pontos de energia de todas as formas e imprime os valores antes e depois da normalização em um arquivo .txt 
void percorre_arvore_nf(KDTree tree,void (*seta_pontos_energia)(void*),void (*imprimir)(void*,FILE*) ,FILE* txt_qry);

void percorre_kdtree_generico(KDTree Tree, void (*funcao)(void*, void*), void* DadoExtra);

// Essa função remove um Nó da arvore 
void deletar_no_kdtree(KDTree Tree, double x, double y);

#endif