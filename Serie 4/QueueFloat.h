#include <stdbool.h>/*cabecera boolean*/
#include <stdlib.h> /*gestión de memoria dinámica*/
typedef float Elemento;
struct nodo{
	Elemento elemento;		
    struct nodo *siguiente;    
};
typedef struct queue{
	struct nodo *head;
	struct nodo *tail;
}Queue;/*Cola/Queue/FIFO*/

/*prototipos*/
Queue* queue_new();/*retornar puntero Queue con *head y tail -> NULL*/
void push(Queue *s,Elemento elem);/*Agregar Elemento en ptr Queue*/
void pop(Queue *s);/*Quitar Elemento en ptr stack*/
bool isEmpty(Queue *s);/*Queue/cola vacía?*/
void stack_print(Queue *s);/*imprimir elementos*/
Elemento top(Queue *s);/*retornar elemento de la cima*/


Elemento top(Queue *s){
	return s->head->elemento;
}
void pop(Queue *s){
	if(!isEmpty(s)){
		printf("pop (%.2f)!\n",s->head->elemento);
		struct nodo *nodo = s->head; /*actual*/
		/*cola unitaria*/
		if(s->head == s->tail){
			nodo = s->head;
									#ifdef DEBUG
										if(!isEmpty(s)){printf("pop queue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);}
									#endif
			free(nodo);
			s->head = NULL;
			s->tail = NULL;
									#ifdef DEBUG
										if(!isEmpty(s)){printf("Queue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);}
										if(!isEmpty(s)){printf("Queue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);}
									#endif
		}else{
			nodo = s->head;
									#ifdef DEBUG
										if(!isEmpty(s)){printf("pop queue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);}
									#endif
			s->head = nodo->siguiente;
			free(nodo);/*liberar memoria*/
									#ifdef DEBUG
										if(!isEmpty(s)){printf("Queue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);}
										if(!isEmpty(s)){printf("Queue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);}
									#endif
		}/*head tail*/
	}else{
		printf("Empty stack\n");
	}
	printf("\n\n");
}

bool isEmpty(Queue *s){
	return (s==NULL||s->tail==NULL);
}
void queue_print(Queue *s){
	printf("Queue print\n");
	struct nodo *n = NULL;
	if(!isEmpty(s)){
									#ifdef DEBUG
										printf("Queue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										printf("Queue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);
									#endif	
		for(n=s->head;n!=NULL;n=n->siguiente){
			#ifdef DEBUG
				printf("\tNodo auxiliar direccion de memoria: %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);		
			#else
				printf("%.2f\t",n->elemento);
			#endif
		}
									#ifdef DEBUG
										printf("Queue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										printf("Queue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);
									#endif
		printf("\n\n");
	}
}


void push(Queue *s,Elemento elem){
	printf("push (%.2f)!\n",elem);
	struct nodo* n = malloc(sizeof *n);
	n->elemento = elem;
	n->siguiente = NULL;
									#ifdef DEBUG
										printf("Nuevo nodo direccion de memoria: %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);
									#endif
	if(isEmpty(s)){
		/*primer elemento*/
		s->head = n;
		s->tail = n;
									#ifdef DEBUG
										printf("\tPrimer elemento\n");
										printf("\tQueue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										printf("\tQueue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);
									#endif
	}else{
									#ifdef DEBUG
										printf("\tQueue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										printf("\tQueue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);
										printf("Queue tail->siguiente = Nuevo nodo\n");
									#endif
		s->tail->siguiente = n;
									#ifdef DEBUG
										printf("\tQueue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);
										printf("Queue tail = Nuevo nodo\n");
									#endif
		s->tail = n;
									#ifdef DEBUG
										printf("Queue head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										printf("Queue tail direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->tail,s->tail->elemento,s->tail->siguiente);
									#endif
		printf("\n\n");
	}
}

Queue* queue_new(){
	Queue* s = malloc(sizeof *s);
	s->head = NULL;
	s->tail = NULL;
  	return s;
}
