#include <stdbool.h>/*cabecera boolean*/
#include <stdlib.h> /*gestión de memoria dinámica*/
typedef float Elemento;
typedef struct nodo{
	Elemento elemento;		
    struct nodo *siguiente;    
}Pila;

Pila *pila;

/*prototipos*/
void crearPilaVacia();
bool pilaVacia();
void apilar(Elemento pElem);
void desapilar();
float cima();
void visualizarElementos();
void desapilarTodo();
float sumaElementos();


/*implementaciones*/
void crearPilaVacia(){ pila = NULL;}
bool pilaVacia(){ return (pila==NULL);}
void apilar(Elemento pElem){
	Pila *aux = pila;
	pila = malloc(sizeof(Pila));
	pila->elemento = pElem;		
	pila->siguiente = aux;
	printf("Elemento insertado!\n");
}
void desapilar(){
	printf("\tDesapilando %.2f\n",cima());
	Pila *aux = pila;/*auxilar a la dirección actual para no perderla*/
	pila = pila->siguiente;/*posicionar el siguiente elmento en la posición actual*/
	free(aux); /*liberar memoria*/
}
float cima(){ return pila->elemento;}/*retornar elemento del tope de la pila*/
void visualizarElementos(){
	Pila *aux =  pila;/*auxiliar para no manipular el contenido original de la pila*/
	if (!pilaVacia()){
		printf("Elementos en pila: ");
		while(aux != NULL){
			printf("%.2f ", aux->elemento);
	    	aux = aux->siguiente;
		}
	}else{
		printf("Pila vacia\n");
	}
	printf("\n\n");
}
void desapilarTodo(){
	while(!pilaVacia()){
		desapilar();
	}
}
float sumaElementos(){
	float suma = 0;	
	Pila *aux =  pila;/*auxiliar para no manipular el contenido original de la pila*/
	if (!pilaVacia()){
		while(aux != NULL){
			suma+=aux->elemento;
	    	aux = aux->siguiente;
		}
	}else{
		printf("Pila vacia\n");
	}
	return suma;
}
