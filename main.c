#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "queue.h"
#include "stack.h"
#include "BST.h"
#include "AVL.h"

int main()
{
    FILE *cFile,*inputFile,*outputFile;

    cFile=fopen("c.in.txt","rt");
    if(cFile==NULL)
    {
        printf("c.in cannot be open");
        exit(1);
    }
    int *c;
    c=(int *)malloc(5*sizeof(int));
    for(int i=0; i<5; i++)
    {
        fscanf(cFile,"%d",c+i);
    }
    fclose(cFile);

    inputFile=fopen("d.in.txt","rt");
    if(inputFile==NULL )
    {
        printf("d.in cannot be open");
        exit(1);
    }
    outputFile=fopen("r.out.txt","wt");
    if(outputFile==NULL )
    {
        printf("r.out cannot be open");
        exit(1);
    }

    NodePlayer *headListPlayers=NULL;
    NodeTeam *headListTeams=NULL;
    int numTeams,numPlayers;

    if((*c)==1)
    {
        createLists(&headListPlayers,&headListTeams,inputFile,&numTeams,&numPlayers);
        if((*(c+1))==0) displayListTeams(headListTeams,outputFile);
    }

    if((*(c+1))==1)
    {
        int numTeamsNeeded;
        for(int i=1; i<=numTeams; i=i*2)
        {
            if(i*2>numTeams)
            {
                numTeamsNeeded=i;
            }
        }
        while(numTeamsNeeded!=numTeams)
        {
            searchTeamWithLowestPoints(&headListTeams,&headListPlayers,minPoints(headListTeams),numPlayers);
            numTeams--;
        }
        numTeams=numTeamsNeeded;
        displayListTeams(headListTeams,outputFile);
    }
    NodeTeam *top8=NULL;
    if((*(c+2))==1)
    {
        NodeTeam *topWinners=NULL, *topLosers=NULL;
        int roundNum=1;
        topWinners=headListTeams;
        while(numTeams!=1)
        {
            Queue *QueueMatches=createQueueMatches();
            if(numTeams==8)
            {
                for(NodeTeam *p=topWinners; p!=NULL; p=p->next)
                {
                    addFirstInListTeams(&top8,p->teamName,p->headPlayer);
                    top8->teamPoints=p->teamPoints;
                }
            }
            numTeams/=2;
            for(NodeTeam *p=topWinners; p!=NULL; p=(p->next)->next)
            {
                enQueueMatches(QueueMatches,p,p->next);
            }
            fprintf(outputFile,"\n\n--- ROUND NO:%d\n",roundNum);
            displayQueueMatches(QueueMatches,outputFile);
            while(topWinners!=NULL)
            {
                pop(&topWinners);
            }
            topWinners=NULL;
            playMatches(QueueMatches,&topWinners,&topLosers,numPlayers);
            fprintf(outputFile,"\nWINNERS OF ROUND NO:%d\n",roundNum);
            roundNum++;
            displayStack(topWinners,outputFile);
            while(topLosers!=NULL)
            {
                modifyListPlayers(&headListPlayers,topLosers->headPlayer,numPlayers);
                pop(&topLosers);
            }
            deleteQueue(QueueMatches);
        }
        free(topWinners);
        free(topLosers);

    }

    NodeBST *rootBST=NULL;

    if((*(c+3))==1)
    {
        for(int i=0; i<8; i++)
        {
            rootBST=insertNodeBST(rootBST,top8->teamName,top8->teamPoints,top8->headPlayer);
            pop(&top8);
        }
        free(top8);
        fprintf(outputFile,"\n\nTOP 8 TEAMS:\n");
        int numNodesPrinted=0;
        reverseInorder(rootBST,outputFile,&numNodesPrinted);
    }

    if((*(c+4))==1)
    {
        NodeTeam *v;
        int index=0;
        v=(NodeTeam *)malloc(8*sizeof(NodeTeam));
        addNodesInArray(v,rootBST, &index);
        NodeBST *rootAVL=NULL;
        for(int i=0; i<8; i++)
        {
            rootAVL=insertNodeAVL(rootAVL,(v+i)->teamName,(v+i)->teamPoints,(v+i)->headPlayer);
        }
        free(v);
        fprintf(outputFile,"\n\nTHE LEVEL 2 TEAMS ARE: \n");
        int nr=0;
        printLevel(rootAVL,3,outputFile,&nr);
        freeTree(rootAVL);
    }



    for(int i=0; i<numPlayers; i++)
    {
        NodePlayer *p=headListPlayers;
        headListPlayers=headListPlayers->next;
        free(p->player->firstName);
        free(p->player->secondName);
        free(p);
    }
    free(headListTeams);
    freeTree(rootBST);
    free(c);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
