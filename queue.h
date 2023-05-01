#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"

struct Match
{
    NodeTeam *TeamOne, *TeamTwo;
    struct Match *next;

};
typedef struct Match Match;

struct Queue
{
    Match *front,*rear;
};
typedef struct Queue Queue;

Queue *createQueueMatches();

void enQueueMatches(Queue *QueueMatches, NodeTeam *firstTeam, NodeTeam *secondTeam);

void displayQueueMatches(Queue *QueueMatches, FILE *outputFile);

