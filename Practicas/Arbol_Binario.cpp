//Diaz Ortiz Brandon Aldair
#include <iostream>
using namespace std;
struct nodo{
    int valor;
    int indice;
    nodo *apu_izq=NULL;
    nodo *apu_der=NULL;
};
typedef nodo *apu_nodo;
void crear_nodo(apu_nodo padre, int valor, int indice){
        apu_nodo auxiliar = new(nodo);
        auxiliar->valor=valor;
        auxiliar->indice=indice;
        if(valor<padre->valor){
            padre->apu_izq=auxiliar;
        }
        else
        {
            padre->apu_der=auxiliar;
        }
        

}
int main()
{
    apu_nodo raiz, auxiliar, actual, padre;
    int inicio=0, fin=6, medio, lista[7]={1,2,5,12,14,17,20},aux_i,aux_f,contador,indice;
    medio=(inicio+fin)/2;
    raiz= new(nodo);
    raiz->valor=lista[medio];
    raiz->indice=medio;
    actual=raiz;
    if (inicio<=medio-1)
    {
        auxiliar=new(nodo);
        indice = (inicio+medio-1)/2;
        auxiliar->valor=lista[indice];
        auxiliar->indice=indice;
    }
    if (medio+1<=fin)
    {
        auxiliar=new(nodo);
        indice = (inicio+medio-1)/2;
        auxiliar->valor=lista[indice];
        auxiliar->indice=indice;
    }
    
    while (contador<7)
    {
        actual->indice
        auxiliar=new(nodo);
        actual->apu_izq=auxiliar
    }
    
    
    

    return 0;
}
