#include "geo.h"
#include "formas.h"
char x[20];char y[20];char corb[20];char corp[20]; char i[20];//todos tem 

    char r[20];//c

    char w[20];char h[20];//r

    char x2[20];char y2[20];char cor[20];// l

    char txto[400];//t

void salva_formas_nas_pilhas_listas_filas(FILE* geo,Lista* listas[],Pilha* pilhas[],Fila* filas[]){

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

            retan = cria_retangulo(i,w,h,x,y,corb,corp);
            
            for(int aux =0;aux<10;aux++){// inserindo em todas as listas 
            insere_lista_final( "r",listas[aux],retan);
            insere_Pilha("r",pilhas[aux],retan);
            insere_Fila("r",filas[aux],retan);
            }

            

        }else if (strcmp(tipo_forma, "c")==0){
            
            fscanf(geo,"%s",i);
            fscanf(geo,"%s",r);
            fscanf(geo,"%s",x);
            fscanf(geo,"%s",y);
            fscanf(geo,"%s",corb);
            fscanf(geo,"%s",corp);

            circ = cria_circulo(i,r,x,y,corb,corp);

            for(int aux =0;aux<10;aux++){
                insere_Pilha("c",pilhas[aux],circ);
                insere_Fila("c",filas[aux],circ);
                insere_lista_final( "c",listas[aux],circ);
            }
            
            

        }else if (strcmp(tipo_forma, "t")==0){

            fscanf(geo,"%s",i);
            fscanf(geo,"%s",x);
            fscanf(geo,"%s",y);
            fscanf(geo,"%s",corb);
            fscanf(geo,"%s",corp);
            fscanf(geo,"%[^\n]s",txto);

            txt = cria_texto(i,x,y,corb,corp,txto);
            for(int aux =0;aux<10;aux++){
            insere_Pilha("t",pilhas[aux],txt);
            insere_Fila("t",filas[aux],txt);
            insere_lista_final( "t",listas[aux],txt);
            }
        
        }else if (strcmp(tipo_forma, "l")==0){

            fscanf(geo,"%s",i);
            fscanf(geo,"%s",x);
            fscanf(geo,"%s",y);
            fscanf(geo,"%s",x2);
            fscanf(geo,"%s",y2);
            fscanf(geo,"%s",cor);
            
            lin = cria_linha(i,x,y,x2,y2,cor);
            for(int aux =0;aux<10;aux++){
            insere_Pilha("l",pilhas[aux],lin);
            insere_Fila("l",filas[aux],lin);
            insere_lista_final( "l",listas[aux],lin);
            }
        }
        final = getc(geo);
    }
}