#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int tElem;

typedef struct nodo{
	tElem elem;		
    struct nodo *siguiente;    
}tLista;

tLista * lista;

void InicializarLista();
bool ListaVacia();
void InsertarPrimero(tElem pElem);
void InsertarAdelante(tElem pElem);
void InsertarElemento(tElem pElem);
void EliminarPrimero();
void VisualizarElementos();
void InsertarK(int k, tElem nuevoDato);
void EliminarK(int k);
void Menu();

void InicializarLista(){	
	lista = NULL;	
}

bool  ListaVacia(){return (lista == NULL);}

void InsertarPrimero(tElem pElem){
	lista = malloc(sizeof(tLista));/*solicitar memoria*/
	lista->elem = pElem;/*añadir elemento*/		
	lista->siguiente = NULL;	
	printf("Primer elemento insertado!\n");
}

void InsertarAdelante(tElem pElem){
	tLista *nuevoNodo= malloc(sizeof(tLista));/*auxiliar*/
	nuevoNodo->elem = pElem;/*añadir elemento*/		
	nuevoNodo->siguiente = lista;/*apuntar a la lista*/
	lista = nuevoNodo;/*cambio de apuntadores (no de contenido)*/		
	printf("Elemento insertado!\n");
}

void InsertarElemento(tElem pElem){
	if (lista == NULL)
		InsertarPrimero(pElem);
	else
		InsertarAdelante(pElem);
}

void EliminarPrimero(){
	tLista *aux = lista;
	lista = lista->siguiente;
	free(aux);/*liberar memoria*/ 
	printf("Primer elemento eliminado!\n");
}

void VisualizarElementos(){
	tLista *aux; /* lo usamos para recorrer la lista */		
	aux = lista;
	if (ListaVacia() == false){
		while(aux != NULL) {
			printf("%d ", aux->elem);
	    	aux = aux->siguiente;
		}
	 }else printf( "\nLa lista esta vacia!!\n" );
	printf("\n\n" );
}

void InsertarK(int k, tElem nuevoDato){
	tLista *nuevoNodo, *aux;/*auxiliares*/
	int i; 
	aux = lista;/*apuntador a lista*/ 
	for(i = 1; i < k-1; i++){aux = aux->siguiente;}	/*El bucle avanza aux hasta el nodo k-1*/
  	nuevoNodo = malloc(sizeof(tLista));/*socilitar memoria*/
	nuevoNodo->elem = nuevoDato; /*añadir elemento*/
	nuevoNodo->siguiente = aux->siguiente;/*apuntar a K*/
  	aux->siguiente = nuevoNodo;/*actualizar direcciones*/
}

void EliminarK(int k){
	tLista * nodoSuprimir, * aux;
	int i; 
	aux = lista; 
	for(i = 1; i < k-1; i++){aux = aux->siguiente;}	/*El bucle avanza aux hasta el nodo k-1*/
	nodoSuprimir = aux->siguiente; 
	aux->siguiente = nodoSuprimir->siguiente; 
	free(nodoSuprimir);  
	printf("Elemento de la posicion %d eliminado\n", k);	
}

int main() {	
	InicializarLista();	
	printf("Lista vacia? %s\n", ListaVacia() ? "si" : "no");	
	InsertarElemento(1);	
	printf("Lista vacia? %s\n", ListaVacia() ? "si" : "no");		
	InsertarElemento(2);	
	InsertarElemento(3);	
	VisualizarElementos();
	InsertarK(3, 5);
	VisualizarElementos();
	InsertarK(2, 10);
	VisualizarElementos();
	EliminarPrimero();
	VisualizarElementos();
	EliminarK(2);
	VisualizarElementos();

	return 0;
}



