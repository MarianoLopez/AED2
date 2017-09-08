/*Autor: Cardozo Martin Ignacio*/

/*
	Desarrollar un programa para la gestión de las ventas de un supermercado mediante la implementación de una pila.
	 Cada nodo deberá contener los siguientes datos asociados a un producto:
	  código del producto, código de rubro, cantidad, precio unitario. 
	Se solicita: 
		a) Escribir una función que devuelva “verdadero” si la pila se encuentra vacía y “falso” en caso contrario.
		b) Escribir una función que devuelva el nodo que está en la CIMA de la pila.
		c) Escribir la función Apilar, debe tener como parámetros elemento a insertar.
		d) Escribir la función Desapilar.
		e) Escribir una función que permita visualizar todos los elementos que se encuentran en la pila. 
		f) Escribir una función que calcule y retorne el monto total recaudado.
 Implementar un menú principal que contenga todos los ítems anteriormente solicitados. 
*/

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
typedef struct producto{
	int codProd;
	int codRub;
	int cant;
	float precio;
}Producto;

typedef struct nodo{
	Producto producto;
	struct nodo *siguiente;
}tPila;

tPila *v_pila;

void crearPilaVacia();
bool pilaVacia();
void apilar(Producto);
void desapilar();
void cima();
void visualizarElementos();
float montoTotal();
void menu();

int main(){
	crearPilaVacia();
	menu();
	return 0;
}

void menu(){
	Producto p;
	int resp;
	printf(" Menu de Opciones\n ");
	printf("1-Agregar Producto\n 2-Quitar Producto\n 3-Mostrar Lista\n 4-Mostrar elemento en la cima\n ");
	printf("5-Mostrar Monto Total\n 6-Saber si la pila esta vacia\n 0-Salir\n Ingrese una opcion: ");
	scanf("%d", &resp); fflush(stdin);
	system("cls");
	while(resp!=0){
		switch(resp){
			case 1:{
				printf("Ingrese codigo de producto: ");
				scanf("%d", &p.codProd);
				printf("Ingrese codigo de rubro: ");
				scanf("%d", &p.codRub);
				printf("Ingrese cantidad de productos: ");
				scanf("%d", &p.cant);
				printf("Ingrese precio unitario: ");
				scanf("%f", &p.precio);
				apilar(p);
				break;
			}
			case 2:{
				desapilar();
				break;
			}
			case 3:{
				visualizarElementos();
				break;
			}
			case 4:{
				cima();
				break;
			}
			case 5:{
				printf("Monto total: %.2f\n", montoTotal());
				break;
			}
			case 6:{
				printf( (pilaVacia())? "SI\n":"NO\n");
				break;
			}
		}
		system("pause");
		system("cls");
		printf(" Menu de Opciones\n ");
	    printf("1-Agregar Producto\n 2-Quitar Producto\n 3-Mostrar Lista\n 4-Mostrar elemento en la cima\n ");
	    printf("5-Mostrar Monto Total\n 6-Saber si la pila esta vacia\n 0-Salir\n Ingrese una opcion: ");
		scanf("%d", &resp); fflush(stdin);
		system("cls");
	}
	printf("FIN DE PROGRAMA");
}

void crearPilaVacia(){
	v_pila=NULL;
}
bool pilaVacia(){
	if(v_pila==NULL){
		return true;
	} else{
		return false;
	}
}

void apilar(Producto p){
	tPila *aux = v_pila;
	/*aux=v_pila;*/
	v_pila=malloc(sizeof(tPila));
	v_pila->producto = p;
	v_pila->siguiente=aux;
	printf("Elemento Insertado!\n");
}

void desapilar(){
	if(!pilaVacia()){
		tPila *aux;
	    aux=v_pila;
		v_pila=v_pila->siguiente;
		free(aux);
		printf("Elemento de la cima Eliminado!\n");
	} else{
		printf("La Pila esta Vacia!!\n");
	}
}

void cima(){
	if(pilaVacia()==false){
		tPila *aux ;
		aux=v_pila;
		/*aux.codProd=v_pila->codProd;
		aux.codRub=v_pila->codRub;
		aux.cant=v_pila->cant;
		aux.precio=v_pila->precio;
		aux.siguiente=v_pila->siguiente;*/
		printf("elementos de la cima: %d %d %d %.2f\n", aux->producto.codProd, aux->producto.codRub, aux->producto.cant, aux->producto.precio);
	} else{
		printf("La pila esta vacia!!\n");
	}	
}

void visualizarElementos(){
	tPila *aux;
	aux=v_pila;
	if(pilaVacia()==false){
		printf("Elementos en la pila: \n");
		printf("Codigo de producto   Codigo de Rubro Cantidad Precio\n");
		while(aux!=NULL){
			printf("\t%d\t\t", aux->producto.codProd);
			printf("%d\t\t", aux->producto.codRub);
			printf("%d\t", aux->producto.cant);
			printf("%.2f\n", aux->producto.precio); 
			aux=aux->siguiente;
		}
	} else{
		printf("La pila esta vacia!!\n");
	}
}
float montoTotal(){
	float acum=0.0;
	tPila *aux;
	aux=v_pila;
	while(aux!=NULL){
		acum=acum+aux->producto.precio;
		aux=aux->siguiente;
	}
	return acum;
}
