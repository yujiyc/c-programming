#include "libvet.h"
#include <stdio.h>
#include <stdlib.h>

void initDynamicIntArray(DynamicIntArray *vec, size_t initial_capacity)
{
    vec->array = (int *)malloc(initial_capacity * sizeof(int));

    if (vec->array == NULL)
    {
        fprintf(stderr, "erro ao alocar memória inicial.\n");
        exit(EXIT_FAILURE);
    }

    vec->size = 0;
    vec->capacity = initial_capacity;
}

void pushBack(DynamicIntArray *vec, int value)
{
    if (vec->size == vec->capacity)
    {
        size_t new_capacity = vec->capacity * 2;
        int *new_array = (int *)realloc(vec->array, new_capacity * sizeof(int));
        if (new_array == NULL)
        {
            fprintf(stderr, "erro ao realocar memória.\n");
            exit(EXIT_FAILURE);
        }
        vec->array = new_array;
        vec->capacity = new_capacity;
    }
    vec->array[vec->size] = value;
    vec->size++;
}

void freeDynamicIntArray(DynamicIntArray *vec)
{
    free(vec->array);
    vec->array = NULL;
    vec->size = 0;
    vec->capacity = 0;
}