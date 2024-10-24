#include "nascimento.h"
#include <time.h>
#include <stdio.h>

typedef struct{
    int mes;
    int dia;
    int ano;
} Atual;

int dias_de_vida(data_t nasc){
    Atual md;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    md.dia = tm.tm_mday;
    md.mes = tm.tm_mon + 1;
    md.ano = tm.tm_year + 1900;
    int diasmes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totDias;
    int i;
    if (nasc.dia == md.dia && nasc.mes == md.mes){
        totDias = (md.ano - nasc.ano) * 365;
    }
    else if (nasc.mes < md.mes || (nasc.mes == md.mes && nasc.dia < md.dia)){

        totDias = (md.ano - nasc.ano) * 365;

        for (i = nasc.mes - 1; i < md.mes - 1; i++){
            totDias += diasmes[i];
        }
        totDias-= nasc.dia;
        totDias += md.dia;
        
    }else{
        totDias = (md.ano - nasc.ano) - 1;
        totDias *= 365;
        for(i = 0; i < md.mes -1; i++){
            totDias += diasmes[i];
        }
        totDias+= md.dia;
    }

    return totDias;
}