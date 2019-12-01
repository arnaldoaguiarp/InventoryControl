#include "compra.h"

struct lista_compra{
    TCompra item_compra[100];
    unsigned num_compra;
};
typedef struct lista_compra TListaCompra;

TListaCompra gera_compra(){
    TListaCompra lisC;
    lisC.item_compra[0].cod_item = 012;
    lisC.item_compra[0].data = dat_sis();
    lisC.item_compra[0].preco_compra_total = 12.3;
    lisC.item_compra[0].quantidade = 12;

    lisC.item_compra[1].cod_item = 025;
    lisC.item_compra[1].data = dat_sis();
    lisC.item_compra[1].preco_compra_total = 15.7;
    lisC.item_compra[1].quantidade = 6;

    lisC.num_compra = 3;
    return lisC;
}

void mostre_lis_compras(TListaCompra *lisC){
    int i;
    printf("%3s %6s %6s %6s" ,"codigo", "quantidade", "preco", "data");
    for(i=0; i<lisC->num_compra; i++){
        printf("%u %u %.2f %2d/%2d/%d\n", lisC->item_compra[i].cod_item, lisC->item_compra[i].quantidade, lisC->item_compra[i].preco_compra_total, lisC->item_compra[i].data.dia, lisC->item_compra[i].data.mes, lisC->item_compra[i].data.ano);
    }
}

void compras_entre_data(TListaCompra lisD, TData datA, TData datB)
{
    TListaCompra lista_compra;
    int j;
    int res1;
    int res2;
    int res3=0;
    for (j=0;j<lista_compra.num_compra;j++)
        {
            res1 = cmp_data(&datA,&lista_compra.item_compra[j].data);
            res2 = cmp_data(&datB,&lista_compra.item_compra[j].data);

            if(res1<0 && res2>0)
            {
                printf("%2c %3.03d %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lisD.item_compra[j].cod_item
                       ,179, lisD.item_compra[j].quantidade,179, lisD.item_compra[j].preco_compra_total,179,
                       lisD.item_compra[j].data.dia,lisD.item_compra[j].data.mes, lisD.item_compra[j].data.ano,179);
                       res3 =1;
            }
        }
        if(res3==0) printf(" NENHUMA COMPRA FEITA NO PER%cODO ESPECIFICADO\n",214);
}

void insere_prod_compra(TListaCompra *lisC, TListaProd *lisP, TListaProd lisP2)
{
    unsigned cod_comp;
    unsigned quantidadeC;
    float preco_compra;
    int res;
    TData resdata;

//        printf(" DIGITE O C%cDIGO DO PRODUTO: ",224);
//        scanf("%u", &cod_comp);
//        if(cod_comp == NULL){
//            printf(" PRODUTO N%cO CADASTRADO, FAVOR REALIZAR O CADASTRO", 199);
//        }
        insere_item(lisP);
        printf(" %c\n %cDIGITE O PRE%cO TOTAL DA COMPRA: ",176,176,128);
        scanf("%f", &preco_compra);
        printf(" %cDIGITE A QUANTIDADE: ",176);
        scanf("%u", &quantidadeC);
        lisC->item_compra[lisC->num_compra].cod_item = cod_comp;
        lisC->item_compra[lisC->num_compra].quantidade = quantidadeC;
        lisC->item_compra[lisC->num_compra].preco_compra_total = preco_compra;
        lisC->item_compra[lisC->num_compra].data = dat_sis();
        lisC->num_compra++;
}


