#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <time.h>
#include "Baum_Header.h"
#include "Server_u._Client_Header.h"
#define BUFFER 1024

void Fehlerausgabe(const char *msg)
{
	time_t c_time;
	time(&c_time);
	fprintf(stdout, "%s : %d | time: %s\n", msg, WSAGetLastError(), ctime(&c_time));
}

void Hilfe(void)
{
	fprintf(stdout, "           [argv]\n");
	fprintf(stdout, "Start Server: ....\n");
	fprintf(stdout, "Start Client \n");
}

void client_header(void)
{
	time_t c_time;
	fprintf(stdout, "Client ready! Connection created\n");
	fprintf(stdout, "-------------------------------\n");
	time(&c_time);
	fprintf(stdout, "Time: %s\n", ctime(&c_time));
	fprintf(stdout, "Welcome\n");
}

void server_client(void)
{
	time_t c_time;
	fprintf(stdout, "Server ready! Waiting for requests....\n");
	fprintf(stdout, "--------------------------------------\n");
	time(&c_time);
	fprintf(stdout, "Time: %s\n", ctime(&c_time));
	fprintf(stdout, "Welcome\n");
}

void echo(SOCKET *client, KNOTEN *wurzel)
{
	char buffer[BUFFER];
	int recv_size;
	time_t c_time;

	recv_size = recv(client, buffer, BUFFER, 0);
	if (recv_size < 0)
	{
		Fehlerausgabe("Fehler mit recv()\n");
	}
	buffer[recv_size] = '\0';
	lese_Morscode(buffer, wurzel);
	time(&c_time);
	fprintf(stdout, " | %s\n", ctime(&c_time));
}