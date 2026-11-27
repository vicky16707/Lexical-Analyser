
#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int isKeyword(char *word);
void identifyToken(FILE *fp);

#endif
