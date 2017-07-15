#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "linkedList.h"

void readSkaterFile(char *fileName);
skater *tokenizeSkater(char *buffer, int *longestName);
float convertSecondtoDecimal(char *target);
int convertInt(char *target);
float convertFloat(char *target);
skater *createSkater();
