#include "list.h"

void addFirstInListPlayers(Node **headListPlayers, FILE * dataFile)
{

    int points;
    char bufferFirstName[15], bufferSecondName[20];
    fscanf(dataFile,"%s %s %d",bufferFirstName,bufferSecondName,&points);

    Node *newNodePlayer=(Node *)malloc(sizeof(Node));
    if(newNodePlayer==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    newNodePlayer->player=(Player *)malloc(sizeof(Player));
    if(newNodePlayer->player==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    newNodePlayer->player->firstName=(char*)malloc((strlen(bufferFirstName)+1)*sizeof(char));
    if(newNodePlayer->player->firstName==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    newNodePlayer->player->secondName=(char*)malloc((strlen(bufferSecondName)+1)*sizeof(char));
    if(newNodePlayer->player->secondName==NULL)
    {
        printf("Memory error");
        exit(1);
    }

    newNodePlayer->player->points=points;
    strcpy(newNodePlayer->player->firstName,bufferFirstName);
    strcpy(newNodePlayer->player->secondName,bufferSecondName);

    printf("%s*%s ->",newNodePlayer->player->firstName,newNodePlayer->player->secondName);
    printf("%d\n",newNodePlayer->player->points);

    newNodePlayer->next=*headListPlayers;
    *headListPlayers=newNodePlayer;
}

void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, Node *headListPlayers)
{
    NodeTeam *newNodeTeam=NULL;

    newNodeTeam=(NodeTeam *)malloc(sizeof(NodeTeam));
    newNodeTeam->teamName=(char *)malloc((strlen(bufferTeamName)+1)*sizeof(char));

    if(newNodeTeam==NULL)
    {
        printf("Memory error");
        exit(1);
    }

    strcpy(newNodeTeam->teamName,bufferTeamName);
    newNodeTeam->headPlayer=headListPlayers;

    newNodeTeam->next=*headListTeams;
    *headListTeams=newNodeTeam;

}
void displayListTeams(NodeTeam *headListTeams, FILE *outputFile)
{
    for(NodeTeam *p=headListTeams; p!=NULL; p=p->next)
    {
        fprintf(outputFile,"%s",p->teamName);
    }
}
void freeListPlayers(Node *headListPlayers)
{
    for(Node *p=headListPlayers;p!=NULL;p=p->next)
    {
        free(p->player->firstName);
        free(p->player->secondName);
        free(p->player);
        free(p);
    }
}
void freeListTeams(NodeTeam *headListTeams)
{
    for(NodeTeam *p=headListTeams;p!=NULL;p=p->next)
    {
        free(p->teamName);
        free(p);
    }
}


