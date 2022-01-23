#include "main.h"
#include "parametros.h"
#include "abrir_input.h"
#include "pilha.h"
#include "lista.h"
#include "fila.h"
#include "geo.h"
#include "svg.h"
#include "qry.h"
#include "formas.h"

int main (int argc, char* argv[]){

    // vetor de pilhas
    Pilha* pilhas[10];
    Pilha* pi = cria_Pilha();Pilha* pi2 = cria_Pilha();Pilha* pi3 = cria_Pilha();Pilha* pi4 = cria_Pilha();
    Pilha* pi5 = cria_Pilha();Pilha* pi6 = cria_Pilha();Pilha* pi7 = cria_Pilha();Pilha* pi8 = cria_Pilha();Pilha* pi9 = cria_Pilha();Pilha* pi10 = cria_Pilha();
    pilhas[0]=pi;pilhas[1]= pi2;pilhas[2]=pi3;pilhas[3]=pi4;pilhas[4]=pi5;pilhas[5]=pi6;pilhas[6]=pi7;pilhas[7]=pi8;pilhas[8]=pi9;pilhas[9]=pi10;
     //---------------------------------

    // vetor filas
    Fila* filas[10];
    Fila* fi = cria_Fila();Fila* fi2 = cria_Fila();Fila* fi3 = cria_Fila();Fila* fi4 = cria_Fila();
    Fila* fi5 = cria_Fila();Fila* fi6 = cria_Fila();Fila* fi7 = cria_Fila();Fila* fi8 = cria_Fila();Fila* fi9 = cria_Fila();Fila* fi10 = cria_Fila();
    filas[0]=fi;filas[1]= fi2;filas[2]=fi3;filas[3]=fi4;filas[4]=fi5;filas[5]=fi6;filas[6]=fi7;filas[7]=fi8;filas[8]=fi9;filas[9]=fi10;
    //---------------------------------
    
    // vetor de listas
    Lista* listas[10];
    Lista* li = cria_lista();Lista* li2 = cria_lista();Lista* li3 = cria_lista();Lista* li4 = cria_lista();
    Lista* li5 = cria_lista();Lista* li6 = cria_lista();Lista* li7 = cria_lista();Lista* li8 = cria_lista();Lista* li9 = cria_lista();Lista* li10 = cria_lista();
    listas[0]=li;listas[1]= li2;listas[2]=li3;listas[3]=li4;listas[4]=li5;listas[5]=li6;listas[6]=li7;listas[7]=li8;listas[8]=li9;listas[9]=li10;
    //---------------------------------

    // vetor registradres
    void* registradores[10];
    void* r1; void* r2; void* r3; void* r4; void* r5; void* r6; void* r7; void* r8; void* r9; void* r10;
    registradores[0] = r1; registradores[1] = r2;registradores[2] = r3; registradores[3] = r4; registradores[4] = r5; registradores[5] = r6;registradores[6] = r7; registradores[7] = r8;
    registradores[8] = r9; registradores[9] = r10;

    parametro_void parametros = cria_parametros();
    define_parametros(parametros, argv, argc);

    FILE* geo = abrir_arquivo_input(parametros,"geo");
    

    // SVG do .GEO
    FILE* svg_geo = cria_path_svg_geo (parametros);// cira o nome do svg e o local onde ele vai ser salvo

    salva_formas_nas_pilhas_listas_filas(geo,listas,pilhas,filas);
    imprime_no_svg (listas[0],svg_geo);// criando um .svg com o geo sem o qry

    int sn = tem_qry(parametros); // sn : sim = 0 / nao =1
    if(sn == 1){
        printf ("nao tem qry");
    }else{
        // SVG do .QRY
        FILE* qry = abrir_arquivo_input(parametros,"qry");
        FILE* svg_qry = cria_path_svg_qry(parametros);
        FILE* txt_qry = cria_path_txt(parametros);
        funcoes_qry(qry,svg_qry,txt_qry,listas,filas,pilhas,registradores);
        imprime_no_svg(listas[0],svg_qry);
        fclose (txt_qry);
        fclose(qry);
    }

    //imprime_lista(listas[0]);
    //imprime_lista(listas[1]);
    //imprime_Pilha (pilhas[0]);
    //imprime_Fila(filas[0]);
    for(int ax = 0; ax < 10;ax++){
        libera_Pilha(pilhas[ax]);
        libera_lista(listas[ax]);
        libera_Fila(filas[ax]);
    }
    
    fclose(geo);
    fclose (svg_geo);
    
    return 0;
}