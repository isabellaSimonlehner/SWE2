#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

HEAD *create_dequeue(void)
{
	HEAD *dequeue;										//pointer zu struct HEAD erstellen
	dequeue = (HEAD*)malloc(sizeof(HEAD));				//speicher für pointer allokieren
	if (NULL == dequeue)								//überprüfung ob allokierung funktioniert hat
	{
		printf("Fehler bei Speicherallokierung!\n");
		return NULL;
	}

	dequeue->first = NULL;	//erstes element = NULL
	dequeue->last = NULL;	//letztes element = NULL
	dequeue->len = 0;		//und länge der dequeue = 0
	return dequeue;			//dequeue zurückgeben
}


ELEM *enqueue(HEAD *head)
{
	int i = 0;
	char c, entscheidung;
	ELEM *element;		//zeiger auf ELEM erstellen

	do
	{
		printf("Wollen sie einen integer (i) oder einen character (c) einfügen?\n");
		scanf("%c", &entscheidung); 
	} while (getchar() != '\n');	//schleifenende dann wenn getchar != zeilenumbruch ist 
	
	if (entscheidung == 'i')		//wenn i eingegeben wurde dann ...
	{
		element = (ELEM*)malloc(sizeof(ELEM));	//speicherallokierung für zeiger
		if (NULL == element)					//kontrolle ob speicherallokierung erfolgreich
		{
			printf("Fehler bei Speicherallokierung!\n");
			return NULL; 
		}

		printf("Geben Sie einen integer Wert ein: \n");
		scanf("%d", &i);	//eingabe des integer wertes
		element->item.num = i;		//i ist zeiger auf item nummer
		element->next = NULL;		//pointer auf next ist NULL
	}

	else if (entscheidung == 'c')	//wenn c eingegeben wurde dann...
	{
		element = (ELEM*)malloc(sizeof(ELEM));	//speicherallokierung für pointer
		if (NULL == element)		//kontrolle ob speicherallokierung funktioniert hat
		{
			printf("Fehler bei Speicherallokierung!\n");
			return NULL; 
		}

		printf("Geben sie einen character Wert ein: \n");
		scanf("%c", &c);		//eingabe des character wertes

		element->item.num = c;	//c ist zeiger auf itme nummber
		element->next = NULL;	//pointer auf next ist NULL
	}

	if (head->len == 0)			//kontrolle ob länge 0 ist
	{
		head->first = element;	//pointer element zeigt auf erstes element
		head->last = element;	//pointer element zeigt auf letztes element
		head->len++;			//länge des headers wird erhöht
	}
	else
	{
		element->next = head->first;	//pointer auf next ist erstes element
		head->first = element;			//erstes element ist pointer element
		head->len++;					//länge des headers wird erhöht
	}
	return element;		//pointer element wird zurückgegeben
}


ELEM *dequeue(HEAD *head)
{
	ELEM *element;
	int count = 0;

	if (head->len == 0)	//kontrolle ob queue befüllt ist
	{
		printf("Queue ist leer!\n");
		return NULL;
	}

	int len = head->len;	//int länge ist gleich länge des headers
	element = head->first;	//pointer element ist zeiger aufs erste element

	while (count == (len-1))//solange bis int count gleich die länge -1 ist
	{
		element = head->first->next;	//pointer elment ist zeiger auf first zeiger auf next
		count++;			//count wird erhöht
	}

	if (head->len == 1)
	{
		head->last = NULL;	//zeiger auf letztes element gleich NULL
		head->first = NULL;	//zeiger auf erstes element gleich NULL
		head->len--;		//länge reduzieren
	}
	else
	{
		head->last = element;	//letztes element ist pointer element
		head->last->next = NULL;//next gleich NULL
		head->len--;			//länge wird reduziert
	}
	return element;
}


ELEM *front(HEAD *head)
{
	if (NULL == head)	//Kontrolle ob head gleich NULL ist
	{
		printf("Fehler mit pointer!\n");
		return NULL;
	}
	return head->last;	//letztes element wird zurückgegeben
}


ELEM *back(HEAD *head)
{
	if (NULL == head)	//Kontrolle ob head gleich NULL ist
	{
		printf("Fehler mit pointer!\n");
		return NULL;
	}
	return head->first;	//erstes element wird zurückgegeben 
}