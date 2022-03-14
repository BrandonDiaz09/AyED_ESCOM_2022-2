#include <stdio.h>

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
    int lista_ord[9] = {0,4,7,10,14,23,45,47,53};
    int resultado = busquedaBinaria(lista_ord, 47,0,8);
    printf("El elemento %d esta en la posicion %d \n",lista_ord[resultado],resultado);
    return 0;
}

        // ciclos++;
        // printf("%d\n",ciclos);		