#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

STACK *create_stack(void)
{
	STACK *stack;			//pointer für dequeue erstellen
	stack = (STACK*)malloc(sizeof(STACK));		//Speicher für dequeue reservieren
	if (stack == NULL)		//fehlerüberwachung falls malloc fehlschlägt
	{
		printf("Fehler bei Speicherreservierung!\n");
		return NULL;
	}
	stack->next = NULL;		//next zeiger auf NULL - zeigt auf "nichts"
	stack->last = NULL;		//last zeiger auf NULL - zeigt auf "nichts"
	stack->len = 0;			//länge wird 0 gesetzt
	return stack;			//erstellten, leeren stack pointer auf header zurückgeben
}

ELEM *push(STACK *head)
{
	int i = 0;
	char c, entscheidung;
	ELEM *element;			//pointer zu struct ELEM 
	do 
	{
		printf("Wollen Sie einen integer(i) oder character(c) ablegen?\n");
		scanf("%c", &entscheidung);
	} while (getchar() != '\n');

		if (entscheidung == 'i')	//wenn i eingegeben wurde dann if ausführen
		{
			element = (ELEM*)malloc(sizeof(ELEM));	//speicher für element pointer
			if (NULL == element)	//kontrolle ob speicherallokierung funktioniert hat
			{
				printf("Fehler bei Speicherallokierung!\n");
				return NULL;
			}
			printf("Geben Sie den Wert des integers ein: \n");
			scanf("%d", &i);
			element->item.num = i;	//i ist pointer auf item nummer
			element->next = NULL;	//und pointer auf NULL
		}
		else if (entscheidung == 'c')	//wenn c bei der entscheidung eingegeben wurde dann else if ausführen
		{
			element = (ELEM*)malloc(sizeof(ELEM));	//wieder speicherallokierung
			if (NULL == element)	//wieder kontrolle ob speicherallokierung funktioniert hat
			{
				printf("Fehler bei Speicherallokierung!\n");
				return NULL;
			}
			printf("Geben Sie den Wert des characters ein: \n");
			scanf("%c", &c);
			element->item.num = c;	//c ist pointer auf item nummer
			element->next = NULL;	//pointer auf NULL
		}
		if (head->len == 0)		//kontrolle ob länge des headers 0 ist
		{
			head->next = element;	//pointer element ist zeiger auf next
			head->last = element;	//pointer element ist zeiger auf last
			head->len++;			//und länge des headers wird erhöht
		}
		else
		{
			head->last->next = element;
			head->len++;
		}
	return element;
}

ELEM *pop(STACK *head)
{
	ELEM *ptr1, *ptr2;		//2 Zeiger erstellen auf ELEM
	ptr1 = head->last;		//ptr1 ist zeiger auf last
	int count = 1;
	
	if (head->len == 0)		//fehlerüberwachung ob länge 0 ist
	{
		printf("Stack ist leer\n");
		return NULL;
	}

	int len = head->len;	//integer len ist länge des headers bzw pointer auf länge des headers
	ptr2 = head->next;		//zweiter pointer ist zeiger auf next
	if (head->len == 1)		//wenn länge des headers 1 ist dann...
	{
		head->next == NULL;	//zeiger auf next ist NULL
		head->last == NULL;	//zeiger auf last ist NULL
		head->len--;		//und länge wird reduziert
	}
	else
	{
		while (count == (len-1)) //solange bis count = länge -1 ist
		{
			ptr2 = ptr2->next;	//zweiter zeiger ist ist zeiger auf next
			count++;			//count wird erhöht
		}
		head->last = ptr2;		//zweiter zeiger ist zeiger auf last
		ptr2->next = NULL;		//zweiter zeiger von while schleife gleich NULL
		head->len--;			//länge wird reduziert
	}
	return ptr1;	//erster zeiger wird zurückgegeben
}

ELEM *top(STACK *head)
{
	if (NULL == head) //kontrolle ob etwas im header ist
	{
		printf("Fehler mit pointer!\n");
		return NULL;
	}
	return head->last;//letztes element vom header zurückgeben
}

