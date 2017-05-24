#ifndef PLAYER_H
#define PLAYER_H

typedef enum { false, true } bool;

typedef struct skater {
    char *firstName;
    char *lastName;
    int age;
    char *position;
    char team[4];
    int gamesPlayed;
    int goals;
    int assists;
    int points;
    int plusMinus;
    int penaltyMinutes;
    int goals5v5;
    int PPgoals;
    int SHgoals;
    int gameWinningGoals;
    int assists5v5;
    int PPassists;
    int SHassists;
    int shots;
    float shootingPercentage;
    int iceTime;
    float avgIceTime;
    int blocks;
    int hits;
    int faceoffWins;
    int faceoffLosses;
    float faceoffPercentage;
    struct skater *next;
}skater;

typedef struct goalie {
    char *firstName;
    char *lastName;
    int age;
    char team[4];
    int gamesPlayed;
    int gamesStarted;
    int wins;
    int losses;
    int overtimeLosses;
    int goalsAgainst;
    int shotsAgainst;
    int saves;
    long savePercentage;
    long goalsAgainstAverage;
    int shutOuts;
    int minutes;
    int goals;
    int assists;
    int points;
    int penaltyMinutes;
    struct goalie *next;
}goalie;

#endif /*PLAYER_H*/
