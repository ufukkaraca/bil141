#include <stdio.h>
int main()
{
	int a = 5;
	int* b = &a; 
	int **c = &b;
	printf("a'nin degeri: %d\n",a);
	printf("a'nin adresi: %d\n",&a);
	printf("b'nin degeri: %d\n",b);
	printf("b'nin adresi: %d\n",&b);
	printf("b pointer'inin tuttugu adresteki deger (a): %d\n",*b);
	printf("c'nin degeri: %d\n",c);
	printf("c'nin adresi: %d\n",&c);
	printf("c pointer'inin tuttugu adresteki deger (b): %d\n",*c);
	printf("c pointer'inin tuttugu adresteki deger bir adresti. O adresteki deger (a): %d\n",**c);
	
	return 0;
}