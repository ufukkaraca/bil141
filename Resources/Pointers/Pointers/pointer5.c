#include <stdio.h>
int main()
{
	int a[3] = {9,4,8};
	int* b = &a[0]; 
	int **c;
	c = &b;
	printf("%d",a[0]);
	(**c)++;
	printf("%d",a[0]);
	(*b)++;
	printf("%d",*b);
	b++;
	printf("%d",*b);
	
	return 0;
}





