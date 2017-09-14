#include <stdio.h>
#define DEBUG /*imprimir paso a paso*/
#include "LinkedListFloat.h"
int main(){
	printf("New LinkedList\n");
	LinkedList *s= linkedList_new();
	printf("Empty LinkedList? %c\n\n",(isEmpty(s))?'S':'N');
	add(s,45);
	printf("\nEmpty LinkedList? %c\n\n",(isEmpty(s))?'S':'N');
	add(s,70);
	add(s,72);
	addK(s,100,2);
	linkedList_print(s);
	deleteK(s,2);
	linkedList_print(s);
	deleteFirst(s);
	linkedList_print(s);
	return 0;
}
