#pragma once
typedef struct baum
{
	char elem;
	struct baum *links;
	struct baum *rechts;
}BAUM;

BAUM *create_Baum(char, BAUM *);
void print_inorder(BAUM *);
void print_postorder(BAUM *);
void print_preorder(BAUM *);
char *durchsucheWurzel(char *);