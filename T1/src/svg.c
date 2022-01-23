#include "svg.h"

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
    
};

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

void imprime_no_svg (Lista* li,FILE* file){

    if(li == NULL)
        return;
    Elem* no = *li;
    
    while(no != NULL){
        if(strcmp(no->tipo_forma,"r")==0){
        
            fprintf(file,"<rect width=\"%s\" height=\"%s\" x=\"%s\" y=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity = \"0.8\" stroke-opacity = \"0.8\"/>\n", no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);

        }else if (strcmp(no->tipo_forma,"c")==0){

            fprintf(file,"<circle cx=\"%s\" cy=\"%s\" r=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",no->circulo.x,no->circulo.y,no->circulo.r,no->circulo.corb,no->circulo.corp);
        
        }else if (strcmp(no->tipo_forma,"t")==0){

            fprintf (file,"<text x=\"%s\" y=\"%s\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\" > %s </text> ->\n",no->texto.x,no->texto.y,no->texto.corb,no->texto.corp,no->texto.txto);
        }else if (strcmp(no->tipo_forma,"l")==0){

        fprintf ( file,"<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"%s\" stroke-width=\"1.0\"/>\n",no->linha.x1,no->linha.y1,no->linha.x2,no->linha.y2,no->linha.cor);

        }

        no = no->prox;
    }

    fprintf(file,"</svg>");
}