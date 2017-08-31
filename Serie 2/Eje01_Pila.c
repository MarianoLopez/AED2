/*	1.	Implemente una pila con capacidad de 10 elementos, donde cada elemento será un número real. 
		El programa debe permitirle al usuario ingresar elementos (números reales) a la pila hasta que la misma se llene o 
		el usuario no desee cargar más valores en la pila. Como salida debe devolver la suma de todos los elementos apilados, a través de una función. 
		Además, mostrar los elementos que se encuentran apilados.
*/

#include <stdio.h>/*cabecera InputOutput*/
#include <stdbool.h>/*cabecera boolean*/
#define max 10 /*constante*/

typedef float Pila [max];/*nuevo tipo de dato "Pila" a partir de array de float*/	

/*prototipos*/
void crearPilaVacia();
bool pilaVacia(); 
bool pilaLlena();
void apilar(float);
void desapilar();
float cima();
void visualizarElementos();
float sumaElementos();

void desapilarTodo();

/*variables globales*/
Pila pila;
int tope;

int main(){
	/*variables locales*/
	char opcion;
	float nro;
	
	crearPilaVacia();	
	printf("Desea ingresar datos? s/n: ");
	scanf("%c", &opcion);
	while (opcion != 'n' && opcion != 'N'){		
		printf("Ingrese un numero real: ");
		scanf("%f", &nro);
		fflush(stdin);
		apilar(nro);
		printf("\tCima actual: %.2f\n",cima());
		printf("Desea ingresar datos? s/n: ");
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

void crearPilaVacia(){
	tope = -1;	/*utilizaremos -1 para identificar que la pila se encuentra vacía*/
}

bool pilaVacia(){
	return (tope==-1);/*Equivalente a: if (tope == -1){ return true; }else{return false;}*/
}

bool pilaLlena(){
	return (tope == (max-1));/*Equivalente a: if (tope == (max-1)){ return true;}else{return false;}*/
}

void apilar(float pElemento){
	if (!pilaLlena()){/*Si la pila NO esta llena*/
		tope += 1;/*incrementar tope en 1*/
		pila[tope] = pElemento; /*asignar el nuevo elemento en la posición nueva del tope}*/		
	}else{
		printf("\tPila Llena!\n");
	}
}

void desapilar(){
	if (!pilaVacia()){/*Si la pila NO esta vacía*/
		printf("\tDesapilando %.2f\n",pila[tope]);
		pila[tope] = 0;/*asignar valor neutro en la posición actual*/
		tope -= 1;/*decrementar tope en 1*/
	}else{
		printf("\tPila Vacia!!!\n");
	}
}

float cima(){
	return pila[tope];/*retornar elemento del tope de la pila*/
}

void visualizarElementos(){
	if(!pilaVacia()){
		int i;
		printf("Elementos en pila: \n");
		for (i = tope; i >= 0; i--){/*LIFO*/
			printf("%.2f ", pila[i]);
		}
		printf("\n\n");		
	}else{
		printf("Pila vacia\n");
	}
	
}

float sumaElementos(){
	int i;
	float suma = 0;	
	for (i = 0; i <= tope; i++){
		suma += pila[i];
	}
	return suma;
}

void desapilarTodo(){
	while(!pilaVacia()){
		desapilar();
	}
}
