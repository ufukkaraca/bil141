#include <stdio.h>
int main()
{
	int a[4]={14,15,16,17};
	printf("%d\n", a[2]);
	printf("%d\n", *(a+2) );
	printf("%d\n", a);
	printf("%d\n", a+2 );
;
    return 0;
}