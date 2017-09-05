#include <stdbool.h>
#include <string.h>
#include <stdlib.h> /*gestión de memoria dinámica*/
typedef char String[50];

typedef struct cola{
	String *arreglo;
	int frente;
	int final;
	int max;
}Cola;

/*prototipos*/
Cola *crearColaVacia(int size);
bool colaVacia(Cola *); 
bool colaLlena(Cola *);
void agregar(Cola *,String);
void quitar(Cola *);
void quitarTodo(Cola *);
void imprimirCola(Cola *);
int diponibilidad(Cola *);


Cola *crearColaVacia(int size){
	static Cola *cola;
	cola = malloc(sizeof(*cola));
	(*cola).frente = -1;/*equivalente a pila->tope =-1*/
	(*cola).final = -1;
	(*cola).max = size;
	cola->arreglo = malloc(size * sizeof(cola->arreglo));/*solicitar memoria para el arreglo*/
	return cola;
}
bool colaVacia(Cola *cola){return((cola->frente == -1) && (cola->final == -1));}
bool colaLlena(Cola *cola){return (cola->final == (cola->max-1));}

void agregar(Cola *cola,String elemento){
	if (!colaLlena(cola)){/*verificar que haya lugar*/
		cola->final += 1;/*incrementar final en 1*/
		strcpy(cola->arreglo[cola->final], elemento);/*copiar pElemento a cola[final]*/
		printf("\t%s agregado! ", cola->arreglo[cola->final]);
		/*significa que es el primer elemento*/
		if (cola->final == 0 ){cola->frente = 0;}
		printf("(Frente: %d - Final: %d)\n",cola->frente,cola->final);
	}else{
		printf("\tNo se pudo agregar: %s, cola llena!\n",elemento);
	}
	printf("Disponibilidad: %d\n",diponibilidad(cola));
}

void quitar(Cola *cola){
	if (!colaVacia(cola)){/*verificar que no este vacía*/
		printf("Quitando %s \n",cola->arreglo[cola->frente]);	
		strcpy(cola->arreglo[cola->frente], "");/*poner en cero o vacio el elemento del frente*/	
		/*si frente y final son iguales significa que elimine el ultimo*/
		if (cola->frente == cola->final){
			cola->frente = -1;
			cola->final = -1;
		}else{
			cola->frente += 1;					
		}
	}else{
		printf("No hay elementos para quitar!\n");
	}
}
void quitarTodo(Cola *cola){
	while(!colaVacia(cola)){quitar(cola);}
}

int diponibilidad(Cola *cola){
	return colaLlena(cola)? 0 : cola->max-1-cola->final;
}

void imprimirCola(Cola *cola){
	printf("\nCola:\n");
	if(!colaVacia(cola)){
		printf("\t");
		int i;
		for (i = cola->frente; i <= cola->final; i++){printf("%s ", cola->arreglo[i]);}
		printf("\n\n");		
	}else{
		printf("\tCola vacia\n");
	}
}
