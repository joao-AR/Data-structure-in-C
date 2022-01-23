
#include "qry.h"
#include <float.h>

void executa_Ef(Variaveis variaveis, char *id, char *v);

int checar_texto_dentro_retangulo(void *txt_geo, void *retangulo_qry);
int checar_linha_dentro_retangulo(void *linha_geo, void *retangulo_qry);
void executa_Xf(Variaveis variaveis, char *id, char *v);
void executa_Qinterroga(Variaveis variaveis, char *id, FILE *txt_qry, int trigger_ep);
void executaQr_interroga(Variaveis variaveis, char *x, char *y, char *w, char *h, Lista lista_circulo, Lista lista_retangulo, Lista lista_linha, Lista lista_texto);
void executa_nf(Variaveis variaveis, FILE *txt_qry);
int NAO_CHECAR(void *v, char *c);
void executa_sp(Variaveis variaveis, double x, double y, double v, FILE *txt_query, FILE *svg_query);
void poda_arvore_sf(KDTree tree, Retangulo rect, Lista lista);
void poda_arvore_sf_rec(KDTree raiz, Retangulo rect, Lista lista, int profundidade);
void checar_contido(void *lista, void *lista_completamente_dentro, int (*checagem_contido)(void *, void *), void *retangulo_qry);
void executa_Sf(Variaveis variaveis, char *x, char *y, char *w, char *h);
int checar_Se_Circulo_Esta_Dentro_Do_Retangulo(void *circulo_geo, void *retangulo_qry);
int checar_Se_Retangulo_Esta_Dentro_Do_Retangulo(void *retangulo_geo, void *retangulo_qry);
void executa_ip(Variaveis Var, int n, FILE *txt_qry, FILE *txt_svg);

void funcoes_qry(FILE *qry, FILE *svg_qry, FILE *txt_qry, Variaveis variaveis)
{
    char tipo_qry[20];
    char final;
    int trigger_ep = 0;
    final = getc(qry);
    fseek(qry, 0, SEEK_SET);

    while (final != EOF)
    {

        fscanf(qry, "%s", tipo_qry);

        if (!strcmp(tipo_qry, "ef"))
        {

            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);
            char id[20];
            char v[10];
            fscanf(qry, "%s", id);
            fscanf(qry, "%s", v); // valor energia
            executa_Ef(variaveis, id, v);
        }
        else if (!strcmp(tipo_qry, "xf"))
        {

            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);
            char id[20];
            char v[10];
            fscanf(qry, "%s", id);
            fscanf(qry, "%s", v); // valor energia
            executa_Xf(variaveis, id, v);
        }
        else if (!strcmp(tipo_qry, "sf"))
        {
            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);

            char x[20];
            char y[20];
            char w[20];
            char h[20];
            fscanf(qry, "%s ", x); // pode ser um numero ou *
            if (!strcmp(x, "*"))
            {
                sprintf(y, "0");
                sprintf(w, "0");
                sprintf(h, "0");
            }
            else
            {
                fscanf(qry, "%s ", y); //y
                fscanf(qry, "%s ", w); //w
                fscanf(qry, "%s", h);  //h
            }

            executa_Sf(variaveis, x, y, w, h);
            Retangulo rect = cria_retangulo("0", w, h, x, y, "black", "white");

            if(strcmp(x, "*")){
                checar_contido(pega_retangulo_dentro_retangulo(variaveis), pega_completamente_retangulo_dentro_retangulo(variaveis), checar_Se_Retangulo_Esta_Dentro_Do_Retangulo, rect);
                checar_contido(pega_circulo_dentro_retangulo(variaveis), pega_completamente_circulo_dentro_retangulo(variaveis), checar_Se_Circulo_Esta_Dentro_Do_Retangulo, rect);
                checar_contido(pega_linha_dentro_retangulo(variaveis), pega_completamente_linha_dentro_retangulo(variaveis), checar_linha_dentro_retangulo, rect);
                checar_contido(pega_texto_dentro_retangulo(variaveis), pega_completamente_txt_dentro_retangulo(variaveis), checar_texto_dentro_retangulo, rect);
            }

            //Imprimir listas no txt
            imprime_lista_no_txt(pega_completamente_retangulo_dentro_retangulo(variaveis), txt_qry, imprime_txt_id_retangulo);
            imprime_lista_no_txt(pega_completamente_circulo_dentro_retangulo(variaveis), txt_qry, imprime_txt_id_circulo);
            imprime_lista_no_txt(pega_completamente_linha_dentro_retangulo(variaveis), txt_qry, imprime_txt_id_linha);
            imprime_lista_no_txt(pega_completamente_txt_dentro_retangulo(variaveis), txt_qry, imprime_txt_id_texto);

            //Imprimindo retangulo no SVG
            fprintf(svg_qry, "<rect width=\"%lf\" height=\"%lf\" x=\"%lf\" y=\"%lf\" stroke=\"black\" stroke-width=\"1.0\" fill=\"none\" fill-opacity =\"0.8\" stroke-opacity =\"0.8\"/>\n", atof(w), atof(h), atof(x), atof(y));
        }
        else if (!strcmp(tipo_qry, "ep"))
        {
            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);

            trigger_ep = 1;

            imprime_lista_no_txt(pega_completamente_retangulo_dentro_retangulo(variaveis), txt_qry, imprime_txt_dados_retangulo_sem_energia);
            imprime_lista_no_txt(pega_completamente_circulo_dentro_retangulo(variaveis), txt_qry, imprime_txt_dados_circulo_sem_energia);
            imprime_lista_no_txt(pega_completamente_linha_dentro_retangulo(variaveis), txt_qry, imprime_txt_dados_linha_sem_energia);
            imprime_lista_no_txt(pega_completamente_txt_dentro_retangulo(variaveis), txt_qry, imprime_txt_dados_texto_sem_energia);

            imprime_lista_no_txt(pega_completamente_retangulo_dentro_retangulo(variaveis), svg_qry, imprime_svg_dados_retangulo);
            imprime_lista_no_txt(pega_completamente_circulo_dentro_retangulo(variaveis), svg_qry, imprime_svg_dados_circulo);
            imprime_lista_no_txt(pega_completamente_linha_dentro_retangulo(variaveis), svg_qry, imprime_svg_dados_linha);
            imprime_lista_no_txt(pega_completamente_txt_dentro_retangulo(variaveis), svg_qry, imprime_svg_dados_txt);

            define_lista_variaveis(variaveis);
        }
        else if (!strcmp(tipo_qry, "q?"))
        {
            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);

            char id[20];
            fscanf(qry, "%s", id);

            executa_Qinterroga(variaveis, id, txt_qry, trigger_ep);
        }
        else if (!strcmp(tipo_qry, "qr?"))
        {

            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);

            char x[20];
            char y[20];
            char w[20];
            char h[20];
            fscanf(qry, "%s ", x); // x
            fscanf(qry, "%s ", y); //y
            fscanf(qry, "%s ", w); //w
            fscanf(qry, "%s", h);  //h

            //Listas temporarias
            Lista lista_circulo = cria_lista();
            Lista lista_retangulo = cria_lista();
            Lista lista_linha = cria_lista();
            Lista lista_texto = cria_lista();
            
            Lista completa_retangulo = cria_lista();
            Lista completa_circulo = cria_lista();
            Lista completa_texto = cria_lista();
            Lista completa_linha = cria_lista();

            executaQr_interroga(variaveis, x, y, w, h, lista_circulo, lista_retangulo, lista_linha, lista_texto);

            Retangulo rect = cria_retangulo("0", w, h, x, y, "black", "white");

            checar_contido(lista_retangulo, completa_retangulo, checar_Se_Retangulo_Esta_Dentro_Do_Retangulo, rect);
            checar_contido(lista_circulo, completa_circulo, checar_Se_Circulo_Esta_Dentro_Do_Retangulo, rect);
            checar_contido(lista_linha, completa_linha, checar_linha_dentro_retangulo, rect);
            checar_contido(lista_texto, completa_texto, checar_texto_dentro_retangulo, rect);

            //Imprimir listas no txt
            imprime_lista_no_txt(completa_retangulo, txt_qry, imprime_txt_dados_retangulo_todos);
            imprime_lista_no_txt(completa_circulo, txt_qry, imprime_txt_dados_circulo_todos);
            imprime_lista_no_txt(completa_linha, txt_qry, imprime_txt_dados_linha_todos);
            imprime_lista_no_txt(completa_texto, txt_qry, imprime_txt_dados_texto_todos);
        }
        else if (!strcmp(tipo_qry, "nf"))
        {
            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);
            executa_nf(variaveis, txt_qry);
        }
        else if (!strcmp(tipo_qry, "sp"))
        {

            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);

            double x;
            double y;
            double v;
            fscanf(qry, "%lf", &x);
            fscanf(qry, "%lf", &y);
            fscanf(qry, "%lf", &v);
            executa_sp(variaveis, x, y, v, txt_qry, svg_qry);
        }
        else if (!strcmp(tipo_qry, "ip"))
        {

            fprintf(txt_qry, "\n[*%s*]\n", tipo_qry);
            int n;
            fscanf(qry, "%d", &n);
            executa_ip(variaveis, n, txt_qry, svg_qry);
        }

        final = getc(qry);
        final = getc(qry);        // usando dois getc para pegar o proximo caractere para ver se eh EOF
        fseek(qry, -1, SEEK_CUR); // volta o cursor em um caractere no arquivo para nao causar problemas
    }
}

void checar_contido(void *lista, void *lista_completamente_dentro, int (*checagem_contido)(void *, void *), void *retangulo_qry)
{
    insere_lista_completamente_dentro(lista, lista_completamente_dentro, checagem_contido, retangulo_qry);
}

FILE *cria_path_txt(void *parametros)
{

    char *nome_geo = pega_nome_geo(parametros);
    char *nome_qry = pega_nome_qry(parametros);
    char nome_svg2[100] = {};
    char *diretorio_saida = pega_diretorio_output(parametros);
    char path_txt_completo[300];
    int aux = 0;

    while (aux < 100)
    { //pegando apenas o nome do qry sem o final .qry

        if (nome_qry[aux] == '.')
        {
            break;
        }
        else if (nome_qry[aux] == '/')
        {
            nome_svg2[aux] = '-'; // tirando / e substituindo por -
        }
        else
        {
            nome_svg2[aux] = nome_qry[aux];
        }

        aux++;
    }

    sprintf(path_txt_completo, "%s/%s.txt", diretorio_saida, nome_svg2); //criando o path do geo
    FILE *txt = fopen(path_txt_completo, "w");                           //abrino o svg do geo

    return txt;
}

FILE *cria_path_svg_qry(void *parametros)
{

    char *nome_qry = pega_nome_qry(parametros);

    char nome_svg[100] = {};
    char nome_svg2[100] = {};
    char *diretorio_saida = pega_diretorio_output(parametros);
    char path_qry_completo[300];
    int aux = 0;

    while (aux < 100)
    { //pegando apenas o nome do qry sem o final .qry

        if (nome_qry[aux] == '.')
        {
            break;
        }
        else if (nome_qry[aux] == '/')
        {
            nome_svg2[aux] = '-'; // tirando / e substituindo por -
        }
        else
        {
            nome_svg2[aux] = nome_qry[aux];
        }

        aux++;
    }

    sprintf(path_qry_completo, "%s/%s.svg", diretorio_saida, nome_svg2); //criando o path do qry
    FILE *svg = fopen(path_qry_completo, "w");                           //abrino o svg do geo
    fprintf(svg, "<svg>\n");
    return svg;
}

int nao_checar(void *x, void *y)
{
    return 1;
}

void checar_Dados_Dentro_Retangulo(KDTree raiz, int (*checar)(void *, void *), Retangulo rect, Lista lista);

void checar_Dados_Retangulo(KDTree tree, int (*checar)(void *, void *), Retangulo rect, Lista lista)
{
    checar_Dados_Dentro_Retangulo(pega_Raiz_KDTreee(tree), checar, rect, lista);
}

void poda_arvore_sf(KDTree tree, Retangulo rect, Lista lista)
{
    int profundidade = 1;
    poda_arvore_sf_rec(pega_Raiz_KDTreee(tree), rect, lista, profundidade);
}

void poda_arvore_sf_rec(KDTree raiz, Retangulo rect, Lista lista, int profundidade)
{

    if (raiz != NULL)
    {

        if (ponto_dentro_retangulo(rect, pega_X_KDTree(raiz), pega_Y_KDTree(raiz)))
        {
            inserir(lista, pega_Dado_KDTree(raiz));
        }

        //definindo qual caminho devemos tomar baseado na profundidade
        if ((profundidade % 2 != 0))
        {

            if (atof(pega_X_retangulo(rect)) < pega_X_KDTree(raiz))
            {
                if (atof(pega_X_retangulo(rect)) + atof(pega_largura_retangulo(rect)) < pega_X_KDTree(raiz))
                {
                    poda_arvore_sf_rec(pega_Esquerda_KDTree(raiz), rect, lista, profundidade + 1);
                }
                else
                {
                    poda_arvore_sf_rec(pega_Esquerda_KDTree(raiz), rect, lista, profundidade + 1);
                    poda_arvore_sf_rec(pega_Direita_KDTree(raiz), rect, lista, profundidade + 1);
                }
            }
            else
            {
                poda_arvore_sf_rec(pega_Direita_KDTree(raiz), rect, lista, profundidade + 1);
            }
        }
        else if (profundidade % 2 == 0)
        {

            if (atof(pega_Y_retangulo(rect)) < pega_Y_KDTree(raiz))
            {
                if (atof(pega_Y_retangulo(rect)) + atof(pega_Altura_retangulo(rect)) < pega_Y_KDTree(raiz))
                {
                    poda_arvore_sf_rec(pega_Esquerda_KDTree(raiz), rect, lista, profundidade + 1);
                }
                else
                {
                    poda_arvore_sf_rec(pega_Esquerda_KDTree(raiz), rect, lista, profundidade + 1);
                    poda_arvore_sf_rec(pega_Direita_KDTree(raiz), rect, lista, profundidade + 1);
                }
            }
            else
            {
                poda_arvore_sf_rec(pega_Direita_KDTree(raiz), rect, lista, profundidade + 1);
            }
        }
    }
    return;
}

void checar_Dados_Dentro_Retangulo(KDTree raiz, int (*checar)(void *, void *), Retangulo rect, Lista lista)
{

    if (raiz != NULL)
    {
        checar_Dados_Dentro_Retangulo(pega_Esquerda_KDTree(raiz), checar, rect, lista);
        int result = (*checar)(pega_Dado_KDTree(raiz), rect);
        if (result)
        {
            inserir(lista, pega_Dado_KDTree(raiz));
        }
        checar_Dados_Dentro_Retangulo(pega_Direita_KDTree(raiz), checar, rect, lista);
    }
}

int checar_Se_Retangulo_Esta_Dentro_Do_Retangulo(void *retangulo_geo, void *retangulo_qry)
{

    if (atof(pega_X_retangulo(retangulo_geo)) >= atof(pega_X_retangulo(retangulo_qry)) && atof(pega_Y_retangulo(retangulo_geo)) >= atof(pega_Y_retangulo(retangulo_qry)))
    {
        if ((atof(pega_X_retangulo(retangulo_geo)) + atof(pega_largura_retangulo(retangulo_geo)) <= atof(pega_X_retangulo(retangulo_qry)) + atof(pega_largura_retangulo(retangulo_qry))) && (atof(pega_Y_retangulo(retangulo_geo)) + atof(pega_Altura_retangulo(retangulo_geo)) <= atof(pega_Y_retangulo(retangulo_qry)) + atof(pega_Altura_retangulo(retangulo_qry))))
        {
            return 1;
        }
    }

    return 0;
}

int checar_Se_Circulo_Esta_Dentro_Do_Retangulo(void *circulo_geo, void *retangulo_qry)
{
    if (atof(pega_Raio_circulo(circulo_geo)) + atof(pega_X_circulo(circulo_geo)) <= atof(pega_X_retangulo(retangulo_qry)) + atof(pega_largura_retangulo(retangulo_qry)))
    {
        if (abs(atof(pega_X_circulo(circulo_geo)) - atof(pega_Raio_circulo(circulo_geo))) >= atof(pega_X_retangulo(retangulo_qry)))
        {
            if (atof(pega_Y_circulo(circulo_geo)) + atof(pega_Raio_circulo(circulo_geo)) <= atof(pega_Y_retangulo(retangulo_qry)) + atof(pega_Altura_retangulo(retangulo_qry)))
            {
                if (abs(atof(pega_Y_circulo(circulo_geo)) - atof(pega_Raio_circulo(circulo_geo))) >= atof(pega_Y_retangulo(retangulo_qry)))
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int checar_texto_dentro_retangulo(void *txt_geo, void *retangulo_qry)
{
    if (atof(pega_X_txt(txt_geo)) >= atof(pega_X_retangulo(retangulo_qry)))
    {

        if (abs(atof(pega_X_txt(txt_geo)) <= atof(pega_X_retangulo(retangulo_qry)) + atof(pega_largura_retangulo(retangulo_qry))))
        {

            if (atof(pega_Y_txt(txt_geo)) >= atof(pega_Y_retangulo(retangulo_qry)))
            {

                if (abs(atof(pega_Y_txt(txt_geo)) <= atof(pega_Y_retangulo(retangulo_qry)) + atof(pega_Altura_retangulo(retangulo_qry))))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int checar_linha_dentro_retangulo(void *linha_geo, void *retangulo_qry)
{

    if ((atof(pega_x1_linha(linha_geo)) >= atof(pega_X_retangulo(retangulo_qry))) && (atof(pega_x2_linha(linha_geo)) >= atof(pega_X_retangulo(retangulo_qry))))
    {

        if ((abs(atof(pega_x1_linha(linha_geo)) <= atof(pega_X_retangulo(retangulo_qry)) + atof(pega_largura_retangulo(retangulo_qry)))) && (abs(atof(pega_x2_linha(linha_geo)) <= atof(pega_X_retangulo(retangulo_qry)) + atof(pega_largura_retangulo(retangulo_qry)))))
        {

            if ((atof(pega_y1_linha(linha_geo)) >= atof(pega_Y_retangulo(retangulo_qry))) && (atof(pega_y2_linha(linha_geo)) >= atof(pega_Y_retangulo(retangulo_qry))))
            {

                if ((abs(atof(pega_y1_linha(linha_geo)) <= atof(pega_Y_retangulo(retangulo_qry)) + atof(pega_Altura_retangulo(retangulo_qry)))) && (abs(atof(pega_y2_linha(linha_geo)) <= atof(pega_Y_retangulo(retangulo_qry)) + atof(pega_Altura_retangulo(retangulo_qry)))))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void executa_Sf(Variaveis variaveis, char *x, char *y, char *w, char *h)
{

    if (!strcmp(x, "*"))
    {
        checar_Dados_Retangulo(pega_arvore_retangulo(variaveis), nao_checar, NULL, pega_completamente_retangulo_dentro_retangulo(variaveis));
        checar_Dados_Retangulo(pega_arvore_circulo(variaveis), nao_checar, NULL, pega_completamente_circulo_dentro_retangulo(variaveis));
        checar_Dados_Retangulo(pega_arvore_linha(variaveis), nao_checar, NULL, pega_completamente_linha_dentro_retangulo(variaveis));
        checar_Dados_Retangulo(pega_arvore_txt(variaveis), nao_checar, NULL, pega_completamente_txt_dentro_retangulo(variaveis));
    }
    else
    {

        Retangulo rect = cria_retangulo("0", w, h, x, y, "black", "white");
        poda_arvore_sf(pega_arvore_retangulo(variaveis), rect, pega_retangulo_dentro_retangulo(variaveis));

        poda_arvore_sf(pega_arvore_circulo(variaveis), rect, pega_circulo_dentro_retangulo(variaveis));

        poda_arvore_sf(pega_arvore_txt(variaveis), rect, pega_texto_dentro_retangulo(variaveis));

        poda_arvore_sf(pega_arvore_linha(variaveis), rect, pega_linha_dentro_retangulo(variaveis));

        libera_retangulo(rect);
    }
}

void executaQr_interroga(Variaveis variaveis, char *x, char *y, char *w, char *h, Lista lista_circulo, Lista lista_retangulo, Lista lista_linha, Lista lista_texto) {
        Retangulo rect = cria_retangulo("0", w, h, x, y, "black", "white");
        poda_arvore_sf(pega_arvore_retangulo(variaveis), rect, lista_retangulo);

        poda_arvore_sf(pega_arvore_circulo(variaveis), rect, lista_circulo);

        poda_arvore_sf(pega_arvore_txt(variaveis), rect, lista_texto);

        poda_arvore_sf(pega_arvore_linha(variaveis), rect, lista_linha);

        libera_retangulo(rect);
}

void executa_Ef(Variaveis variaveis, char *id, char *v)
{
    if (!strcmp(id, "*"))
    {
        //Coloca energia a energia v em todas as figuras
        percorre_arvore(pega_arvore_retangulo(variaveis), atof(v), definir_ponto_energia_retangulo, checar_id_retangulo, NULL);
        percorre_arvore(pega_arvore_circulo(variaveis), atof(v), definir_ponto_energia_circulo, checar_id_circulo, NULL);
        percorre_arvore(pega_arvore_txt(variaveis), atof(v), definir_ponto_energia_texto, checar_id_texto, NULL);
        percorre_arvore(pega_arvore_linha(variaveis), atof(v), seta_ponto_energia_linha, checar_id_linha, NULL);
    }
    else
    {
        //Coloca a energia v na figura com seu determinado id
        percorre_arvore(pega_arvore_retangulo(variaveis), atof(v), definir_ponto_energia_retangulo, checar_id_retangulo, id);
        percorre_arvore(pega_arvore_circulo(variaveis), atof(v), definir_ponto_energia_circulo, checar_id_circulo, id);
        percorre_arvore(pega_arvore_txt(variaveis), atof(v), definir_ponto_energia_texto, checar_id_texto, id);
        percorre_arvore(pega_arvore_linha(variaveis), atof(v), seta_ponto_energia_linha, checar_id_linha, id);
    }
}

void executa_Xf(Variaveis variaveis, char *id, char *v)
{
    if (!strcmp(id, "*"))
    {
        //Coloca energia a energia v em todas as figuras
        percorre_arvore(pega_arvore_retangulo(variaveis), atof(v), aumenta_ponto_energia_retangulo, checar_id_retangulo, NULL);
        percorre_arvore(pega_arvore_circulo(variaveis), atof(v), aumenta_ponto_energia_circulo, checar_id_circulo, NULL);
        percorre_arvore(pega_arvore_txt(variaveis), atof(v), aumenta_ponto_energia_texto, checar_id_texto, NULL);
        percorre_arvore(pega_arvore_linha(variaveis), atof(v), aumenta_ponto_energia_linha, checar_id_linha, NULL);
    }
    else
    {
        //Coloca a energia v na figura com seu determinado id
        percorre_arvore(pega_arvore_retangulo(variaveis), atof(v), aumenta_ponto_energia_retangulo, checar_id_retangulo, id);
        percorre_arvore(pega_arvore_circulo(variaveis), atof(v), aumenta_ponto_energia_circulo, checar_id_circulo, id);
        percorre_arvore(pega_arvore_txt(variaveis), atof(v), aumenta_ponto_energia_texto, checar_id_texto, id);
        percorre_arvore(pega_arvore_linha(variaveis), atof(v), aumenta_ponto_energia_linha, checar_id_linha, id);
    }
}

void executa_Qinterroga(Variaveis variaveis, char *id, FILE *txt_qry, int trigger_ep)
{
    if (trigger_ep)
    {
        percorre_arvore_q_interroga(pega_arvore_retangulo(variaveis), imprime_txt_dados_retangulo_todos, checar_id_retangulo, id, txt_qry);
        percorre_arvore_q_interroga(pega_arvore_circulo(variaveis), imprime_txt_dados_circulo_todos, checar_id_circulo, id, txt_qry);
        percorre_arvore_q_interroga(pega_arvore_txt(variaveis), imprime_txt_dados_texto_todos, checar_id_texto, id, txt_qry);
        percorre_arvore_q_interroga(pega_arvore_linha(variaveis), imprime_txt_dados_linha_todos, checar_id_linha, id, txt_qry);
    }
    else
    {
        percorre_arvore_q_interroga(pega_arvore_retangulo(variaveis), imprime_txt_dados_retangulo_qinterroga, checar_id_retangulo, id, txt_qry);
        percorre_arvore_q_interroga(pega_arvore_circulo(variaveis), imprime_txt_dados_circulo_q_interroga, checar_id_circulo, id, txt_qry);
        percorre_arvore_q_interroga(pega_arvore_txt(variaveis), imprime_txt_dados_texto_q_interroga, checar_id_texto, id, txt_qry);
        percorre_arvore_q_interroga(pega_arvore_linha(variaveis), imprime_txt_dados_linha_q_interroga, checar_id_linha, id, txt_qry);
    }
}

int NAO_CHECAR(void *v, char *c)
{

    return 1;
}

void nao_faz_nada(void *nada)
{
    //essa função nao faz nada
    //usando no caso do txt pois no txt nao tem como normalizar pois só tem um ponto de energia
}

void executa_nf(Variaveis variaveis, FILE *txt_qry)
{

    percorre_arvore_nf(pega_arvore_circulo(variaveis), normaliza_ponto_energia_circulo, imprime_txt_dados_circulo_todos, txt_qry);
    percorre_arvore_nf(pega_arvore_retangulo(variaveis), normaliza_ponto_energia_retangulo, imprime_txt_dados_retangulo_todos, txt_qry);
    percorre_arvore_nf(pega_arvore_linha(variaveis), normaliza_ponto_energia_linha, imprime_txt_dados_linha_todos, txt_qry);
    percorre_arvore_nf(pega_arvore_txt(variaveis), nao_faz_nada, imprime_txt_dados_texto_todos, txt_qry);

    imprimir(pega_arvore_circulo(variaveis), imprimir_arvore_circulo_aux);
}

void executa_sp(Variaveis variaveis, double x, double y, double v, FILE *txt_query, FILE *svg_query)
{

    Ponto_Energia ponto_mais_proximo = encontrar_vizinho_mais_proximo_kdtree(pega_arvore_ponto_energia(variaveis), x, y);

    descontar_ponto_energia(ponto_mais_proximo, v);
    char tipoFigura = pega_ponto_energia_figura_tipo_origem(ponto_mais_proximo);
    char *figuraId;
    Dado figura = pega_ponto_energia_figura(ponto_mais_proximo);
    int resultadoChecagem;

    //SVG

    fprintf(svg_query, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"red\" stroke-width=\"1.0\" fill-opacity =  \"0\" stroke-opacity = \"0.8\"/>\n",
            pega_X_ponto_energia(ponto_mais_proximo), pega_Y_ponto_energia(ponto_mais_proximo), 2.0);
    fprintf(svg_query, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"red\" stroke-width=\"1.0\" fill-opacity =  \"0\" stroke-opacity = \"0.8\"/>\n",
            pega_X_ponto_energia(ponto_mais_proximo), pega_Y_ponto_energia(ponto_mais_proximo), 4.0);

    fprintf(svg_query, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"red\" stroke-width=\"1.0\" fill-opacity =  \"0\" stroke-opacity = \"0.8\"/>\n", x, y, 2.0);

    fprintf(svg_query, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"red\" stroke-width=\"1.0\"/>\n", pega_X_ponto_energia(ponto_mais_proximo), pega_Y_ponto_energia(ponto_mais_proximo), x, y);

    //FIMSVG

    fprintf(txt_query, "Ponto Query X-> %lf | Y -> %lf\n", x, y);
    fprintf(txt_query, "Ponto mais próximo: X-> %lf | Y-> %lf\n", pega_X_ponto_energia(ponto_mais_proximo), pega_Y_ponto_energia(ponto_mais_proximo));
    fprintf(txt_query, "Dados da figura:\n");
    switch (tipoFigura)
    {
    case 'c':
        resultadoChecagem = checar_pontos_energia_zero_circulo(figura);
        if (resultadoChecagem)
        {
            printf("vai remover \n");
            figuraId = pega_id_circulo(figura);
            deletar_no_kdtree(pega_arvore_circulo(variaveis), atof(pega_X_circulo(figura)), atof(pega_Y_circulo(figura)));
            
        }

        imprime_txt_dados_circulo_todos(figura, txt_query);

        break;
    case 'r':
        resultadoChecagem = checar_pontos_energia_zero_retangulo(figura);
        if (resultadoChecagem)
        {
            printf("vai remover retangulo\n");
            figuraId = pega_id_retangulo(figura);
            deletar_no_kdtree(pega_arvore_retangulo(variaveis), atof(pega_X_retangulo(figura)), atof(pega_Y_retangulo(figura)));
            
        }

        imprime_txt_dados_retangulo_todos(figura, txt_query);

        break;
    case 't':
        resultadoChecagem = checar_pontos_energia_zero_texto(figura);
        if (resultadoChecagem)
        {
            printf("vai remover texto\n");
            figuraId = pega_id_txt(figura);
            deletar_no_kdtree(pega_arvore_txt(variaveis), atof(pega_X_txt(figura)), atof(pega_Y_txt(figura)));
            
        }
        imprime_txt_dados_texto_todos(figura, txt_query);
        break;
    case 'l':
        resultadoChecagem = checar_pontos_energia_zero_linha(figura);
        if (resultadoChecagem)
        {
            printf("vai remover linha\n");
            figuraId = pega_id_linha(figura);
            deletar_no_kdtree(pega_arvore_linha(variaveis), atof(pega_x1_linha(figura)), atof(pega_y1_linha(figura)));
            
        }

        imprime_txt_dados_linha_todos(figura, txt_query);
        break;
    }
}

typedef struct
{
    double distancia;
    Ponto_Energia p1;
    Ponto_Energia p2;
} par_mais_prox;

par_mais_prox parMinimo(par_mais_prox x, par_mais_prox y)
{
    return (x.distancia < y.distancia) ? x : y;
}

par_mais_prox encontrar_par_mais_proximo_pontos_fronteira(Ponto_Energia pontosFronteira[], int n, double melhorDistancia)
{

    par_mais_prox parFronteira;
    parFronteira.distancia = DBL_MAX;

    //ordena os pontos de fronteira pela coordenada y
    qsort(pontosFronteira, n, sizeof(Ponto_Energia), comparar_pontos_pela_coordenada_y);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n && (pega_Y_ponto_energia(pontosFronteira[j]) - pega_Y_ponto_energia(pontosFronteira[i])) < melhorDistancia; ++j)
        {
            double distancia = calcula_distancia_pontos(pega_X_ponto_energia(pontosFronteira[i]), pega_Y_ponto_energia(pontosFronteira[i]), pega_X_ponto_energia(pontosFronteira[j]), pega_Y_ponto_energia(pontosFronteira[j]));
            if (distancia < melhorDistancia)
            {
                melhorDistancia = distancia;
                parFronteira.p1 = pontosFronteira[i];
                parFronteira.p2 = pontosFronteira[j];
                parFronteira.distancia = melhorDistancia;
            }
        }
    return parFronteira;
}

par_mais_prox encontrar_par_mais_proximo_recursivo(Ponto_Energia pontos[], int n)
{
    par_mais_prox par;

    if (n == 1)
    { //caso base 1
        par.distancia = DBL_MAX;
        return par;
    }

    if (n == 2)
    { //caso base 2
        par.distancia = calcula_distancia_pontos(pega_X_ponto_energia(pontos[0]), pega_Y_ponto_energia(pontos[0]), pega_X_ponto_energia(pontos[1]), pega_Y_ponto_energia(pontos[1]));
        par.p1 = pontos[0];
        par.p2 = pontos[1];
        return par;
    }

    // encontrando ponto do meio.
    int meio = n / 2;
    Ponto_Energia pontoMeio = pontos[meio];

    // encontrando os pares mais proximos da esquerda e da direita
    par_mais_prox parEsquerda = encontrar_par_mais_proximo_recursivo(pontos, meio);
    par_mais_prox parDireita = encontrar_par_mais_proximo_recursivo(pontos + meio, n - meio);

    //par mais proximo atual.
    par_mais_prox parMin = parMinimo(parEsquerda, parDireita);

    // vetor com um subconjunto de pontos que estao a menos que parMin.distancia unidades x do ponto do meio.
    Ponto_Energia pontosFronteira[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(pega_X_ponto_energia(pontos[i]) - pega_X_ponto_energia(pontoMeio)) < parMin.distancia)
        {
            pontosFronteira[j] = pontos[i];
            j++;
        }

    // encontra o par mais proximo no vetor pontosFronteira e retorna o menor par entre ele e o par minimo encontrado ate agora.
    par = parMinimo(parMin, encontrar_par_mais_proximo_pontos_fronteira(pontosFronteira, j, parMin.distancia));

    return par;
}

par_mais_prox encontrar_par_mais_proximo(Ponto_Energia pontos[], int n)
{

    if(n < 2){
        par_mais_prox par;
        par.distancia = -1;
        return par;
    }
    //ordenar vetor de pontos pela coordenada x.
    qsort(pontos, n, sizeof(Ponto_Energia), comparar_pontos_pela_coordenada_x);

    return encontrar_par_mais_proximo_recursivo(pontos, n);
}

typedef struct
{
    int ultimaPosicao;
    void **vet;
} vetor;

void salva_dado_vetor(void *dado, void *Vet)
{
    Ponto_Energia pe = dado;

    if (pega_ponto_energia_energia(pe) > 0)
    {
        vetor *vet = (vetor *)Vet;
        (vet->vet)[vet->ultimaPosicao] = pe;
        vet->ultimaPosicao++;
    }
}

void remover_ponto_desenergizado(vetor* vet, int n, Ponto_Energia remover);

void executa_ip(Variaveis Var, int n, FILE *txt_qry, FILE *txt_svg)
{

    int quantidade = pega_quantidade_KDTree(pega_arvore_ponto_energia(Var));
    vetor vet;
    vet.ultimaPosicao = 0;
    vet.vet = (void **)malloc(quantidade * sizeof(void *));
    percorre_kdtree_generico(pega_arvore_ponto_energia(Var), salva_dado_vetor, &vet);

    for (int i = 0; i < n; i++)
    {
        
        par_mais_prox par = encontrar_par_mais_proximo(vet.vet, quantidade);
        if(par.distancia < 0) break;
        double energia_p1 = pega_ponto_energia_energia(par.p1);
        double energia_p2 = pega_ponto_energia_energia(par.p2);
        descontar_ponto_energia(par.p1,energia_p2);
        descontar_ponto_energia(par.p2,energia_p1);
        
        //1.txt: printar par mais prox, sua energia, e as figuras que eles pertencem.

        //figura1
        char tipoFigura1 = pega_ponto_energia_figura_tipo_origem(par.p1);
        Dado figura1 = pega_ponto_energia_figura(par.p1);

        char* (*para_string)(void*);
        char* string;
        energia_p1 = pega_ponto_energia_energia(par.p1);
        int checagemFigura = 0;
        double x, y;
        char removido[15];
        removido[0] = '\0';
        
        switch (tipoFigura1){
            case 'r':
                para_string = retangulo_para_string;
                if(energia_p1 == 0){
                    checagemFigura = checar_pontos_energia_zero_retangulo(figura1);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_X_retangulo(figura1));
                        y = atof(pega_Y_retangulo(figura1));
                        deletar_no_kdtree(pega_arvore_retangulo(Var), x, y);
                    }
                }
                break;
            case 'c':
                para_string = circulo_para_string;
                if(energia_p1 == 0){
                    checagemFigura = checar_pontos_energia_zero_circulo(figura1);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_X_circulo(figura1));
                        y = atof(pega_Y_circulo(figura1));
                        deletar_no_kdtree(pega_arvore_circulo(Var), x, y);
                    }
                }
                break;
            case 'l':
                para_string = linha_para_string;
                if(energia_p1 == 0){
                    checagemFigura = checar_pontos_energia_zero_linha(figura1);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_x1_linha(figura1));
                        y = atof(pega_y1_linha(figura1));
                        deletar_no_kdtree(pega_arvore_linha(Var), x, y);
                    }                
                }
                break;
            case 't':
                para_string = txt_para_string;
                if(energia_p1 == 0){
                    checagemFigura = checar_pontos_energia_zero_texto(figura1);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_X_txt(figura1));
                        y = atof(pega_Y_txt(figura1));
                        deletar_no_kdtree(pega_arvore_txt(Var), x, y);
                    }
                }
                break;
        }   
        fprintf(txt_qry, "\niteracao: %d\n", i);
        fprintf(txt_qry, "ponto1: (%lf, %lf), energia: %lf\n", pega_X_ponto_energia(par.p1),pega_Y_ponto_energia(par.p1),pega_ponto_energia_energia(par.p1));
        fprintf(txt_qry, "figura 1 %s: %s \n", removido, (string = (*para_string)(figura1))); 
        free(string);
        
        removido[0] = '\0';


        //figura2
        char tipoFigura2 = pega_ponto_energia_figura_tipo_origem(par.p2);
        Dado figura2 = pega_ponto_energia_figura(par.p2);
        energia_p2 = pega_ponto_energia_energia(par.p2);
        switch (tipoFigura2){
            case 'r':
                para_string = retangulo_para_string;
                if(energia_p2 == 0){
                    checagemFigura = checar_pontos_energia_zero_retangulo(figura2);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_X_retangulo(figura2));
                        y = atof(pega_Y_retangulo(figura2));
                        deletar_no_kdtree(pega_arvore_retangulo(Var), x, y);
                    }
                }
                break;
            case 'c':
                para_string = circulo_para_string;
                if(energia_p2 == 0){
                    checagemFigura = checar_pontos_energia_zero_circulo(figura2);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_X_circulo(figura2));
                        y = atof(pega_Y_circulo(figura2));
                        deletar_no_kdtree(pega_arvore_circulo(Var), x, y);
                    }                
                }
                break;
            case 'l':
                para_string = linha_para_string;
                if(energia_p2 == 0){
                    checagemFigura = checar_pontos_energia_zero_linha(figura2);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_x1_linha(figura2));
                        y = atof(pega_y1_linha(figura2));
                        deletar_no_kdtree(pega_arvore_linha(Var), x, y);
                    }
                }
                break;
            case 't':
                para_string = txt_para_string;
                if(energia_p2 == 0){
                    checagemFigura = checar_pontos_energia_zero_texto(figura2);
                    if(checagemFigura){
                        sprintf(removido, "(removido)");
                        x = atof(pega_X_txt(figura2));
                        y = atof(pega_Y_txt(figura2));
                        deletar_no_kdtree(pega_arvore_txt(Var), x, y);
                    }
                }
                break;
        }
        fprintf(txt_qry, "ponto2: (%lf, %lf), energia: %lf\n",pega_X_ponto_energia(par.p2),pega_Y_ponto_energia(par.p2),pega_ponto_energia_energia(par.p2) );
        fprintf(txt_qry, "figura 2 %s: %s\n", removido, (string = (*para_string)(figura2)));
        free(string);


        //se o ponto zerar vamos remove-lo do vetor de pontos de energia...
        if(energia_p1 == 0){
            remover_ponto_desenergizado(&vet, quantidade, par.p1);
            quantidade--;
        }
        if(energia_p2 == 0){
            remover_ponto_desenergizado(&vet, quantidade, par.p2);
            quantidade--;
        }

    }
}

void remover_ponto_desenergizado(vetor* vet, int n, Ponto_Energia remover){
    for(int i = 0; i<n; i++){
        if(vet->vet[i] == remover){
            for(int j = i + 1; j<n; j++){
                vet->vet[i] = vet->vet[j];
                i++;
            }
            break;
        }
    }

    vet->ultimaPosicao--;
}