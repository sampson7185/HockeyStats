#include "readPlayerFile.h"

void readSkaterFile(char *fileName) {
    FILE *skaterFile;
    skater *newSkater;
    skater *head;
    char buffer[255];

    skaterFile = fopen(fileName, "r");

    while(fgets(buffer, 255, skaterFile) != NULL) {
        printf("%s\n", buffer);
        newSkater = tokenizeSkater(buffer);
        /*insertSkater(head, newSkater);*/
    }

    printf("Name: %s %s\nAge: %d\nPosition: %s\nTeam: %s\nGames Played: %d\n\
Goals: %d\nAssists: %d\nPoints: %d\nPlus-Minus: %d\nPenalty Minutes: %d\n\
5v5 Goals: %d\nPowerplay Goals: %d\nShorthanded Goals: %d\n\
Game Winning Goals: %d\n5v5 Assists: %d\nPowerplay Assists: %d\n\
Shorthanded Assists: %d\nShots: %d\nShooting Percentage: %.1f\n\
Ice Time: %d\nAverage Ice Time: %.2f\nBlocks: %d\nHits: %d\n\
Faceoff Wins: %d\nFaceoff Losses: %d\nFaceoff Percentage: %.1f\n",
    newSkater->firstName, newSkater->lastName, newSkater->age,
    newSkater->position, newSkater->team, newSkater->gamesPlayed,
    newSkater->goals, newSkater->assists, newSkater->points,
    newSkater->plusMinus, newSkater->penaltyMinutes, newSkater->goals5v5,
    newSkater->PPgoals, newSkater->SHgoals, newSkater->gameWinningGoals,
    newSkater->assists5v5, newSkater->PPassists, newSkater->SHassists,
    newSkater->shots, newSkater->shootingPercentage, newSkater->iceTime,
    newSkater->avgIceTime, newSkater->blocks, newSkater->hits,
    newSkater->faceoffWins, newSkater->faceoffLosses,
    newSkater->faceoffPercentage);

    fclose(skaterFile);
    return;
}

skater *tokenizeSkater(char *buffer) {
    char *token;
    skater *newSkater;
    char *end;

    newSkater = malloc(sizeof(skater));
    token = strtok(buffer, " ");
    newSkater->firstName = malloc(strlen(token) + 1);
    strcpy(newSkater->firstName, token);
    token = strtok(NULL, ",");
    newSkater->lastName = malloc(strlen(token) + 1);
    strcpy(newSkater->lastName, token);
    token = strtok(NULL, ",");
    newSkater->age = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->position = malloc(strlen(token) + 1);
    strcpy(newSkater->position, token);
    token = strtok(NULL, ",");
    strcpy(newSkater->team, token);
    token = strtok(NULL, ",");
    newSkater->gamesPlayed = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->goals = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->assists = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->points = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->plusMinus = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->penaltyMinutes = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->goals5v5 = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->PPgoals = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->SHgoals = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->gameWinningGoals = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->assists5v5 = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->PPassists = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->SHassists = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->shots = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->shootingPercentage = convertFloat(token);
    token = strtok(NULL, ",");
    newSkater->iceTime = convertInt(token);
    token = strtok(NULL, ":");
    newSkater->avgIceTimeI = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->avgIceTimeF = convertSecondtoDecimal(token);
    token = strtok(NULL, ",");
    newSkater->blocks = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->hits = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->faceoffWins = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->faceoffLosses = convertInt(token);
    token = strtok(NULL, ",");
    newSkater->faceoffPercentage = convertFloat(token);
    return newSkater;
}

float convertSecondtoDecimal(char *target) {
    float converted, temp;

    if (target != NULL) {
        temp = strtod(target, NULL);
        converted = temp / 60.0;
        return converted;
    }
    return NULL;
}

int convertInt(char *token) {
    char *end;

    if (token != NULL)
        return strtol(token, &end, 10);
    return NULL;
}

float convertFloat(char *token) {
    if (token != NULL)
        return strtod(target, NULL);
    return NULL;
}
