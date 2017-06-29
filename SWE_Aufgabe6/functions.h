#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "image_header.h"

void readimage(char *pfad, IMAGE *image)
{
	FILE *fp;
	fp = fopen(pfad, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "File konnte nicht geoeffnet werden\n");
		exit(-1);
	}

	fscanf(fp, "P%d\n", &image->typ);
	printf("Der Typ ist: %d\n", image->typ);

	fscanf(fp, "#%s\n", &image->beschreibung);
	printf("Dateiname: %s\n", image->beschreibung);
	
	fscanf(fp, "%d \t %d\n", &image->breite, &image->hoehe);
	printf("Anzahl der Zeilen: %d \t Anzahl der Spalten: %d\n", image->hoehe, image->breite);

	fscanf(fp, "%d\n", &image->max);
	printf("Höchster Wert: %d\n", image->max);

	int i, j;
	int img[image->hoehe][image->breite];
	for (i = 0; i < image->hoehe; i++)
	{
		for (j = 0; j < image->breite; j++)
		{
			int tmp;
			fscanf(fp, "%d\t", &tmp);
			img[i][j] = tmp;
			printf("%d\t", img[i][j]);
		}
		fscanf(fp, "\n");
		printf("\n");
	}
	fclose(fp);
}


void safeimage(IMAGE *image)
{
	int i, j;
	FILE *fp_out = fopen("bw.pgm", "w");
	if (fp_out == NULL)
	{
		fprintf(stderr, "Datei konnte nicht geöffnet werden\n");
		exit(-2);
	}

	int img[image->hoehe][image->breite];

	fputs("P2\n#", fp_out);
	fprintf(fp_out, "%s\n", image->beschreibung);
	fprintf(fp_out, "%d \t %d\n", sizeof(img[0]) / sizeof(int), sizeof(img) / sizeof(img[0]));
	fprintf(fp_out, "%d\n", 1);

	for (i = 0; i < image->hoehe; i++)
	{
		for (j = 0; j < image->breite; j++)
		{
			if (img[i][j] > (image->max / 2))
			{
				fprintf(fp_out, "1\t");
			}
			else
			{
				fprintf(fp_out, "0\t");
			}
		}
		fprintf(fp_out, "\n");
	}
	fclose(fp_out);
}