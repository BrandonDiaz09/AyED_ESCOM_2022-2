//Diaz Ortiz Brandon Aldair
#include <iostream>
using namespace std;
struct nodo{
    int valor;
    nodo *apu_sig;
};

typedef nodo *apu_nodo;

int main(){
    //Primer nodo
    apu_nodo actual,inicial,auxiliar;
    actual = NULL, auxiliar=NULL,inicial = NULL;
    actual = new(nodo);
    if (actual==NULL)
    {
        cout<<"Algo fallo";

    } else {
        actual->valor=10;
        inicial = actual;

    }
    //Segundo nodo
    auxiliar = new(nodo);
    if (auxiliar==NULL)
    {
        cout<<"Algo fallo";
        cout<<"Debe indicarlo";

    } else {
        auxiliar -> valor=20;
        actual -> apu_sig=auxiliar;
        auxiliar->apu_sig=NULL;
        actual = auxiliar;
    }
    //Mostrar lista
    if (inicial ==NULL)
    {
        cout<<"lista vacia";
    }
    else{
        actual= inicial;
        while (actual != NULL)
        {
            cout<<"El valor es :"<<actual->valor<<"\n";
            actual = actual->apu_sig;
        }
    }
    return 0;
}
