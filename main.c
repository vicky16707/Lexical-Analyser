
#include "lexer.h"

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2)
    {
        printf("Usage: ./lexer input.c\n");
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    printf("TOKEN\t\tTOKEN TYPE\n");
    printf("-----------------------------\n");

    identifyToken(fp);

    fclose(fp);

    return 0;
}
