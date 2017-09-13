#include <stdio.h>
#define DEBUG /*imprimir paso a paso*/
#include "PilaFloat.h"
int main(){
	printf("New stack\n");
	Stack *s= stack_new();
	printf("Empty stack? %c\n\n",(isEmpty(s))?'S':'N');
	push(s,45);
	printf("Stack top: %.2f\n\n",top(s));
	printf("\nEmpty stack? %c\n\n",(isEmpty(s))?'S':'N');
	push(s,70);
	push(s,72);
	printf("Stack top: %.2f\n\n",top(s));
	stack_print(s);
	pop(s);
	stack_print(s);
	pop(s);
	printf("Stack top: %.2f\n\n",top(s));
	pop(s);
	pop(s);/*empty stack*/
	stack_print(s);
	/*stack 2*/
	printf("\nStack2\n");
	Stack *s2= stack_new();
	push(s2,100);
	push(s2,200);
	stack_print(s2);
	return 0;
}
