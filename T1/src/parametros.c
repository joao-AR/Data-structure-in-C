
#include "parametros.h"



typedef struct parametros{
    char* inputDirectory;   // -e: diretorio de entrada
    char* geoName;          // -f: nome + extensao do arquivo .geo
    char* qryName;          // -q: nome + extensao do arquivo .qry
    char* outputDirectory;  // -o: diretorio de saida
}parametros;

int tem_qry(void* param){ // verfica se foi passado um arquivo .qry
    parametros *Param = (parametros*) param;
    if(Param->qryName == NULL){
        return 1; // Não foi passado
    }else{
        return 0; // foi passado
    }
}
parametro_void cria_parametros(){
    parametros *param = (parametros*) malloc(sizeof(parametros));
    
    if(param == NULL){
        printf("Erro ao alocar memória para o TAD dos parametros..\nFinalizando o programa..\n");
        exit(1);
    }

    //Limpando o lixo dos ponteiros alocados
    param->inputDirectory = NULL;
    param->geoName = NULL;
    param->qryName = NULL;
    param->outputDirectory = NULL;
    
    return param;
}

void define_parametros (parametro_void Param, char* argv[], int argc){
    int i = 1;
    parametros *param = (parametros*) Param; 
    
    while(i < argc){

        if(strcmp("-e", argv[i]) == 0){
            ++i;
            define_parametro_atual(&param->inputDirectory, argv[i]);
            
        }else if(strcmp("-f", argv[i]) == 0){
            ++i;
            define_parametro_atual(&param->geoName, argv[i]);
            

        }else if(strcmp("-q", argv[i]) == 0){
            ++i;
            define_parametro_atual(&param->qryName, argv[i]);

        }else if(strcmp("-o", argv[i]) == 0){
            ++i;
            define_parametro_atual(&param->outputDirectory, argv[i]);
        
        }
        
        i++;
    }

     //Se um diretorio de entrada não for especificado (-e), usaremos o diretorio atual:
    if(param->inputDirectory == NULL){ 
        param->inputDirectory = (char*) malloc(3 * sizeof(char));     
        strcpy(param->inputDirectory, "./");  
    }

    if(param->geoName == NULL){
        printf("O parametro -f, que e obrigatorio, esta ausente..\nFinalizando o programa..\n");
        exit(1);
    }

    if(param->outputDirectory == NULL){
        printf("O parametro -o, que e obrigatorio, esta ausente...\nFinalizando programa..\n");
        exit(1);
    }
}

void define_parametro_atual(char** parametro_atual, char* argv_atual){
    *parametro_atual = (char*) malloc((strlen(argv_atual) + 1) * sizeof(char)); //Alocando memória para guardar a string referente ao parametro atual.
    
    if(*parametro_atual == NULL){
        printf("Erro ao alocar memoria para o parametro \"%s\"..\nFinalizando o programa..\n", argv_atual);
        exit(1);
    }
    
    strcpy(*parametro_atual, argv_atual);
}

char* pega_diretorio_input(parametro_void Param){

    if(Param == NULL){
        printf("Erro: A instancia de Parametros nao existe..\nFinalizando o programa..\n");
        //***Desalocar memórias alocadas até o momentos***
        exit(1);
    }
    
    parametros *param = (parametros*) Param;
    return param->inputDirectory;

}

char* pega_diretorio_output(parametro_void Param){

    if(Param == NULL){
        printf("Erro ao alocar memória para o atributo inputDirectory..\nFinalizando o programa..\n");
        //***Desalocar memórias alocadas até o momentos***
        exit(1);
    }
    
    parametros *param = (parametros*) Param;
    return param->outputDirectory;

}


char* pega_nome_geo(parametro_void Param){
    if(Param == NULL){
        printf("Erro: A instancia de Parametros nao existe..\nFinalizando o programa..\n");
        //***Desalocar memórias alocadas até o momentos***
        exit(1);
    }
    
    parametros *param = (parametros*) Param;
    return param->geoName;
}

char* pega_nome_qry(parametro_void Param){
    if(Param == NULL){
        printf("Erro: A instancia de Parametros nao existe..\nFinalizando o programa..\n");
        //***Desalocar memórias alocadas até o momentos***
        exit(1);
    }
    
    parametros *param = (parametros*) Param;
    return param->qryName;
}