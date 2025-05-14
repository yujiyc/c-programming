#include <stdio.h>
#include "troca.h"

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}