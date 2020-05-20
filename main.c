#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syntaxchecker.c"
#include "autoindent.c"

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("\nUSAGE : ./a.out Filename");
        exit(0);
    }
	printf("\nCode Summary:\n");
	printf("=====================================================\n");
    summarize(argv[1]);

	printf("\n\n\nIndentation Check:\n");
    indent(argv[1]);
}
