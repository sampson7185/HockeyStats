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
    int nameBuffer, positionBuffer;

    ptr = head;
    printf("Name");
    for (i = 0; i < longestName - 2; i++) {
        printf(" ");
    }
    printf("Age Pos   Team GP G  A  P   +/-  PM  G5V5 PPG SHG GWG A5V5 PPA SHA SH  SH%% IT   AIT BLK HIT FOW FOL FO%%\n");
    while (ptr->next != NULL) {
        avgIceTime = ptr->avgIceTimeI + ptr->avgIceTimeF;
        nameBuffer = longestName - (strlen(ptr->firstName) + strlen(ptr->lastName) + 1);
        positionBuffer = 6 - strlen(ptr->position);
        printf("%s %s ", ptr->firstName, ptr->lastName);
        for (i = 0; i <= nameBuffer; i++) {
            printf(" ");
        }
        printf("%d  %s", ptr->age, ptr->position);
        for (i = 0; i < positionBuffer; i++) {
            printf(" ");
        }
        printf("%s  %d", ptr->team, ptr->gamesPlayed);
        checkDoubleDigit2space(ptr->gamesPlayed);
        printf("%d", ptr->goals);
        checkDoubleDigit2space(ptr->goals);
        printf("%d", ptr->assists);
        checkDoubleDigit2space(ptr->assists);
        printf("%d", ptr->points);
        checkTripleDigit(ptr->points);
        printf("%d", ptr->plusMinus);
        checkPlusMinus(ptr->plusMinus);
        printf("%d", ptr->penaltyMinutes);
        checkTripleDigit(ptr->penaltyMinutes);
        printf("%d", ptr->goals5v5);
        checkDoubleDigit3space(ptr->goals5v5);
        printf(" ");
        printf("%d", ptr->PPgoals);
        checkDoubleDigit3space(ptr->PPgoals);
        printf("%d", ptr->SHgoals);
        checkDoubleDigit3space(ptr->SHgoals);
        printf("%d", ptr->gameWinningGoals);
        checkDoubleDigit3space(ptr->gameWinningGoals);
        printf("%d", ptr->assists5v5);
        checkDoubleDigit3space(ptr->assists5v5);
        printf(" ");
        printf("%d", ptr->PPassists);
        checkDoubleDigit3space(ptr->PPassists);
        printf("%d", ptr->SHassists);
        checkDoubleDigit3space(ptr->SHassists);
        printf("%d", ptr->shots);
        checkTripleDigit(ptr->shots);
        printf("\n");
        ptr = ptr->next;
    }
}

void checkDoubleDigit2space(int target) {
    if (target / 10 > 0) {
        printf(" ");
    }
    else {
        printf("  ");
    }
}

void checkDoubleDigit3space(int target) {
    if (target / 10 > 0) {
        printf("  ");
    }
    else {
        printf("   ");
    }
}

void checkTripleDigit(int target) {
    if (target / 100 > 0) {
        printf(" ");
    }
    else if (target / 10 > 0) {
        printf("  ");
    }
    else {
        printf("   ");
    }
}

void checkPlusMinus(int target) {
    if (target < 0) {
        if (target / 10 < 0) {
            printf("  ");
        }
        else {
            printf("   ");
        }
    }
    else if (target / 10 > 0) {
        printf("   ");
    }
    else {
        printf("    ");
    }
}
