#include "svg.h"
#include "circulo.h"
#include "texto.h"
#include "linha.h"
#include "retangulo.h"
FILE* cria_path_svg_geo (void* parametros){

    char* nome_geo = pega_nome_geo(parametros);
    
    char nome_svg[100]={};
    char *diretorio_saida = pega_diretorio_output(parametros);
    char path_geo_completo[300];
    int aux =0;

    while( aux <100){ //pegando apenas o nome do geo sem o fina .geo
        
        if(nome_geo[aux]=='.'){
            break;
        }else{
            nome_svg[aux] = nome_geo[aux];
        }
        aux++;
    }

    sprintf(path_geo_completo,"%s/%s.svg",diretorio_saida,nome_svg);//criando o path do geo 
    FILE *svg = fopen(path_geo_completo,"w");//abrino o svg do geo
    fprintf(svg,"<svg>\n");
    
    return svg;
}

void imprime_svg_retangulos_rec(KDTree retangulos, FILE *arq) {
    if(retangulos != NULL) {
        imprime_svg_retangulos_rec(pega_Esquerda_KDTree(retangulos), arq);

        fprintf(arq,"<rect width=\"%s\" height=\"%s\" x=\"%s\" y=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity = \"0.8\" stroke-opacity = \"0.8\"/>\n",
        pega_largura_retangulo(pega_Dado_KDTree(retangulos)),pega_Altura_retangulo(pega_Dado_KDTree(retangulos)),pega_X_retangulo(pega_Dado_KDTree(retangulos)),pega_Y_retangulo(pega_Dado_KDTree(retangulos)),pega_Corb_retangulo(pega_Dado_KDTree(retangulos)),pega_Corp_retangulo(pega_Dado_KDTree(retangulos)));

        imprime_svg_retangulos_rec(pega_Direita_KDTree(retangulos), arq);
    }
}

void imprime_svg_circulos_circ(KDTree Circulo, FILE *arq) {
    if(Circulo != NULL) {
        
        imprime_svg_circulos_circ(pega_Esquerda_KDTree(Circulo), arq);

        fprintf(arq,"<circle cx=\"%s\" cy=\"%s\" r=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",
        pega_X_circulo(pega_Dado_KDTree(Circulo)), pega_Y_circulo(pega_Dado_KDTree(Circulo)), pega_Raio_circulo(pega_Dado_KDTree(Circulo)),pega_Corb_circulo(pega_Dado_KDTree(Circulo)),pega_Corp_circulo(pega_Dado_KDTree(Circulo)));

        imprime_svg_circulos_circ(pega_Direita_KDTree(Circulo), arq);
    }
}

void imprime_svg_texto_txt(KDTree Txt, FILE *arq) {
    if(Txt != NULL) {
        
        imprime_svg_texto_txt(pega_Esquerda_KDTree(Txt), arq);
        fprintf (arq,"<text x=\"%s\" y=\"%s\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\" > %s </text> ->\n",pega_X_txt(pega_Dado_KDTree(Txt)), pega_Y_txt(pega_Dado_KDTree(Txt)), pega_Corb_txt(pega_Dado_KDTree(Txt)),pega_Corp_txt(pega_Dado_KDTree(Txt)),pega_Conteudo_txt(pega_Dado_KDTree(Txt)));

        imprime_svg_texto_txt(pega_Direita_KDTree(Txt), arq);
    }
}

void imprime_svg_linha_lin(KDTree Lin, FILE *arq) {
    if(Lin != NULL) {
        
        imprime_svg_linha_lin(pega_Esquerda_KDTree(Lin), arq);

        fprintf (arq,"<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"%s\" stroke-width=\"1.0\"/>\n",pega_x1_linha(pega_Dado_KDTree(Lin)),pega_y1_linha(pega_Dado_KDTree(Lin)),pega_x2_linha(pega_Dado_KDTree(Lin)),pega_y2_linha(pega_Dado_KDTree(Lin)),pega_cor_linha(pega_Dado_KDTree(Lin)));

        imprime_svg_linha_lin(pega_Direita_KDTree(Lin), arq);
    }
}


void imprime_svg(KDTree Retan, KDTree Circ, KDTree Txt, KDTree Lin,FILE* arq) {
    
    if(Retan == NULL || Circ == NULL || Txt == NULL || Lin == NULL ) return;
    
    imprime_svg_retangulos_rec(pega_Raiz_KDTreee(Retan), arq);
    imprime_svg_circulos_circ (pega_Raiz_KDTreee(Circ), arq);
    imprime_svg_texto_txt     (pega_Raiz_KDTreee(Txt), arq);
    imprime_svg_linha_lin     ( pega_Raiz_KDTreee(Lin), arq);

    fprintf(arq,"</svg>");
}
