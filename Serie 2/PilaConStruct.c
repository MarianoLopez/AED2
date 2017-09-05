#include <stdio.h>
#include "PilaFloat.h"

int main(){
	/*variables locales*/
	char opcion;
	float nro;
	
	Pila *pila = crearPilaVacia();
	printf("Desea ingresar datos? s/n [s]: ");
	scanf("%c", &opcion);
	while (opcion != 'n' && opcion != 'N'){		
		printf("\tIngrese un numero real: ");
		scanf("%f", &nro);
		fflush(stdin);
		apilar(pila,nro);
		printf("Desea ingresar datos? s/n [s]: ");
		scanf("%c", &opcion);
		fflush(stdin);
	}	
	printf("\nSuma de todos los numeros apilados: %.2f\n", sumaElementos(pila));		
	visualizarElementos(pila);
	printf("Desapilando....\n");
	desapilarTodo(pila);
	visualizarElementos(pila);
	return 0;
}
