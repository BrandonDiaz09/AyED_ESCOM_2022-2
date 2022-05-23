//Diaz Ortiz Brandon Aldair
#include <iostream>
#define N 7
using namespace std;
struct nodo{
    int valor;
    int indice;
    nodo *apu_izq=NULL;
    nodo *apu_der=NULL;
};
typedef nodo *apu_nodo;
apu_nodo raiz=NULL;
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
bool busqueda(apu_nodo padre,int x){
	if(padre==NULL)//si el arbol esta vacio
		return false;
	else{
		while(padre!=NULL && x!=padre->valor){
			if(x<padre->valor)
				raiz=padre->apu_izq;
			else
				raiz=padre->apu_der;
		}
		if(raiz!=NULL)
			return true;
		else
			return false;
	}
}
void insertar_nodo(int x){
	apu_nodo nuevo = new(nodo);
	nuevo->valor=x;
	nuevo->apu_der=NULL;
	nuevo->apu_izq=NULL;
	if(raiz==NULL){
		raiz = nuevo;//Nodo raiz
	}
	else{
		if(busqueda(raiz,x)==false){
			apu_nodo anterior, reco;
			anterior=NULL;
			reco=raiz; 
			while(reco!=NULL){
				anterior = reco;
				if(x<reco->valor)
					reco = reco->apu_izq;
				else
					reco = reco->apu_der;
			}
			if(x<anterior->valor)
				anterior->apu_izq=nuevo;
			else
				anterior->apu_der=nuevo;
		}
		else
			printf("\nEl Dato ingresado ya existe");
	}
}

void imprimir_arbol(apu_nodo padre, int contador){
	if(padre == NULL){
		return;
	}
	else{
		imprimir_arbol(padre->apu_der,contador+1);
		int i;
		for(i=0;i<contador;i++){
			printf("   ");
		}
		printf("%d\n",padre->valor);
		imprimir_arbol(padre->apu_izq,contador+1);
	}
}
int main()
{
    apu_nodo auxiliar, actual, padre;
    //int inicio=0, fin=6, medio, lista[7]={1,2,5,12,14,17,20},aux_i,aux_f,contador,indice;
    int lista_bin[N]={12,2,17,1,5,14,20};
    /*medio=(inicio+fin)/2;
    raiz= new(nodo);
    raiz->valor=lista[medio];
    raiz->indice=medio;
    actual=raiz;*/

    
    int i=0;
    for ( i = 0; i < N; i++)
    {
        insertar_nodo(lista_bin[i]);
    }
    int contador=0;
    imprimir_arbol(raiz, contador);
    
    
    
    

    return 0;
}