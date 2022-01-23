#include "abrir_input.h"

FILE* abrir_arquivo_input(parametro_void Param, char* tipo_arquivo){ 
    
    char* inputDirectory = pega_diretorio_input(Param); 
    char* nome_arquivo_input;

    if(strcmp(tipo_arquivo, "geo") == 0){
        nome_arquivo_input = pega_nome_geo(Param); 
        
    }else if(strcmp(tipo_arquivo, "qry") == 0){
        nome_arquivo_input = pega_nome_qry(Param);

    }else{
        printf("%s é um tipo invalido. Nao foi possivel abrir o arquivo ..\n", tipo_arquivo);
        return NULL;
    }
    
    char* path_arquivo_input = constroi_path_arquivo_input(inputDirectory, nome_arquivo_input); 

    FILE* file = fopen(path_arquivo_input, "r");

    if(file == NULL){
        printf("Erro ao abrir o arquivo %s..\nFinalizando o programa..\n", tipo_arquivo);
        exit(1);
    }
    printf("O arquivo %s foi aberto..\n", tipo_arquivo);  
    
    free(path_arquivo_input);
    return file;
}

char* constroi_path_arquivo_input(char* diretorio_input, char* nome_arquivo_input){

    char* inputFilePath = (char*) malloc((strlen(diretorio_input) + strlen(nome_arquivo_input)) * sizeof(char) + 5);
    int tamanho_diretorio_input = strlen(diretorio_input);

    if((diretorio_input[tamanho_diretorio_input-1] != '/') && (nome_arquivo_input[0] != '/') //corrige o seguinte erro:  /home/ed/testes001.geo  -> dirarq
        && (nome_arquivo_input[0] != '.') ){

        sprintf(inputFilePath, "%s/%s", diretorio_input, nome_arquivo_input);

    }else if((diretorio_input[tamanho_diretorio_input-1] != '/') && (nome_arquivo_input[0] == '.')){ //corrige o seguinte erro: /home/ed/testes./001.geo -> dir./arq

        sprintf(inputFilePath, "%s/%s", diretorio_input, nome_arquivo_input);

    }else if((diretorio_input[tamanho_diretorio_input-1] == '/') && (nome_arquivo_input[0] == '/')){  //corrige o seguinte erro: /home/ed/testes//001.geo dir//arq

        sprintf(inputFilePath, "%s.%s", diretorio_input, nome_arquivo_input);

    }else{ //caso o path seja inserido corretamente: ././arq ;  dir/./arq ; 
        sprintf(inputFilePath, "%s%s", diretorio_input, nome_arquivo_input);
    }
    
    return inputFilePath;
}

