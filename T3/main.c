#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "hash.h"

int main (){
    
    char nome[100],nome_busca[100];
    int op,telefone;

    Pessoa* hash_table[Tamanho_Tabela]; // criando a tabela hash
    inicia_tabela_hash(hash_table); // inicia ta tabela hash com NULL
    
    // ponteiro que será usado para criar e inserir na lista uma struct pessoa
    void* pessoa;
    
    // Pontrio pra um struct pessoa que será usada para escrever os dados na busca e remoção
    Pessoa* tmp; 

    do{// MENU
        printf("1 - Inserir\n2 - Buscar\n3 - Imprimir\n4 - Remover\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 0:
            printf("\nSaindo...\n");
        break;
        
        case 1:// Inserir 
            // Lendo o nome e o telefone
            printf("\ndigite o nome: ");
            scanf("%s",nome);
            printf("\nDigite o telefone : ");
            scanf("%d",&telefone);

            pessoa = cria_pessoa(nome,telefone);
            insere_tabela_hash(pessoa,hash_table);
        break;
        
        case 2:// Buscar 
            // Lendo o nome que vai ser buscado
            printf("\nDigite o nome da pessoa para buscar : ");
            scanf("%s", nome_busca);

            // *struct pessoa tmp recebe a pessoa que foi buscada 
            tmp = busca_tabela_hash(nome_busca,hash_table);
            
            // imprime as informações da pessoa se ela foi encontrada 
            printf("---------------------------------------");
            if(tmp != NULL){
                printf("\n\tNome: %s / Telefone: %d\n",tmp->nome, tmp->telefone);
                printf("-------------------------------------\n");
            }else{
                printf("\nPessoa nao encontrada!\n");
                printf("--------------------------------------\n");
            }
        break;
            
        case 3:// imprimir tabela hash
            imprime_tabela(hash_table);
        break;
        
        case 4:// Remover
            // le o nome da pessoa que vai ser removida
            printf("\nDigite o nome da pessoa para ser removida: ");
            scanf("%s",nome_busca);

            tmp = remove_tabela_hash(nome_busca,hash_table);
            printf ("\nNome:%s Telefone:%d <REMOVIDO>\n",tmp->nome,tmp->telefone);
        break;
        
        default:
            printf("\n<Opcao invalida!>\n");
        }

    }while(op != 0);

    return 0;
}