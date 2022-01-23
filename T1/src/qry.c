
#include "qry.h"

typedef struct retangulo
{
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char i[20];
    char w[20];
    char h[20];
}retangulo;

typedef struct circulo {

    char i[20];
    char r[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    
}circulo;

typedef struct linha{

    char i[20];
    char x1[20];
    char y1[20];
    char x2[20];
    char y2[20];
    char cor[20];

}Linha;

typedef struct texto
{
    char i[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char txto[400];
}Text;

struct elemento{
    retangulo retan;
    circulo circulo;
    Linha linha;
    Text texto;

    char tipo_forma[20];
    struct elemento *prox;

};

void funcoes_qry (FILE* qry,FILE* svg_qry,FILE* txt_qry,Lista* listas[],Fila* filas[],Pilha* pilhas[], void* registradores[]){
        char tipo_qry[20];
        char final;
        final = getc(qry);
        fseek(qry,0,SEEK_SET);

    while (final != EOF){
            
            fscanf(qry,"%s",tipo_qry);

            if(strcmp(tipo_qry, "o?")==0){
        
                fprintf (txt_qry,"%s\n",tipo_qry);
                char j[10]; char k[10]; char id[20]; char cor1[20]; char cor2[20];
                fscanf(qry,"%s",j);
                fscanf(qry,"%s",k);
                fscanf(qry,"%s",id);
                fscanf(qry,"%s",cor1);
                fscanf(qry,"%s",cor2);
                sobreposicao_de_formas(j,k,id,cor1,cor2, listas[0],txt_qry,svg_qry);
            
            }else if (strcmp(tipo_qry, "i?")==0){

                fprintf (txt_qry,"%s\n",tipo_qry);
                char j[20]; char x[20]; char y[20];

                fscanf (qry,"%s",j);
                fscanf (qry,"%s",x);
                fscanf (qry,"%s",y);
                
                eh_iterno (j,x,y,listas[0],txt_qry,svg_qry);
                


            }else if (strcmp(tipo_qry, "pnt")==0){

                fprintf (txt_qry,"%s\n",tipo_qry);
                char j[20]; char corb[20]; char corp[20];
                fscanf (qry,"%s",j);
                fscanf (qry,"%s",corb);
                fscanf (qry,"%s",corp);
                
                muda_corb_corp (j,corb,corp,listas[0],txt_qry);
            }else if (strcmp(tipo_qry, "delf")==0){
                
                fprintf (txt_qry,"delf\n");
                char j[20];
                fscanf (qry,"%s",j);
                Remove_elemento_id_j(j,listas[0],txt_qry);
                
                

            }else if(strcmp(tipo_qry, "psh")==0){
                fprintf (txt_qry,"psh\n");
                char p[10]; char i[20];
                fscanf (qry,"%s",p);
                fscanf (qry,"%s",i);
                int pilha = atoi(p);
                pilha = pilha - 1;

                empilha_pilha_p(pilhas[pilha],i,listas[1]);
            }else if(strcmp(tipo_qry, "pop")==0){
                fprintf(txt_qry,"pop\n");
                char p[20]; char i[20]; char dx[20];char dy[20]; char prop[20];
                fscanf (qry,"%s",p);
                fscanf (qry,"%s",i);
                fscanf (qry,"%s",dx);
                fscanf (qry,"%s",dy);
                fscanf (qry,"%s",prop);
                
                int pilha = atoi(p);
                pilha = pilha - 1;
                remove_empilha_modificado(pilhas[pilha],i,dx,dy,prop,txt_qry);
            }else if(strcmp(tipo_qry, "inf")==0){
                
                fprintf (txt_qry,"inf\n");
                char f[10]; char i[20];
                fscanf (qry,"%s",f);
                fscanf (qry,"%s",i);
                int fila = atoi(f);
                fila = fila - 1;

                insere_na_fila_id(listas[0],filas[fila],i);

            }else if(strcmp(tipo_qry, "rmf")==0){
                
                fprintf(txt_qry,"rmf\n");
                char f[20]; char i[20]; char dx[20];char dy[20]; char prop[20];
                fscanf (qry,"%s",f);
                fscanf (qry,"%s",i);
                fscanf (qry,"%s",dx);
                fscanf (qry,"%s",dy);
                fscanf (qry,"%s",prop);
                
                int fila = atoi(f);
                fila = fila - 1;
                remove_insere_Fila_modificado (listas[0],filas[fila],i,dx,dy,prop,txt_qry);

            }else if(strcmp(tipo_qry, "ii")==0){
                
                fprintf (txt_qry,"ii\n");
                char l[20]; char id[20]; char r[20]; 
                
                fscanf (qry,"%s",l);
                fscanf (qry,"%s",id);
                fscanf (qry,"%s",r);
                int re = atoi(r);
                re = re-1;
                int lista = atoi(l);
                lista = lista - 1;
                
                insere_inicio_lista_registrador(listas[lista],id,registradores,re);

            }else if(strcmp(tipo_qry, "if")==0){
                fprintf (txt_qry,"if\n");
                char l[20]; char id[20]; char r[20]; 
                
                fscanf (qry,"%s",l);
                fscanf (qry,"%s",id);
                fscanf (qry,"%s",r);
                int re = atoi(r);
                re = re-1;
                int lista = atoi(l);
                lista = lista - 1;
                
                insere_fim_lista_registrador(listas[lista],id,registradores,re);

            }else if(strcmp(tipo_qry, "ia")==0){
                fprintf(txt_qry,"ia\n");
                char l[20]; char i[20]; 
                char ro[20]; char rd[20];

                fscanf(qry,"%s",l);
                fscanf(qry,"%s",i);
                fscanf(qry,"%s",ro);
                fscanf(qry,"%s",rd);

                int lista = atoi(l); int iro = atoi(ro); int ird = atoi(rd); 
                lista = lista -1; iro = iro -1; ird = ird -1;
                insere_lista_antes_registrador(listas[lista],i,registradores,iro,ird);
            }else if(strcmp(tipo_qry, "id")==0){
                fprintf(txt_qry,"id\n");
                char l[20]; char i[20]; 
                char ro[20]; char rd[20];

                fscanf(qry,"%s",l);
                fscanf(qry,"%s",i);
                fscanf(qry,"%s",ro);
                fscanf(qry,"%s",rd);

                int lista = atoi(l); int iro = atoi(ro); int ird = atoi(rd); 
                lista = lista -1; iro = iro - 1;ird = ird -1;
                insere_lista_depois_registrador(listas[lista],i,registradores,iro,ird);
                

            }else if(strcmp(tipo_qry, "da")==0){
                fprintf(txt_qry,"da\n");
                char l[20]; char r[20];
                fscanf(qry,"%s",l);
                fscanf(qry,"%s",r);
                int lista = atoi(l);
                lista = lista -1;
                int re = atoi (r);
                re = re -1;
                remove_lista_antes_registrador(listas[lista],registradores,re);
            }else if(strcmp(tipo_qry, "dd")==0){
            
                char l[20]; char r[20];
                fscanf(qry,"%s",l);
                fscanf(qry,"%s",r);
                int lista = atoi(l);
                lista = lista -1;
                int re = atoi (r);
                re = re -1;
                remove_lista_depois_registrador(listas[lista],registradores,re);
            }else if(strcmp(tipo_qry, "dpl")==0){
                
                char l[20],i[20],dx[20],dy[20],prop[20],incprop[20];

                fscanf(qry,"%s",l);
                fscanf(qry,"%s",i);
                fscanf(qry,"%s",dx);
                fscanf(qry,"%s",dy);
                fscanf(qry,"%s",prop);
                fscanf(qry,"%s",incprop);

                int lista = atoi(l); lista = lista-1;
                int id = atoi(i);
                float _prop = atof(prop);
                float _incprop = atof(incprop);
                percorre_lista_cria_elementos_esvazia(listas[lista],lista,id,dx,dy,_prop,_incprop,listas,pilhas,filas);

            }
            final = getc(qry);
            final = getc(qry);// usando dois getc para pegar o proximo caractere para ver se eh EOF 
            fseek(qry,-1,SEEK_CUR);// volta o cursor em um caractere no arquivo para nao causar problemas
            
        }
}

FILE* cria_path_txt (void* parametros){

    char* nome_geo = pega_nome_geo(parametros);
    char* nome_qry = pega_nome_qry (parametros);
    char nome_svg[100]={};
    char nome_svg2[100]={};
    char *diretorio_saida = pega_diretorio_output(parametros);
    char path_txt_completo[300];
    int aux =0;

    while( aux <100){ //pegando apenas o nome do qry sem o final .qry
        
        if(nome_qry[aux]=='.'){
            break;
        }else if (nome_qry[aux]=='/'){
            nome_svg2[aux] = '-'; // tirando / e substituindo por -
            }else{
            nome_svg2[aux] = nome_qry[aux];
        }
        
        aux++;
    }


    sprintf(path_txt_completo,"%s/%s-%s.txt",diretorio_saida,nome_svg,nome_svg2);//criando o path do geo 
    FILE *txt = fopen(path_txt_completo,"w");//abrino o svg do geo
    
    return txt;
}

FILE* cria_path_svg_qry (void* parametros){
    
    char* nome_geo = pega_nome_geo (parametros);
    char* nome_qry = pega_nome_qry (parametros);

    char nome_svg[100]={};
    char nome_svg2[100] ={};
    char *diretorio_saida = pega_diretorio_output(parametros);
    char path_qry_completo[300];
    int aux =0;
    
    while( aux <100){ //pegando apenas o nome do qry sem o final .qry
        
        if(nome_qry[aux]=='.'){
            break;
        }else if(nome_qry[aux]== '/'){
            nome_svg2[aux] = '-'; // tirando / e substituindo por -
            }else{
            nome_svg2[aux] = nome_qry[aux];
        }
        
        aux++;
    }

    sprintf(path_qry_completo,"%s/%s-%s.svg",diretorio_saida,nome_svg,nome_svg2);//criando o path do geo 
    FILE *svg = fopen(path_qry_completo,"w");//abrino o svg do geo
    fprintf(svg,"<svg>\n");
    return svg;
}

void sobreposicao_de_formas(char j[],char k[],char id[],char cor1[],char cor2[],Lista* li,FILE* txt,FILE* svg_qry){
    
    Elem* noJ = pega_forma_com_id (j,li);
    Elem* noK =  pega_forma_com_id (k,li);


    if(strcmp(noJ->tipo_forma,"r")==0 && strcmp(noK->tipo_forma,"r")==0 ){

        float kY = atof(noK->retan.y); float jY = atof(noJ->retan.y); 
        float kH = atof(noK->retan.h); float jH = atof(noJ->retan.h);
        float kX = atof(noK->retan.x); float jX = atof(noJ->retan.x);
        float kW = atof(noK->retan.w); float jW = atof(noJ->retan.w);

        //Eles vão se sobrepor quando pelo menos umas das condiçoes abaixo forem satisfeitas: 
        if( ((kY + kH > jY) && (kY < jY + jH)) ||
            ((kY < jY + jH) && (kY + kH > jY)) ||
            ((kX + kW > jX) && (kX < jX + jW)) ||
            ((kX < jX + jW) && (kX + kW > jX)) ){
            
            fprintf(txt,"j= %s e K= %s estao sobrepostos\n",j,k);

            strcpy(noJ->retan.corp,cor1);
            strcpy(noK->retan.corp,cor1);

            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY + jH);

            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY + kH);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);

            float max_rx; float max_ry; float min_rx; float min_ry;

            if(kX>jX){
                min_rx = jX;
            }else{
                min_rx = kX;
            }  

            if(kY>jY){
                min_ry = jY;
            }else{
                min_ry = kY;
            }

            if( (kX + kW) > (jX+jW) ){
                max_rx = kX + kW;
            }else{
                max_rx = jX+jW;
            }

            if( (kY + kH) > (jY+jH) ){
                max_ry = kY + kH;
            }else{
                max_ry = jY+jH;
            }
            
            float w_retan_pontilhado; float h_retan_pontilhado;
            
            w_retan_pontilhado = (max_rx - min_rx );
            h_retan_pontilhado = (max_ry - min_ry);
            
            fprintf(svg_qry,"<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" stroke=\"blue\" stroke-width=\"1.0\" fill-opacity=\"0\" stroke-dasharray=\"2,2\"/>\n",w_retan_pontilhado,h_retan_pontilhado,min_rx,min_ry);
            
            
        }else{
            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY + jH);

            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY + kH);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);
            fprintf(txt,"j= %s e K= %s nao estao sobrepostos\n",j,k);
            strcpy(noJ->retan.corp,cor2);
            strcpy(noK->retan.corp,cor2);
        }
        
    }else if(strcmp(noJ->tipo_forma,"c")==0 && strcmp(noK->tipo_forma,"c")==0){
        float jR = atof(noJ->circulo.r); float kR = atof(noK->circulo.r); 
        float jX = atof(noJ->circulo.x); float kX = atof(noK->circulo.x);
        float jY = atof(noJ->circulo.y); float kY = atof(noK->circulo.y);

        double distancia_entre_centros = sqrt(pow((kX - jX), 2) + pow((kY - jY), 2));

        if(distancia_entre_centros < jR + kR){ //Se sobrepõem:

            fprintf(txt,"j= %s e K= %s estao sobrepostos\n",j,k);
            strcpy(noJ->circulo.corp,cor1);
            strcpy(noK->circulo.corp,cor1);
            
            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY);

            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);

            float max_rx; float max_ry; float min_rx; float min_ry;

            if((kX - kR) > (jX - jR) ){
                min_rx = jX - jR;
            }else{
                min_rx = kX - kR;
            }  

            if(kY > (jY-jR) ){
                min_ry = jY-jR;
            }else{
                min_ry = kY;
            }

            if( (kX + kR) > (jX+jR) ){
                max_rx = kX + kR;
            }else{
                max_rx = jX+jR;
            }

            if( (kY + kR) > (jY+jR) ){
                max_ry = kY + kR;
            }else{
                max_ry = jY+jR;
            }
            
            float w_retan_pontilhado; float h_retan_pontilhado;
            
            w_retan_pontilhado = (max_rx - min_rx );
            h_retan_pontilhado = (max_ry - min_ry);
            
            fprintf(svg_qry,"<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" stroke=\"blue\" stroke-width=\"1.0\" fill-opacity=\"0\" stroke-dasharray=\"2,2\"/>\n",w_retan_pontilhado,h_retan_pontilhado,min_rx,min_ry);
            

        }else{ //Não se sobrepõem:
            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY);

            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);
        fprintf(txt,"j= %s e K= %s nao estao sobrepostos\n",j,k);
            strcpy(noJ->retan.corp,cor2);
            strcpy(noK->retan.corp,cor2);
        }

        
    }else if(strcmp(noJ->tipo_forma,"c")==0 && strcmp(noK->tipo_forma,"r")==0){

        float jR = atof(noJ->circulo.r); float kY = atof(noK->retan.y);
        float jX = atof(noJ->circulo.x); float kX = atof(noK->retan.x);
        float jY = atof(noJ->circulo.y); float kW = atof(noK->retan.w);
                                         float kH = atof(noK->retan.h);

        float ponto_x_retangulo;
        if(jX<kX){
            ponto_x_retangulo = kX;
        }else if(jX> (kX+kW)){
            ponto_x_retangulo = kX+kW;
        }else{
            ponto_x_retangulo = jX;
        }

        float ponto_y_retangulo;
        if(jY<kY){
            ponto_y_retangulo = kY;
        }else if(jY> (kY+kH)){
            ponto_y_retangulo = kY+kH;
        }else{
            ponto_y_retangulo = jY;
        }

        //distancia entre o centro dos circulo e o ponto do retangulo mais proximo dele:
        double Distancia = sqrt(pow((ponto_x_retangulo - jX), 2) + pow((ponto_y_retangulo - jY), 2));

        if(Distancia < jR){// sobrepostos
            fprintf(txt,"j= %s e K= %s estao sobrepostos\n",j,k);

            strcpy(noJ->circulo.corp,cor1);
            strcpy(noK->retan.corp,cor1);

            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY);
            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY + kH);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);

            float max_rx; float max_ry; float min_rx; float min_ry;

            if( kX > (jX - jR) ){
                min_rx = jX - jR;
            }else{
                min_rx = kX;
            }  

            if( kY>(jY - jR) ){
                min_ry = jY- jR;
            }else{
                min_ry = kY;
            }

            if( (kX + kW) > (jX+jR) ){
                max_rx = kX + kW;
            }else{
                max_rx = jX+jR;
            }

            if( (kY + kH) > (jY+jR) ){
                max_ry = kY + kH;
            }else{
                max_ry = jY+jR;
            }
            
            float w_retan_pontilhado; float h_retan_pontilhado;
            
            w_retan_pontilhado = (max_rx - min_rx );
            h_retan_pontilhado = (max_ry - min_ry);
            
            fprintf(svg_qry,"<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" stroke=\"blue\" stroke-width=\"1.0\" fill-opacity=\"0\" stroke-dasharray=\"2,2\"/>\n",w_retan_pontilhado,h_retan_pontilhado,min_rx,min_ry);
            
            
            
        }else{// não sobrepostos

            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY);
            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY + kH);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);

            fprintf(txt,"j= %s e K= %s nao estao sobrepostos\n",j,k);
            strcpy(noJ->circulo.corp,cor2);
            strcpy(noK->retan.corp,cor2);
        }
    
    }else if(strcmp(noJ->tipo_forma,"r")==0 && strcmp(noK->tipo_forma,"c")==0){


        float jY = atof(noJ->retan.y); float kR = atof(noK->circulo.r);
        float jX = atof(noJ->retan.x); float kX = atof(noK->circulo.x);
        float jW = atof(noJ->retan.w); float kY = atof(noK->circulo.y);
        float jH = atof(noJ->retan.h);

        float ponto_x;
        if(kX< jX){
            ponto_x = jX;
        }else if(kX > (jX + jW)){
            ponto_x = jX + jW;
        }else{
            ponto_x = kX;
        }

        float ponto_y;
        if(kY< jY){
            ponto_y = jY;
        }else if(kY > (jY + jH)){
            ponto_y = jY + jH;
        }else{
            ponto_y = kY;
        }


        double Distancia = sqrt(pow((ponto_x- kX), 2) + pow((ponto_y - kY), 2));

        if(Distancia < kR){//  sobrepostos
            fprintf(txt,"j= %s e K= %s estao sobrepostos\n",j,k); 
            strcpy(noJ->retan.corp,cor1);
            strcpy(noK->circulo.corp,cor1);
            
            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY + jH);
            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);
            
            float max_rx; float max_ry; float min_rx; float min_ry;

            if((kX - kR) >  jX ){
                min_rx = jX ;
            }else{
                min_rx = kX - kR;
            }  

            if((kY - kR) > jY){
                min_ry = jY;
            }else{
                min_ry = kY - kR;
            }

            if( (kX + kR) > (jX+jW) ){
                max_rx = kX + kR;
            }else{
                max_rx = jX+jW;
            }

            if( (kY + kR) > (jY+jH) ){
                max_ry = kY + kR;
            }else{
                max_ry = jY+jH;
            }
            
            float w_retan_pontilhado; float h_retan_pontilhado;
            
            w_retan_pontilhado = (max_rx - min_rx );
            h_retan_pontilhado = (max_ry - min_ry);
            
            fprintf(svg_qry,"<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" stroke=\"blue\" stroke-width=\"1.0\" fill-opacity=\"0\" stroke-dasharray=\"2,2\"/>\n",w_retan_pontilhado,h_retan_pontilhado,min_rx,min_ry);
            

        }else{// não sobrepostos
            char x1[20]; sprintf (x1,"%lf",jX);
            char y1[20]; sprintf (y1,"%lf",jY + jH);
            char x2[20]; sprintf (x2,"%lf",kX);
            char y2[20]; sprintf (y2,"%lf",kY);
            void* linha = cria_linha(id,x1,y1,x2,y2,"red");
            insere_lista_final("l",li,linha);
            fprintf(txt,"j= %s e K= %s nao estao sobrepostos\n",j,k);
            strcpy(noJ->retan.corp,cor2);
            strcpy(noK->circulo.corp,cor2);
        }
    }   

}

void eh_iterno (char j[],char x[],char y[],Lista *li,FILE* txt,FILE* svg){

    if (*li == NULL){
        printf ("ERRO NA LISTA\n");
        
        return;
    }

    Elem* no = pega_forma_na_posicao (j,li);

    if(no == NULL){
        printf (" A possicao que voce esta querendo acessar não é valida \n");
        return ;
    }
    
    if(strcmp(no->tipo_forma,"r")==0){

        float _x = atof(x); float _y = atof(y);
        
        float retan_x; float retan_y; float retan_w; float retan_h;
        
        retan_x = atof(no->retan.x);
        retan_y = atof(no->retan.y);
        retan_w = atof(no->retan.w);
        retan_h = atof(no->retan.h);

        if( _x <= retan_x && _x >= retan_x - retan_w
        && _y <= retan_y && _y >= retan_y - retan_y){// interno
        
        fprintf(svg,"<circle cx=\"%s\" cy=\"%s\" r=\"1.0\" stroke=\"blue\" stroke-width=\"1.0\" fill=\"blue\" />\n",x,y);

        
        fprintf(txt,"tipo da forma: retangulo, eh interno\n");
        }else{//externo

            char x2[20]; char y2[20];
            sprintf(x2,"%lf",retan_x + (retan_w/2));
            sprintf(y2,"%lf",retan_y + (retan_h/2));
            
            fprintf (svg,"<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"#FF00FF\" stroke-width=\"1.0\"/>\n",x,y,x2,y2);
            fprintf(svg,"<circle cx=\"%s\" cy=\"%s\" r=\"1.0\" stroke=\"#FF00FF\" stroke-width=\"1.0\" fill=\"#FF00FF\" />\n",x,y);
            fprintf(txt,"tipo da forma: retangulo, eh externo\n"); 
                
                
        }

    }else if(strcmp(no->tipo_forma,"c")==0){

        float _x = atof(x); float _y = atof(y);
        
        float circ_x; float circ_y; float circ_r; 
        
        circ_x = atof(no->circulo.x);
        circ_y = atof(no->circulo.y);
        circ_r = atof(no->circulo.r);
        

        if(_x <= circ_x + circ_r && _x >= circ_x - circ_r &&
        _y <= circ_y + circ_r && _y >= circ_y - circ_r ){// interno
        
        fprintf(svg,"<circle cx=\"%s\" cy=\"%s\" r=\"1.0\" stroke=\"blue\" stroke-width=\"1.0\" fill=\"blue\" />\n",x,y);
        fprintf(txt,"tipo da forma: circulo, eh interno \n");
        
        }else{//externo

            char x2[20]; char y2[20];
            sprintf(x2,"%lf",circ_x);
            sprintf(y2,"%lf",circ_y);

            fprintf (svg,"<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"#FF00FF\" stroke-width=\"1.0\"/>\n",x,y,x2,y2);
            fprintf(svg,"<circle cx=\"%s\" cy=\"%s\" r=\"1.0\" stroke=\"#FF00FF\" stroke-width=\"1.0\" fill=\"#FF00FF\" />\n",x,y);
            fprintf(txt,"tipo da forma: circulo, eh externo\n");

        }
    }





}

void muda_corb_corp (char j[],char corb[],char corp[],Lista* li, FILE* txt){
    
    Elem* no = pega_forma_com_id (j,li);

    if(strcmp(no->tipo_forma,"r")==0){
        strcpy(no->retan.corb,corb);
        strcpy(no->retan.corp,corp);

        fprintf(txt,"X: %s Y: %s",no->retan.x,no->retan.y);
    }else if(strcmp(no->tipo_forma,"c")==0){
        strcpy(no->circulo.corb,corb);
        strcpy(no->circulo.corp,corp);

        fprintf(txt,"X: %s Y: %s",no->circulo.x,no->circulo.y);
    }else if (strcmp(no->tipo_forma,"t")==0){
        strcpy(no->texto.corb,corb);
        strcpy(no->texto.corp,corp);

        fprintf(txt,"X: %s Y: %s",no->texto.x,no->texto.y);
    }

}

void Remove_elemento_id_j (char j[],Lista* li,FILE* txt){
    
    Elem* no = pega_forma_com_id (j,li);
    if(strcmp(no->tipo_forma,"r")==0){
        fprintf(txt,"id: %s w: %s h: %s x: %s y: %s corb: %s corp: %s\n",no->retan.i,no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);
    }else if(strcmp(no->tipo_forma,"c")==0){
        fprintf(txt,"id: %s r: %s x: %s y: %s corb: %s corp: %s\n",no->circulo.i,no->circulo.r,no->circulo.x,no->circulo.y,no->circulo.corb,no->circulo.corp);
    }else if (strcmp(no->tipo_forma,"t")==0){
        fprintf(txt,"id: %s corb: %s corp: %s txto: %s\n",no->texto.i,no->texto.x,no->texto.y,no->texto.txto);
    }else if (strcmp(no->tipo_forma,"l")==0){
        fprintf(txt,"id: %s x1: %s y1: %s x2: %s y2: %s cor: %s\n",no->linha.i,no->linha.x1,no->linha.y1,no->linha.x2,no->linha.y2,no->linha.cor);
    }else{
        printf ("nehunha forma valida");
    }

    remove_lista_id(j,li);

}

void empilha_pilha_p (Pilha* pi, char id[],Lista* li){

    Elem* no = pega_forma_com_id(id,li);

    if (strcmp(no->tipo_forma,"r")==0){

        void* retan = cria_retangulo(no->retan.i,no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);
        insere_Pilha("r",pi,retan);
    }else if (strcmp(no->tipo_forma,"c")==0){
        void* circ = cria_circulo(no->circulo.i,no->circulo.r,no->circulo.x,no->circulo.y,no->circulo.corb,no->circulo.corp);
        insere_Pilha("c",pi,circ);
    }else if (strcmp(no->tipo_forma,"l")==0){
        void* linha = cria_linha(no->linha.i,no->linha.x1,no->linha.y1,no->linha.x2,no->linha.y2,no->linha.cor);
        insere_Pilha("l",pi,linha);
    }else if(strcmp(no->tipo_forma,"t")==0){
        void* txto = cria_texto(no->texto.i,no->texto.x,no->texto.y,no->texto.corb,no->texto.corp,no->texto.txto);
        insere_Pilha("t",pi,txto);
    }else{
        printf("forma invalida\n");
    }

}

void remove_empilha_modificado (Pilha* pi,char id[],char dx[],char dy[],char prop[],FILE* txt){

    Elem* no = pega_primeiro_elemento_pilha(pi);
    
    if(strcmp(no->tipo_forma,"r")==0){
        char x[20]; char y[20]; char corb[20]; char corp[20];
        float w; float h; char w1[20]; char h1[20];
        float proporcao = atof(prop);
        strcpy(x,dx);strcpy(y,dy);
        strcpy(corb,no->retan.corp);
        strcpy(corp,no->retan.corb);
        
        w = atof(no->retan.w) * proporcao;
        h = atof(no->retan.h) * proporcao;

        
        sprintf(w1,"%lf",w);
        sprintf(h1,"%lf",h);
        void* retan = cria_retangulo(id,w1,h1,x,y,corb,corp);
        fprintf(txt,"elemento removido, id: %s w:%s h:%s x:%s y:%s corb:%s corp: %s\n",
        no->retan.i,no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);
        remove_Pilha(pi);
        insere_Pilha("r",pi,retan);

    }else if (strcmp(no->tipo_forma,"c")==0){
        
        char x[20]; char y[20]; char corb[20];
        char corp[20]; float r; char    rc[20];


        float proporcao = atof(prop);
        strcpy(x,dx);strcpy(y,dy);
        strcpy(corb,no->circulo.corp);
        strcpy(corp,no->circulo.corb);
        
        r = atof(no->circulo.r) * proporcao;
        
        sprintf(rc,"%lf",r);
        void* circ = cria_circulo(id,rc,x,y,corb,corp);
        fprintf(txt,"elemento removido, id: %s r:%s x:%s y:%s corb:%s corp: %s\n",
        no->circulo.i,no->circulo.r,no->circulo.x,no->circulo.y,no->circulo.corb,no->circulo.corp);
        remove_Pilha(pi);
        insere_Pilha("c",pi,circ);

    }
    // não tem para linha e para o texto pois eles não possuem os atributos nescessarios

}

void insere_na_fila_id(Lista* li, Fila* fi,char id[]){
    
    Elem* no = pega_forma_com_id(id,li);

    if (strcmp(no->tipo_forma,"r")==0){

        void* retan = cria_retangulo(no->retan.i,no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);
        insere_Fila("r",fi,retan);
    }else if (strcmp(no->tipo_forma,"c")==0){
        void* circ = cria_circulo(no->circulo.i,no->circulo.r,no->circulo.x,no->circulo.y,no->circulo.corb,no->circulo.corp);
        insere_Fila("c",fi,circ);
    }else if (strcmp(no->tipo_forma,"l")==0){
        void* linha = cria_linha(no->linha.i,no->linha.x1,no->linha.y1,no->linha.x2,no->linha.y2,no->linha.cor);
        insere_Fila("l",fi,linha);
    }else if(strcmp(no->tipo_forma,"t")==0){
        void* txto = cria_texto(no->texto.i,no->texto.x,no->texto.y,no->texto.corb,no->texto.corp,no->texto.txto);
        insere_Fila("t",fi,txto);
    }else{
        printf("forma invalida\n");
    }
}

void remove_insere_Fila_modificado (Lista* li,Fila* fi,char id[],char dx[],char dy[],char prop[],FILE* txt){

    Elem* no = pega_primeiro_elemento_lista(li);
    
    if(strcmp(no->tipo_forma,"r")==0){
        char x[20]; char y[20]; char corb[20]; char corp[20];
        float w; float h; char w1[20]; char h1[20];
        float proporcao = atof(prop);
        strcpy(x,dx);strcpy(y,dy);
        strcpy(corb,no->retan.corp);
        strcpy(corp,no->retan.corb);
        
        w = atof(no->retan.w) * proporcao;
        h = atof(no->retan.h) * proporcao;

        
        sprintf(w1,"%lf",w);
        sprintf(h1,"%lf",h);
        void* retan = cria_retangulo(id,w1,h1,x,y,corb,corp);
        fprintf(txt,"elemento removido, id: %s w:%s h:%s x:%s y:%s corb:%s corp: %s\n",
        no->retan.i,no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);
        remove_Fila(fi);
        insere_Fila("r",fi,retan);

    }else if (strcmp(no->tipo_forma,"c")==0){
        
        char x[20]; char y[20]; char corb[20];
        char corp[20]; float r; char    rc[20];


        float proporcao = atof(prop);
        strcpy(x,dx);strcpy(y,dy);
        strcpy(corb,no->circulo.corp);
        strcpy(corp,no->circulo.corb);
        
        r = atof(no->circulo.r) * proporcao;
        
        sprintf(rc,"%lf",r);
        void* circ = cria_circulo(id,rc,x,y,corb,corp);
        fprintf(txt,"elemento removido, id: %s r:%s x:%s y:%s corb:%s corp: %s\n",
        no->circulo.i,no->circulo.r,no->circulo.x,no->circulo.y,no->circulo.corb,no->circulo.corp);
        remove_Fila(fi);
        insere_Fila("c",fi,circ);

    }
    // não tem para linha e para o texto pois eles não possuem os atributos nescessarios

}

void insere_inicio_lista_registrador (Lista* li,char id[],void* registrador[],int n_registrador){

    Elem* no2 = pega_forma_com_id(id,li);
    Elem *no = (Elem*) malloc(sizeof(Elem));
    
    if(strcmp(no2->tipo_forma,"r")==0){

        void* _retan = cria_retangulo(no2->retan.i,no2->retan.w,no2->retan.h,no2->retan.x,no2->retan.y,no2->retan.corb,no2->retan.corp);
        
        Rect* retan;
        retan = (Rect*) _retan;

        strcpy(no->tipo_forma,"r");
        strcpy(no->retan.i,retan->i);
        strcpy(no->retan.w,retan->w);
        strcpy(no->retan.h,retan->h);
        strcpy(no->retan.x,retan->x);
        strcpy(no->retan.y,retan->y);
        strcpy(no->retan.corb,retan->corb);
        strcpy(no->retan.corp,retan->corp);
        no->prox = NULL;

        registrador[n_registrador] = &no->retan.i;
        
        no->prox = (*li);
        *li = no;
        
        

    }else if (strcmp(no2->tipo_forma,"c")==0){
        void* circu = cria_circulo(no2->circulo.i,no2->circulo.r,no2->circulo.x,no2->circulo.y,no2->circulo.corb,no2->circulo.corp);
        
        Circ* circ;
        circ = (Circ*) circu;

        strcpy(no->tipo_forma,"c");
        strcpy(no->circulo.i,circ->i);
        strcpy(no->circulo.r,circ->r);
        strcpy(no->circulo.x,circ->x);
        strcpy(no->circulo.y,circ->y);
        strcpy(no->circulo.corb,circ->corb);
        strcpy(no->circulo.corp,circ->corp);
        no->prox = NULL;

        registrador[n_registrador] = &no->circulo.i;
        no->prox = (*li);
        *li = no;
        
    }else if (strcmp(no2->tipo_forma,"l")==0){

        void* linha = cria_linha(no2->linha.i,no2->linha.x1,no2->linha.y1,no2->linha.x2,no2->linha.y2,no2->linha.cor);
        Linha* _linha;
        _linha = (Linha*) linha;

        strcpy(no->tipo_forma,"l");
        strcpy(no->linha.i,_linha->i);
        strcpy(no->linha.x1,_linha->x1);
        strcpy(no->linha.y1,_linha->y1);
        strcpy(no->linha.x2,_linha->x2);
        strcpy(no->linha.y2,_linha->y2);
        strcpy(no->linha.cor,_linha->cor);
        no->prox = NULL;

        registrador[n_registrador] = &no->linha.i;
        no->prox = (*li);
        *li = no;
        

    }else if(strcmp(no2->tipo_forma,"t")==0){
        void* txto = cria_texto(no2->texto.i,no2->texto.x,no2->texto.y,no2->texto.corb,no2->texto.corp,no2->texto.txto);
        Text* txt;
        txt = (Text*) txto;

        strcpy(no->tipo_forma,"t");
        strcpy(no->texto.i,txt->i);
        strcpy(no->texto.x,txt->x);
        strcpy(no->texto.y,txt->y);
        strcpy(no->texto.corb,txt->corb);
        strcpy(no->texto.corp,txt->corp);
        strcpy(no->texto.txto,txt->txto);
        no->prox = NULL;

        registrador[n_registrador] = &no->texto.i;
        no->prox = (*li);
        *li = no;
        
    }else{
        printf ("forma invalida\n");
        
    }



}

void insere_fim_lista_registrador (Lista* li,char id[],void* registrador[],int n_registrador){

    Elem* no2 = pega_forma_com_id(id,li);
    Elem *no = (Elem*) malloc(sizeof(Elem));
    
    if(strcmp(no2->tipo_forma,"r")==0){
        
        void* _retan = cria_retangulo(no2->retan.i,no2->retan.w,no2->retan.h,no2->retan.x,no2->retan.y,no2->retan.corb,no2->retan.corp);
        
        retangulo* retan;
        retan = (retangulo*) _retan;
        strcpy(no->tipo_forma,"r");
        strcpy(no->retan.i,retan->i);
        strcpy(no->retan.w,retan->w);
        strcpy(no->retan.h,retan->h);
        strcpy(no->retan.x,retan->x);
        strcpy(no->retan.y,retan->y);
        strcpy(no->retan.corb,retan->corb);
        strcpy(no->retan.corp,retan->corp);
        no->prox = NULL;

        registrador[n_registrador] = &no->retan.i;
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        

    }else if (strcmp(no2->tipo_forma,"c")==0){
        void* circu = cria_circulo(no2->circulo.i,no2->circulo.r,no2->circulo.x,no2->circulo.y,no2->circulo.corb,no2->circulo.corp);
        
        Circ* circ;
        circ = (Circ*) circu;

        strcpy(no->tipo_forma,"c");
        strcpy(no->circulo.i,circ->i);
        strcpy(no->circulo.r,circ->r);
        strcpy(no->circulo.x,circ->x);
        strcpy(no->circulo.y,circ->y);
        strcpy(no->circulo.corb,circ->corb);
        strcpy(no->circulo.corp,circ->corp);
        no->prox = NULL;

        registrador[n_registrador] = &no->circulo.i;
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;

    }else if (strcmp(no2->tipo_forma,"l")==0){

        void* linha = cria_linha(no2->linha.i,no2->linha.x1,no2->linha.y1,no2->linha.x2,no2->linha.y2,no2->linha.cor);
        Linha* _linha;
        _linha = (Linha*) linha;

        strcpy(no->tipo_forma,"l");
        strcpy(no->linha.i,_linha->i);
        strcpy(no->linha.x1,_linha->x1);
        strcpy(no->linha.y1,_linha->y1);
        strcpy(no->linha.x2,_linha->x2);
        strcpy(no->linha.y2,_linha->y2);
        strcpy(no->linha.cor,_linha->cor);
        no->prox = NULL;

        registrador[n_registrador] = &no->linha.i;
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        

    }else if(strcmp(no2->tipo_forma,"t")==0){
        void* txto = cria_texto(no2->texto.i,no2->texto.x,no2->texto.y,no2->texto.corb,no2->texto.corp,no2->texto.txto);
        Text* txt;
        txt = (Text*) txto;

        strcpy(no->tipo_forma,"t");
        strcpy(no->texto.i,txt->i);
        strcpy(no->texto.x,txt->x);
        strcpy(no->texto.y,txt->y);
        strcpy(no->texto.corb,txt->corb);
        strcpy(no->texto.corp,txt->corp);
        strcpy(no->texto.txto,txt->txto);
        no->prox = NULL;

        registrador[n_registrador] = &no->texto.i;
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }else{
        printf ("forma invalida\n");
        
    }

}

void insere_lista_antes_registrador (Lista* li,char id[],void* registradores[],int ro,int rd){

    int posicao = pega_posicao_elemento_registrador(li,registradores,ro);

    Elem* no = pega_forma_com_id(id,li);
    
    if(strcmp(no->tipo_forma,"r")==0){
        void* retan = cria_retangulo(no->retan.i,no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);
        insere_lista_antes_posi("r",li,retan,registradores,rd,posicao);
    }else if (strcmp(no->tipo_forma,"c")==0){
        
        void* circ = cria_circulo(no->circulo.i,no->circulo.r,no->circulo.x,no->circulo.y,no->circulo.corb,no->circulo.corp);
        insere_lista_antes_posi("c",li,circ,registradores,rd,posicao);
        
    }else if (strcmp(no->tipo_forma,"l")==0){

        void* linha = cria_linha(no->linha.i,no->linha.x1,no->linha.y1,no->linha.x2,no->linha.y2,no->linha.cor);
        insere_lista_antes_posi("l",li,linha,registradores,rd,posicao);

    }else if(strcmp(no->tipo_forma,"t")==0){
        void* txto = cria_texto(no->texto.i,no->texto.x,no->texto.y,no->texto.corb,no->texto.corp,no->texto.txto);
        insere_lista_antes_posi("t",li,txto,registradores,rd,posicao);
    }else{
        printf ("forma invalida\n");
    }
}

void insere_lista_depois_registrador(Lista* li,char id[],void* registradores[],int ro,int rd){
    
    int posicao = pega_posicao_elemento_registrador(li,registradores,ro);

    Elem* no = pega_forma_com_id(id,li);
    
    if(strcmp(no->tipo_forma,"r")==0){
        void* retan = cria_retangulo(no->retan.i,no->retan.w,no->retan.h,no->retan.x,no->retan.y,no->retan.corb,no->retan.corp);
        insere_lista_depois_posi("r",li,retan,registradores,rd,posicao);
    }else if (strcmp(no->tipo_forma,"c")==0){
        
        void* circ = cria_circulo(no->circulo.i,no->circulo.r,no->circulo.x,no->circulo.y,no->circulo.corb,no->circulo.corp);
        insere_lista_depois_posi("c",li,circ,registradores,rd,posicao);
        
    }else if (strcmp(no->tipo_forma,"l")==0){

        void* linha = cria_linha(no->linha.i,no->linha.x1,no->linha.y1,no->linha.x2,no->linha.y2,no->linha.cor);
        insere_lista_depois_posi("l",li,linha,registradores,rd,posicao);

    }else if(strcmp(no->tipo_forma,"t")==0){
        void* txto = cria_texto(no->texto.i,no->texto.x,no->texto.y,no->texto.corb,no->texto.corp,no->texto.txto);
        insere_lista_depois_posi("t",li,txto,registradores,rd,posicao);
    }else{
        printf ("forma invalida\n");
    }

}

void remove_lista_antes_registrador (Lista* li, void* registradores[],int n_registrador){

    int posicao = pega_posicao_elemento_registrador(li,registradores,n_registrador);
    remover_lista_ants_registrador(li,posicao);

}

void remove_lista_depois_registrador(Lista* li, void* registradores[],int n_registrador){

    int posicao = pega_posicao_elemento_registrador(li,registradores,n_registrador);
    remover_lista_dps_registrador(li,posicao);
}


void percorre_lista_cria_elementos_esvazia(Lista* li,int n_lista,int id,char dx[],char dy[],float _prop, float _incprop,Lista* listas[],Pilha* pilhas[],Fila* filas[]){

    Elem* no = *li;
    while(no != NULL){

        if(strcmp(no->tipo_forma,"r")==0){
            char i[20]; char w[20]; char h[20]; 
            sprintf(i,"%d",id);
            sprintf(w,"%lf", atof(no->retan.w) * _prop);
            sprintf(h,"%lf", atof(no->retan.h) * _prop);
            void* novo_retan = cria_retangulo(i,w,h,dx,dy,no->retan.corb,no->retan.corp);

            for( int aux = 0; aux <10;aux++){

                if(aux != n_lista){
                    insere_lista_final("r",listas[aux],novo_retan);
                }
                
                insere_Pilha("r",pilhas[aux],novo_retan);
                insere_Fila("r",filas[aux],novo_retan);
            }
            no = no -> prox;
            
        }else if(strcmp(no->tipo_forma,"c")==0){
            
            char i[20]; char r[20]; 
            sprintf(i,"%d",id);
            sprintf(r,"%lf", atof(no->circulo.r) * _prop);
            void* novo_circulo = cria_circulo(i,r,dx,dy,no->circulo.corb,no->circulo.corp);

            for( int aux = 0; aux <10;aux++){
                
                if(aux != n_lista){
                    insere_lista_final("c",listas[aux],novo_circulo);
                }
                
                insere_Pilha("c",pilhas[aux],novo_circulo);
                insere_Fila("c",filas[aux],novo_circulo);
            }
            no = no -> prox;
        }
        
        id++;
        _prop = _prop + _incprop;
        
    }

    esvazia_lista(li);
}