#include <stdio.h>
#include <string.h>
int main()
{
    char str1[50] ="simla" ;
    char revstr[50];
    char *stptr = str1;
    char *rvptr = revstr;
    //int i=-1;
	
	stptr += strlen(str1);
	int i = 0;
    /*while(*stptr)
    {
    	stptr++;
    	i++;
    }*/
	printf("%d %c\n", i, *stptr);
    while(i<strlen(str1))
    {
		stptr--;
		*rvptr = *stptr;
		rvptr++;
		i++;
    }
    *rvptr='\0';
    printf("Reverse of the string is : %s\n\n",revstr);
    return 0;
}