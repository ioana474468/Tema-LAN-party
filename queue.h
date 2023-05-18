#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"

Queue *createQueueMatches();
void enQueueMatches(Queue *QueueMatches, NodeTeam *firstTeam, NodeTeam *secondTeam);
void deleteQueue(Queue* q);
void displayQueueMatches(Queue *QueueMatches, FILE *outputFile);

