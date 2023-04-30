#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///#include "player.h"
#include "list.h"

int main()
{
    FILE *cFile,*inputFile,*outputFile;

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

    inputFile=fopen("d.in.txt","rt");
    if(inputFile==NULL)
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
        NodePlayer *headListPlayers=NULL;
        NodeTeam *headListTeams=NULL;
        createLists(&headListPlayers,&headListTeams,inputFile);
        displayListTeams(headListTeams,outputFile);

    }

    free(c);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
