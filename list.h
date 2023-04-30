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
    NodePlayer *headPlayer;
    struct NodeTeam *next;
};
typedef struct NodeTeam NodeTeam;

void createLists(NodePlayer **headListPlayers, NodeTeam **headListTeams, FILE * inputFile);
void addFirstInListPlayers(NodePlayer **headListPlayers, FILE * inputFile);
void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, NodePlayer *headListPlayers);
void displayListTeams(NodeTeam *headListTeams, FILE *outputFile);

