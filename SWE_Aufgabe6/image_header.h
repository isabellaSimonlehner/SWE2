#pragma once

typedef struct image
{
	int hoehe;
	int breite;
	char beschreibung[80];
	int typ;
	int max;
}IMAGE;

void readimage(char *pfad, IMAGE *);
void safeimage(IMAGE *);