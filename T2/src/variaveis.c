#include "variaveis.h"

typedef struct variaveis {
    KDTree circulos;
    KDTree retangulos;
    KDTree linhas;
    KDTree textos;
    KDTree geral;
    KDTree pontosEnergia;

    Lista circulos_dentro_retangulo;
    Lista retangulos_dentro_retangulo;
    Lista linhas_dentro_retangulo;
    Lista txts_dentro_retangulo;

    Lista completamete_dentro_retangulo;
    Lista completamente_dentro_circulo;
    Lista completamente_dentro_txt;
    Lista completamente_dentro_linha;

}variaveis_t;

Variaveis cria_variaveis() {
    variaveis_t *var = (variaveis_t*) malloc(sizeof(variaveis_t));

    //Criando arvores
    var->circulos      = cria_kdtree();
    var->retangulos    = cria_kdtree();
    var->linhas        = cria_kdtree();
    var->textos        = cria_kdtree();
    var->geral         = cria_kdtree();
    var->pontosEnergia = cria_kdtree();

    //Criando listas
    var->circulos_dentro_retangulo   = cria_lista();
    var->retangulos_dentro_retangulo = cria_lista();
    var->linhas_dentro_retangulo     = cria_lista();
    var->txts_dentro_retangulo       = cria_lista();

    //Criando listas completamente dentro
    var->completamente_dentro_circulo   = cria_lista();
    var->completamete_dentro_retangulo  = cria_lista();
    var->completamente_dentro_txt       = cria_lista();
    var->completamente_dentro_linha     = cria_lista();

    return var;
}

void define_lista_variaveis(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    //Criando listas
    var->circulos_dentro_retangulo      = cria_lista();
    var->retangulos_dentro_retangulo     = cria_lista();
    var->linhas_dentro_retangulo        = cria_lista();
    var->txts_dentro_retangulo          = cria_lista();
    var->completamente_dentro_circulo   = cria_lista();
    var->completamete_dentro_retangulo  = cria_lista();
    var->completamente_dentro_txt       = cria_lista();
    var->completamente_dentro_linha     = cria_lista();
}

KDTree pega_arvore_circulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->circulos;
}

KDTree pega_arvore_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->retangulos;
}

KDTree pega_arvore_linha(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->linhas;
}

KDTree pega_arvore_txt(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->textos;
}

KDTree pega_arvore_geral(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->geral;
}

void definir_retangulo_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    var->retangulos_dentro_retangulo = cria_lista();
}

Lista pega_retangulo_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->retangulos_dentro_retangulo;
}

Lista pega_circulo_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->circulos_dentro_retangulo;
}

Lista pega_texto_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->txts_dentro_retangulo;
}

Lista pega_linha_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->linhas_dentro_retangulo;
}

Lista pega_completamente_retangulo_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->completamete_dentro_retangulo;
}

Lista pega_completamente_circulo_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->completamente_dentro_circulo;
}

Lista pega_completamente_txt_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->completamente_dentro_txt;
}

Lista pega_completamente_linha_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->completamente_dentro_linha;
}

void definir_circulo_dentro_retangulo(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    var->retangulos_dentro_retangulo = cria_lista();
}




KDTree pega_arvore_ponto_energia(Variaveis variavel) {
    variaveis_t *var = (variaveis_t*) variavel;
    return var->pontosEnergia;
}


