#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define MAX 30

int main()
{
	char filename[MAX];
	printf("Geben sie den Dateinamen ein: ");
	fgets(filename, MAX - 1, stdin);
	filename[strlen(filename) - 1] = '\0';
	IMAGE image;
	readimage(filename, &image);
	safeimage(&image);

    return 0;
}

