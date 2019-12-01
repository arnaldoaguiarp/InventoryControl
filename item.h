#include "data1.h"
#include <string.h>

struct item
{
    unsigned cod;
    char descricao[51];
    unsigned quantidade;
    TData validade;
    float preco_venda;
};
typedef struct item TItem;

int comp_cod(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return aa->cod - ab->cod;
}

int comp_des(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return strcmp(aa->descricao, ab->descricao);
}

int comp_quant(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return aa->quantidade - ab->quantidade;
}

int comp_preco_menor(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return aa->preco_venda - ab->preco_venda;
}

int comp_preco_maior(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return 100*(ab->preco_venda) - 100*(aa->preco_venda);
}

int comp_validade(const void *a, const void *b)
{
    TItem *aa = (TItem *) a;
    TItem *ab = (TItem *) b;
    return cmp_data(&aa->validade, &ab->validade);
}
