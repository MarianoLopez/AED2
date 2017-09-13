#include <stdio.h>
#include "PilaFloat_v1.h"

int main(){
	/*variables locales*/
	char opcion;
	Elemento nro;
	
	crearPilaVacia();
	printf("Desea ingresar datos? s/n [s]: ");
	scanf("%c", &opcion);
	while (opcion != 'n' && opcion != 'N'){		
		printf("\tIngrese un numero real: ");
		scanf("%f", &nro);
		fflush(stdin);
		apilar(nro);
		printf("Desea ingresar datos? s/n [s]: ");
		scanf("%c", &opcion);
		fflush(stdin);
	}	
	printf("\nSuma de todos los numeros apilados: %.2f\n", sumaElementos());		
	visualizarElementos();
	printf("Desapilando....\n");
	desapilarTodo();
	visualizarElementos();
	return 0;
}
