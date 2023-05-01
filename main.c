#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "queue.h"
#include "stack.h"

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
        ///printf("%d\n", numTeams);///
        int numTeamsNeeded;
        for(int i=1; i<=numTeams; i=i*2)
        {
            if(i*2>numTeams)
            {
                numTeamsNeeded=i;
            }
        }
        ///printf("%d\n",numTeamsNeeded);///
        ///printf("%d\n",minPoints(headListTeams));

        while(numTeamsNeeded!=numTeams)
        {
            modifyListTeams(&headListTeams,&headListPlayers,minPoints(headListTeams),numPlayers);
            numTeams--;
        }
        numTeams=numTeamsNeeded;
        ///fseek(outputFile,0,0);
        /**if((*(c+2))==0)**/ displayListTeams(headListTeams,outputFile);

    }
    if((*(c+2))==1)
    {
        Queue *QueueMatches=createQueueMatches();
        for(NodeTeam *p=headListTeams;p!=NULL;p=(p->next)->next)
        {
            enQueueMatches(QueueMatches,p,p->next);
        }
        fprintf(outputFile,"\n\n--- ROUND NO:1\n");
        displayQueueMatches(QueueMatches,outputFile);
        fprintf(outputFile,"\nWINNERS OF ROUND NO:1\n");


    }

    ///printf("%s \n",headListTeams->teamName);

/*
        for(NodePlayer *p=headListPlayers;p!=NULL;p=p->next)
        {
            printf("%s * %s -> %d\n",p->player->firstName,p->player->secondName,p->player->points);///
        }
*/
    ///freeTeam(headListTeams,numPlayers*numTeams);

    ///free(headListTeams);

    free(c);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
