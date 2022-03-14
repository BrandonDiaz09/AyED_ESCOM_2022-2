/******************************************************************************
Autor: Diaz Ortiz Brandon Aldair
2CV1 Práctica 1
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 11
#define TAM 100

int main()
{
    int cantidad,num_aleatorio,i;
    srand(time(NULL));
    printf("¿Cuantos numeros aleaotorios quieres generar? ");
    scanf("%d",&cantidad);
    for( i = 0; i < cantidad; i++){
        num_aleatorio=rand() % MAX+50;
        if ((num_aleatorio%2)==0) {
            printf("%d\t", num_aleatorio);
        }
        else 
            i--;
    }

    exit(EXIT_SUCCESS);
}
