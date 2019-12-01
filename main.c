#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_itens.h"
#include "lista_compra.h"
#include "lista_venda.h"

char menu_principal()
{
    printf(" ______________________________________\n");
    printf(" ------------MENU PRINCIPAL------------\n\n");
    printf("  1 - LISTAR PRODUTOS\n");
    printf("  2 - BUSCAR PRODUTOS\n");
    printf("  3 - VENDER PRODUTO\n");
    printf("  4 - INSERIR PRODUTO\n");
    printf("  5 - CONTROLE DE ESTOQUE\n");

    printf("\n |0 - SAIR DO APLICATIVO|\n\n");
    printf("     %cESCOLHA UMA OP%c%cO: ",175,128,199);
    return getche();
    printf("\n");
}

char menu_listagem()
{
    printf("\n ______________________________________\n");
    printf(" -----------MENU DE LISTAGEM-----------\n\n");
    printf(" 1 - ORDENADOS PELO C%cDIGO\n",224);
    printf(" 2 - ORDENADOS PELO NOME\n");
    printf(" 3 - ORDENADOS PELO MENOR PRECO\n");
    printf(" 4 - ORDENADOS PELO MAIOR PRECO\n");
    printf(" 5 - ORDENADOS PELA QUANTIDADE\n");
    printf(" 6 - ORDENADOS PELA DATA DE VALIDADE\n");

    printf("\n |0 - VOLTAR PARA O MENU PRINCIPAL|\n");
    printf("     %cESCOLHA UMA OP%c%cO: ",175,128,199);
    return getche();
}

char menu_estoque()
{
    printf("\n ______________________________________\n");
    printf(" -----------MENU DE ESTOQUE -----------\n\n");
    printf(" 1 - ADICIONAR PRODUTO COMPRADO\n");
    printf(" 2 - MOSTRAR LISTA DE PRODUTOS COMPRADOS\n");
    printf(" 3 - PRODUTOS PR%cXIMOS AO VENCIMENTO\n",224);
    printf(" 4 - PRODUTOS EM BAIXA QUANTIDADE\n");
    printf(" 5 - CONTROLE DE VENDAS ENTRE DATAS\n");

    printf("\n |0 - VOLTAR PARA O MENU PRINCIPAL|\n");
    printf("     %cESCOLHA UMA OP%c%cO: ",175,128,199);
    return getche();
}

char menu_de_busca()
{
    printf("\n _________________________________________\n");
    printf(" ----------- MENU DE BUSCA --------------\n\n");
    printf(" 1 - BUSCAR PELO NOME\n");
    printf(" 2 - BUSCAR PELO C%cDIGO\n", 224);

    printf("\n |0 - VOLTAR PARA O MENU PRINCIPAL|\n");
    printf("     %cESCOLHA UMA OP%c%cO: ",175,128,199);
    return getche();
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int i;
    int v=1;
    char nome_produto[51];
    unsigned cod_produto;

    TListaProd list;
    TItem it;
    list = gera_lista();

    TListaCompra list_compra;
    list_compra = gera_compra();
    TListaVend lis_venda;
    lis_venda = gere_lis_venda();

    TData dt1, dt2;

    ////list = lista de produtos
    FILE *file;
    file = fopen("estoque.arq","rb");
    fread(&list.ni, sizeof(unsigned), 1, file);
    fread(list.itens, sizeof(TListaProd), list.ni, file);
    if(file == NULL)
    {
        printf(" Falha na abertura do arquivo! ");
        exit(1);
    }

    char op,op2,op3,op4,op5;
    while(1) {
        system("cls");

        printf(" ______________________________________\n");
        printf(" %c%c%c SISTEMA DE CONTROLE DE VENDAS %c%c%c%c\n",176,176,176,176,176,176,176,176);
        printf(" %cEmpresa.SA%c%c%cCNPJ:00.000.000.0009-99%c\n\n",175,184,174,175,174);

        op=menu_principal();
        printf("\n");

        if(op == '0')
            break;

        switch(op)
       {
            case '1':
            system("cls");

               while(1) {
                    op2 = menu_listagem();
                    if(op2 == '0')
                        break;

                     switch(op2){
                        case '1':
                            system("cls");
                            printf(" __________________________________________________________________\n");
                            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c PRODUTOS EM ORDEM DE C%cDIGO %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,224,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                            qsort(list.itens, list.ni, sizeof(TItem), comp_cod);
                            mostre_lista_itens(&list);
                            break;
                        case '2':
                            system("cls");
                            printf(" __________________________________________________________________\n");
                            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c PRODUTOS EM ORDEM DE NOME %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                            qsort(list.itens, list.ni, sizeof(TItem), comp_des);
                            mostre_lista_itens(&list);
                            break;
                        case '3':
                            system("cls");
                            printf(" __________________________________________________________________\n");
                            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c PRODUTOS EM ORDEM DE  MENOR PRE%cO %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,128,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                            qsort(list.itens, list.ni, sizeof(TItem), comp_preco_menor);
                            mostre_lista_itens(&list);
                            break;
                        case '4':
                            system("cls");
                            printf(" __________________________________________________________________\n");
                            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c PRODUTOS EM ORDEM DE  MAIOR PRE%cO %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,128,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                            qsort(list.itens, list.ni, sizeof(TItem), comp_preco_maior);
                            mostre_lista_itens(&list);
                            break;
                        case '5':
                            system("cls");
                            printf(" __________________________________________________________________\n");
                            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c PRODUTOS EM ORDEM DE QUANTIDADE %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                            qsort(list.itens, list.ni, sizeof(TItem), comp_quant);
                            mostre_lista_itens(&list);
                            break;
                        case '6':
                            system("cls");
                            printf(" __________________________________________________________________\n");
                            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c PRODUTOS EM ORDEM DE VALIDADE %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                            qsort(list.itens, list.ni, sizeof(TItem), comp_validade);
                            mostre_lista_itens(&list);
                            break;
                    }
                }
               break;

            case '2':
                system("cls");
                while(1)
                {
//                    system("cls");
                    op4 = menu_de_busca();
                    if (op4=='0')
                        break;
                    switch(op4)
                    {
                        case '1':
                            system("cls");
                            fflush(stdin);
                            printf("\n\n __________________________________________________________________\n");
                            printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);

                            printf("\n\n DIGITE O NOME DO PRODUTO: ");
                            gets(nome_produto);
                            busca_por_nome(list, nome_produto);

                            break;
                        case '2':
                            printf("\n\n DIGITE O C%cDIGO DO PRODUTO: \n",224);
                            gets(cod_produto);
                            busca_pelo_codigo(list, cod_produto);

                            break;
                    }
                  }
                break;

            case '3':
                system("cls");
                printf(" _________________________________________\n");
                printf(" ------------ VENDA DE PRODUTOS ----------\n\n");
                remove_item(&list);
                break;

            case '4':
                system("cls");
                printf(" _________________________________________\n");
                printf(" ------------ INSERIR PRODUTO ----------\n\n");
                insere_item(&list);
                mostre_lista_itens(&list);
                break;

            case '5':
                system("cls");
                printf("\n");

                    while(1) {
                        op3 = menu_estoque();
                        if(op3=='0')
                            break;
                        switch(op3){
                            case'1':
                                system("cls");
                                printf(" __________________________________________________________________\n");
                                printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ADICIONAR PRODUTO AO ESTOQUE %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                                insere_prod_compra(&list_compra, &list, list);
                                mostre_lista_itens(&list);
                                break;
                            case'2':
                                system("cls");
                                printf(" __________________________________________________________________\n");
                                printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c LISTA DE PRODUTOS COMPRADOS %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                                mostre_lis_compras(&list);
                                break;
                            case'3':
                                printf("\n\n __________________________________________________________________\n");
                                printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c CONTROLE DE VALIDADE DOS PRODUTOS %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                                system("cls");
                                qsort(list.itens, list.ni, sizeof(TItem), comp_cod);
                                mostre_lista_itens(&list);
                                break;
                            case '4':
                                printf("\n\n __________________________________________________________________\n");
                                printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c CONTROLE DE QUANTIDADE DOS PRODUTOS %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,224,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
                                system("cls");
                                op = '0';

                                mostra_prod_quant_baixa(&list);
                                break;
                            case '5':
                                printf("\n\n __________________________________________________________________\n");
                                printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c CONTROLE DE VENDAS ENTRE DATAS %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);

                                printf("%c DIGITE A PRIMEIRA DATA:\n%c",178,178);
                                dt1 =le_data();
                                printf("%c DIGITE A SEGUNDA DATA DATA:\n%c",178);
                                dt2 = le_data();
                                compras_entre_data(list_compra, dt1, dt2);
                                break;
                        }

                    }
           default:
               printf("\n Escolha uma das opc%ces do menu\n",135);
        }
        printf("\n\n");
    }
    file = fopen("estoque.arq","wb");
    fwrite(&list.ni, sizeof(unsigned), 1, file);
    fwrite(list.itens, sizeof(TListaProd), list.ni, file);
    fclose(file);
    return 0;
};
