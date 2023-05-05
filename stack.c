#include "stack.h"


void playMatches(Queue *QueueMatches,NodeTeam **topWinners,NodeTeam **topLosers, int numPlayers)
{
    for(Match *p=QueueMatches->front; p!=NULL; p=p->next)
    {
        if(p->TeamOne->teamPoints>p->TeamTwo->teamPoints)
        {
            push(&(*topWinners),p->TeamOne);
            p->TeamOne->teamPoints++;
            addPointToPlayers(p->TeamOne,numPlayers);
            push(&(*topLosers),p->TeamTwo);
        }
        else
        {
            push(&(*topLosers),p->TeamOne);
            push(&(*topWinners),p->TeamTwo);
            p->TeamTwo->teamPoints++;
            addPointToPlayers(p->TeamTwo,numPlayers);
        }
    }
}
void addPointToPlayers(NodeTeam *currentTeam, int numPlayers)
{
    NodePlayer *nodeCopy=currentTeam->headPlayer;
    for(int i=0; i<numPlayers; i++)
    {
        nodeCopy->player->points++;
        nodeCopy=nodeCopy->next;
    }
}

void push(NodeTeam **top, NodeTeam *currentTeam)
{
    NodeTeam* newNode=(NodeTeam*)malloc(sizeof(NodeTeam));
    newNode=currentTeam;
    newNode->next=*top;
    *top=newNode;
}

void displayStack(NodeTeam *top, FILE *outputFile)
{
    for(NodeTeam *p=top; p!=NULL; p=p->next)
    {
        fprintf(outputFile,"%s",p->teamName);
        for(int i=0; i<34-strlen(p->teamName); i++)
        {
            fprintf(outputFile," ");
        }
        fprintf(outputFile,"-  ");
        fprintf(outputFile,"%.2f",p->teamPoints);
        if(p->next!=NULL)
        {
            fprintf(outputFile,"\n");
        }
    }
}
void pop(NodeTeam **top)
{
    NodeTeam *temp=(*top);
    *top=(*top)->next;
    free(temp->teamName);
    free(temp);

}



