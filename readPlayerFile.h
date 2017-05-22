#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "linkedList.h"

typedef enum { false, true } bool;

void readSkaterFile(char *fileName);
skater *tokenizeSkater(char *buffer);
float convertSecondtoDecimal(char *target);
