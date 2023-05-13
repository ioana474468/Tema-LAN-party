
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"

void addNodesInArray(NodeTeam *v,NodeBST *root, int *i);


int Max(int a, int b);
int nodeHeight(NodeBST *root);

NodeBST *insertNodeAVL(NodeBST *node, char *tName, int tPoints, NodePlayer *hPlayer);

NodeBST *RightRotation(NodeBST *z);
NodeBST *LeftRotation(NodeBST *z);
NodeBST *LRRotation(NodeBST *z);
NodeBST *RLRotation(NodeBST *z);

void preorder(NodeBST *root);

