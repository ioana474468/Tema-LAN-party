#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"

#ifndef BST_H
#define BST_H


NodeBST* newNodeBST(NodeTeam *currentTeam);
NodeBST* insertNodeBST(NodeBST* node, NodeTeam *currentTeam);
void reverseInorder(NodeBST *root,FILE *outputFile, int *numNodesPrinted);
void freeTree(NodeBST *root);

#endif
