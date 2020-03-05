#include <stdio.h>
void ucgen( int n);
int main()
{
	ucgen(5);
    return 0;
}
void ucgen( int n)
{
	if(n==0)
		return;
	int i;
	for(i=1; i<=n; i++)
		printf("* ");
	printf("\n");
	
	ucgen(n-1);	
}