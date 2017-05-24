#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "linkedList.h"

void readSkaterFile(char *fileName);
skater *tokenizeSkater(char *buffer);
float convertSecondtoDecimal(char *target);
