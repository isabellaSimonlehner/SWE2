#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Baum_Header.h"

BAUM *create_Baum(char elem, BAUM *baum)
{
	if (baum == NULL)
	{
		baum = (BAUM*)malloc(sizeof(BAUM));
		if (baum == NULL)
		{
			printf("Fehler bei Speicherallokierung\n");
			return NULL;
		}
		baum->links = NULL;
		baum->rechts = NULL;
		baum->elem = elem;
	}
	else if (baum->elem > elem)
	{
		baum->links = create_Baum(elem, baum->links);
	}
	else
	{
		baum->rechts = create_Baum(elem, baum->rechts);
	}
	return baum;
}


void print_preorder(BAUM *baum)
{
	if (baum == NULL)
	{
		printf("Baum ist leer\n");
		return;
	}
	else
	{
		printf("%d, ", baum->elem);
		print_preorder(baum->links);
		print_preorder(baum->rechts);
	}
}


void print_inorder(BAUM *baum)
{
	if (baum == NULL)
	{
		printf("Baum ist leer\n");
		return;
	}
	else
	{
		print_inorder(baum->links);
		printf("%d, ", baum->elem);
		print_inorder(baum->rechts);
	}
}


void print_postorder(BAUM *baum)
{
	if (baum == NULL)
	{
		printf("Baum ist leer\n");
		return;
	}
	else
	{
		print_postorder(baum->links);
		print_postorder(baum->rechts);
		printf("%d, ", baum->elem);
	}
}


char *durchsuche_Baum(char *exp)
{
	int counter = 0;
	while (*exp != '\0')
	{
		if (*exp == '(')
		{
			counter++;
		}
		else if (*exp == ')')
		{
			counter--;
		}
		else if ((*exp == '+' || *exp == '-' || *exp == '/' || *exp == '*') && counter == 0)
		{
			return exp;
		}
		exp++;
	}
	return NULL;
}