#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///#include "player.h"
#include "list.h"

int main()
{
    FILE *cFile,*dataFile,*outputFile;

    cFile=fopen("c.in.txt","rt");
    if(cFile==NULL)
    {
        printf("File cannot be open");
        exit(1);
    }

    int *c;
    c=(int *)malloc(5*sizeof(int));

    for(int i=0; i<5; i++)
    {
        fscanf(cFile,"%d",c+i);
    }

    fclose(cFile);

    dataFile=fopen("d.in.txt","rt");
    if(dataFile==NULL)
    {
        printf("File cannot be open");
        exit(1);
    }

    outputFile=fopen("r.out.txt","wt");
    if(outputFile==NULL)
    {
        printf("File cannot be open");
        exit(1);
    }

    if((*c)==1)
    {
        Node *headListPlayers=NULL;
        NodeTeam *headListTeams=NULL;
        int numTeams,numPlayers;
        fscanf(dataFile,"%d",&numTeams);
        printf("%d\n",numTeams);

        for(int i=0; i<numTeams; i++)
        {
            fscanf(dataFile,"%d ",&numPlayers);

            char bufferTeamName[50];
            fgets(bufferTeamName,50,dataFile);
            for(int j=0; j<numPlayers; j++)
            {
                addFirstInListPlayers(&headListPlayers,dataFile);
            }
            addFirstInListTeams(&headListTeams,bufferTeamName,headListPlayers);
        }
        displayListTeams(headListTeams,outputFile);

    }

    free(c);

    fclose(dataFile);
    fclose(outputFile);

    return 0;
}
