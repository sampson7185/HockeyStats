#include "readPlayerFile.h"

void readSkaterFile(char *fileName) {
    FILE *skaterFile;
    skater *newSkater;
    skater *head = NULL;
    char buffer[255];
    int longestName;

    skaterFile = fopen(fileName, "r");

    while(fgets(buffer, 255, skaterFile) != NULL) {
        newSkater = tokenizeSkater(buffer, &longestName);
        insertSkater(&head, newSkater);
    }
    printSkatersGridFormat(head, longestName);

    fclose(skaterFile);
    return;
}

skater *tokenizeSkater(char *buffer, int *longestName) {
    char *token;
    skater *newSkater = NULL;
    int nameLength;

    newSkater = createSkater();

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
    nameLength = strlen(newSkater->firstName) + strlen(newSkater->lastName);
    if (nameLength > (*longestName))
        (*longestName) = nameLength;
    return newSkater;
}

float convertSecondtoDecimal(char *target) {
    float converted, temp;

    if (target != NULL) {
        temp = strtod(target, NULL);
        converted = temp / 60.0;
        return converted;
    }
    return 0.0;
}

int convertInt(char *target) {
    char *end;

    if (target != NULL)
        return strtol(target, &end, 10);
    return 0;
}

float convertFloat(char *target) {
    if (target != NULL)
        return strtod(target, NULL);
    return 0.0;
}

/*constructor for skater*/
skater *createSkater() {
    skater *newSkater;

    newSkater = malloc(sizeof(skater));
    if (newSkater != NULL) {
        newSkater->firstName = NULL;
        newSkater->lastName = NULL;
        newSkater->position = NULL;
        newSkater->next = NULL;
    }
    else {
        printf("Failed to allocate memory, try again\n");
        exit(1);
    }
    return newSkater;
}
