#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int n = 10;
	int dizi[10]= {5,8,4,6,3,9,7,1,0,2};
	int gecis,j;
	for(gecis=1; gecis<=n-1; gecis++)
	{
		//her geciste gorevim ciftleri incelemek
		for(j=0; j<=n-2; j++)
		{
			if( dizi[j] > dizi[j+1])
			{
				int temp = dizi[j];
				dizi[j] = dizi[j+1];
				dizi[j+1] = temp;
			}

		}

	}

	
	int i=0;
	for(;i<10;i++)
		printf("%d ",dizi[i]);
	
	return 0;
}
