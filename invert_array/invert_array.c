#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "invert_array.h"

// Função para alocar dinamicamente um vetor de inteiros
int *alocarVetor(int tamanho)
{
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    return vetor;
}

// Função para preencher o vetor com valores aleatórios
void preencherVetor(int *vetor, int tamanho)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100; // Preenche com valores aleatórios entre 0 e 99
    }
}

// Função para imprimir o vetor
void imprimirVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para inverter os elementos do vetor
void inverterVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho / 2; i++)
    {
        int temp = vetor[i];
        vetor[i] = vetor[tamanho - i - 1];
        vetor[tamanho - i - 1] = temp;
    }
}