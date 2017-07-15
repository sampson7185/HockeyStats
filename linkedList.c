#include "linkedList.h"

/*inserts a skater into linked list of skaters, if head is unassigned, assigns target to head*/
void insertSkater(skater **head, skater *target) {
    skater *ptr;

    if ((*head) == NULL)
        (*head) = target;
    else {
        if ((*head)->next == NULL)
            (*head)->next = target;
        else {
            ptr = (*head);
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = target;
        }
    }
}

void printSkatersVerbose(skater *head) {
    skater *ptr;
    float avgIceTime;

    ptr = head;
    while (ptr->next != NULL) {
        avgIceTime = ptr->avgIceTimeI + ptr->avgIceTimeF;
        printf("Name: %s %s\nAge: %d\nPosition: %s\nTeam: %s\nGames Played: %d\n\
Goals: %d\nAssists: %d\nPoints: %d\nPlus-Minus: %d\nPenalty Minutes: %d\n\
5v5 Goals: %d\nPowerplay Goals: %d\nShorthanded Goals: %d\n\
Game Winning Goals: %d\n5v5 Assists: %d\nPowerplay Assists: %d\n\
Shorthanded Assists: %d\nShots: %d\nShooting Percentage: %.1f\n\
Ice Time: %d minutes\nAverage Ice Time: %.2f\nBlocks: %d\nHits: %d\n\
Faceoff Wins: %d\nFaceoff Losses: %d\nFaceoff Percentage: %.1f\n",
        ptr->firstName, ptr->lastName, ptr->age, ptr->position, ptr->team,
        ptr->gamesPlayed, ptr->goals, ptr->assists, ptr->points, ptr->plusMinus,
        ptr->penaltyMinutes, ptr->goals5v5, ptr->PPgoals, ptr->SHgoals,
        ptr->gameWinningGoals, ptr->assists5v5, ptr->PPassists, ptr->SHassists,
        ptr->shots, ptr->shootingPercentage, ptr->iceTime, avgIceTime,
        ptr->blocks, ptr->hits, ptr->faceoffWins, ptr->faceoffLosses,
        ptr->faceoffPercentage);
        ptr = ptr->next;
    }
}

void printSkatersGridFormat(skater *head, int longestName) {
    skater *ptr;
    int i;
    float avgIceTime;

    ptr = head;
    printf("Name");
    for (i = 0; i <= longestName; i++) {
        printf(" ");
    }
    printf("Age Pos Team GP G A P +/- PM G5V5 PPG SHG GWG A5V5 PPA SHA SH SH%% IT AIT BLK HIT FOW FOL FO%%\n");
    /*while (ptr->next != NULL) {
        avgIceTime = ptr->avgIceTimeI + ptr->avgIceTimeF;
        printf("%s\n", );
    }*/
}
