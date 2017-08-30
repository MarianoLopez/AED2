/*
	 Realizar un programa en C que permita leer el archivo generado en el punto anterior y 
	 emita un informe de todas las cuentas. 
	 Obtener e informar al final los totales de importe de depósito y extracción. 
*/
#include <stdio.h>
#include "Movimiento.h"
void leerMovimientos(FILE *fichero);
int main(){
	FILE *fichero = fopen("Movimientos.dat", "rb");/*puntero del tipo FILE, modo lectura*/
	if(fichero != NULL){/*verificar que exista el archivo Movimientos.dat. NULL es valor especial aplicado a un puntero (o referencia) usado para indicar que no se apunta a un objeto o dato válidos*/
		printf("Leyendo....\n");
		leerMovimientos(fichero);
	}
	fclose(fichero);
	return 0;
}
void leerMovimientos(FILE *fichero){
	Movimiento movimiento;
	float depositos = 0;
	float extracciones = 0;
	/*fread (puntero, longitud, numelem, fich);
		Dónde:
			puntero es un puntero a la zona de memoria donde se va a iniciar la transferencia.
			longitud es el tamaño N en bytes de cada elemento a transferir.
			numelem es el número k de elementos a transferir
			fich es el puntero al archivo que se utiliza para la transferencia.
		Para transferir registros de un archivo, la longitud se determina aplicando el operador sizeof a la estructura 
		que devuelve el número de bytes que la compone, y en numelem el valor 1 dado que se desea transferir una estructura*/
	fread(&movimiento, sizeof(Movimiento), 1, fichero);/* lee primer registro del archivo Movimientos */
	while(!feof(fichero)) {/*mientras no sea el fin de archivo*/
		imprimirMovimiento(&movimiento);
		if(movimiento.codMovimiento==1){
			depositos+=movimiento.importe;
		}else if(movimiento.codMovimiento==2){
			extracciones +=movimiento.importe;
		}
		fread(&movimiento, sizeof(Movimiento), 1, fichero);
	}
	printf("Importe depositos: %.2f\nImporte extracciones: %.2f\n",depositos,extracciones);
}
