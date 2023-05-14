
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"


void addNodesInArray(NodeTeam *v,NodeBST *root, int *i);



int nodeHeight(NodeBST *root);
int updateHeight(NodeBST *root);

NodeBST *insertNodeAVL(NodeBST *node, char *tName, float tPoints, NodePlayer *hPlayer);

NodeBST *RightRotation(NodeBST *z);
NodeBST *LeftRotation(NodeBST *z);
NodeBST *LRRotation(NodeBST *z);
NodeBST *RLRotation(NodeBST *z);

void printLevel(NodeBST* root, int level,FILE * outputFile, int *numNodesPrinted);

