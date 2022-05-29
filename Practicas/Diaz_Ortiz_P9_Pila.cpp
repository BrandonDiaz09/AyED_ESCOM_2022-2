//Autor: Diaz Ortiz Brandon Aldair
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 11
#define TAM 100

#include <iostream>
using namespace std;
struct nodo{
    int valor;
    nodo *apu_ant;
};

typedef nodo *apu_nodo;

int main(){
     srand(time(NULL));
    apu_nodo actual,tope,auxiliar;
    actual = NULL, auxiliar=NULL,tope = NULL;
	int num_nodos,i,opcion,num_aleatorio;
    while (opcion!=4)
    {
        cout<<"\n Escriba el numero de la funcion desea realizar?\n 1. Ingresa elemento\n 2. Ver elemento \n 3. Eliminar elemento \n 4. Salir \n";
        cin>>opcion;
        switch(opcion) 
        {
            case 1: 
                num_aleatorio=rand() % MAX;
                //Ingresar
	            if(i==0){
	            	actual = new(nodo);
                	if (actual==NULL)
                	{
                		cout<<"Algo fallo";
                	} else {
                		actual->valor=num_aleatorio;

                        
                        actual->apu_ant=NULL;
                        i++;
                	}
	            }
	            else{
	            	auxiliar = new(nodo);
                	if (auxiliar==NULL)
                	{
                		cout<<"Algo fallo";
                	} 
                    else {
                		auxiliar -> valor=num_aleatorio;
                		auxiliar->apu_ant=tope;
                        tope=auxiliar;
                        i++;
                	}
	            }
            break;
            case 2: 
                //Ver
                if (tope ==NULL)
                {
                    cout<<"lista vacia";
                }
                else{
                    cout<<"El valor es: "<<tope->valor<<"\n";
                }
            break;
            case 3: 
                //Borrar 
                if (tope==NULL)
                    cout<<"lista vacia";
                else{
                	auxiliar=tope->apu_ant;
                    delete(tope);
                    tope=auxiliar;
                    i--;
	            }
            break;
        }
    }
    
    

    return 0;
}