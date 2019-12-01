#include "item.h"

struct LisProduto
{
    TItem itens[100];
    unsigned ni;
};
typedef struct LisProduto TListaProd;

TListaProd gera_lista()
{
    TListaProd lis;
    srand(time(NULL));
    char produtos[][51] = {"Pitaya(Uni)", "Goma de mascar-Pct", "Manga(Uni)", "Sonho de valsa-Pct(25un)", "Iogurte 750ml", "Nesfit(Uni)",
                           "Nescau 1L", "Cheetos 75g"};
    float precos[]  = {15.00, 17.50 , 4.00, 28.90, 23.75, 4.60, 12.30, 2.00};
    int i,q, d, m;
    for(i=0;i<6; i++){
    q = rand()%15;
    d = rand()%30+1;
    m = rand()%11+1;
    lis.itens[i].cod=i+1;
    strcpy(lis.itens[i].descricao,produtos[i]);
    lis.itens[i].quantidade = q+3;
    lis.itens[i].preco_venda = precos[i];
    lis.itens[i].validade.dia = d;
    lis.itens[i].validade.mes = m;
    lis.itens[i].validade.ano =2018;
    }
    lis.ni = 6;
    return lis;
}

void insere_item(TListaProd *lis)
{
//    TData data_prod;
    char nome[51];
    printf(" %c\n %cDIGITE O C%cDIGO DO PRODUTO:",176,176,224);
    scanf("%u", &lis->itens[lis->ni].cod);
    printf(" %c",176);

    printf("\n %cDIGITE A DESCRI%c%cO DO PRODUTO:",176,128,199);
    scanf("%s", nome);
    strcpy( lis->itens[lis->ni].descricao,nome);
    printf(" %c",176);

    printf("\n %cDIGITE A QUANTIDADE QUE DESEJA CADASTRAR:",176);
    scanf("%u", &lis->itens[lis->ni].quantidade);
    printf(" %c",176);

    printf("\n %cDIGITE O PRE%cO DO PRODUTO:", 176,128);
    scanf("%f", &lis->itens[lis->ni].preco_venda);
    printf(" %c",176);

//    printf("\nDIGITE A DIA DA V%cLIDADE DO PRODUTO (dd/mm/aaaa):\n",181);
//    data_prod = le_data();
//    lis->itens[lis->ni].validade=data_prod;

    printf("\n %cDIGITE A DIA DA V%cLIDADE DO PRODUTO:",176,181);
    scanf("%d",&lis->itens[lis->ni].validade.dia);
    printf(" %cDIGITE UM M%cS DA V%cLIDADE DO PRODUTO:", 176,210,181);
    scanf("%d",&lis->itens[lis->ni].validade.mes);
    printf(" %cDIGITE UM ANO DA V%cLIDADE DO PRODUTO:",176,181);
    scanf("%d", &lis->itens[lis->ni].validade.ano);

    lis->ni++;
//    scanf("%c/%c/%hd", &lis->itens[lis->ni].validade.dia, &lis->itens[lis->ni].validade.mes,&lis->itens[lis->ni].validade.ano); //&res.dia, &res.mes, &res.ano);
}

void remove_item(TListaProd *lis)
{
    printf(" DIGITE O C%cDIGO DO PRODUTO: ", 224);
    scanf("%u", &lis->itens[lis->ni].cod);

    lis->ni--;
}

void mostre_lista_itens(TListaProd *lis)
{
//    int i,j;
    int j;

    printf("%2c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",
           201,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
           205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,203,205,205,205,205,205,205,
           205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%2c C%cD %c PRODUTOS                 %c QUANT %c  VALOR  %cDATA DE VALID%c \n",186,224,186,186,186,186,186);
    printf("%2c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",
           204,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
           205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,206,205,205,205,205,205,205,
           205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,185);

    for(j=0; j<lis->ni; j++)
    {
        printf("%2c %3.03d %c %-24s %c %5u %c %7.2f %c %3.02d/%02d/%04d%2c\n",179, lis->itens[j].cod,179,
               lis->itens[j].descricao,179, lis->itens[j].quantidade,179, lis->itens[j].preco_venda,179,
               lis->itens[j].validade.dia,lis->itens[j].validade.mes, lis->itens[j].validade.ano,179);
    }
    printf("%2c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",
           200,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
           205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,
           205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}

void mostra_prod_perto_vencer(TListaProd lis)
{
    int res;
    TData dt;
    dt = dat_sis();
    int j;

    printf("%2c %s %c   %s %12c %s %c %6s %c %10s %2c\n",179 ,"COD",179 ,"PRODUTO",179 ,"QUANTIDADE",179 ,"VALOR", 179 ,"VALIDADE",179);
    for(j<0;j<lis.ni+1;j++)
    {
       res = cmp_data(&dt,&lis.itens[j].validade);
       if(res < 15)
        {
                   printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis.itens[j].cod,179,
                   lis.itens[j].descricao,179, lis.itens[j].quantidade,179, lis.itens[j].preco_venda,179,
                   lis.itens[j].validade.dia,lis.itens[j].validade.mes, lis.itens[j].validade.ano,179);
        }
    }
}

void mostra_prod_quant_baixa(TListaProd *lis)
{
    int j;

    printf("%2c %-8s %c %s %16c %s %c %-8s %2c %s %4c\n",179 ,"COD",179 ,"PRODUTO",179 ,"QUANTIDADE",179 ,"VALOR", 179 ,"VALIDADE",179);

    for (j=0;j<lis->ni;j++)
        {
            if(lis->itens[j].quantidade <15)
            {
               printf("%2c %-8.03d %c %-22s %c %8u %3c %-8.2f %2c %3.02d/%02d/%04u%2c\n",179, lis->itens[j].cod,179,
               lis->itens[j].descricao,179, lis->itens[j].quantidade,179, lis->itens[j].preco_venda,179,
               lis->itens[j].validade.dia,lis->itens[j].validade.mes, lis->itens[j].validade.ano,179);
            }
        }
}

int busca_pelo_codigo(TListaProd lis, unsigned codigo)
{
    int j, res1, k=0;
    for (j=0;j<lis.ni;j++)
    {
        res1 = comp_cod(&lis.itens[j].cod, codigo);
        if(lis.itens[j].cod==codigo)
        {
            if(res1 == 0){
                printf("%2c %3.03d %c %-20s %c %8u %3c %.2f %3c %3.02d/%02d/%04d%2c\n",179, lis.itens[j].cod,179,
                lis.itens[j].descricao,179, lis.itens[j].quantidade,179, lis.itens[j].preco_venda,179,
                lis.itens[j].validade.dia,lis.itens[j].validade.mes, lis.itens[j].validade.ano,179);
                k=1;
        }
    }
    if(k==0){
        printf(" %cPRODUTO N%cO ENCONTRADO NO ESTOQUE%c", 178,199,178);
        return -1;
    }
    return -2;
    }
}

void busca_por_nome(TListaProd lis, char n[51])
{
    int j, res2, k=0;
    for(j=0;j<lis.ni;j++)
    {
        res2 = comp_des(&lis.itens[j].descricao, n);
        if(res2 == 0){

            printf("%2c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",
                   201,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
                   205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,203,205,205,205,205,205,205,
                   205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
            printf("%2c C%cD %c PRODUTOS                 %c QUANT %c  VALOR  %cDATA DE VALID%c \n",186,224,186,186,186,186,186);
            printf("%2c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",
                   204,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
                   205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,206,205,205,205,205,205,205,
                   205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
            printf("%2c %3.03d %c %-24s %c %5u %c %7.2f %c %3.02d/%02d/%04d%2c\n",179, lis.itens[j].cod,179,
                   lis.itens[j].descricao,179, lis.itens[j].quantidade,179, lis.itens[j].preco_venda,179,
                   lis.itens[j].validade.dia,lis.itens[j].validade.mes, lis.itens[j].validade.ano,179);
            printf("%2c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",
                   200,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
                   205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,
                   205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

               k=1;
       }
    }
    if (k==0)
        {
        printf(" %cPRODUTO N%cO ENCONTRADO NO ESTOQUE%c", 178,199,178);
        }
}

