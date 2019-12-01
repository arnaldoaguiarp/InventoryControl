#include<time.h>

struct data
{
    char dia;
    char mes;
    short ano;
};
typedef struct data TData;

void mostre_data(TData a)
{
    printf("%02d/%02d/%d", a.dia, a.mes, a.ano);
}

void mostre_data_ext(TData d)
{
    char nm[13][10] = {"","janeiro","fevereiro","mar\x87o",
                 "abril","maio","junho","julho","agosto",
                 "setembro","outubro","novembro","dezembro"};
    printf("%02d de %s de %d", d.dia, nm[(int)d.mes], d.ano);
}

int e_bissexto(int ano)
{
    return ano%4==0 && (ano%100 != 0 || ano%400 == 0);
}

TData passa_um_dia(TData d)
{
    int ndm[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(e_bissexto(d.ano))
        ndm[2] = 29;
    d.dia++;
    if(d.dia > ndm[(int)d.mes])
    {
        d.dia = 1;
        d.mes++;
        if(d.mes > 12)
        {
            d.mes = 1;
            d.ano++;
        }
    }
    return d;
}

void passa_um_dia_ref(TData *d)
{
    int ndm[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(e_bissexto(d->ano))
        ndm[2] = 29;
    d->dia++;
    if(d->dia > ndm[(int)d->mes])
    {
        d->dia = 1;
        d->mes++;
        if(d->mes > 12)
        {
            d->mes = 1;
            d->ano++;
        }
    }
}

int cmp_data(const void *a, const void *b)
{
    TData *da = (TData *) a;
    TData *db = (TData *) b;

    if(da->ano != db->ano)
        return da->ano - db->ano;
    else
        if(da->mes != db->mes)
            return da->mes - db->mes;
        else
            return da->dia - db->dia;
}

TData le_data()
{
    TData res;
    scanf("%c/%c/%hd", &res.dia, &res.mes, &res.ano);
    return res;
}

TData dat_sis()
{
    TData res;
    time_t tempo = time(NULL);
    struct tm data = *localtime(&tempo);
    res.dia = data.tm_mday;
    res.mes = data.tm_mon+1;
    res.ano = data.tm_year+1900;
    return res;
}

unsigned desde_1_1_1990(TData dat)
{
    int ndm[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(e_bissexto(dat.ano))
        ndm[2] = 29;
    unsigned res = 0;
    short ano = 1900;
    char mes = 1;
    while(ano < dat.ano)
    {
        if (e_bissexto(ano))
            res += 366;
        else
            res += 365;
        ano++;
    }
    while(mes < dat.mes)
    {
        res += ndm[(int) mes];
        mes++;
    }
    return res + dat.dia - 1;
}

int dia_semana(TData dat)
{
    return desde_1_1_1990(dat) % 7;
}

void dia_sem_ext(TData dat)
{
    char dse[7][16] = {"domingo","segunda-feira","ter\x87 \ba-feira","quarta-feira","quinta-feira","sexta-feira","s\xa0 \bbado"};
    printf("%s", dse[dia_semana(dat)]);
}

