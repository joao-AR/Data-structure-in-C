#include "main.h"
#include "parametros.h"
#include "abrir_input.h"
#include "lista.h"

#include "geo.h"
#include "svg.h"
#include "qry.h"
#include "retangulo.h"
#include "variaveis.h"

int main(int argc, char *argv[])
{

    Variaveis arvores_listas = cria_variaveis();

    parametro_void parametros = cria_parametros();
    define_parametros(parametros, argv, argc);

    FILE *geo = abrir_arquivo_input(parametros, "geo");

    // SVG do .GEO
    FILE *svg_geo = cria_path_svg_geo(parametros); // cria o nome do svg e o local onde ele vai ser salvo

    salva_formas_nas_arvores(geo, arvores_listas);
    imprime_svg(pega_arvore_retangulo(arvores_listas), pega_arvore_circulo(arvores_listas),
                pega_arvore_txt(arvores_listas), pega_arvore_linha(arvores_listas), svg_geo);

    int sn = tem_qry(parametros); // sn -> sim = 0 / nao =1
    if (sn == 1)
    {
        printf("nao tem qry");
    }
    else
    {
        // SVG do .QRY
        FILE *qry = abrir_arquivo_input(parametros, "qry");
        FILE *svg_qry = cria_path_svg_qry(parametros);
        FILE *txt_qry = cria_path_txt(parametros);
        funcoes_qry(qry, svg_qry, txt_qry, arvores_listas);
        imprime_svg(pega_arvore_retangulo(arvores_listas), pega_arvore_circulo(arvores_listas),
                    pega_arvore_txt(arvores_listas), pega_arvore_linha(arvores_listas), svg_qry);
        fclose(txt_qry);
        fclose(qry);
    }

    fclose(geo);
    fclose(svg_geo);
    free(arvores_listas);
    return 0;
}