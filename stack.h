
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"

#ifndef STACK_H
#define STACK_H

void playMatches(Queue *QueueMatches,NodeTeam **topWinners,NodeTeam **topLosers, int numPlayers);

void addPointToPlayers(NodeTeam *currentTeam, int numPlayers);

void push(NodeTeam **top, NodeTeam *currentTeam);

void displayStack(NodeTeam *top, FILE *outputFile);

void pop(NodeTeam **top);

#endif
