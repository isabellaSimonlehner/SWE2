#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Baum_Header.h"
#define M_MAX 1024

KNOTEN *erstelle_Binaerbaum(char c, const char *str, KNOTEN *knoten)
{
	if (knoten == NULL)		//kontrolle ob schon elemente im knoten sind
	{
		knoten = (KNOTEN*)malloc(sizeof(KNOTEN));//speicherallokierung für knoten
		if (NULL == knoten)//fehlerüberprüfung ob speicherallokierung funktioniert hat
		{
			fprintf(stderr, "Fehler bei Speicherallokierung\n");
			return NULL;
		}
		knoten->character = c;  //c als character in knoten struct deklarieren
		int len = strlen(str); //länge deklarieren durch strln von string
		strncpy(knoten->str, str, len + 1); //string von struct knoten in string von funktion kopieren
		knoten->links = NULL; //linker knoten ist leer
		knoten->rechts = NULL; //rechter knoten ist leer
	}
	else if (*str == '.') //wenn string . enthält dann wird...
	{
		str++; //string erhöht
		knoten->links = erstelle_Binaerbaum(c, str, knoten->links); //und link ein neuer knoten erstellt
	}
	else if (*str == '-')//wenn string - enthält dann wird...
	{
		str++; //string erhöht
		knoten->rechts = erstelle_Binaerbaum(c, str, knoten->rechts); //und rechts ein neuer knoten erstellt
	}
	return knoten; //knoten wird zurückgegeben
}


KNOTEN *erstelle_Morscodebaum(void)
{
	char *morscode[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
						"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
						"..-", "...-", ".--", "-..-", "--..", "-----", ".----", "..---", "...--",
						"....-", ".....", "-....", "--...", "---..", "----.", ".-.-.", "-..-.", "-...-" };
	KNOTEN *root;
	root = erstelle_Binaerbaum('#', "START", root);
	if (NULL != root)
	{//linker ast
		erstelle_Binaerbaum('E', morscode[4], root);
		erstelle_Binaerbaum('I', morscode[8], root);
		erstelle_Binaerbaum('A', morscode[0], root);
		erstelle_Binaerbaum('S', morscode[18], root);
		erstelle_Binaerbaum('U', morscode[20], root);
		erstelle_Binaerbaum('R', morscode[17], root);
		erstelle_Binaerbaum('W', morscode[22], root);
		erstelle_Binaerbaum('H', morscode[7], root);
		erstelle_Binaerbaum('v', morscode[21], root);
		erstelle_Binaerbaum('F', morscode[5], root);
		erstelle_Binaerbaum('$', "..--$", root);
		erstelle_Binaerbaum('L', morscode[11], root);
		erstelle_Binaerbaum('$', ".-.-$", root);
		erstelle_Binaerbaum('P', morscode[15], root);
		erstelle_Binaerbaum('J', morscode[9], root);
		erstelle_Binaerbaum('5', morscode[31], root);
		erstelle_Binaerbaum('4', morscode[30], root);
		erstelle_Binaerbaum('3', morscode[29], root);
		erstelle_Binaerbaum('2', morscode[28], root);
		erstelle_Binaerbaum('+', morscode[36], root);
		erstelle_Binaerbaum('1', morscode[27], root);

		//rechter ast
		erstelle_Binaerbaum('T', morscode[19], root);
		erstelle_Binaerbaum('N', morscode[13], root);
		erstelle_Binaerbaum('M', morscode[12], root);
		erstelle_Binaerbaum('D', morscode[3], root);
		erstelle_Binaerbaum('K', morscode[10], root);
		erstelle_Binaerbaum('G', morscode[6], root);
		erstelle_Binaerbaum('O', morscode[14], root);
		erstelle_Binaerbaum('B', morscode[1], root);
		erstelle_Binaerbaum('X', morscode[23], root);
		erstelle_Binaerbaum('C', morscode[2], root);
		erstelle_Binaerbaum('Y', morscode[24], root);
		erstelle_Binaerbaum('Z', morscode[25], root);
		erstelle_Binaerbaum('Q', morscode[16], root);
		erstelle_Binaerbaum('$', "---.$", root);
		erstelle_Binaerbaum('$', "----$", root);
		erstelle_Binaerbaum('6', morscode[32], root);
		erstelle_Binaerbaum('=', morscode[38], root);
		erstelle_Binaerbaum('/', morscode[37], root);
		erstelle_Binaerbaum('7', morscode[33], root);
		erstelle_Binaerbaum('8', morscode[34], root);
		erstelle_Binaerbaum('9', morscode[35], root);
		erstelle_Binaerbaum('0', morscode[26], root);

		return root;
	}
	return NULL;
}


char *schreibe_Morscode(const char *str)
{
	if (str == NULL)
	{
		fprintf(stderr, "Fehler mit string pointer\n");
		return NULL;
	}

	char *morscode[] = { ".-$", "-...$", "-.-.$", "-..$", ".$", "..-.$", "--.$", "....$",
						"..$", ".---$", "-.-$", ".-..$", "--$", "-.$", "---$", ".--.$",
						"--.-$", ".-.$", "...$", "-$", "..-$", "...-$", ".--$", "-..-$"
						"-.--$", "--..$", "-----$", ".----$", "..---$", "...--$", "....-$",
						".....$", "-....$", "--...$", "---..$", "----.$", ".-.-.$", "-..-.$", "-...-$" };
	char *msg = (char*)calloc(M_MAX, sizeof(char));
	if (msg == NULL)
	{
		fprintf(stderr, "Fehler mit Nachrichten pointer\n");
		return NULL;
	}

	while (*str != '\0')
	{
		if (*str == 'A' || *str == 'a')
		{
			strncat(msg, morscode[0], 4);
		}
		else if (*str == 'B' || *str == 'b')
		{
			strncat(msg, morscode[1], 6);
		}
		else if (*str == 'C' || *str == 'c')
		{
			strncat(msg, morscode[2], 6);
		}
		else if (*str == 'D' || *str == 'd')
		{
			strncat(msg, morscode[3], 5);
		}
		else if (*str == 'E' || *str == 'e')
		{
			strncat(msg, morscode[4], 3);
		}
		else if (*str == 'E' || *str == 'e') 
		{
			strncat(msg, morscode[4], 3);
		}
		else if (*str == 'F' || *str == 'f') 
		{
			strncat(msg, morscode[5], 6);
		}
		else if (*str == 'G' || *str == 'g') 
		{
			strncat(msg, morscode[6], 5);
		}
		else if (*str == 'H' || *str == 'h') 
		{
			strncat(msg, morscode[7], 6);
		}
		else if (*str == 'I' || *str == 'i') 
		{
			strncat(msg, morscode[8], 4);
		}
		else if (*str == 'J' || *str == 'j') 
		{
			strncat(msg, morscode[9], 6);
		}
		else if (*str == 'K' || *str == 'k') 
		{
			strncat(msg, morscode[10], 5);
		}
		else if (*str == 'L' || *str == 'l') 
		{
			strncat(msg, morscode[11], 6);
		}
		else if (*str == 'M' || *str == 'm') 
		{
			strncat(msg, morscode[12], 4);
		}
		else if (*str == 'N' || *str == 'n') 
		{
			strncat(msg, morscode[13], 4);
		}
		else if (*str == 'O' || *str == 'o') 
		{
			strncat(msg, morscode[14], 5);
		}
		else if (*str == 'P' || *str == 'p') 
		{
			strncat(msg, morscode[15], 6);
		}
		else if (*str == 'Q' || *str == 'q') 
		{
			strncat(msg, morscode[16], 6);
		}
		else if (*str == 'R' || *str == 'r') 
		{
			strncat(msg, morscode[17], 5);
		}
		else if (*str == 'S' || *str == 's') 
		{
			strncat(msg, morscode[18], 5);
		}
		else if (*str == 'T' || *str == 't') 
		{
			strncat(msg, morscode[19], 3);
		}
		else if (*str == 'U' || *str == 'u') 
		{
			strncat(msg, morscode[20], 5);
		}
		else if (*str == 'V' || *str == 'v') 
		{
			strncat(msg, morscode[21], 6);
		}
		else if (*str == 'W' || *str == 'w') 
		{
			strncat(msg, morscode[22], 5);
		}
		else if (*str == 'X' || *str == 'x') 
		{
			strncat(msg, morscode[23], 6);
		}
		else if (*str == 'Y' || *str == 'y') 
		{
			strncat(msg, morscode[24], 6);
		}
		else if (*str == 'Z' || *str == 'z') 
		{
			strncat(msg, morscode[25], 6);
		}
		else if (*str == '0') 
		{
			strncat(msg, morscode[26], 7);
		}
		else if (*str == '1') 
		{
			strncat(msg, morscode[27], 7);
		}
		else if (*str == '2') 
		{
			strncat(msg, morscode[28], 7);
		}
		else if (*str == '3') 
		{
			strncat(msg, morscode[29], 7);
		}
		else if (*str == '4') 
		{
			strncat(msg, morscode[30], 7);
		}
		else if (*str == '5') 
		{
			strncat(msg, morscode[31], 7);
		}
		else if (*str == '6') 
		{
			strncat(msg, morscode[32], 7);
		}
		else if (*str == '7') 
		{
			strncat(msg, morscode[33], 7);
		}
		else if (*str == '8') 
		{
			strncat(msg, morscode[34], 7);
		}
		else if (*str == '9') 
		{
			strncat(msg, morscode[35], 7);
		}
		else if (*str == '+') 
		{
			strncat(msg, morscode[36], 7);
		}
		else if (*str == '/') 
		{
			strncat(msg, morscode[37], 7);
		}
		else if (*str == '=') 
		{
			strncat(msg, morscode[38], 7);
		}
		else 
		{
			strncat(msg, "$", 2);             //undefiniertes symbol
		}
		str++;
	}
	msg[strlen(msg) + 1] = '\0'; //string "leeren"
	return msg;
}


int lese_Morscode(const char *str, KNOTEN *wurzel)
{
	if (str == NULL)//fehlerkontrolle ob string befüllt ist
	{
		fprintf(stderr, "Fehler mit string\n");
		return -1;
	}

	while (*str != '\0') //solange bis ende von string
	{
		durchsuche_Character(str, wurzel);
		while (*str != '$') //nächsten char suchen
		{
			str++;
		}
		str++;
	}
	return 0;
}


void printe_Morscode(KNOTEN *knoten)
{
	if (knoten->links != NULL)
	{
		printe_Morscode(knoten->links);
	}
	if (knoten != NULL)
	{
		fprintf(stdout, "Pointer: %p, Character: %c \n", knoten, knoten->character);
	}
	if (knoten->rechts != NULL)
	{
		printe_Morscode(knoten->rechts);
	}
}


KNOTEN *durchsuche_Character(const char *str, KNOTEN *wurzel)
{
	if (str == NULL || wurzel == NULL)
	{
		fprintf(stderr, "Fehler mit pointer\n");
		return NULL;
	}

	if (*str == '$')
	{
		fprintf(stdout, " ");
		return wurzel;
	}
	KNOTEN *knoten;
	if (*str == '.')
	{
		knoten = wurzel->links;
		str++;
	}

	while (*str != '$')
	{
		if (*str == '.')
		{
			knoten = knoten->links;
		}
		else if (*str == '-')
		{
			knoten = knoten->rechts;
		}
		str++;
	}
	fprintf(stdout, "%c", knoten->character);
	return knoten;
}