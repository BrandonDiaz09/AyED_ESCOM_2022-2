//Diaz Ortiz Brandon Aldair
#include <iostream>
using namespace std;
struct nodo{
    int valor;
    nodo *apu_izq;
    nodo *apu_der;
};
typedef nodo *apu_nodo;
#define N=7;
int main()
{
    apu_nodo raiz, auxiliar, actual, padre;
    int inicio, fin, medio, lista[N]={1,2,5,12,14,17,20},aux_i,aux_f,contador;
    medio=(incio+fin)/2;
    raiz= new(nodo);
    raiz->valor=lista[medio];
    auxiliar=raiz;

    while (contador<N)
    {
        while (inicio<=fin)
        {
        aux_i=incio;
        aux_f=medio-1;
        medio=(inicio+fin)/2;
        actual=new(nodo);
        auxiliar-->apu_izq=actual;
        actual-->valor=lista[medio];
        contador++;}
        padre=auxiliar;
        actual-->apu_izq=NULL;
        actual-->apu_der=NULL;
        auxiliar=actual;
        }
    }
    
    
    

    return 0;
}
