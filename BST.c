#include "BST.h"
#include "stack.h"

NodeBST* newNodeBST(char* tName, float tPoints, NodePlayer *hPlayer)
{
    NodeBST* node=(NodeBST*)malloc(sizeof(NodeBST));
    node->team=(NodeTeam*)malloc(sizeof(NodeTeam));
    node->team->teamName=(char*)malloc((strlen(tName)+1)*sizeof(char));

    node->team->teamPoints=tPoints;
    strcpy(node->team->teamName,tName);
    node->team->headPlayer=hPlayer;

    node->left=node->right=NULL;
    ///node->height=height(node);
    return node;
}

NodeBST* insertBST(NodeBST* node, char* tName, float tPoints, NodePlayer *hPlayer)
{
    if(node==NULL)
    {
        return newNodeBST(tName,tPoints,hPlayer);
    }

    if(tPoints<node->team->teamPoints)
    {
        node->left=insertBST(node->left,tName,tPoints,hPlayer);
    }
    else if(tPoints>node->team->teamPoints)
    {
        node->right=insertBST(node->right,tName,tPoints,hPlayer);
    }
    else if(tPoints==node->team->teamPoints)
    {
        if(strcmp(tName,node->team->teamName)<0)
        {
            node->left=insertBST(node->left,tName,tPoints,hPlayer);
        }
        else if(strcmp(tName,node->team->teamName)>0)
        {
            node->right=insertBST(node->right,tName,tPoints,hPlayer);
        }
    }



    ///node->height = height(node);
    return node;
}

void reverseInorder(NodeBST *root,FILE *outputFile, int *numNodesPrinted)
{
    if(root!=NULL)
    {
        reverseInorder(root->right,outputFile,numNodesPrinted);
        fprintf(outputFile,"%s",root->team->teamName);
        for(int i=0; i<34-strlen(root->team->teamName); i++)
        {
            fprintf(outputFile," ");
        }
        fprintf(outputFile,"-  %.2f",root->team->teamPoints);
        (*numNodesPrinted)++;
        if(*numNodesPrinted<8)
        {
            fprintf(outputFile,"\n");
        }
        reverseInorder(root->left,outputFile,numNodesPrinted);

    }
}


