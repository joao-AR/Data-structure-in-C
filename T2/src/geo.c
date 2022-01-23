#include "geo.h"
#include "variaveis.h"
#include "kdtree.h"

#include "retangulo.h"
#include "circulo.h"
#include "texto.h"
#include "linha.h"

char x[20];char y[20];char corb[20];char corp[20]; char i[20];//todos tem 

    char r[20];//c

    char w[20];char h[20];//r

    char x2[20];char y2[20];char cor[20];// l

    char txto[400];//t

void salva_formas_nas_arvores(FILE* geo, Variaveis arvores_listas){

    int contador_aux = 0;    

    void* retan;
    void* circ;
    void* lin;
    void* txt;


    char tipo_forma [100];
    char final;
    final = getc(geo);
    fseek(geo,0,SEEK_SET);
    
    while (final != EOF){
        
        fscanf(geo,"%s",tipo_forma);

        if(strcmp(tipo_forma, "r")==0){

            fscanf(geo,"%s",i);
            fscanf(geo,"%s",w);
            fscanf(geo,"%s",h);
            fscanf(geo,"%s",x);
            fscanf(geo,"%s",y);
            fscanf(geo,"%s",corb);
            fscanf(geo,"%s",corp);

            Retangulo retangulo = cria_retangulo(i,w,h,x,y,corb,corp);
            
            inserir_kdtree(pega_arvore_retangulo(arvores_listas), retangulo, atof(pega_X_retangulo(retangulo)), atof(pega_Y_retangulo(retangulo)));

            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P1_retangulo(retangulo), pega_X_ponto_energia((pega_P1_retangulo(retangulo))), pega_Y_ponto_energia((pega_P1_retangulo(retangulo))));
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P2_retangulo(retangulo), pega_X_ponto_energia((pega_P2_retangulo(retangulo))), pega_Y_ponto_energia((pega_P2_retangulo(retangulo))));
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P3_retangulo(retangulo), pega_X_ponto_energia((pega_P3_retangulo(retangulo))), pega_Y_ponto_energia((pega_P3_retangulo(retangulo))));
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P4_retangulo(retangulo), pega_X_ponto_energia((pega_P4_retangulo(retangulo))), pega_Y_ponto_energia((pega_P4_retangulo(retangulo))));
            

        }else if (strcmp(tipo_forma, "c")==0){
            
            fscanf(geo,"%s",i);
            fscanf(geo,"%s",r);
            fscanf(geo,"%s",x);
            fscanf(geo,"%s",y);
            fscanf(geo,"%s",corb);
            fscanf(geo,"%s",corp);

            Circulo circ_ = cria_circulo(i,r,x,y,corb,corp);
            inserir_kdtree(pega_arvore_circulo(arvores_listas), circ_, atof(pega_X_circulo(circ_)), atof(pega_Y_circulo(circ_)));
            
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P1_circulo(circ_), pega_X_ponto_energia((pega_P1_circulo(circ_))), pega_Y_ponto_energia((pega_P1_circulo(circ_))));
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P2_circulo(circ_), pega_X_ponto_energia((pega_P2_circulo(circ_))), pega_Y_ponto_energia((pega_P2_circulo(circ_))));
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P3_circulo(circ_), pega_X_ponto_energia((pega_P3_circulo(circ_))), pega_Y_ponto_energia((pega_P3_circulo(circ_))));
        }else if (strcmp(tipo_forma, "t")==0){
            
            fscanf(geo,"%s",i);
            fscanf(geo,"%s",x);
            fscanf(geo,"%s",y);
            fscanf(geo,"%s",corb);
            fscanf(geo,"%s",corp);
            fscanf(geo,"%[^\n]s",txto);

            Text txt = cria_texto(i,x,y,corb,corp,txto);
            inserir_kdtree(pega_arvore_txt(arvores_listas),txt, atof(pega_X_txt(txt)), atof(pega_Y_txt(txt)));
            
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P1_txt(txt), pega_X_ponto_energia((pega_P1_txt(txt))), pega_Y_ponto_energia((pega_P1_txt(txt))));


        
        }else if (strcmp(tipo_forma, "l")==0){

            fscanf(geo,"%s",i);
            fscanf(geo,"%s",x);
            fscanf(geo,"%s",y);
            fscanf(geo,"%s",x2);
            fscanf(geo,"%s",y2);
            fscanf(geo,"%s",cor);

            Linha lin = cria_linha(i,x,y,x2,y2,cor);
            inserir_kdtree(pega_arvore_linha(arvores_listas),lin, atof(pega_x1_linha(lin)), atof(pega_y1_linha(lin)));

            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P1_linha(lin), pega_X_ponto_energia((pega_P1_linha(lin))), pega_Y_ponto_energia((pega_P1_linha(lin))));
            inserir_kdtree(pega_arvore_ponto_energia(arvores_listas), pega_P2_linha(lin), pega_X_ponto_energia((pega_P2_linha(lin))), pega_Y_ponto_energia((pega_P2_linha(lin))));

        }
        final = getc(geo);
        final = getc(geo);// usando dois getc para pegar o proximo caractere para ver se eh EOF 
        fseek(geo,-1,SEEK_CUR);// volta o cursor em um caractere no arquivo para nao causar problemas
            
    }

}