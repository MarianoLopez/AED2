/*
	Realizar un programa en C que permita grabar un archivo de datos (binario) con los siguientes campos: 
		N�mero de Cuenta, Documento, Importe, C�digo de movimiento.
		El c�digo de movimiento vale 1.Dep�sito 2.Extracci�n
*/
#include <stdio.h>
#include "Movimiento.h"/*archivo cabecera propio*/
#define ARRAY_SIZE 4
Movimiento* datosDeEjemplo();/*prototipo*/
void grabarMovimientos(FILE *fichero);
int main(){
	FILE *fichero = fopen("Movimientos.dat", "wb");/* crea/abre archivo binario para escritura*/
	grabarMovimientos(fichero);
	fclose(fichero);
	return 0;
}
void grabarMovimientos(FILE *fichero){
	Movimiento *movimientos = datosDeEjemplo();
	printf("Escribiendo.....\n");
	int i;
	for(i=0;i<ARRAY_SIZE;i++){
		imprimirMovimiento(movimientos+i); /*ver Movimiento.h*/
		/*fwrite (puntero, longitud, numelem, fich);
		D�nde:
			puntero es un puntero a la zona de memoria donde se va a iniciar la transferencia.
			longitud es el tama�o N en bytes de cada elemento a transferir.
			numelem es el n�mero k de elementos a transferir
			fich es el puntero al archivo que se utiliza para la transferencia.
		Para transferir registros de un archivo, la longitud se determina aplicando el operador sizeof a la estructura 
		que devuelve el n�mero de bytes que la compone, y en numelem el valor 1 dado que se desea transferir una estructura*/
		fwrite((movimientos+i), sizeof(Movimiento), 1, fichero);/* graba el registro (del tipo Movimiento) en el archivo indicado */
	}
}
Movimiento* datosDeEjemplo(){
	static Movimiento movimientos[ARRAY_SIZE] = {
		{445,36194445,10500.00,1},
		{445,36194445,2000.50,2},
		{445,36194445,2000.50,2},
		{445,36194445,5000,2}
	};
	return movimientos;
}
