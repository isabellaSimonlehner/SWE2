#pragma once
typedef struct element
{
	char wert;
	struct element *prev;
	struct element *next;
}ELEM;

typedef struct header
{
	int len;
	ELEM *first;
	ELEM *last;
}HEAD;

HEAD *create_Stack(void);
ELEM *push(HEAD *, char);
ELEM *pop(HEAD *);
ELEM *top(HEAD *);
int empty_Stack(HEAD *);
ELEM *to_outputstack(char *);
int fill_Stack(HEAD *, const char*);