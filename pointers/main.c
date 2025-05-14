#include <stdio.h>

int main()
{

    float n;
    float *ptr_n;

    // Lê o valor da entrada padrão e coloca na variável do tipo float
    printf("Informe um valor float: ");
    scanf("%f", &n);

    // Atribui o endereço da variável tipo float para o ponteiro do tipo float
    ptr_n = &n;

    // Soma 10 ao conteúdo apontado pelo ponteiro do tipo float
    *ptr_n += 10;

    // Imprime o conteúdo da variável do tipo float
    printf("O novo valor é: %.2f\n", n);

    return 0;
}
