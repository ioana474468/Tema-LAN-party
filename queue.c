#include "queue.h"

Queue *createQueueMatches()
{
    Queue *QueueMatches;
    QueueMatches=(Queue *)malloc(sizeof(Queue));
    if(QueueMatches==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    QueueMatches->front=NULL;
    QueueMatches->rear=NULL;
    return QueueMatches;
}

void enQueueMatches(Queue *QueueMatches, NodeTeam *firstTeam, NodeTeam *secondTeam)
{
    Match *newMatch=(Match *)malloc(sizeof(Match));

    newMatch->TeamOne=firstTeam;
    newMatch->TeamTwo=secondTeam;

    newMatch->next=NULL;
    if(QueueMatches->rear==NULL)
    {
        QueueMatches->rear=newMatch;
    }
    else
    {
        (QueueMatches->rear)->next=newMatch;
        (QueueMatches->rear)=newMatch;
    }
    if(QueueMatches->front==NULL)
    {
        QueueMatches->front=QueueMatches->rear;
    }
}
void deleteQueue(Queue* q)
{
    Match* temp;
    while (q->front!=NULL)
    {
        temp=q->front;
        q->front=q->front->next;
        free(temp);
    }
    free(q);
}

void displayQueueMatches(Queue *QueueMatches, FILE *outputFile)
{
    for(Match *p=QueueMatches->front; p!=NULL; p=p->next)
    {
        fprintf(outputFile,"%s",p->TeamOne->teamName);
        for(int i=0; i<33-strlen(p->TeamOne->teamName); i++)
        {
            fprintf(outputFile," ");
        }
        fprintf(outputFile,"-");
        for(int i=0; i<33-strlen(p->TeamTwo->teamName); i++)
        {
            fprintf(outputFile," ");
        }
        fprintf(outputFile,"%s\n",p->TeamTwo->teamName);
    }
}


