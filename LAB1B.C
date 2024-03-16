/*
 Develop a Program in C for the following:
---------------------------------------------------------------------------------------------------
a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent
7 days of a week. Each Element of the array is a structure having three fields. The first
field is the name of the Day (A dynamically allocated String), The second field is the
date of the Day (A integer), the third field is the description of the activity for a
particular day (A dynamically allocated String).
---------------------------------------------------------------------------------------------------
Develop a Program in C for the following:
b) Write functions create(), read() and display(); to create the calendar, to read the data
from the keyboard and to print weeks activity details report on screen.
---------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define W 7

//structure to represent a day 
typedef struct 
{
    char *DAY;
    int iDATE;
    char *AC;
}DT;


void disp (DT *);
void read (DT *);
DT *creat();

int main()
{
    DT *wcal = creat();
    read(wcal);
    disp(wcal);
    
    return 0;
}

DT *creat()
{
    DT *cal = (DT *)malloc(W *sizeof(DT));
    for (int i = 0; i < W; i++)
    {
        cal[i].DAY = NULL;
        cal[i].iDATE = 0;
        cal[i].AC = NULL;
    }
    return cal;
}

void read(DT *cal)
{
    char c;
    for(int i = 0; i < W; i++)
    {
        printf("DO YOU WANT TO ENTER DETAILS FOR DAY %d [Y/N]: ", i+1);
        // printf("\n");
        scanf("%c", &c);
        getchar();

        if(tolower(c) == 'n')
        continue;
        
        printf("DAY NAME : ");
        
        char nB[50];
        scanf("%s",nB);
        cal[i].DAY = strdup(nB);

        printf("DATE : ");
        scanf("%d", &cal[i].iDATE);

        printf("ACTIVITY : ");
        char aB[100];
        scanf("%c", aB);
        cal[i].AC = strdup(aB);
        printf("\n");
        getchar(); 
    }
}

void disp(DT *cal)
{
    printf("\nWEEKS AC DERAILS : \n");
    for(int i = 0; i < W; i++)
    {
        printf("DAY %d : \n",i+1);
        if(cal[i].iDATE == 0)
        {
            printf("NO AC  \n");
            continue;
        }
        printf(" DAY NAME : %s\n", cal[i].DAY);
        printf(" DATE : %d\n",cal[i].iDATE);
        printf(" ACTIVITY : %s\n",cal[i].AC);
    }
} 


 
 
 
 
 
 

