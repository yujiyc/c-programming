#include <stdio.h>
#include "sum_ascii.h"

int sum_ascii(const char *str)
{
    int sum = 0;

    // percorre cada caractere da string até achar o caractere nulo '\0'
    while (*str != '\0')
    {
        sum += (int)(*str);
        str++;
    }
    return sum;
}
