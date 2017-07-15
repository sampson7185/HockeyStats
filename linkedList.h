#include <stdlib.h>
#include <stdio.h>
#include "player.h"

/*inserts a skater into linked list of skaters, if head is unassigned, assigns target to head*/
void insertSkater(skater **head, skater *target);
void printSkatersVerbose(skater *head);
void printSkatersGridFormat(skater *head, int longestName);
