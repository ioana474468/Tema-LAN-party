#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

struct Node
{
    Player *player;
    struct Node *next;
};
typedef struct Node Node;

struct NodeTeam
{
    char *teamName;
    Node *headPlayer;
    struct NodeTeam *next;
};
typedef struct NodeTeam NodeTeam;

void addFirstInListPlayers(Node **headListPlayers, FILE * dataFile);
void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, Node *headListPlayers);
void displayListTeams(NodeTeam *headListTeams, FILE *outputFile);

