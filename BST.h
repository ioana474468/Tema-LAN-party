#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"

#ifndef BST_H
#define BST_H


NodeBST* newNodeBST(char* tName, float tPoints, NodePlayer *hPlayer);
NodeBST* insertNodeBST(NodeBST* node, char* tName, float tPoints, NodePlayer *hPlayer);
void reverseInorder(NodeBST *root,FILE *outputFile, int *numNodesPrinted);
void freeTree(NodeBST *root);

#endif
