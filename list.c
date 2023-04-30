#include "list.h"

void createLists(NodePlayer **headListPlayers, NodeTeam **headListTeams, FILE *inputFile)
{
    int numTeams,numPlayers;
    fscanf(inputFile,"%d",&numTeams);
    ///printf("%d\n",numTeams);///

    for(int i=0; i<numTeams; i++)
    {
        fscanf(inputFile,"%d ",&numPlayers);
        ///printf("%d\n",numPlayers); ///

        char bufferTeamName[50];
        fgets(bufferTeamName,50,inputFile);
        ///printf("%s\n",bufferTeamName);///
        for(int j=0; j<numPlayers; j++)
        {
            addFirstInListPlayers(headListPlayers,inputFile);
        }
        addFirstInListTeams(headListTeams,bufferTeamName,*headListPlayers);
    }
}
void addFirstInListPlayers(NodePlayer **headListPlayers, FILE *inputFile)
{
    int points;
    char bufferFirstName[15], bufferSecondName[20];
    fscanf(inputFile,"%s %s %d",bufferFirstName,bufferSecondName,&points);

    NodePlayer *newNodePlayer=(NodePlayer *)malloc(sizeof(NodePlayer));
    newNodePlayer->player=(Player *)malloc(sizeof(Player));
    newNodePlayer->player->firstName=(char*)malloc((strlen(bufferFirstName)+1)*sizeof(char));
    newNodePlayer->player->secondName=(char*)malloc((strlen(bufferSecondName)+1)*sizeof(char));

    if(newNodePlayer==NULL || newNodePlayer->player==NULL || newNodePlayer->player->firstName==NULL || newNodePlayer->player->secondName==NULL)
    {
        printf("Memory error");
        exit(1);
    }

    newNodePlayer->player->points=points;
    strcpy(newNodePlayer->player->firstName,bufferFirstName);
    strcpy(newNodePlayer->player->secondName,bufferSecondName);
    ///printf("%s*%s ->",newNodePlayer->player->firstName,newNodePlayer->player->secondName);///
    ///printf("%d\n",newNodePlayer->player->points);///
    newNodePlayer->next=*headListPlayers;
    *headListPlayers=newNodePlayer;
}

void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, NodePlayer *headListPlayers)
{
    NodeTeam *newNodeTeam=NULL;
    newNodeTeam=(NodeTeam *)malloc(sizeof(NodeTeam));
    newNodeTeam->teamName=(char *)malloc((strlen(bufferTeamName)+1)*sizeof(char));
    if(newNodeTeam==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    int lenght=strlen(bufferTeamName);
    lenght--;
    strncpy(newNodeTeam->teamName,bufferTeamName,lenght);
    newNodeTeam->teamName[lenght]='\0';
    newNodeTeam->headPlayer=headListPlayers;
    newNodeTeam->next=*headListTeams;
    *headListTeams=newNodeTeam;

}
void displayListTeams(NodeTeam *headListTeams, FILE *outputFile)
{
    for(NodeTeam *p=headListTeams; p!=NULL; p=p->next)
    {
        printf("%s",p->teamName);///
        fprintf(outputFile,"%s",p->teamName);
        if(p->next!=NULL)
        {
            fprintf(outputFile,"\n");
            printf("\n");
        }
    }
}
void freeListPlayers(NodePlayer *headListPlayers)
{
    for(NodePlayer *p=headListPlayers; p!=NULL; p=p->next)
    {
        free(p->player->firstName);
        free(p->player->secondName);
        free(p->player);
        free(p);
    }
}
void freeListTeams(NodeTeam *headListTeams)
{
    for(NodeTeam *p=headListTeams; p!=NULL; p=p->next)
    {
        free(p->teamName);
        free(p);
    }
}


