#include "AVL.h"
#include "BST.h"

void orderTop8(NodeBST *root, NodeTeam **top8)
{
    if(root!=NULL)
    {
        orderTop8(root->left,top8);
        root->team->next=*top8;
        *top8=root->team;
        orderTop8(root->right,top8);
    }
}

int nodeHeight(NodeBST *root)
{
    if(root==NULL) return 0;
    else return root->height;
}
int updateHeight(NodeBST *root)
{
    int leftH=nodeHeight(root->left);
    int rightH=nodeHeight(root->right);
    if(leftH>rightH) return 1+leftH;
    else return 1+rightH;
}

NodeBST *RightRotation(NodeBST *z)
{
    NodeBST *y=z->left;
    z->left=y->right;
    y->right=z;
    z->height=updateHeight(z);
    y->height=updateHeight(y);
    return y;
}

NodeBST *LeftRotation(NodeBST *z)
{
    NodeBST *y=z->right;
    z->right=y->left;
    y->left=z;
    z->height=updateHeight(z);
    y->height=updateHeight(y);
    return y;
}

NodeBST *LRRotation(NodeBST *z)
{
    z->left=LeftRotation(z->left);
    return RightRotation(z);
}

NodeBST *RLRotation(NodeBST *z)
{
    z->right=RightRotation(z->right);
    return LeftRotation(z);
}

NodeBST *insertNodeAVL(NodeBST *node, NodeTeam *currentTeam)
{
    if(node==NULL)
    {
        return newNodeBST(currentTeam);
    }
    if(currentTeam->teamPoints<node->team->teamPoints)
    {
        node->left=insertNodeAVL(node->left,currentTeam);
    }
    else if(currentTeam->teamPoints>node->team->teamPoints)
    {
        node->right=insertNodeAVL(node->right,currentTeam);
    }
    else if(currentTeam->teamPoints==node->team->teamPoints)
    {
        if(strcmp(currentTeam->teamName,node->team->teamName)<0)
        {
            node->left=insertNodeAVL(node->left,currentTeam);
        }
        else if(strcmp(currentTeam->teamName,node->team->teamName)>0)
        {
            node->right=insertNodeAVL(node->right,currentTeam);
        }
    }
    else
    {
        return node;
    }
    node->height=updateHeight(node);
    int k=nodeHeight(node->left)-nodeHeight(node->right);

    if(k>1 && (currentTeam->teamPoints<node->left->team->teamPoints || (currentTeam->teamPoints==node->left->team->teamPoints && strcmp(currentTeam->teamName,node->left->team->teamName)<0))) return RightRotation(node); ///LL
    if(k<-1 && (currentTeam->teamPoints>node->right->team->teamPoints || (currentTeam->teamPoints==node->right->team->teamPoints && strcmp(currentTeam->teamName,node->right->team->teamName)>0))) return LeftRotation(node); ///RR
    if(k>1 && (currentTeam->teamPoints>node->left->team->teamPoints || (currentTeam->teamPoints==node->left->team->teamPoints && strcmp(currentTeam->teamName,node->left->team->teamName)>0))) return LRRotation(node); ///LR
    if(k<-1 && (currentTeam->teamPoints<node->right->team->teamPoints || (currentTeam->teamPoints==node->right->team->teamPoints && strcmp(currentTeam->teamName,node->right->team->teamName)<0))) return RLRotation(node); ///RL

    return node;
}


void printLevel(NodeBST* root, int level,FILE * outputFile, int *numNodesPrinted)
{
    if(root==NULL) return;
    if(level==1)
    {
        fprintf(outputFile,"%s",root->team->teamName);
        if(*numNodesPrinted<3)
        {
            fprintf(outputFile,"\n");
            (*numNodesPrinted)++;
        }
    }
    else if(level>1)
    {
        printLevel(root->right,level-1,outputFile,numNodesPrinted);
        printLevel(root->left, level-1,outputFile,numNodesPrinted);
    }
}
