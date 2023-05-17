
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"


void orderTop8(NodeBST *root, NodeTeam **top8);



int nodeHeight(NodeBST *root);
int updateHeight(NodeBST *root);

NodeBST *insertNodeAVL(NodeBST *node, NodeTeam *currentTeam);

NodeBST *RightRotation(NodeBST *z);
NodeBST *LeftRotation(NodeBST *z);
NodeBST *LRRotation(NodeBST *z);
NodeBST *RLRotation(NodeBST *z);

void printLevel(NodeBST* root, int level,FILE * outputFile, int *numNodesPrinted);

