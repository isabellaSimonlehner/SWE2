

typedef union char_or_int
{
	int num;
	char sym;
}DATA;

typedef struct elem
{
	struct elem *next;
	DATA item;
}ELEM;

typedef struct head
{
	ELEM *first;
	ELEM *last;
	int len;
}HEAD;

typedef struct stack
{
	ELEM *next;
	ELEM *last;
	int len;
}STACK;


HEAD *create_dequeue(void);		//erstellen der dequeue
STACK *create_stack(void);		//erstellen von stack
ELEM *push(STACK*);		//LIFO - Stack -> F�gt vorne neues element hinzu
ELEM *enqueue(HEAD*);		//FIFO - Liste -> f�gt vorne neues element hinzu
ELEM *dequeue(HEAD*);		//FIFO - Liste -> gibt letzte element zur�ck und l�scht es aus liste
ELEM *pop(STACK*);			//LIFO - Stack -> gibt erste element zur�ck und l�scht es aus liste 
ELEM *front(HEAD*);		//FIFO - Liste -> gibt letzte element zur�ck ohne es aus liste zu l�schen
ELEM *top(STACK*);			//LIFO - Stack -> gibt erste element zur�ck ohne es aus liste zu l�schen
ELEM *back(HEAD*);		//FIFO - Liste -> gibt erste element zur�ck ohne es aus liste zu l�schen
