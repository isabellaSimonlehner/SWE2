#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser_Header.h"

bool expression(FILE *fp)
{
	if (term(fp) == true)
	{
		if (*s == '+' || *s == '-')
		{
			s++;
			if (expression(fp) == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	return false;
}


bool term(FILE *fp)
{
	if (factor(fp) == true)
	{
		if (*s == '*' || *s == '/')
		{
			s++;
			if (term(fp) == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	return false;
}


bool factor(FILE *fp)
{
	if (constant(fp) == true)
	{
		return true;
	}
	if (var(fp) == true)
	{
		return true;
	}
	if (*s == '(')
	{
		s++;
		if (expression(fp) == true)
		{
			if (*s == ')')
			{
				s++;
				if (*s == '\0')
				{
					fprintf(fp, "Ende des Strings erreicht\n");
					fprintf(stdout, "Ende des Strings erreicht\n");
					return true;
				}
				return true;
			}
		}
	}
	return false;
}


bool var(FILE *fp)
{
	if (*s >= 'a' && *s <= 'f')
	{
		fprintf(fp, "Wert gefunden: %c\n", *s);
		fprintf(stdout, "Wert gefunden: %s\n", *s);
		s++;
		if (*s == '\0')
		{
			fprintf(fp, "Ende des Strings erreicht\n");
			fprintf(stdout, "Ende des Strings erreicht\n");
			return true;
		}
		return true;
	}
	fprintf(fp, "Keinen Wert gefunden\n");
	return false;
}


bool constant(FILE *fp)
{
	if (digit(fp) == true)
	{
		while (digit(fp) == true)
		{
			fprintf(fp, "Konstante gefunden %c\n", *s);
			fprintf(stdout, "Konstante gefunden %c\n", *s);
			s++;
		}
		return true;
	}
	fprintf(fp, "Keine Konstante gefunden %c\n", *s);
	return false;
}

bool digit(FILE *fp)
{
	if (*s >= '0' && *s <= '9')
	{
		fprintf(fp, "Digit gefunden %c\n", *s);
		fprintf(stdout, "Digit gefunden %c\n", *s);
		s++;
		if (*s == '\0')
		{
			fprintf(fp, "Ende des Strings erreicht\n");
			fprintf(stdout, "Ende des Strings erreicht\n");
			return true;
		}
		return true;
	}
	fprintf(fp, "Kein Digit gefunden %c\n", *s);
	return false;
}