#ifndef hash_H
#define hash_H
#define Max_Nome 256
#define Tamanho_Tabela 10

typedef struct pessoa{
    char nome[Max_Nome];
    int telefone;
    struct pessoa* proximo;
}Pessoa;

int funcao_hash(char* nome);
void inicia_tabela_hash(Pessoa* hash_table[]);
bool insere_tabela_hash(void* pes,Pessoa* hash_table[]);
Pessoa* busca_tabela_hash(char* nome,Pessoa* hash_table[] );
Pessoa* remove_tabela_hash(char* nome,Pessoa* hash_table[]);
void imprime_tabela(Pessoa* hash_table[]);

void* cria_pessoa(char nome[] ,int telefone);

#endif