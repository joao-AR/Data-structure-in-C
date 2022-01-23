
#include "ponto_energia.h"
#include "kdtree.h"

typedef struct pontoEnergia{
    char id[20];
    char tipo_figira_de_origem;
    void* figura;
    double x, y;
    double energia;
}ponto_energia;

Ponto_Energia cria_ponto_energia(char tipo_figira_de_origem, void* figura, char* id, double x,double y, double energia){

    ponto_energia *ponto = (ponto_energia*) malloc(sizeof(ponto_energia));
    ponto->tipo_figira_de_origem = tipo_figira_de_origem;
    ponto->figura = figura;
    strcpy(ponto->id, id);
    ponto->x = x;
    ponto->y = y;
    ponto->energia = energia;

    return ponto;
}

void pega_ponto_energia_imprime(Ponto_Energia ponto) {
    if(ponto == NULL)
        return;
    ponto_energia *p_energia = (ponto_energia*) ponto;

    printf("Ponto X -> %f ", p_energia->x);
    printf("Ponto Y -> %f.\n", p_energia->y);

}

void* pega_ponto_energia_figura(Ponto_Energia ponto) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    return p_energia->figura;
}

char pega_ponto_energia_figura_tipo_origem(Ponto_Energia ponto) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    return p_energia->tipo_figira_de_origem;
}

double pega_X_ponto_energia(Ponto_Energia ponto) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    return p_energia->x;
}

double pega_Y_ponto_energia(Ponto_Energia ponto) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    return p_energia->y;
}

double pega_ponto_energia_energia(Ponto_Energia ponto) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    return p_energia->energia;
}

void descontar_ponto_energia(Ponto_Energia ponto, double v) {
    if(ponto == NULL)
        return;
    ponto_energia *p_energia = (ponto_energia*) ponto;

    p_energia->energia -= v;
    if(p_energia->energia < 0) p_energia->energia = 0;
}


void definir_X_ponto_energia(Ponto_Energia ponto, double x) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    p_energia->x = x;
}

void definir_Y_ponto_energia(Ponto_Energia ponto, double y) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    p_energia->y = y;
}

void definir_ponto_energia_energia(Ponto_Energia ponto, double energia) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    p_energia->energia = energia;
}

void aumenta_ponto_energia_energia(Ponto_Energia ponto, double energia) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    p_energia->energia += energia;
}

double calcula_distancia_pontos(double x,double y,double x2,double y2){

    double distancia = 0;
    distancia = sqrt(pow(x2-x,2)+pow(y2-y,2));
    return distancia;
}

int comparar_pontos_pela_coordenada_x(const void* ponto1, const void* ponto2){
    ponto_energia **p_energia1 = (ponto_energia**) ponto1;
    ponto_energia **p_energia2 = (ponto_energia**) ponto2;
    return ((*p_energia1)->x - (*p_energia2)->x);
}


int comparar_pontos_pela_coordenada_y(const void* ponto1, const void* ponto2){
    ponto_energia **p_energia1 = (ponto_energia**) ponto1;
    ponto_energia **p_energia2 = (ponto_energia**) ponto2;
    return ((*p_energia1)->y - (*p_energia2)->y);
}

void libera_ponto_energia(Ponto_Energia ponto) {
    ponto_energia *p_energia = (ponto_energia*) ponto;
    free(p_energia);
}