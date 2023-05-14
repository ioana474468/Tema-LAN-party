#include "AVL.h"
#include "BST.h"

void addNodesInArray(NodeTeam *v, NodeBST *root, int *i)
{
    if(root!=NULL)
    {
        addNodesInArray(v,root->right, i);

        (v+(*i))->teamPoints=root->team->teamPoints;
        (v+(*i))->headPlayer=root->team->headPlayer;
        (v+(*i))->teamName=(char*)malloc((strlen(root->team->teamName)+1)*sizeof(char));
        if((v+(*i))->teamName==NULL)
        {
            printf("Memory error");
            exit(1);
        }
        strcpy((v+(*i))->teamName,root->team->teamName);
        (*i)++;
        addNodesInArray(v,root->left, i);
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

NodeBST *insertNodeAVL(NodeBST *node, char *tName, float tPoints, NodePlayer *hPlayer) ///
{
    if(node==NULL)
    {
        return newNodeBST(tName,tPoints,hPlayer);
    }
    if(tPoints<node->team->teamPoints)
    {
        node->left=insertNodeAVL(node->left,tName,tPoints,hPlayer);
    }
    else if(tPoints>node->team->teamPoints)
    {
        node->right=insertNodeAVL(node->right,tName,tPoints,hPlayer);
    }
    else if(tPoints==node->team->teamPoints)
    {
        if(strcmp(tName,node->team->teamName)<0)
        {
            node->left=insertNodeAVL(node->left,tName,tPoints,hPlayer);
        }
        else if(strcmp(tName,node->team->teamName)>0)
        {
            node->right=insertNodeAVL(node->right,tName,tPoints,hPlayer);
        }
    }
    else
    {
        return node;
    }


    node->height=updateHeight(node);
    int k=nodeHeight(node->left)-nodeHeight(node->right);

    /*
    if(k>1 && tPoints<node->left->team->teamPoints ) return RightRotation(node); ///LL
    if(k<-1 && tPoints>node->right->team->teamPoints) return LeftRotation(node); ///RR
    if(k>1 && tPoints>node->left->team->teamPoints ) return LRRotation(node); ///LR
    if(k<-1 && tPoints<node->right->team->teamPoints ) return RLRotation(node); ///RL
        */

    if(k>1 && (tPoints<node->left->team->teamPoints || (tPoints==node->left->team->teamPoints && strcmp(tName,node->team->teamName)<0))) return RightRotation(node); ///LL
    if(k<-1 && (tPoints>node->right->team->teamPoints || (tPoints==node->right->team->teamPoints && strcmp(tName,node->team->teamName)>0))) return LeftRotation(node); ///RR
    if(k>1 && (tPoints>node->left->team->teamPoints || (tPoints==node->left->team->teamPoints && strcmp(tName,node->team->teamName)>0))) return LRRotation(node); ///LR
    if(k<-1 && (tPoints<node->right->team->teamPoints || (tPoints==node->right->team->teamPoints && strcmp(tName,node->team->teamName)<0))) return RLRotation(node); ///RL

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
