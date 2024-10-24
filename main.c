#include <stdio.h>
#include "nascimento.h"

int main(){
    data_t info;
    printf("Qual o ano em que voce nasceu?");
    scanf("%d", &info.ano);
    printf("Qual o mes em que voce nasceu? [1-12]");
    scanf("%d", &info.mes);
    if(info.mes > 12){
        printf("Data invalida");
        return 3;
    }
    printf("Qual o dia em que voce nasceu?");
    scanf("%d", &info.dia);
    if(info.dia > 31){
        printf("Data invalida");
        return 3;
    }

    int diasvida = dias_de_vida(info);
    printf("Voce viveu %d\n", diasvida);

    return 0;
}