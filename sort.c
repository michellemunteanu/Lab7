#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *text[LENGTH];
    int i=0;
    
    FILE *sth;
    
//open file to read from
    sth = fopen("sth.csv", "r");
    if (sth == NULL)
    {
        printf("There was a problem opening the file\n");
        return 1;
    }
//while you haven't reached EOF, assign each line to an array of strings
    while(fscanf(sth, "%s ", &text[i]) != EOF)
    {
	i++;	
    }
//after array of strings is complete, excecute command line options
 
    int sflag=0;
    int nflag=0;
    int rflag=0;

    if (argc == 1)
    {
	//the input will be copied to the output unchanged
    }
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            sflag=1;
        }
        else if (strcmp(argv[i], "-n") == 0)
        {
            nflag=1;
        }
        else if (strcmp(argv[i], "-r") == 0)
        {
            rflag=1;
        }
        else
        {
            printf("Note: -s, -n, or -r are the only valid options\n");
	    return 1;
        }
    }
    
    if(sflag)
    {
	//text output will be sorted in ascending order 
    }
    else if(nflag)
    {
	//numeric output will be sorted in ascending order
    }
    
    if(rflag)
    {
	//the output will be reversed
    }
//print out array
fclose(sth);    
return 0;
}
                                                                                44,1       
