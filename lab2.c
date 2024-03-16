#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char mainstr[200], searchstr[30], repstr[30], resstr[200], copystr[200];
    int i=0, j=0 ,k=0, l, matchcnt, iStop, len, numofmatch=0;

    printf("\nEnter the main string :\n");
	scanf(" %[^\n]", mainstr);

    printf("\nEnter the Pattern string :\n");
	scanf(" %[^\n]", searchstr);
    
    printf("\nEnter the Replace string :\n");
	scanf(" %[^\n]", repstr);    
    
    strcpy(copystr, mainstr);
    
    for(i=0;i<(strlen(mainstr)-strlen(searchstr)+1);i++)
    {
        matchcnt = 0;
        for(j=0;j<strlen(searchstr);j++)
        {
            if(mainstr[i+j] == searchstr[j])
            {
                matchcnt++;
            }
            else
            {
                break;
            }
            if(matchcnt == strlen(searchstr))   //Check if number of character matches equals length of pattern string
            {
                numofmatch++;      //update number of total matches by 1
                for(k=0;k<i;k++)
                {
                    resstr[k] = mainstr[k];     //copy till the ith character where the match occured
                }
                iStop = k + strlen(searchstr); //point from where rest of the original string has to be copied
                resstr[k] = '\0';
                strcat(resstr, repstr); // append the replacement string
                len = strlen(resstr);
for(k=iStop, l=0; mainstr[k] != '\0';k++, l++) //copy rest of original string
                {
                    resstr[len+l] = mainstr[k];
                }
                resstr[len+l] = '\0';
                strcpy(mainstr,resstr);
            }
        }
    }
    printf("\nInput Text :\n");
    printf("%s\n",copystr);
    if(numofmatch > 0)
    {
        printf("\n%d matches occured\n\nText after replacing matched patterns is shown below\n", numofmatch);
        printf("\n%s\n",resstr);
    }
    else
    {
        printf("\nPattern String not found in Text\n");
    }
    return 0;
}

