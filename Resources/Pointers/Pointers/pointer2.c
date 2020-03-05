#include <stdio.h>
int main()
{
	int* yasar;
	int a;
	yasar=&a;// bir işaretçi değişkeninin değerini elle atama
	//Muhtemelen o uydurduğumuz adrese erişim olmayacak ve kod çökecektir.
	printf("%d", *yasar);//Bu adres içindeki veriyi bastırma
    return 0;
}