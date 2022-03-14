/******************************************************************************
Autor: Diaz Ortiz Brandon Aldair
2CV1 Práctica 3
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int busquedaBinaria(int lista[], int x,int indiceIzquierdo,int indiceDerecho ){
    int medio,encontrado= -1;
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
    int cantidad,num_abuscar;
    char respuesta;
    printf("Cuantos numeros aleatorios quieres generar? ");
    scanf("%d",&cantidad);
    int num_aleatorios[cantidad],num_aux,i,j;
    srand(time(NULL));
    //Imprimir lista no ordenada
    fflush(stdin);
    printf("\nQuieres imprimir la lista de numeros aleatorios NO ORDENADOS? [S/N]\n");
    scanf(" %c", &respuesta);
    if (respuesta == 'S' || respuesta == 's')
    {
        printf("\nNumeros NO ordenados: \n");
        for (i=0; i < cantidad; i++){
            num_aleatorios[i]=rand()%MAX;
            printf("%d\t", num_aleatorios[i]);
        }
    }
    //Algoritmo de ordenamiento por burbuja   
    for (i=0; i<cantidad;i++){
        j=cantidad-1;
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
    //Imprimir datos ordenados
    fflush(stdin);
    printf("\n\nQuieres imprimir la lista de numeros aleatorios ORDENADOS? [S/N]\n");
    scanf(" %c", &respuesta);
    if (respuesta=='S' || respuesta =='s'){
        printf("\nNumeros ordenados:\n");
        for ( i = 0; i < cantidad; i++)
        {
            printf("%d\t", num_aleatorios[i]);
        }
    }

    //Llamada a algoritmo de busqueda binaria
    printf("\nQue numero deseas buscar? ");
    scanf("%d",&num_abuscar);

    int resultado = busquedaBinaria(num_aleatorios, num_abuscar,0,cantidad-1);
    //Validación se se encontró el numero a buscar
    if (resultado==-1)
        printf("\nEl elemento %d no se encontro en la lista", num_abuscar);
    else
        printf("\nEl elemento %d esta en la posicion %d de la lista ORDENADA \n",num_aleatorios[resultado],resultado);

    return 0;
}