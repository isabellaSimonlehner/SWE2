/*Implementieren Sie Server-Client-Applikation bei der Server mit mehreren Clients
Textnachrichten austauschen kann. Übertragung der Zeichen soll im Morsecode-Alphabet 
geschehen. Dazu besitzen Server und clients jeweils Binärbaum der die Transformation
zw. Ascii-Zeichen und Morsecode übernimmt

Jeder Schritt nach links entspricht dabei einem Punkt und jeder Schritt nach rechts 
einen Strich. Zeichen "A" entspricht daher Code ".-" und "Z" dem Code "--.."
So kann mittels Baumes in beide Richtungen "übersetzt" werden
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <WinSock2.h>
#include <time.h>
#include "Binärbaum_functins.h"
#include "server_u._client_functions.h"

#define SENBUFFER 1024
#define RCVBUFFER 1024
#define PORT 666

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		WORD wVersionRequested;
		WSADATA wsaData;
		wVersionRequested = MAKEWORD(1, 1);
		if (WSAStartup(wVersionRequested, &wsaData) != 0)
		{
			Fehlerausgabe("Fehler mit Winsock Initialisierung\n");
		}
		else
		{
			printf("Winsock initliaisiert\n");
		}


		char *echo_str;
		char buffer[RCVBUFFER];
		SOCKET sock;
		SOCKADDR_IN server;
		unsigned long addr;
		int buff_len, echo_len;

		sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 1)
		{
			Fehlerausgabe("Socketerzeugung fehlgeschlagen\n");
			return -1;
		}

		memset(&server, 0, sizeof(server));
		if ((addr = inet_addr(argv[1])) != INADDR_NONE)
		{
			memcpy((char*)&server.sin_addr, &addr, sizeof(addr));
		}
		server.sin_family = AF_INET;
		server.sin_port = htons(PORT);

		if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
		{
			Fehlerausgabe("Kann keine Verbindung mit Server aufnehmen\n");
			return -3;
		}

		client_header();

		while (1)
		{
			fgets(buffer, RCVBUFFER, stdin);
			buff_len = strlen(buffer);
			buffer[buff_len - 1] = '\0';
			if (strcmp(buffer, "exit") == 0)
			{
				break;
			}
			echo_str = schreibe_Morscode(buffer);
			echo_len = strlen(echo_str);
			echo_str[echo_len] = '\0';
			if (send(sock, echo_str, echo_len, 0) != echo_len)
			{
				Fehlerausgabe("Fehler, mehr Bytes als erwartet\n");
			}
		}

		closesocket(sock);
		return 0;
	}

	else if (argc == 1)
	{
		WORD wVersionRequested;
		WSADATA wsaData;
		wVersionRequested = MAKEWORD(1, 1);
		if (WSAStartup(wVersionRequested, &wsaData) != 0)
		{
			Fehlerausgabe("Fehler mit Winsock Initialisierung\n");
		}
		else
		{
			printf("Winsock initlialisiert\n");
		}

		SOCKET sock, fd;
		SOCKADDR_IN server, client;
		int len;
		KNOTEN *wurzel = erstelle_Morscodebaum();

		sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sock < 1)
		{
			Fehlerausgabe("Socket konnte nicht erstellt werden\n");
			return -1;
		}

		memset(&server, 0, sizeof(server));
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = htonl(INADDR_ANY);
		server.sin_port = htons(PORT);

		if (bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
		{
			Fehlerausgabe("Socket konnte nicht gebunden werden\n");
			return -2;
		}

		if (listen(sock, 5) == -1)
		{
			Fehlerausgabe("Fehler bei listen\n");
			return -3;
		}

		server_header();

		for (;;)
		{
			len = sizeof(client);
			fd = accept(sock, (struct sockaddr*) &client, &len);
			if (fd < 0)
			{
				Fehlerausgabe("Fehler bei akzeptieren\n");
				return -4;
			}
			printf("Bearbeite Auftrag von Client mit Addresse: %s\n", inet_ntoa(client.sin_addr));
			echo(fd, wurzel);
		}
		closesocket(sock);
		return 0;
	}
    return 1;
}

