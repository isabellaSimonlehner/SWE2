#pragma once
#include  <WinSock2.h>
#include "Baum_Header.h"

void Fehlerausgabe(const char*);
void Hilfe(void);
void client_header(void);
void server_header(void);
void echo(SOCKET*, KNOTEN*);