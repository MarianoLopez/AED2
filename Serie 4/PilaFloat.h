#include <stdbool.h>/*cabecera boolean*/
#include <stdlib.h> /*gestión de memoria dinámica*/
typedef float Elemento;
struct nodo{
	Elemento elemento;		
    struct nodo *siguiente;    
};
typedef struct stack{struct nodo *head;}Stack;/*Pila/Stack/LIFO*/

/*prototipos*/
Stack* stack_new();/*retornar puntero Stack con *siguiente->NULL*/
void push(Stack *s,Elemento elem);/*apilar Elemento en ptr stack*/
void pop(Stack *s);/*desapilar Elemento en ptr stack*/
bool isEmpty(Stack *s);/*stack/pila vacía?*/
void stack_print(Stack *s);/*imprimir elementos*/
Elemento top(Stack *s);/*retornar elemento de la cima*/


Elemento top(Stack *s){
	return s->head->elemento;
}
void pop(Stack *s){
	if(!isEmpty(s)){
		printf("pop (%.2f)!\n",s->head->elemento);
		#ifdef DEBUG
			if(!isEmpty(s)){printf("pop stack head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);}
		#endif
		struct *nodo = s->head;/*actual*/
		s->head = s->head->siguiente;
		free(nodo);/*liberar memoria*/
		#ifdef DEBUG
			if(!isEmpty(s)){printf("Stack head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);}
		#endif
	}else{
		printf("Empty stack\n");
	}
	printf("\n\n");
}

bool isEmpty(Stack *s){
	return (s==NULL||s->head==NULL);
}
void stack_print(Stack *s){
	printf("Stack print\n");
	struct nodo *n = NULL;
	if(!isEmpty(s)){
		#ifdef DEBUG
			printf("Stack head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
		#endif	
		for(n=s->head;n!=NULL;n=n->siguiente){
			#ifdef DEBUG
				printf("\tNodo auxiliar direccion de memoria: %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);		
			#else
				printf("%.2f\t",n->elemento);
			#endif
		}
		#ifdef DEBUG
			printf("Stack head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
		#endif
		printf("\n\n");
	}
}


void push(Stack *s,Elemento elem){
	printf("push (%.2f)!\n",elem);
	struct nodo* n = malloc(sizeof *n);
	n->elemento = elem;
	n->siguiente = NULL;
	#ifdef DEBUG
		printf("Nuevo nodo direccion de memoria: %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);
	#endif
	if(isEmpty(s)){
		s->head = n;
		#ifdef DEBUG
			printf("Primer elemento\n");
			printf("Stack head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
		#endif
	}else{
		n->siguiente = s->head;
		#ifdef DEBUG
			printf("Stack head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
			printf("Nuevo nodo->siguiente = Stack->head\n");
			printf("Nuevo nodo direccion de memoria: %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);
		#endif
		s->head = n;
		#ifdef DEBUG
			printf("Stack->head = nuevo nodo\n");
			printf("Stack head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
		#endif
		printf("\n\n");
	}
}

Stack* stack_new(){
	Stack* s = malloc(sizeof *s);
	s->head = NULL;
  	return s;
}
