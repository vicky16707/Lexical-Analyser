
#include "lexer.h"

int isKeyword(char *word)
{
    char *keywords[] = {
        "int", "float", "char", "double", "if",
        "else", "while", "for", "return", "void"
    };

    int i;

    for (i = 0; i < 10; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

void identifyToken(FILE *fp)
{
    int ch, i;
    char word[SIZE];

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isspace(ch))
            continue;

        if (isalpha(ch) || ch == '_')
        {
            i = 0;

            while (isalnum(ch) || ch == '_')
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';
            ungetc(ch, fp);

            if (isKeyword(word))
                printf("%s\tKeyword\n", word);
            else
                printf("%s\tIdentifier\n", word);
        }

        else if (isdigit(ch))
        {
            i = 0;

            while (isdigit(ch) || ch == '.')
            {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';
            ungetc(ch, fp);

            if (strchr(word, '.') != NULL)
                printf("%s\tFloat Literal\n", word);
            else
                printf("%s\tInteger Literal\n", word);
        }

        else if (ch == '\'')
        {
            printf("\tCharacter Literal\n");

            while ((ch = fgetc(fp)) != '\'' && ch != EOF);
        }

        else if (ch == '"')
        {
            printf("\tString Literal\n");

            while ((ch = fgetc(fp)) != '"' && ch != EOF);
        }

        else if (strchr("+-*/%=<>!", ch))
            printf("%c\tOperator\n", ch);

        else if (ch == '[' || ch == ']' ||
                 ch == ';' || ch == ',' ||
                 ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}')
            printf("%c\tSpecial Symbol\n", ch);
    }
}
