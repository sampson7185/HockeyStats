#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

/*inserts a skater into linked list of skaters, if head is unassigned, assigns target to head*/
void insertSkater(skater **head, skater *target);
void printSkatersVerbose(skater *head);
void printSkatersGridFormat(skater *head, int longestName);
void checkDoubleDigit2space(int target);
void checkDoubleDigit3space(int target);
void checkTripleDigit(int target);
void checkPlusMinus(int target);
void checkFloatLength(float target);
void checkQuadDigit(int target);
