/* Autor: Diaz Ortiz Brandon Aldair*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int main()
{
    srand(time(NULL));
    int i=0,j=0,k=0,cantidad1,cantidad2,num_aux,cantidadRes;
    
    printf("Cuantos numeros aleatorios quieres generar para el arreglo 1? ");
    scanf("%d",&cantidad1);
    int arreglo1[cantidad1];
    
    printf("\n Arreglo 1: ");
    for (i=0; i < cantidad1; i++){
            arreglo1[i]=rand()%MAX;
            printf("%d\t", arreglo1[i]);
        }
        
    printf("\nCuantos numeros aleatorios quieres generar para el arreglo 2? ");
    scanf("%d",&cantidad2);
    int arreglo2[cantidad2];
    printf("\n Arreglo 2: ");
    for (i=0; i < cantidad2; i++){
            arreglo2[i]=rand()%MAX;
            printf("%d\t", arreglo2[i]);
        }

    //Algoritmo de ordenamiento por burbuja para primer arreglo
    for (i=0; i<cantidad1;i++){
        j=cantidad1-1;
        do {
            if (arreglo1[j]<arreglo1[j-1])
            {
                num_aux=arreglo1[j];
                arreglo1[j]=arreglo1[j-1];
                arreglo1[j-1]=num_aux;
            }
            j--;
        } while(j>=0);
    }
    //Imprimir datos ordenados de primer arreglo
    printf("\n\nArreglo 1 ordenado:");
    for ( i = 0; i < cantidad1; i++)
    {
        printf("%d\t", arreglo1[i]);
    }
    
    //Algoritmo de ordenamiento por burbuja para segundo arreglo   
    for (i=0; i<cantidad2;i++){
        j=cantidad2-1;
        do {
            if (arreglo2[j]<arreglo2[j-1])
            {
                num_aux=arreglo2[j];
                arreglo2[j]=arreglo2[j-1];
                arreglo2[j-1]=num_aux;
            }
            j--;
        } while(j>=0);
    }
    //Imprimir datos ordenados de segundo arreglo
    printf("\nArreglo 2 ordenado: ");
    for ( i = 0; i < cantidad2; i++)
    {
        printf("%d\t", arreglo2[i]);
    }
    
    //Algoritmo de mezcla
    i=0,j=0,k=0;
    cantidadRes=cantidad1+cantidad2;
    int arregloRes[cantidadRes];
    
    while (i<cantidad1 && j<cantidad2)
    {
        if (arreglo1[i]<=arreglo2[j]){
            arregloRes[k]=arreglo1[i];
            k++; 
            i++;
        }
        else{
            arregloRes[k]=arreglo2[j];
            k++;
            j++;
        }
    }
    while (i<cantidad1)
    {
        arregloRes[k]=arreglo1[i];
        k++;
        i++;
    }
    while (j<cantidad2)
    {
        arregloRes[k]=arreglo2[j];
        k++;
        j++;
    }
    printf("\n\nArreglo Final Ordenado\n");
    for ( i = 0; i < cantidadRes; i++)
    {
        printf("%d\t",arregloRes[i]);
    }
    
    return 0;
}
