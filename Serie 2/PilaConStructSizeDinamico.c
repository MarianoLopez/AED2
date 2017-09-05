#include <stdio.h>
#include "PilaFloatSizeDinamico.h"

int main(){
	printf("Pila 1\n");
	Pila *pila = crearPilaVacia(5);/*Pila 1 con longitud de 5*/
	apilar(pila,20.2);
	apilar(pila,3.1);
	apilar(pila,2.3);
	apilar(pila,4.4);
	apilar(pila,55.5);
	apilar(pila,9.10);/*pila llena*/
	printf("\nSuma de todos los numeros apilados: %.2f\n", sumaElementos(pila));
	visualizarElementos(pila);
	printf("\nPila 2\n");
	Pila *p = crearPilaVacia(2);/*Pila 2 con longitud de 2*/
	apilar(p,20);
	apilar(p,3.2);
	apilar(p,2);/*pila llena*/
	printf("\nSuma de todos los numeros apilados: %.2f\n", sumaElementos(p));
	visualizarElementos(p);
	return 0;
}
