//Diaz Ortiz Brandon Aldair
#include <iostream>
#define N 16
using namespace std;
struct nodo{
    int valor;
    int indice;
    nodo *apu_izq=NULL;
    nodo *apu_der=NULL;
};
typedef nodo *apu_nodo;

struct nodo_pila{
    int ind_ini;
    int ind_fin;
    nodo_pila *apu_ant=NULL;
};
typedef nodo_pila *apu_nodo_pila;

apu_nodo raiz=NULL;
apu_nodo_pila tope=NULL;
void agregar_pila( int valor_ini, int valor_fin){
    apu_nodo_pila actual,auxiliar;
    //Ingresar
	if(tope==NULL){
		actual = new(nodo_pila);
    	if (actual==NULL)
    	{
    		cout<<"Algo fallo";
    	} else {
    		actual->ind_ini=valor_ini;
    		actual->ind_fin=valor_fin;
            actual->apu_ant=NULL;
            tope=actual;
            cout<<"("<<tope->ind_ini<<","<<tope->ind_fin<<")\t";
    	}
	}
	else{
		auxiliar = new(nodo_pila);
    	if (auxiliar==NULL)
    	{
    		cout<<"Algo fallo";
    	} 
        else {
    		auxiliar -> ind_ini=valor_ini;
    		auxiliar -> ind_fin=valor_fin;
    		auxiliar->apu_ant=tope;
            tope=auxiliar;
            cout<<"("<<tope->ind_ini<<","<<tope->ind_fin<<")\t";
    	}
	}
    
}
void eliminar_pila(){
    //Borrar 
    if (tope==NULL)
        cout<<"lista vacia";
    else{
    	apu_nodo_pila auxiliar=tope->apu_ant;
        delete(tope);
        tope=auxiliar;
	}
}
int sacar_indice_valor(){   
    int indice,inicio,fin;
    indice=(tope->ind_ini+tope->ind_fin)/2;
    inicio=tope->ind_ini;
    fin=tope->ind_fin;
    eliminar_pila();
    if ((indice+1)<=fin )
        agregar_pila(indice+1,fin);
    if (inicio<=(indice-1) )
        agregar_pila(inicio,indice-1 );
    return indice;
}
bool busqueda(apu_nodo padre,int x){
	if(padre==NULL)//si el arbol esta vacio
		return false;
	else{
		while(padre!=NULL && x!=padre->valor){
			if(x<padre->valor)
				padre=padre->apu_izq;
			else
				padre=padre->apu_der;
		}
		if(padre!=NULL)
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
        cout<<raiz->valor<<"\t";
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
			if(x<anterior->valor){
				anterior->apu_izq=nuevo;
                cout<<anterior->apu_izq->valor<<"\t";}
			else{
				anterior->apu_der=nuevo;
                cout<<anterior->apu_der->valor<<"\t";}
		}
		else
			printf("\nEl Dato ingresado ya existe");
	}
}
void mostrarArbol(apu_nodo arbol, int cont){//contador ayuda a separar un nodo del otro
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->apu_der,cont+1);
		int i;
		for(i=0;i<cont;i++){
			printf("   ");
		}
		printf("%d\n",arbol->valor);
		mostrarArbol(arbol->apu_izq,cont+1);
	}
}
int main()
{
    int lista[N]={1,2,4,5,6,8,10,11,12,14,15,16,18,20,21,22}, contador;
    int indice;
    agregar_pila(0,N-1);
    while (tope!=NULL)
    {
        indice=sacar_indice_valor();
        cout<<"\tinidice:"<<indice<<"\t";
        insertar_nodo(lista[indice]);
        //cout<<contador<<"\t";
    }
    cout<<"\n";
    mostrarArbol(raiz,contador=0);
    
}
