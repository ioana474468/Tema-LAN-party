#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"


void createLists(NodePlayer **headListPlayers, NodeTeam **headListTeams, FILE *inputFile, int *numTeams, int *numPlayers);
void addFirstInListPlayers(NodePlayer **headListPlayers, FILE *inputFile);
void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, NodePlayer *headListPlayers);
void displayListTeams(NodeTeam *headListTeams, FILE *outputFile);
float minPoints(NodeTeam *headListTeams);
void searchTeamWithLowestPoints(NodeTeam **headListTeams, NodePlayer **headListPlayers, float Min, int numPlayers);

void modifyListPlayers(NodePlayer **headListPlayers, NodePlayer *headPlayer, int numPlayers);


