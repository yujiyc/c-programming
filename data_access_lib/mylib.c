#include "mylib_pri.h"
#include "mylib_pub.h"

int criarTDA(ppTDA pp, int tamanho_info)
{
    *pp = (pTDA)malloc(sizeof(TDA));
    if (*pp == NULL)
    {
        return FRACASSO;
    }

    (*pp)->tamanho_info = tamanho_info;
    (*pp)->TDA_info1 = 0;
    (*pp)->TDA_info2 = 0;
    return SUCESSO;
}

int retornarTDA_info1(pTDA p, int *TDA_info1)
{
    if (p == NULL || TDA_info1 == NULL)
        return FRACASSO;
    *TDA_info1 = p->TDA_info1;
    return SUCESSO;
}

int alterarTDA(pTDA p, int TDA_info)
{
    if (p == NULL)
        return FRACASSO;
    p->TDA_info1 = TDA_info;
    return SUCESSO;
}

int destroirTDA(ppTDA pp)
{
    if (pp == NULL || *pp == NULL)
        return FRACASSO;
    free(*pp);
    *pp = NULL;
    return SUCESSO;
}

// exemplo de função privada
int finterna(int p2)
{
    return p2 * 2;
}