#include "primes.h"

int is_prime(int num)
{
    if (num < 2)
    {
        return 0; // numeros menores que 2 nao sao primos
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0; // se for divisivel por um número alem de 1 e o mesmo, nao é numero primo
        }
    }
    return 1; // se nao encontrou divisor, é primo
}

int next_prime(int current)
{
    int next = current + 1;
    while (!is_prime(next))
    {
        next++; // procura ate encontrar um primo
    }
    return next;
}