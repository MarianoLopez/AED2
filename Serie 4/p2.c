#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tElem;

typedef struct nodo
{
	tElem elem;		
    struct nodo *siguiente;    
}tPila;

tPila * pila;

void InicializarPila();
bool PilaVacia();
void Apilar(tElem pElem);
void Desapilar();
void VisualizarElementos();
char Cima();

void InicializarPila()
{	
	pila = NULL;	
}

bool  PilaVacia()
{
	if (pila == NULL)
		return true;
	else
		return false;
	//return (lista == NULL);
}

void Apilar(tElem pElem)
{
	tPila * aux;
	aux = pila;
	pila = malloc(sizeof(tPila));	
	pila->elem = pElem;		
	pila->siguiente = aux;				
	printf("Elemento insertado!\n");		
}

void Desapilar()
{
	tPila * aux;
	aux = pila;
	pila = pila->siguiente;
	free(aux); 
	printf("Elemento de la cima eliminado!\n");
}

void VisualizarElementos()
{
	tPila *aux;		
	aux = pila;
	if (PilaVacia() == false)
	{
		printf( "\nElementos en la pila: \n" );
		while(aux != NULL) 
		{
			printf("%c \n", aux->elem);
	    	aux = aux->siguiente;
		}
	 }else printf( "\nLa pila esta vacia!!\n" );
	printf("\n\n" );
}

tElem Cima()
{
	return pila->elem;	
}

int main() 
{	
	InicializarPila();	
	printf("Pila vacia? %s\n", PilaVacia() ? "si" : "no");	
	Apilar('a');	
	printf("Pila vacia? %s\n", PilaVacia() ? "si" : "no");	
	Apilar('b');	
	Apilar('c');	
	VisualizarElementos();	
	Desapilar();
	VisualizarElementos();
	printf( "\nElemento en la cima: %c \n", Cima());
	return 0;
}



