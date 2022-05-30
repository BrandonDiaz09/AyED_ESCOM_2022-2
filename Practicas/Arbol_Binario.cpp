//Diaz Ortiz Brandon Aldair
#include <iostream>
#include <math.h>
#define N 15
using namespace std;
struct nodo{
    int valor;
    nodo *apu_izq=NULL;
    nodo *apu_der=NULL;
};
typedef nodo *apu_nodo;

struct nodo_pila{
    int valor1;
    int valor2;
    nodo_pila *apu_ant=NULL;
};
typedef nodo_pila *apu_nodo_pila;

struct nodo_rec{
    nodo *apu_nodo=NULL;
    nodo_rec *apu_ant=NULL;
};
typedef nodo_rec *apu_nodo_rec;

apu_nodo raiz=NULL;
apu_nodo_pila tope=NULL;
apu_nodo_rec tope_rec=NULL;
apu_nodo_rec salida=NULL;
apu_nodo_rec entrada=NULL;
void agregar_pila( int valor_ini, int valor_fin){
    apu_nodo_pila actual,auxiliar;
    //Ingresar
	if(tope==NULL){
		actual = new(nodo_pila);
    	if (actual==NULL)
    	{
    		cout<<"Algo fallo";
    	} else {
    		actual->valor1=valor_ini;
    		actual->valor2=valor_fin;
            actual->apu_ant=NULL;
            tope=actual;
//            cout<<"("<<tope->valor1<<","<<tope->valor2<<")\t";
    	}
	}
	else{
		auxiliar = new(nodo_pila);
    	if (auxiliar==NULL)
    	{
    		cout<<"Algo fallo";
    	} 
        else {
    		auxiliar -> valor1=valor_ini;
    		auxiliar -> valor2=valor_fin;
    		auxiliar->apu_ant=tope;
            tope=auxiliar;
//            cout<<"("<<tope->valor1<<","<<tope->valor2<<")\t";
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
//Funcion para agregar un elemento a nuestra pila de recorrido
void agregar_pila_rec(apu_nodo nodo_arb){
    apu_nodo_rec actual;
    //Ingresar
	if(tope_rec==NULL){
		actual = new(nodo_rec);
    	if (actual==NULL)
    	{
    		cout<<"Algo fallo";
    	} else {
    		actual->apu_nodo=nodo_arb;
            actual->apu_ant=NULL;
            tope_rec=actual;
            //cout<<"("<<tope_rec->apu_nodo->valor<<")\t";
    	}
	}
	else{
		actual = new(nodo_rec);
    	if (actual==NULL)
    	{
    		cout<<"Algo fallo";
    	} 
        else {
    		actual -> apu_nodo=nodo_arb;
    		actual->apu_ant=tope_rec;
            tope_rec=actual;
            //cout<<"("<<tope_rec->apu_nodo->valor<<")\t";
    	}
	}
    
}
void eliminar_pila_rec(){
    //Borrar 
    if (tope_rec==NULL)
        cout<<"lista vacia";
    else{
    	apu_nodo_rec auxiliar=tope_rec->apu_ant;
        delete(tope_rec);
        tope_rec=auxiliar;
	}
}

void agregar_cola(apu_nodo nodo_arb){
	apu_nodo_rec actual;
    //Ingresar
	if(salida==NULL){
		actual = new(nodo_rec);
    	if (actual==NULL)
    	{
    		cout<<"Algo fallo";
    	} else {
    		actual->apu_nodo=nodo_arb;
            actual->apu_ant=NULL;
			salida=actual;
            entrada=actual;
            //cout<<"("<<tope_rec->apu_nodo->valor<<")\t";
    	}
	}
	else{
		actual = new(nodo_rec);
    	if (actual==NULL)
    	{
    		cout<<"Algo fallo";
    	} 
        else {
    		actual -> apu_nodo=nodo_arb;
			entrada->apu_ant=actual;
    		entrada=actual;
            //cout<<"("<<tope_rec->apu_nodo->valor<<")\t";
    	}
	}
}
void eliminar_cola(){
    //Borrar 
    if (salida==NULL)
        cout<<"lista vacia";
    else{
    	apu_nodo_rec auxiliar=salida->apu_ant;
        delete(salida);
        salida=auxiliar;
	}
}

int sacar_indice_valor(){   
    int indice,inicio,fin;
    indice=(tope->valor1+tope->valor2)/2;
    inicio=tope->valor1;
    fin=tope->valor2;
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
	if(raiz==NULL)
		raiz = nuevo;//Nodo raiz
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
void espaciado_fun(int espaciado){
	int j;
	for ( j = espaciado; j > 0; j--)
	{
			cout<<"   ";
	}
}

void imprimirArbol(){
	int i=0,contador=0,n=0,espacio[N];
	apu_nodo actual;
	while (n<N)
	{
		n=pow(2,contador)+n;
		contador++;
	}
	int imprimir[N];
	if (raiz!=NULL)
	{
		actual=raiz;
		agregar_cola(actual);
		//cout<<raiz->valor<<"\t";
		imprimir[i]=actual->valor;
		i++;
	}
	while (actual->apu_izq!=NULL || actual->apu_der!=NULL)
	{
		if (actual->apu_izq!=NULL)
			agregar_cola(actual->apu_izq);
		if (actual->apu_der!=NULL)
			agregar_cola(actual->apu_der);
		
		//cout<<actual->apu_izq->valor<<"\t";
		//cout<<actual->apu_der->valor<<"\t";
		if (actual->apu_izq->valor!=NULL)
		{
			imprimir[i]=actual->apu_izq->valor;
			i++;
		}
		if (actual->apu_der->valor!=NULL)
		{
			imprimir[i]=actual->apu_der->valor;
			i++;
		}
		eliminar_cola();
		actual=salida->apu_nodo;
	}
	while (n<N)
	{
		n=pow(2,contador)+n;
		contador++;
	}
	cout<<"\n";
	int k=0,j,cantidad=1;
	int espaciado=contador;
	for ( i = 0; i < contador; i++)
	{
		/*for ( j = espaciado; j > 0; j--)
		{
			cout<<"   ";
		}*/
		for ( j = 0; j < cantidad; j++)
		{
			espaciado_fun(n/2);
			cout<<imprimir[k]<<"\t";
			espaciado_fun(n/2);
			k++;
		}
		cout<<"\n";
		cantidad=2*cantidad;
		n=n-(pow(2,espaciado-1));
		espaciado--;
	}
	/*n=0;
	while (n<N)
	{
		for ( i = 0; i < pow(2,contador); i++)
		{
			espacio[(N-1)-n-i]=(pow(2,contador)+n)/2;
		}
		n=pow(2,contador)+n;
		contador++;
	}
	for ( i = 0; i < N; i++)
	{
		cout<<espacio[i]<<"\t";
	}*/
	
}

void listaArbol(int lista[]){
	int i=0;
	apu_nodo actual = raiz;
    while (actual != NULL || tope_rec!=NULL) {
        while (actual != NULL) {
            agregar_pila_rec(actual);
            actual = actual->apu_izq;
        }
		actual = tope_rec->apu_nodo;
		lista[i]=actual->valor;
		i++;
        eliminar_pila_rec();
        actual = actual->apu_der;
    }
}

int main()
{
    int lista[N]={1,2,4,5,6,8,10,11,12,14,15,16,18,20,21}, contador;
    int indice,i;
    agregar_pila(0,N-1);
    while (tope!=NULL)
    {
        indice=sacar_indice_valor();
        insertar_nodo(lista[indice]);
    }
    cout<<"\n";
    //mostrarArbol(raiz,contador=0);
	int listaRes[N];
	listaArbol(listaRes);
	cout<<"Arbol";
	imprimirArbol();
	cout<<"\nLista\n";
	for ( i = 0; i < N; i++)
		cout<<listaRes[i]<<"\t";
    
}
