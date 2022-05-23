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
//Creamos nuestra función teniendo como parametros el indice inicio, indice medio, indice fin y nuestro nodo padre
void crear_arbol(int inicio, int fin, int medio, apu_nodo padre, int lista[]){
    apu_nodo hijo_izq,hijo_der;
    if(inicio<=medio-1){
        hijo_izq = new(nodo);
        if (inicio==medio-1)
        {
            hijo_izq->valor=lista[inicio]; 
            cout<<hijo_izq->valor<<"\t";  
            padre->apu_izq=hijo_izq;
        }
        else
        {
            int indice = (inicio+medio-1)/2;
            hijo_izq->valor=lista[indice]; 
            cout<<hijo_izq->valor<<"\t";  
            padre->apu_izq=hijo_izq;
            crear_arbol(inicio, medio-1, indice, hijo_izq, lista);
        }
    }
    if(medio+1<=fin){
        hijo_der = new(nodo);
        if (medio+1==fin)
        {
            hijo_der->valor=lista[inicio]; 
            cout<<hijo_der->valor<<"\t";  
            padre->apu_der=hijo_der;
        }
        else
        {
            int indice = (medio+1+fin)/2;
            hijo_der->valor=lista[indice];   
            cout<<hijo_der->valor<<"\t";  
            padre->apu_der=hijo_der;
            crear_arbol(medio+1, fin, indice, hijo_der, lista);
        }
        
        
    }
}
int main()
{
    apu_nodo raiz, auxiliar, actual, padre;
    int inicio=0, fin=6, medio, lista[7]={1,2,5,12,14,17,20},aux_i,aux_f,contador;
    medio=(inicio+fin)/2;
    raiz= new(nodo);
    raiz->valor=lista[medio];
    auxiliar=raiz;
    crear_arbol(inicio,fin,medio,raiz,lista);
    
    

    return 0;
}
