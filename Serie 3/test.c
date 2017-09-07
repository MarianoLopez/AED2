#include <stdio.h>
#include <stdlib.h> /*gestión de memoria dinámica*/

typedef float Acertijo;/*nuevo tipo de dato 'Acertijo' a partir del tipo de dato float*/
typedef Acertijo *Ap;/*nuevo tipo de dato 'Ap' el cual es un puntero a Acertijo*/

void invertirValores(int *a,int *b);
void invertirValoresSinPuntero(int a,int b);

int main(){	
   printf("Ejemplo puntero\n");
   int  var = 20;   /* declaración e inicialización  */
   int  *ip;        /* declaración de puntero*/
   ip = &var;  /* almacenar la dirección de memoria "&" de la variable var en el puntero ip*/
   printf("\tDireccion de var: %x\n", &var  );
   printf("\tDireccion almacenada en el puntero ip: %x\n", ip );
   printf("\tValor de var: %d\n",var);
   printf("\tValor de *ip: %d\n", *ip);/* acceder al contenido del puntero '*' */
   printf("\tModificacion del contenido: *ip=60;\n");
   *ip = 60;/*modificación del contenido*/
   printf("\tValor de var: %d\n",var);
   printf("\tValor de *ip: %d\n", *ip);
   
   /*utilización*/
   int a = 30;
   int b = 88;
   printf("\nValores originales de a: %d, b: %d\n",a,b);
   invertirValoresSinPuntero(a,b);
   printf("invertirValoresSinPuntero a: %d, b: %d\n",a,b);
   invertirValores(&a,&b);	
   printf("invertirValores a: %d, b: %d\n\n",a,b);
   
   /*test*/
   Ap a1;/*puntero float*/
   a1 = malloc(sizeof(Acertijo));/*solicitar memoria*/
   *a1 = 1.1;/*contenido*/
   printf("Direccion: %x - valor: %.2f\n",a1,*a1);
   return 0;
}

void invertirValores(int *a,int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void invertirValoresSinPuntero(int a,int b){
	int aux = a;
	a = b;
	b = aux;
}
