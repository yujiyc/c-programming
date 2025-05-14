#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de dados
typedef struct
{
    int id;
    float valor;
} Dados;

// Função para operar na estrutura dinâmica
void operacaoEstrutura(void *estrutura)
{
    Dados *d = (Dados *)estrutura;
    d->valor *= 2;
}

int main()
{
    // Alocação dinâmica da estrutura
    Dados *ptr_dados = (Dados *)malloc(sizeof(Dados));
    if (ptr_dados == NULL)
    {
        fprintf(stderr, "erro ao alocar memória.\n");
        return 1;
    }

    // Preenchendo a estrutura com dados
    ptr_dados->id = 1;
    ptr_dados->valor = 10.5;

    // Chamando a função para operar na estrutura
    operacaoEstrutura(ptr_dados);

    // Exibindo os dados modificados da estrutura
    printf("ID: %d, Valor: %.2f\n", ptr_dados->id, ptr_dados->valor);

    // Liberando a memória alocada
    free(ptr_dados);

    return 0;
}