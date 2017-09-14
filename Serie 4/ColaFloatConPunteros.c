#include <stdio.h>
#define DEBUG /*imprimir paso a paso*/
#include "QueueFloat.h"
int main(){
	printf("New Queue\n");
	Queue *s= queue_new();
	printf("Empty Queue? %c\n\n",(isEmpty(s))?'S':'N');
	push(s,45);
	printf("Queue top: %.2f\n\n",top(s));
	printf("\nEmpty Queue? %c\n\n",(isEmpty(s))?'S':'N');
	push(s,70);
	push(s,72);
	printf("Queue top: %.2f\n\n",top(s));
	queue_print(s);
	pop(s);
	queue_print(s);
	pop(s);
	printf("Queue top: %.2f\n\n",top(s));
	pop(s);
	pop(s);
	queue_print(s);
	printf("\nQueue2\n");
	Queue *s2= queue_new();
	push(s2,100);
	push(s2,200);
	queue_print(s2);
	return 0;
}
