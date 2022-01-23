
#ifndef __VARIAVEIS_H
#define __VARIAVEIS_H

#include "main.h"
#include "kdtree.h"
#include "lista.h"

typedef void *Variaveis;

Variaveis cria_variaveis();

Variaveis pega_arvore_retangulo(Variaveis variavel);  // pega a  arvore de retangulo
Variaveis pega_arvore_circulo(Variaveis variavel);    // pega a  arvore de circulo
Variaveis pega_arvore_linha(Variaveis variavel);      // pega a  arvore de linha
Variaveis pega_arvore_txt(Variaveis variavel);        // pega a  arvore de txt
Variaveis pega_arvore_geral(Variaveis variavel);      // pega a  arvore de que tem todos os dados dentro
KDTree pega_arvore_ponto_energia(Variaveis variavel); // pega a  arvore que tem todos os pontos de energia

Lista pega_circulo_dentro_retangulo(Variaveis variavel);   // pega lista de circulos que estavam dentro do retangulo
Lista pega_texto_dentro_retangulo(Variaveis variavel);     // pega lista de texto que estavam dentro do retangulo
Lista pega_linha_dentro_retangulo(Variaveis variavel);     // pega lista de linha que estavam dentro do retangulo
Lista pega_retangulo_dentro_retangulo(Variaveis variavel); // pega lista de retangulo que estavam dentro do retangulo

void definir_retangulo_dentro_retangulo(Variaveis variavel);
void definir_circulo_dentro_retangulo(Variaveis variavel);
void define_lista_variaveis(Variaveis variavel);

Lista pega_completamente_retangulo_dentro_retangulo(Variaveis variavel); // pega lista de retangulos que estavam com todos os pontos de energia dentro do retangulo
Lista pega_completamente_circulo_dentro_retangulo(Variaveis variavel);   // pega lista de circulos que estavam com todos os pontos de energia dentro do retangulo
Lista pega_completamente_txt_dentro_retangulo(Variaveis variavel);       // pega lista de texto que estavam com todos os pontos de energia dentro do retangulo
Lista pega_completamente_linha_dentro_retangulo(Variaveis variavel);     // pega lista de linhas que estavam com todos os pontos de energia dentro do retangulo

#endif