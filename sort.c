#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getarray(char *lines[]);
void printarray(char *lines[], int max);
int scmp (char **str1, char **str2);
int icmp (const void *a, const void *b);

int main(int argc, char *argv[])
{
    char *lines[100];
    int numlines = getarray(lines);
    printf("Got %d lines\n", numlines);
    //printarray(lines, numlines);

    int sflag=0;
    int nflag=0;
    int rflag=0;

    if (argc == 1) //no option selected -->cat
    {
        printarray(lines, numlines);
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
        qsort(lines, numlines, sizeof(char *), &scmp);
    }
    else if(nflag)
    {
	//sscanf(, 
	qsort(lines, numlines, sizeof(char *), &icmp);
        //numeric output will be sorted in ascending order
    }

    if(rflag)
    {
	//the output will be reversed
    }


    printarray(lines, numlines);
    return 0;    
}

int getarray(char *lines[])
{
    int i=0;
    char *text = (char *)malloc(200);
    while (fgets(text, 200, stdin) != NULL)
    {
	lines[i] = text;
	i++;
	text = (char *)malloc(200);
    }
    return i;
}

void printarray(char *lines[], int max)
{
    for (int i=0; i<max; i++)
    {
	printf("%s", lines[i]);
    }	
}
      
int scmp (char **str1, char **str2)
{
    return strcmp(*str1,*str2);
}

int icmp (const void *a, const void *b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    return aa-bb;
}
