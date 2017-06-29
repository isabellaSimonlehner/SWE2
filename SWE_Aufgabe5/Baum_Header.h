#pragma once

typedef struct knoten
{
	char character;
	char str[7];		//Morscode
	struct knoten *rechts; //rechter pointer -
	struct knoten *links; //linker pointer .
}KNOTEN;

typedef struct wurzel
{
	char str[6];
	int len;
	KNOTEN *links; //pointer zu links
	KNOTEN *rechts; //pointer zu rechts
}WURZEL;

KNOTEN *erstelle_Binaerbaum(char, const char*, KNOTEN*);
KNOTEN *erstelle_Morscodebaum(void);
char *schreibe_Morscode(const char*);
int lese_Morscode(const char*, KNOTEN*);
void printe_Morscode(KNOTEN*);
KNOTEN *durchsuche_Character(const char*, KNOTEN*);
