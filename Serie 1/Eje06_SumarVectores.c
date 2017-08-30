/*
	Escribir una funci�n que permita cargar los elementos de un vector desde el teclado, 
	luego escribir una funci�n que permita sumar dos vectores A y B, recibidos como par�metro de entrada, 
	y devuelva el vector suma C, finalmente escribir una funci�n para mostrar los elementos de los vectores.
	 Hacer uso de �stas funciones invoc�ndolas desde la funci�n main (bloque principal). 
*/
#include <stdio.h>
#include <stdlib.h> /*gesti�n de memoria din�mica*/
void inicializarArray(int size,float *array);/*solicita carga por teclado*/
void imprimirArray(int size,float *array);
float* sumarArrays(int size,float *arrayA,float *arrayB);
int main(){
	int size;
	printf("Ingresar el tama�o para los arrays: ");
	scanf("%d",&size);
	/*declaraci�n de arrays*/
	float arrayA[size];
	float arrayB[size];
	
	/*inicializaci�n de arrays*/
	printf("Inicializar arrayA\n");
	inicializarArray(size,arrayA);
	printf("Inicializar arrayB\n");
	inicializarArray(size,arrayB);
	
	/*imprimir arrays*/
	printf("Imprimir arrayA\n");
	imprimirArray(size,arrayA);
	printf("Imprimir arrayB\n");
	imprimirArray(size,arrayB);
	
	/*sumar arrays*/
	float *arrayC = sumarArrays(size,arrayA,arrayB);
	printf("Imprimir arrayC\n");
	imprimirArray(size,arrayC);
	return 0;
}

void inicializarArray(int size,float *array){
	int indice;
	for(indice=0;indice<size;indice++){
		printf("\tIngresar valor para la posici�n %d: ",indice+1);
		scanf("%f",array+indice);
	}
}
void imprimirArray(int size,float *array){
	int indice;
	for(indice=0;indice<size;indice++){
		printf("\t%.2f\t",*(array+indice));
	}
	printf("\n");
}
float* sumarArrays(int size,float *arrayA,float *arrayB){
	/*https://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm*/
	/*static float arrayCC[size];/*Error: Storage size of array isn`t constant. Necesidad de utilizar malloc*/
	static float *arrayC; /*https://stackoverflow.com/questions/648533/how-to-declare-the-size-of-an-array-at-runtime-in-c*/
	arrayC = malloc(size * sizeof(*arrayC)); /*malloc -- Asigna la memoria solicitada y devuelve un puntero a ella*/
	int indice;
	for(indice=0;indice<size;indice++){
		*(arrayC+indice) = *(arrayA+indice) + *(arrayB+indice);
	}
	return arrayC;
}

