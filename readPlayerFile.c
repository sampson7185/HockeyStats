#include "readPlayerFile.h"

void readSkaterFile(char *fileName) {
    FILE *skaterFile;
    char buffer[255];

    skaterFile = fopen(fileName, "r");
    fgets(buffer, 255, skaterFile);


    fclose(skaterFile);
    return;
}

skater *tokenizeSkaterFile(char *buffer) {
    char *token;
    skater *newSkater;

    token = strtok(buffer, " ");
    newSkater->firstName = malloc(strlen(token) + 1);

}
