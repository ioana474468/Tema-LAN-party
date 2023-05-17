#include "BST.h"
#include "stack.h"



NodeBST* newNodeBST(NodeTeam *currentTeam)
{
    NodeBST* node=(NodeBST*)malloc(sizeof(NodeBST));
    if(node==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    node->team=currentTeam;
    node->left=node->right=NULL;
    node->height=1;
    return node;
}

NodeBST* insertNodeBST(NodeBST* node, NodeTeam *currentTeam)
{
    if(node==NULL)
    {
        return newNodeBST(currentTeam);
    }
    if(currentTeam->teamPoints<node->team->teamPoints)
    {
        node->left=insertNodeBST(node->left,currentTeam);
    }
    else if(currentTeam->teamPoints>node->team->teamPoints)
    {
        node->right=insertNodeBST(node->right,currentTeam);
    }
    else if(currentTeam->teamPoints==node->team->teamPoints)
    {
        if(strcmp(currentTeam->teamName,node->team->teamName)<0)
        {
            node->left=insertNodeBST(node->left,currentTeam);
        }
        else if(strcmp(currentTeam->teamName,node->team->teamName)>0)
        {
            node->right=insertNodeBST(node->right,currentTeam);
        }
    }
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
void freeTree(NodeBST *root)
{
    if(root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


