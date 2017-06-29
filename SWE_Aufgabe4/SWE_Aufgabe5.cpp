//implementieren sie anhand geg. definitionen notwendige funktionen
//um durch dynamische einfach verkettete Liste eine double ended queue zu realisieren

#include <stdlib.h>
#include <stdio.h>
#include "Header.h"
#include "queue_functions.h"
#include "stack_functions.h"

int main()
{
	STACK *stack;

	stack = create_stack();

	push(stack);

	fflush(stdin);

	push(stack);
	printf("Länge: %d \t Nächstes: %p \t Letztes: %p\n", stack->len, stack->next, stack->last);

	pop(stack);
	printf("Länge: %d \t Nächstes: %p \t Letztes: %p\n", stack->len, stack->next, stack->last);

    return 0;
}

