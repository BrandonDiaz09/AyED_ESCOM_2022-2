#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 265000
#define MAX 1000000

int main(){
    int num_aleatorios[N],num_aux,i,j;
    clock_t inicio, fin;
    srand(time(NULL));
    for (i=0; i < N; i++){
        num_aleatorios[i]=rand()%MAX;
    }
    inicio = clock();
    // for (i=0; i<N;i++){
    //     for ( j = 0; j < (N-1); j++)
    //     {
    //         if (num_aleatorios[j]>num_aleatorios[j+1])
    //         {
    //             num_aux=num_aleatorios[j];
    //             num_aleatorios[j]=num_aleatorios[j+1];
    //             num_aleatorios[j+1]=num_aux;
    //         }
            
    //     }
        
    // }
    for (i=0; i<N-1;i++){
        if (num_aleatorios[i]>num_aleatorios[i+1])
        {
            for ( j = i; j >=0; j--)
            {
                if (num_aleatorios[j]>num_aleatorios[j+1])
                {
                    num_aux=num_aleatorios[j];
                    num_aleatorios[j]=num_aleatorios[j+1];
                    num_aleatorios[j+1]=num_aux;
                }
                
            }
        }
    }
    fin = clock();
    double tiempo =((double)(fin-inicio))/CLOCKS_PER_SEC;
    // for ( i = 0; i < N; i++)
    // {
    //     printf("%d\t", num_aleatorios[i]);
    // }
    printf("\n%f",tiempo);
}