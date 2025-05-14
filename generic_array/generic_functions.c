#include "generic_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5

int readGenericData(struct GenericData *data, int *dataSize)
{
    char buffer[100];

    if (*dataSize >= MAX_SIZE)
    {
        printf("Ultrapassou o tamanho máximo do vetor.\n");
        return 3;
    }

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return 1;
    }

    buffer[strcspn(buffer, "\n")] = 0; // remove newline

    if (strcmp(buffer, ".") == 0)
    {
        return 2;
    }

    // Tenta converter para int
    char *endptr;
    int intValue = strtol(buffer, &endptr, 10);
    if (*endptr == '\0')
    {
        data[*dataSize].type = 0;
        data[*dataSize].data.intValue = intValue;
        (*dataSize)++;
        return 0;
    }

    // Tenta converter para float
    float floatValue = strtof(buffer, &endptr);
    if (*endptr == '\0')
    {
        data[*dataSize].type = 1;
        data[*dataSize].data.floatValue = floatValue;
        (*dataSize)++;
        return 0;
    }

    // Se não é número, é string
    data[*dataSize].type = 2;
    data[*dataSize].data.stringValue = malloc(strlen(buffer) + 1);
    if (data[*dataSize].data.stringValue == NULL)
    {
        return 1;
    }
    strcpy(data[*dataSize].data.stringValue, buffer);
    (*dataSize)++;
    if (*dataSize >= MAX_SIZE)
    {
        printf("Ultrapassou o tamanho máximo do vetor.\n");
        return 3;
    }
    return 0;
}

int printGenericData(struct GenericData *data, int dataSize)
{
    bool printedTypes[3] = {false, false, false};

    for (int i = 0; i < dataSize; i++)
    {
        int currentType = data[i].type;

        if (!printedTypes[currentType])
        {
            printedTypes[currentType] = true;

            // Imprime todos os dados desse tipo na ordem de entrada
            for (int j = 0; j < dataSize; j++)
            {
                if (data[j].type == currentType)
                {
                    switch (data[j].type)
                    {
                    case 0:
                        if (j == 0 || data[j - 1].type != currentType)
                            printf("int ");
                        printf("%d ", data[j].data.intValue);
                        break;
                    case 1:
                        if (j == 0 || data[j - 1].type != currentType)
                            printf("float ");
                        printf("%.1f ", data[j].data.floatValue);
                        break;
                    case 2:
                        if (j == 0 || data[j - 1].type != currentType)
                            printf("string ");
                        printf("%s ", data[j].data.stringValue);
                        break;
                    }
                }
            }
        }
    }

    printf("\n");
    return 0;
}