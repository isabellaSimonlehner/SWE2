#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Stack_Header.h"

HEAD *create_Stack(void)
{
	HEAD *stack;
	stack = (HEAD*)malloc(sizeof(HEAD));
	if (stack == NULL)
		return NULL;

	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
	return stack;
}

ELEM *push(HEAD *head, char t)
{
	if (head == NULL)
		return NULL;

	ELEM *elem;
	elem = (ELEM*)malloc(sizeof(ELEM));
	if (elem == NULL)
		return NULL;

	if (head->len == 0)
	{
		elem->wert = t;
		elem->next = NULL;
		elem->prev = NULL;
		head->first = elem;
		head->last = elem;
		head->len++;
	}
	else
	{
		elem->wert = t;
		elem->prev = NULL;
		elem->next = head->first;
		head->first->prev = elem;
		head->first = elem;
		head->len++;
	}
	return elem;
}

ELEM *pop(HEAD *head)
{
	ELEM *elem;
	if (elem == NULL)
		return NULL;

	if (head->len == 0)
	{
		elem = head->first;
		head->first = NULL;
		head->last = NULL;
		head->len--;
		free(elem);
	}
	else
	{
		elem = head->first;
		head->first->next->prev = NULL;
		head->first = head->first->next;
		head->len--;
		free(elem);
	}
	return head->first;
}

ELEM *top(HEAD *head)
{
	if (head == NULL)
		return NULL;

	if (head->len == 0)
		printf("Stack ist leer\n");

	ELEM *elem = head->first;
	return elem;
}

int empty_Stack(HEAD *head)
{
	ELEM *elem = head->first;
	if (head == NULL)
		return -1;

	if (head->len == 0)
	{
		printf("Stack ist leer\n");
		return -2;
	}

	while (elem != NULL)
	{
		printf("%c, ", elem->wert);
		elem = elem->next;
	}

	elem = head->last;
	while (head->len > 1)
	{
		head->last = elem->prev;
		head->last->next = NULL;
		head->len--;
		free(elem);
		elem = head->last;
	}
	while (head->len == 1)
	{
		elem = head->first;
		free(elem);
		head->len = 0;
		head->first = NULL;
		head->last = NULL;
	}
	return 0;
}

int fill_Stack(HEAD *head, const char *s)
{
	if (head == NULL)
		return -1;
	if (s == NULL)
		return -2;
	while (*s != '\0')
	{
		push(head, *s);
		s++;
	}
	return 0;
}