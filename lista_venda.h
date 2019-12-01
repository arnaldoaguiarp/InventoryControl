#include "venda.h"
struct lista_venda
{
    TVenda item_venda[100];
    unsigned nv;
};
typedef struct lista_venda TListaVend;

TListaVend gere_lis_venda(){
        TListaVend lisV;
        lisV.item_venda[0].cod_item=0;
        lisV.item_venda[0].quantidade= 3;
        lisV.item_venda[0].preco_venda = 6;
        lisV.item_venda[0].data_venda = dat_sis();
//        lisV.it_vend[0].data_venda.dia = 22;
//        lisV.it_vend[0].data_venda.mes = 12;
//        lisV.it_vend[0].data_venda.ano =2017;

        lisV.nv =1;
        return lisV;
}

void mostra_vendas(TListaVend *lisV){
    int i,j;

    printf("%2c %s %c %4s %c %14s %c %s %8c\n",179 ,"COD",179 ,"QUANTIDADE",179 ,"VALOR DA VENDA", 179 ,"DATA",179);
    for(j=0;j<lisV->nv;j++)
            {
               printf("%2c %3.03d %c %-8u %3c %-14.2f %c %3.02d/%02d/%04hd%2c\n",179, lisV->item_venda[j].cod_item
                      ,179, lisV->item_venda[j].quantidade,179, lisV->item_venda[j].preco_venda,179,
               lisV->item_venda[j].data_venda.dia,lisV->item_venda[j].data_venda.mes, lisV->item_venda[j].data_venda.ano,179);
            }
}

