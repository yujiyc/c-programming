#include <stdio.h>
#include "primes.h"

int main()
{
    int count = 0;
    int current_prime = 2;
    printf("Os primeiros 10 números primos são:\n");
    while (count < 10)
    {
        printf("%d ", current_prime);
        current_prime = next_prime(current_prime);
        count++;
    }
    printf("\n");
    return 0;
}