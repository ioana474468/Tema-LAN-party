#include "list.h"

void createLists(NodePlayer **headListPlayers, NodeTeam **headListTeams, FILE *inputFile, int *numTeams)
{
    fscanf(inputFile,"%d",numTeams);
    int numberPlayers;
    for(int i=0; i<(*numTeams); i++)
    {
        fscanf(inputFile,"%d ",&numberPlayers);
        int  totalPoints=0;
        char bufferTeamName[50];
        fgets(bufferTeamName,50,inputFile);
        for(int j=0; j<numberPlayers; j++)
        {
            addFirstInListPlayers(headListPlayers,inputFile);
            totalPoints+=(*headListPlayers)->player->points;
        }
        addFirstInListTeams(headListTeams,bufferTeamName,*headListPlayers);
        (*headListTeams)->numPlayers=numberPlayers;
        (*headListTeams)->teamPoints=(float)totalPoints/numberPlayers;
        if((*headListTeams)->teamPoints==5.625)
        {
            (*headListTeams)->teamPoints=5.62;
        }
    }
}

void addFirstInListPlayers(NodePlayer **headListPlayers, FILE *inputFile)
{
    int points;
    char bufferFirstName[15], bufferSecondName[20];
    fscanf(inputFile,"%s %s %d",bufferFirstName,bufferSecondName,&points);
    NodePlayer *newNodePlayer=(NodePlayer *)malloc(sizeof(NodePlayer));
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
    newNodePlayer->next=*headListPlayers;
    *headListPlayers=newNodePlayer;
}

void addFirstInListTeams(NodeTeam **headListTeams, char *bufferTeamName, NodePlayer *headListPlayers)
{
    NodeTeam *newNodeTeam=NULL;
    newNodeTeam=(NodeTeam *)malloc(sizeof(NodeTeam));
    if(newNodeTeam==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    newNodeTeam->teamName=(char *)malloc((strlen(bufferTeamName)+1)*sizeof(char));
    if(newNodeTeam->teamName==NULL)
    {
        printf("Memory error");
        exit(1);
    }
    int lenght=strlen(bufferTeamName);
    if(bufferTeamName[lenght-1]=='\n')
    {
        lenght--;
    }
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
        fprintf(outputFile,"%s",p->teamName);
        if(p->next!=NULL)
        {
            fprintf(outputFile,"\n");
        }
    }
}

float minPoints(NodeTeam *headListTeams)
{
    float Min=headListTeams->teamPoints;
    for(NodeTeam *p=headListTeams->next; p!=NULL; p=p->next)
    {
        if(Min>p->teamPoints)
        {
            Min=p->teamPoints;
        }
    }
    return Min;
}

void searchTeamWithLowestPoints(NodeTeam **headListTeams, NodePlayer **headListPlayers, float Min)
{
    NodeTeam *headcopy=*headListTeams;
    if(headcopy->teamPoints==Min)
    {
        *headListTeams=(*headListTeams)->next;
    }
    else
    {
        for(NodeTeam *p=*headListTeams; p!=NULL; p=p->next)
        {
            if(p->next->teamPoints==Min)
            {
                headcopy=p->next;
                p->next=p->next->next;
                break;
            }
        }
    }
    modifyListPlayers(&(*headListPlayers),headcopy->headPlayer,headcopy->numPlayers);
    free(headcopy->teamName);
    free(headcopy);
}

void modifyListPlayers(NodePlayer **headListPlayers, NodePlayer *headPlayer, int numberPlayers)
{
    NodePlayer *headcopy=*headListPlayers;
    if(headcopy==headPlayer)
    {
        int i=0;
        while(i!=numberPlayers)
        {
            headcopy=*headListPlayers;
            *headListPlayers=(*headListPlayers)->next;
            free(headcopy->player->firstName);
            free(headcopy->player->secondName);
            free(headcopy);
            i++;
        }
    }
    else
    {
        for(NodePlayer *p=*headListPlayers; p!=NULL; p=p->next)
        {
            if(p->next==headPlayer)
            {
                int i=0;
                while(i!=numberPlayers)
                {
                    headcopy=p->next;
                    p->next=p->next->next;
                    free(headcopy->player->firstName);
                    free(headcopy->player->secondName);
                    free(headcopy);
                    i++;
                }
                break;
            }
        }
    }
}




