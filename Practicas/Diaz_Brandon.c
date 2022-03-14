/******************************************************************************
Autor: Diaz Ortiz Brandon Aldair
2CV1 Práctica 2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define MAX 100

int main()
{
    int num_aleatorios[N],num_aux,i,j;

    srand(time(NULL));
    printf("Numeros NO ordenados\n");
    for (i=0; i < N; i++){
        num_aleatorios[i]=rand()%MAX;
        printf("%d\t", num_aleatorios[i]);
    }

   
    for (i=0; i<N;i++){
        j=N-1;
        do {
            if (num_aleatorios[j]<num_aleatorios[j-1])
            {
                num_aux=num_aleatorios[j];
                num_aleatorios[j]=num_aleatorios[j-1];
                num_aleatorios[j-1]=num_aux;
            }
            j--;
        } while(j>=0);
        
        
    }

    printf("\nNumeros ordenados:\n");
    for ( i = 0; i < N; i++)
    {
        printf("%d\t", num_aleatorios[i]);
    }
    return 0;
}