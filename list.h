#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

struct NodePlayer
{
    Player *player;
    struct NodePlayer *next;
};
typedef struct NodePlayer NodePlayer;

struct NodeTeam
{
    char *teamName;
    int teamPoints;
    NodePlayer *headPlayer;
    struct NodeTeam *next;
};
typedef struct NodeTeam NodeTeam;

void createLists(NodePlayer **headListPlayers, NodeTeam **headListTeams, FILE *inputFile, int *numTeams, int *numPlayers);
void addFirstInListPlayers(NodePlayer **headListPlayers, FILE *inputFile);
void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, NodePlayer *headListPlayers);
void displayListTeams(NodeTeam *headListTeams, FILE *outputFile);
int minPoints(NodeTeam *headListTeams);
void modifyListTeams(NodeTeam **headListTeams, NodePlayer **headListPlayers, int Min, int numPlayers);

void modifyListPlayers(NodePlayer **headListPlayers, NodePlayer *headPlayer, int numPlayers);


