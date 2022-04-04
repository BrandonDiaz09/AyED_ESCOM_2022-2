#include <iostream>
using namespace std;
struct nodo{
    int valor;
    nodo *apu_sig;
};
typedef nodo *apu_nodo;
int main(void)
{
    apu_nodo actual, auxiliar, inicial;
    actual = new(nodo);
    actual = NULL, auxiliar=NULL,inicial = NULL;
    if (actual==NULL)
    {
        cout<<"Algo fallo";
        cout<<"Debe indicarlo";

    }
    actual->valor =33;
    inicial = actual;

    auxiliar = new(nodo);
    if (actual==NULL)
    {
        cout<<"Algo fallo";
        cout<<"Debe indicarlo";

    }
    auxiliar -> valor=9;
    actual -> apu_sig=auxiliar;
    actual = auxiliar;
    auxiliar = new(nodo);
    auxiliar -> valor = 58;
    actual -> apu_sig=auxiliar;
    auxiliar -> apu_sig= NULL;
    actual = auxiliar;
    //Agregar al inicio
    auxiliar = new(nodo);
    auxiliar -> valor=333;
    auxiliar -> apu_sig = inicial;
    inicial= auxiliar;
    actual =auxiliar;
    //mostrar lista
    if (inicial ==NULL)
    {
        cout<<"lista vacia";
    }
    else {
        actual= inicial;{
            while (actual != NULL)
            {
                cout<<"El valor es :"<<actual-> valor;
                actual = actual->apu_sig;
            }
        }
    }
    //Borrar al incio
    auxiliar = inicial;
    inicial = inicial -> apu_sig;
    delete (auxiliar);
    if (inicial == NULL) actual = NULL;       
    return 0;
}
