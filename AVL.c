#include "AVL.h"
#include "BST.h"


void addNodesInArray(NodeTeam *v, NodeBST *root, int *i)
{
    if(root!=NULL)
    {
        addNodesInArray(v,root->left, i);
        printf("%s %.2f\n", root->team->teamName, root->team->teamPoints);

        (v+(*i))->teamPoints=root->team->teamPoints;
        (v+(*i))->headPlayer=root->team->headPlayer;
        (v+(*i))->teamName=(char*)malloc((strlen(root->team->teamName)+1)*sizeof(char));
        if((v+(*i))->teamName==NULL)
        {
            printf("memory error");
            exit(1);
        }
        strcpy((v+(*i))->teamName,root->team->teamName);
        (*i)++;

        addNodesInArray(v,root->right, i);
    }
}



int Max(int a, int b)
{
    if(a>b) return a;
    else return b;

}
int nodeHeight(NodeBST *root)
{
    if(root==NULL) return -1;
    else return root->height;
}

NodeBST *RightRotation(NodeBST *z)
{
    NodeBST *y=z->left;
    NodeBST *T3=y->right;

    y->right=z;
    z->left=T3;

    z->height=Max(nodeHeight(z->left),nodeHeight(z->right))+1;
    y->height=Max(nodeHeight(y->left),nodeHeight(y->right))+1;

    return y;
}

NodeBST *LeftRotation(NodeBST *z)
{
    NodeBST *y=z->right;
    NodeBST *T2=y->left;

    y->left=z;
    z->right=T2;

    z->height=Max(nodeHeight(z->left),nodeHeight(z->right))+1;
    y->height=Max(nodeHeight(y->left),nodeHeight(y->right))+1;

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

NodeBST *insertNodeAVL(NodeBST *node, char *tName, int tPoints, NodePlayer *hPlayer) ///
{
    insertNodeBST(node,tName,tPoints,hPlayer);


    node->height=1+Max(nodeHeight(node->left),nodeHeight(node->right));

    int k=nodeHeight(node->left)-nodeHeight(node->right);

    if(k>1 && tPoints<node->left->team->teamPoints) return RightRotation(node); ///LL

    if(k<-1 && tPoints>node->right->team->teamPoints) return LeftRotation(node); ///RR

    if(k>1 && tPoints>node->left->team->teamPoints) return LRRotation(node); ///LR

    if(k<-1 && tPoints<node->right->team->teamPoints) return RLRotation(node); ///RL

    return node;
}

void preorder(NodeBST *root)
{
    if(root!=NULL)
    {
        printf("%.2f ",root->team->teamPoints);
        preorder(root->left);
        preorder(root->right);
        printf("\n");
    }
}
