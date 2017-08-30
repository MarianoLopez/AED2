/*
Escribir un programa que lea desde el teclado los siguientes datos correspondientes a los clientes de un banco: 
	Número de cuenta, nombre del cliente y saldo. 
Utilizando procedimientos y/o funciones 
	verificar la cantidad de cuentas con saldo deudor 
	y la cantidad de cuentas con saldo acreedor 
	e informar por fin de programa.
*/
#include <stdio.h>
/*prototipo de las funciones*/
void ingresoDeDatos(int *nroCuenta, char *nombre, float *saldo);/* "*" = puntero, los utilizáremos para evitar el uso de variables globales*/
void verificarCuentas(float *saldo, int *cantidadAcreedor, int *cantidadDeudor);
void imprimirCliente(int *nroCuenta, char *nombre, float *saldo);
int main(){
	/*variable locales a main*/
	int nroCuenta; 		
	char nombre[25];/*array de char = String*/ 	
	float saldo;
	
	/*contadores*/
	int cantidadAcreedor = 0;
	int cantidadDeudor = 0;
	
	char respuesta = 's';/*identificar fin de entrada de datos*/
	while(respuesta=='s'||respuesta=='S'){
		ingresoDeDatos(&nroCuenta,nombre,&saldo);/*notar la falta de & en nombre: https://www.tutorialspoint.com/cprogramming/c_pointer_to_an_array.html*/
		verificarCuentas(&saldo,&cantidadAcreedor,&cantidadDeudor);
		imprimirCliente(&nroCuenta,nombre,&saldo);
		printf("Desea continuar el ingreso de datos? s/n: ");
		scanf("%c",&respuesta);
	}
	/*informe de totales*/
	printf("Cuentas acreedoras: %d\nCuentas deudoras: %d",cantidadAcreedor,cantidadDeudor);
	return 0;
}
void verificarCuentas(float *saldo, int *cantidadAcreedor, int *cantidadDeudor){
	if(*saldo>=0){
		(*cantidadAcreedor)++;/*https://stackoverflow.com/questions/8208021/how-to-increment-a-pointer-address-and-pointers-value*/
	}else{
		(*cantidadDeudor)++;
	}
}
void imprimirCliente(int *nroCuenta, char *nombre, float *saldo){
	printf("\tCuenta: %d\n\tNombre: %s\n\tSaldo: %.2f\n",*nroCuenta,nombre,*saldo);
}
void ingresoDeDatos(int *nroCuenta, char *nombre, float *saldo){
		/*notar la NO utilización de "&" en los scanf, dado que las variables son punteros*/
		printf("Ingrese nro de cuenta: ");/*printf -> imprimir por consola*/ 		
		scanf("%d", nroCuenta);/*scanf -> recuperar desde consola y almacenar en la variable por referencia. %d = especificador para enteros con signo.*/
		/*Especificadores: http://wiki.cabal.mx/wiki/Curso_de_Programaci%C3%B3n_en_C/Especificadores_de_Conversi%C3%B3n_de_printf()*/
		fflush(stdin);/*Limpiar buffer de entrada, EJ: limpiar el \n "enter" luego de ingresar el número de cuenta*/
		
		printf("Ingresar Nombre: ");
		/*[] = expresión regular (https://es.wikipedia.org/wiki/Expresi%C3%B3n_regular), ^ = representa el inicio de la cadena, \ = Se utiliza para escapar el siguiente carácter de la expresión de búsqueda */
		scanf("%[^\n]s",nombre);/*[^\n] acepta cualquier String omitiendo \n, de esta forma "nombre" admite espacios en blanco "omitidos por defecto"*/
		
		
		printf("Ingrese saldo: "); 		
		scanf("%f", saldo);
		fflush(stdin);
}

