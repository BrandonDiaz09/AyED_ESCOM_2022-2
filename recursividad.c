#include <stdio.h>
int funcion1(int a,int resultado){
    if (a>0)
    {
        resultado=a*(funcion1(a-1);)
        
        printf("\nVuelta %d",a);
    }
    return resultado;
}
int main()
{
    int a=0,resultado=0;
    printf("Dame un numero: ");
    scanf("%d",&a); 
    a=funcion1(a,resultado);
    printf("%d",&a);
    return 0;
}
