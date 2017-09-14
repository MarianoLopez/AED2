#include <stdbool.h>/*cabecera boolean*/
#include <stdlib.h> /*gestión de memoria dinámica*/
typedef float Elemento;
struct nodo{
	Elemento elemento;		
    struct nodo *siguiente;    
};
typedef struct list{struct nodo *head;}LinkedList;/*Lista enlazada/LinkedList*/

/*prototipos*/
LinkedList* linkedList_new();/*retornar puntero Stack con *siguiente->NULL*/
void addFirst(LinkedList *s,Elemento elem);/*insertar al principio*/
void addFoward(LinkedList *s,Elemento elem);/*insertar adelante*/
void add(LinkedList *s,Elemento elem);/*insertar al principio si list = null sino insertar adelante*/
bool isEmpty(LinkedList *s);/*Lista vacía?*/
void linkedList_print(LinkedList *s);/*imprimir elementos*/
void deleteFirst(LinkedList *s);/*eliminar primer elemento*/
void addK(LinkedList *s,Elemento elem,int k);/*insertar elemento en la posición k*/
void deleteK(LinkedList *s,int k);


void deleteK(LinkedList *s,int k){
	printf("deleteK\n");
	struct nodo *n, *aux;/*auxiliares*/
	int i; 
	aux = s->head;/*apuntador a lista*/ 
	for(i = 1; i < k-1; i++){aux = aux->siguiente;}	/*El bucle avanza aux hasta el nodo k-1*/
										#ifdef DEBUG
											printf("Nodo auxiliar (k-1) direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",aux,aux->elemento,aux->siguiente);
										#endif
	n = aux->siguiente;/*elemento a eliminar*/
										#ifdef DEBUG
											printf("Nodo auxiliar (k) direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);
										#endif
	printf("delete (%.2f) index: %d!\n",n->elemento,k);
	aux->siguiente = n->siguiente;/*apuntar a k+1*/
										#ifdef DEBUG
											printf("Nodo auxiliar (k) direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",aux,aux->elemento,aux->siguiente);
										#endif
  	free(n);
	printf("\n");
}

void addK(LinkedList *s,Elemento elem,int k){
	printf("add (%.2f) index: %d!\n",elem,k);
	struct nodo *n, *aux;/*auxiliares*/
	int i; 
	aux = s->head;/*apuntador a lista*/ 
	for(i = 1; i < k-1; i++){aux = aux->siguiente;}	/*El bucle avanza aux hasta el nodo k-1*/
										#ifdef DEBUG
											printf("Nodo auxiliar (k) direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",aux,aux->elemento,aux->siguiente);
										#endif
  	n = malloc(sizeof(*n));/*socilitar memoria*/
	n->elemento = elem; /*añadir elemento*/
	n->siguiente = aux->siguiente;/*apuntar a K*/
										#ifdef DEBUG
												printf("Nuevo nodo direccion de memoria %x -> (elemento: %.2f, nodo siguiente (k+1): %x)\n",n,n->elemento,n->siguiente);
												printf("Nodo auxiliar (k)->siguiente = nuevo nodo\n");
										#endif
  	aux->siguiente = n;/*actualizar direcciones*/
									  	#ifdef DEBUG
									  			printf("Nodo auxiliar (k) direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",aux,aux->elemento,aux->siguiente);
									  	#endif
	printf("\n");
}
void deleteFirst(LinkedList *s){
	if(!isEmpty(s)){
		printf("delete (%.2f)!\n",s->head->elemento);
										#ifdef DEBUG
											printf("LinkedList head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										#endif	
		struct nodo *n = s->head;
		s->head = n->siguiente;
										#ifdef DEBUG
											printf("\tLinkedList head = siguiente\n");
											printf("LinkedList head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										#endif	
		free(n);/*liberar memoria*/ 
	}
	printf("\n");
}

bool isEmpty(LinkedList *s){
	return (s==NULL||s->head==NULL);
}
void linkedList_print(LinkedList *s){
	printf("LinkedList print\n");
	if(!isEmpty(s)){
		struct nodo *n = NULL;
										#ifdef DEBUG
											printf("LinkedList head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										#endif	
		for(n=s->head;n!=NULL;n=n->siguiente){
			#ifdef DEBUG
				printf("\tNodo auxiliar direccion de memoria: %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);		
			#else
				printf("%.2f\t",n->elemento);
			#endif
		}
										#ifdef DEBUG
											printf("LinkedList head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										#endif
		printf("\n\n");
	}
}

void addFirst(LinkedList *s,Elemento elem){
	struct nodo *n = malloc(sizeof(*n));
	n->elemento = elem;
	n->siguiente = NULL;
	s->head = n;
										#ifdef DEBUG
												printf("Primer elemento\n");
												printf("Nuevo nodo direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);
												printf("LinkedList head = nuevo nodo\n");
												printf("LinkedList head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										#endif
}
void addForward(LinkedList *s,Elemento elem){
	struct nodo *n = malloc(sizeof(*n));
	n->elemento = elem;
	n->siguiente = NULL;
										#ifdef DEBUG
												printf("LinkedList head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
												printf("Nuevo nodo direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);
												printf("Nuevo nodo siguiente = LinkedList head\n");
										#endif
	n->siguiente = s->head;
										#ifdef DEBUG
												printf("\tNuevo nodo direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",n,n->elemento,n->siguiente);
												printf("LinkedList head = nuevo nodo\n");
										#endif
	s->head = n;/*cambio de apuntadores (no de contenido)*/
										#ifdef DEBUG
												printf("LinkedList head direccion de memoria %x -> (elemento: %.2f, nodo siguiente: %x)\n",s->head,s->head->elemento,s->head->siguiente);
										#endif
}
void add(LinkedList *s,Elemento elem){
	printf("add (%.2f)!\n",elem);
	if(isEmpty(s)){
		addFirst(s,elem);
	}else{
		addForward(s,elem);
	}
	printf("\n");
}

LinkedList* linkedList_new(){
	LinkedList* s = malloc(sizeof *s);
	s->head = NULL;
  	return s;
}
