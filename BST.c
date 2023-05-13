#include "BST.h"
#include "stack.h"

int height(NodeBST *root)
{
    int hs, hd;
    if(root==NULL) return -1;
    hs=height(root->left);
    hd=height(root->right);
    if(hs>hd) return 1+hs;
    else return 1+hd;
}

NodeBST* newNodeBST(char* tName, float tPoints, NodePlayer *hPlayer)
{
    NodeBST* node=(NodeBST*)malloc(sizeof(NodeBST));
    if(node==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    node->team=(NodeTeam*)malloc(sizeof(NodeTeam));
    if(node->team==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    node->team->teamName=(char*)malloc((strlen(tName)+1)*sizeof(char));
    if(node->team->teamName==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    node->team->teamPoints=tPoints;
    strcpy(node->team->teamName,tName);
    node->team->headPlayer=hPlayer;
    node->left=node->right=NULL;
    node->height=height(node);
    return node;
}

NodeBST* insertNodeBST(NodeBST* node, char* tName, float tPoints, NodePlayer *hPlayer)
{
    if(node==NULL)
    {
        return newNodeBST(tName,tPoints,hPlayer);
    }
    if(tPoints<node->team->teamPoints)
    {
        node->left=insertNodeBST(node->left,tName,tPoints,hPlayer);
    }
    else if(tPoints>node->team->teamPoints)
    {
        node->right=insertNodeBST(node->right,tName,tPoints,hPlayer);
    }
    else if(tPoints==node->team->teamPoints)
    {
        if(strcmp(tName,node->team->teamName)<0)
        {
            node->left=insertNodeBST(node->left,tName,tPoints,hPlayer);
        }
        else if(strcmp(tName,node->team->teamName)>0)
        {
            node->right=insertNodeBST(node->right,tName,tPoints,hPlayer);
        }
    }
    node->height = height(node);
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


