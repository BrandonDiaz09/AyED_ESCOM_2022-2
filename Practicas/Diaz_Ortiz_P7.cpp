//Diaz Ortiz Brandon Aldair
#include <iostream>
using namespace std;
struct nodo{
    int valor;
    nodo *apu_sig;
};

typedef nodo *apu_nodo;

int main(){
	apu_nodo actual,inicial,auxiliar;
    actual = NULL, auxiliar=NULL,inicial = NULL;
	int num_nodos,i;
	cout<<"Cuantos nodos quieres crear? ";
	cin>>num_nodos;
	//Crear nodos
	for(i=0;i<num_nodos; i++){
		if(i==0){
			actual = new(nodo);
    		if (actual==NULL)
    		{
        		cout<<"Algo fallo";

    		} else {
        		actual->valor=i+1;
        		inicial = actual;
    		}
		}
		else{
			auxiliar = new(nodo);
    		if (auxiliar==NULL)
    		{
        		cout<<"Algo fallo";
    		} else {
        		auxiliar -> valor=i+1;
        		actual -> apu_sig=auxiliar;
        		auxiliar->apu_sig=NULL;
        		actual = auxiliar;
    		}
		}
	}
    //Mostrar valores de nodos
    i=0;
    if (inicial ==NULL)
    {
        cout<<"lista vacia";
    }
    else{
        actual= inicial;
        while (actual != NULL)
        {
            cout<<"El valor es: "<<actual->valor<<"\n";
            actual = actual->apu_sig;
        }
    }
    cout<<"\n Ahora vamos a borrar el ultimo nodo e imprimir nuevamente los datos.\n";
    //Borrar el ultimo nodo;
    if (inicial==NULL)cout<<"lista vacia";
    else{
    	auxiliar=inicial;
    	actual=inicial;
    	while(auxiliar->apu_sig!=NULL){
    		actual=auxiliar;
    		auxiliar=auxiliar->apu_sig;
		}
		actual->apu_sig=NULL;
		delete(auxiliar);
	}
	//Mostrar valores de nodos
    i=0;
    if (inicial ==NULL)
    {
        cout<<"lista vacia";
    }
    else{
        actual= inicial;
        while (actual != NULL)
        {
            cout<<"El valor es: "<<actual->valor<<"\n";
            actual = actual->apu_sig;
        }
    }
    return 0;
}
