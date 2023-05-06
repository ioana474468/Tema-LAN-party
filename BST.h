#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "nodes.h"


NodeBST* newNodeBST(char* tName, float tPoints, NodePlayer *hPlayer);
NodeBST* insertBST(NodeBST* node, char* tName, float tPoints, NodePlayer *hPlayer);
void reverseInorder(NodeBST *root,FILE *outputFile, int *numNodesPrinted);

