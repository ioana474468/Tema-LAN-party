#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"

void createLists(NodePlayer **headListPlayers, NodeTeam **headListTeams, FILE *inputFile, int *numTeams, int *numPlayers);
void addFirstInListPlayers(NodePlayer **headListPlayers, FILE *inputFile);
void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, NodePlayer *headListPlayers);
void displayListTeams(NodeTeam *headListTeams, FILE *outputFile);
int minPoints(NodeTeam *headListTeams);
void modifyListTeams(NodeTeam **headListTeams, NodePlayer **headListPlayers, int Min, int numPlayers);

void modifyListPlayers(NodePlayer **headListPlayers, NodePlayer *headPlayer, int numPlayers);


