/* Autor: Diaz Oritz Brandon Aldair*/
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i=0,j=0,k=0,arreglo1[4]= {2,4,6,7},arreglo2[6]= {1,3,5,8,9,10},arregloRes[10];

    while (i<4 && j<6)
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
    while (i<4)
    {
        arregloRes[k]=arreglo1[i];
        k++;
        i++;
    }
    while (j<6)
    {
        arregloRes[k]=arreglo2[j];
        k++;
        j++;
    }
    for ( i = 0; i < 10; i++)
    {
    printf("%d\t",arregloRes[i]);
    }
    
    return 0;
}
