#include <stdbool.h>/*cabecera boolean*/
#include <stdlib.h> /*gestión de memoria dinámica*/
#define max 10
typedef float Arreglo [max];
struct pila{
	Arreglo arreglo;
	int tope;
};
typedef struct pila Pila;

/*prototipos*/
Pila *crearPilaVacia();
bool pilaVacia(Pila *); 
bool pilaLlena(Pila *);
void apilar(Pila *,float);
void desapilar(Pila *);
float cima(Pila *);
void visualizarElementos(Pila *);
void desapilarTodo(Pila *);
float sumaElementos(Pila *);

/*implementaciones*/
Pila *crearPilaVacia(){
	static Pila *pila;
	pila = malloc(sizeof(*pila));
	(*pila).tope = -1;
	return pila;
}
bool pilaVacia(Pila *pila){ return (pila->tope==-1);}
bool pilaLlena(Pila *pila){return (pila->tope == (max-1));}
void apilar(Pila *pila,float elemento){
	if (!pilaLlena(pila)){/*Si la pila NO esta llena*/
		pila->tope += 1;/*incrementar tope en 1*/
		pila->arreglo[pila->tope] = elemento; /*asignar el nuevo elemento en la posición nueva del tope}*/	
	}else{
		printf("\tPila Llena!\n");
	}
	printf("\tCima actual: %.2f\n",cima(pila));
}
void desapilar(Pila *pila){
	if (!pilaVacia(pila)){/*Si la pila NO esta vacía*/
		printf("\tDesapilando %.2f\n",pila->arreglo[pila->tope]);
		pila->arreglo[pila->tope] = 0;/*asignar valor neutro en la posición actual*/
		pila->tope-= 1;/*decrementar tope en 1*/
	}else{
		printf("\tPila Vacia!!!\n");
	}
}
float cima(Pila *pila){ return pila->arreglo[pila->tope];}/*retornar elemento del tope de la pila*/
void visualizarElementos(Pila *pila){
	if(!pilaVacia(pila)){
		int i;
		printf("Elementos en pila: ");
		for (i = pila->tope; i >= 0; i--){/*LIFO*/
			printf("%.2f ", pila->arreglo[i]);
		}
		printf("\n\n");		
	}else{
		printf("Pila vacia\n");
	}
}
void desapilarTodo(Pila *pila){
	while(!pilaVacia(pila)){
		desapilar(pila);
	}
}
float sumaElementos(Pila *pila){
	int i;
	float suma = 0;	
	for (i = 0; i <= pila->tope; i++){
		suma += pila->arreglo[i];
	}
	return suma;
}

