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
    int teamPoints;
    NodePlayer *headPlayer;
    struct NodeTeam *next;
};
typedef struct NodeTeam NodeTeam;

#endif /* NODES_H */
