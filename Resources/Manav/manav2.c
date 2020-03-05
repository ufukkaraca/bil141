#include <stdio.h>
typedef struct
{
	int kod;
	char isim[100];
	double fiyat;
} urun_yapi;
int main()
{
	FILE* dosya = fopen("manav.txt", "r");
	if(dosya==NULL)
		return 1;

	urun_yapi urun[6]; // urun[0]	urun[1]
	int i;
	for(i=0; i<6; i++)
	{
		fscanf(dosya, "%d", &urun[i].kod );
		fscanf(dosya, "%s", urun[i].isim );
		fscanf(dosya, "%lf", &urun[i].fiyat );
		//printf("%d %s %lf alindi.\n", urun[i].kod, urun[i].isim, urun[i].fiyat );
	}

	printf("MANAVA HOS GELDINIZ!\n");
	printf("KOD\tISIM\t\tFIYAT\n");
	int j;
	for(i=0; i<6; i++)
	{
		for(j=0; j<6; j++) //kod sýrasýna göre yazdýrmak için - kabarcýk sýralama alternatifi olan yöntem
			if( urun[j].kod == i+1)
				printf("%.3d\t%s\t\t%.2lf\n",urun[j].kod, urun[j].isim, urun[j].fiyat );
	}


	return 0;
}
