#include "list.h"

void createLists(NodePlayer **headListPlayers, NodeTeam **headListTeams, FILE *inputFile, int *numTeams)
{
    int numPlayers;
    fscanf(inputFile,"%d",numTeams);
    ///printf("%d\n",numTeams);///

    for(int i=0; i<(*numTeams); i++)
    {
        fscanf(inputFile,"%d ",&numPlayers);

        ///printf("%d\n",*numPlayers); ///

        int totalPoints=0;
        char bufferTeamName[50];
        fgets(bufferTeamName,50,inputFile);

        ///printf("%s\n",bufferTeamName);///
        for(int j=0; j<numPlayers; j++)
        {
            addFirstInListPlayers(headListPlayers,inputFile);
            totalPoints+=(*headListPlayers)->player->points;
        }
        addFirstInListTeams(headListTeams,bufferTeamName,*headListPlayers);
        (*headListTeams)->teamPoints=totalPoints;
        ///printf("%s %d\n",(*headListTeams)->teamName,(*headListTeams)->teamPoints);
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
    if(bufferTeamName[lenght-1]==' ')
    {
        lenght--;
    }


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
        ///printf("%s",p->teamName);
        fprintf(outputFile,"%s",p->teamName);
        if(p->next!=NULL)
        {
            fprintf(outputFile,"\n");
            ///printf("\n");
        }
    }
}

int minPoints(NodeTeam *headListTeams)
{
    int Min=headListTeams->teamPoints;
    for(NodeTeam *p=headListTeams->next; p!=NULL; p=p->next)
    {
        if(Min>p->teamPoints)
        {
            Min=p->teamPoints;
        }
    }
    return Min;
}

void modifyListTeams(NodeTeam **headListTeams, int Min)
{
    NodeTeam *headcopy=*headListTeams;
    if(headcopy->teamPoints==Min)
    {
        *headListTeams=(*headListTeams)->next;
        //freeTeam(headcopy);
        return;
    }
    else
    {
        for(NodeTeam *p=*headListTeams; p!=NULL; p=p->next)
        {
            if(p->next->teamPoints==Min)
            {
                headcopy=p->next;
                p->next=p->next->next;
                //freeTeam(headcopy);

                ///p->next=aux->next;
                ///freeTeam(p->next);
                ///freeTeam(aux);
                return;
            }
        }
    }

}

void freeTeam(NodeTeam *currentTeam)
{
    for(NodePlayer *p=currentTeam->headPlayer; p!=(currentTeam->next)->headPlayer; p=p->next)
    {
        freePlayer(p);
    }
    free(currentTeam->teamName);
    free(currentTeam->headPlayer);
    free(currentTeam);
}

void freePlayer(NodePlayer *currentPlayer)
{
    free(currentPlayer->player->firstName);
    free(currentPlayer->player->secondName);
    free(currentPlayer->player);
    free(currentPlayer);
}

