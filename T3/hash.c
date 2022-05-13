#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "hash.h"


void* cria_pessoa(char nome[] ,int telefone){
    // vai cirar uma struct pessoa com os valores passados pelo usuario e retorna essa pessoa
    Pessoa *nova = malloc (sizeof(Pessoa));
    strcpy (nova->nome,nome);
    nova->telefone = telefone;
    return nova;
}

int funcao_hash(char* nome){
    int tamanho = strnlen(nome,Max_Nome);// pega o tamanho da sting 
    int valor_hash = 0;
    
    for (int i=0; i < tamanho; i++){
        //valor hash recebe soma ao valor hash da poisição com o valor da letra na tabela ascii
        valor_hash += nome[i]; 
        // valor  recebe o resto da divisão do valor da posição na hash multiplicado pelo valor na tabela ascii da letra 
        valor_hash = (valor_hash * nome[i])% Tamanho_Tabela; 
    }
    return valor_hash;
}

void inicia_tabela_hash(Pessoa* hash_table[]){
    for(int i=0; i< Tamanho_Tabela;i++){
        hash_table[i] = NULL;
    }
}

bool insere_tabela_hash(void *pes,Pessoa* hash_table[]){
    // cria um ponteiro para struct pessoa, esse ponteiro recebe o casting a pessoa void* passada
    Pessoa* p = (Pessoa*) pes; 
    if(p == NULL) return false;
    int indice = funcao_hash(p->nome);// indice recebe o valor da função hash
    // insere a pessoa no inicio da lista 
    p->proximo = hash_table[indice];// A nova pessoa apontando para proximo criada recebe a pessoa que está no inicio atual  
    hash_table[indice] = p; // o inicio da lista de pessoa na tabela hash na posição (indice) vai ser a nova pessoa criada  
    return true;

}

Pessoa* busca_tabela_hash(char* nome,Pessoa* hash_table[] ){
    // calcula o indice da pessoa
    int indice = funcao_hash(nome); 
    // tmp recebe a lista de pessoas no indice indicado na tabela hash
    Pessoa* tmp = hash_table[indice];
    
    while (tmp != NULL && strncmp(tmp->nome,nome,Max_Nome)!= 0){
        // andando até o final da lista ou até acharmos uma pessoa com o nome igual ao passado para a função
        tmp = tmp->proximo;
    }
    return tmp;
}

Pessoa* remove_tabela_hash(char* nome,Pessoa* hash_table[]){
    
    int indice = funcao_hash(nome);
    // tmp recebe a lista de pessoas na função hash no indice i
    Pessoa *tmp = hash_table[indice];
    Pessoa *anterior= NULL;

    while(tmp != NULL && strncmp(tmp->nome,nome,Max_Nome)!=0){
        // procular na lista a pessoa digitada 
        anterior = tmp;
        tmp = tmp->proximo;
    }

    // se o while não achar a pessoa difitada retorna NULL
    if(tmp == NULL) return NULL;

    if(anterior == NULL){//deletando No cabeça
        hash_table[indice] = tmp->proximo;
    }else{
        // Pessoa anterior recebe o proximo da Pessa que vai ser deletada 
        anterior->proximo = tmp->proximo; 
    }
    return tmp;
}

void imprime_tabela(Pessoa* hash_table[]){
    
    printf("\n-----Inicio Tabela-----\n");
    
    for(int i=0; i< Tamanho_Tabela; i++){
        // andar em todas as posições da tabela hash
        
        if(hash_table[i] == NULL){
            // se posição no indice i na tabela hash não conter nada 
            printf("\t%i\t--\n",i);
        }else{
            // se conter pessoas na lista na tabela hash no inidice i
            printf("\t%i\t",i);
            // ponteiro para pessoa tmp rece a lista da tabela hash no indice i
            Pessoa *tmp = hash_table[i];

            while(tmp != NULL){// enquanto não acabar a lista 
                printf("%s-",tmp->nome);// imprimir o nome da pessoa 
                tmp = tmp->proximo;// ir para a proxima pessoa na lista 
            }
            printf("\n");
        }
    }
    printf("------Fim Tabela------\n");
}


