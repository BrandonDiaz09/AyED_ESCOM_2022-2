//Autor: Diaz Ortiz Brandon Aldair
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **matriz,i,j, filas, columnas,valor,indice,datos;
    printf("Cuantos valores quieres ingresar: ");
    scanf("%d",&filas);
    matriz = (int **)calloc(filas,sizeof(int *));
    
    
    for (i=0;i<filas;i++){
        printf("Introduzca el valor %d:", i+1);
        scanf("%d",&valor);
        indice=valor%filas;
        if (matriz[indice]==NULL)
        {
            matriz[indice] = (int *) malloc (2*sizeof(int));
            matriz[indice][0]=1;
            //En esta nueva casilla guerdamos el numero de valores que tiene la fila
            matriz[indice][1]=valor;
        }
        else
        {
            datos=matriz[indice][0];
            matriz[indice]=(int *) realloc (matriz[indice],(datos+1)*sizeof(int));
            matriz[indice][0]++;
            matriz[indice][datos+1]=valor;
        }   
    }
    //Imprimir datos
    for ( i = 0; i < filas; i++)
    {
        printf("\n");
        if (matriz[i]!=NULL)
        {
            for ( j = 1; j <= matriz[i][0]; j++)
            {
                printf("%d \t",matriz[i][j]);
            }
        } 
        
    }
    for ( i = 0; i < filas; i++)
        free(matriz[i]);
    free(matriz);
    return 0;
}
