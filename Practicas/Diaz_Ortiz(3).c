/******************************************************************************
Autor: Diaz Ortiz Brandon Aldair
2CV1 Práctica 3
*******************************************************************************/

# include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int nums_aleatorios(int num_aleatorios[],int cantidad)
{
    srand(time(NULL));
    int i;
    for( i = 0; i < cantidad; i++){
        num_aleatorios[i]=rand() % MAX;
    }
    return num_aleatorios;
}

int ordenamiento(int num_aleatorios[],int N){
    int num_aux,j,i;
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

int busquedaBinaria(int lista[], int x,int indiceIzquierdo,int indiceDerecho ){
    int ciclos=0,medio,encontrado= -1;
    while (indiceIzquierdo<= indiceDerecho){

        medio = (indiceIzquierdo+indiceDerecho)/2;
        if (x==lista[medio]){
            encontrado=medio;
            break;
        }
        else if (lista[medio]<x)
            indiceIzquierdo=medio + 1;

        else
            indiceDerecho=medio - 1;
    }
    return encontrado;
}

int main()
{
    int cantidad, num_abuscar;
    printf("¿Cuantos numeros aleaotorios quieres generar? ");
    scanf("%d",&cantidad);
    int numeros[cantidad];
    nums_aleatorios(numeros,cantidad);
    ordenamiento(numeros,cantidad);
    printf("¿Qué número deseas bucar? ");
    scanf("%d",&num_abuscar);
    busquedaBinaria(numeros,num_abuscar, 0,cantidad-1);

    return 0;
}
