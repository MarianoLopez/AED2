#include <stdio.h>
#include "ColaStringSizeDinamico.h"

int main(){
	Cola *cola = crearColaVacia(2);
	printf("Disponibilidad: %d\n",diponibilidad(cola));
	agregar(cola,"Mariano");
	agregar(cola,"Emanuel");
	agregar(cola,"Alejandro");
	imprimirCola(cola);
	printf("Disponibilidad: %d\n",diponibilidad(cola));
	quitarTodo(cola);
	imprimirCola(cola);
	printf("Disponibilidad: %d\n",diponibilidad(cola));
	agregar(cola,"Perez");
	imprimirCola(cola);
	return 0;
}
