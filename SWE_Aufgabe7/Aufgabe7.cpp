#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Baum_Header.h"
#include "parser_Header.h"
#include "Stack_Header.h"
#define SIZE 100


int main()
{
	bool result;
	char string[SIZE];

	FILE *fp = fopen("log.txt", "w");
	if (fp == NULL)
	{
		printf("File konnte nicht geöffnet werden\n");
		return -1;
	}

	FILE *fp1 = fopen("expression.txt", "r");
	if (fp1 == NULL)
	{
		printf("File konnte nicht geöffnet werden\n");
		return -2;
	}

	fgets(string, SIZE - 1, fp1);
	fprintf(fp, "Parsen gestartet\n");
	printf("Parsen gestartet\n");

	s = string;
	result = expression(fp);
	if (result == false)
	{
		fprintf(fp, "Kein arithmetischer Ausdruck gefunden\n");
		printf("Kein arithmetischer Ausdruck gefunden\n");
	}
	else if(result == true)
	{
		fprintf(fp, "Arithmetischer Ausdruck gefunden\n");
		printf("Arithmetischer Ausdruck gefunden\n");
	}

	HEAD *inputStack = create_Stack();
	if (inputStack == NULL)
	{
		fprintf(fp, "Fehler mit Stack Erstellung\n");
		printf("Fehler mit Stack Erstellung\n");
		return -4;
	}

	HEAD *operatorStack = create_Stack();
	if (operatorStack == NULL)
	{
		fprintf(fp, "Fehler mit Stack Erstellung\n");
		printf("Fehler mit Stack Erstellung\n");
		return -5;
	}

	HEAD *outputstack = create_Stack();
	if (outputstack == NULL)
	{
		fprintf(fp, "Fehler mit Stack Erstellung\n");
		printf("Fehler mit Stack Erstellung\n");
		return -6;
	}

	fill_Stack(inputStack, string);
	empty_Stack(inputStack);

	printf("Test\n");
	fputs(string, stdout);
	char *test = durchsucheWurzel(string);
	BAUM *wurzel = create_Baum(*test, NULL);
	printf("\n%c\n", wurzel->elem);

	printf("Reversed polnish notation: \n");
	print_postorder(wurzel);

	printf("Infix notation: \n");
	print_inorder(wurzel);

	fclose(fp);
	fclose(fp1);

    return 0;
}

