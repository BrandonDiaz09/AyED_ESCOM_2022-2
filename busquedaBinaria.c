#include <stdio.h>>

int main()
{
    int dato,inicio,fin,medio,pasos=0, lista_ord[8]= {2,4,5,6,9,15,18,20};

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &dato);
    inicio=0;
    fin=8-1;
    do
    {
        medio=(inicio+fin)/2;
        if (lista_ord[medio]<=dato)
            inicio=medio+1;
        else 
            fin=medio-1;
        pasos++;
        
    } while (inicio<=fin);
    printf("El elemento %d esta en %d y se econtro en %d pasos\n",lista_ord[medio],medio,pasos);
    return 0;
}
