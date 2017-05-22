#include "readPlayerFile.h"

void readSkaterFile(char *fileName) {
    FILE *skaterFile;
    skater *newSkater;
    char buffer[255];

    skaterFile = fopen(fileName, "r");

    fgets(buffer, 255, skaterFile);
    newSkater = tokenizeSkater(buffer);

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
    newSkater->age = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    strcpy(newSkater->position, token);
    token = strtok(NULL, ",");
    strcpy(newSkater->team, token);
    token = strtok(NULL, ",");
    newSkater->gamesPlayed = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->goals = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->assists = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->points = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->plusMinus = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->penaltyMinutes = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->goals5v5 = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->PPgoals = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->SHgoals = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->gameWinningGoals = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->assists5v5 = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->PPassists = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->SHassists = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->shots = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->shootingPercentage = strtod(token, NULL);
    token = strtok(NULL, ",");
    newSkater->iceTime = strtol(token, &end, 10);
    token = strtok(NULL, ":");
    newSkater->avgIceTime = strtod(token, NULL);
    token = strtok(NULL, ",");
    newSkater->avgIceTime += convertSecondtoDecimal(token);
    token = strtok(NULL, ",");
    newSkater->blocks = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->hits = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->faceoffWins = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->faceoffLosses = strtol(token, &end, 10);
    token = strtok(NULL, ",");
    newSkater->faceoffPercentage = strtod(token, NULL);
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
    return newSkater;
}

float convertSecondtoDecimal(char *target) {
    float converted, temp;

    temp = strtod(target, NULL);
    converted = temp / 60.0;
    return converted;
}
