#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	
	int n = 10;
	int dizi[10]= {5,8,4,6,3,9,7,1,0,2};
	int gecis,j;
	int sayac;
	for(gecis=1; gecis<=n-1; gecis++)
	{
		sayac = 0;
		//her geciste gorevim ciftleri incelemek
		for(j=0; j<=n-2 -(gecis-1); j++)
		{
			if( dizi[j] > dizi[j+1])
			{
				// dizi[j] -> 4  dizi[j] -> 9
				int temp = dizi[j];
				dizi[j] = dizi[j+1];
				dizi[j+1] = temp;
				sayac++;
			}

		}
		/*Her gecisin sonunda dizinin aldigi hali ekrana yazdiralim*/
		if(sayac == 0)
			break;
		printf("%d.gecis sonucu:", gecis);
		int i=0;
		for(;i<10;i++)
			printf("%d ",dizi[i]);
		printf("\n");

	}
	int i=0;
	for(;i<10;i++)
		printf("%d ",dizi[i]);
	return 0;
}
