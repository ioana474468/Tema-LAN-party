#ifndef NODES_H
#define NODES_H

struct NodePlayer
{
    Player *player;
    struct NodePlayer *next;
};
typedef struct NodePlayer NodePlayer;

struct NodeTeam
{
    char *teamName;
    int numPlayers;
    float teamPoints;
    NodePlayer *headPlayer;
    struct NodeTeam *next;
};
typedef struct NodeTeam NodeTeam;

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

struct NodeBST
{
    NodeTeam *team;
    int height;
    struct NodeBST *left, *right;
};
typedef struct NodeBST NodeBST;


#endif /* NODES_H */
