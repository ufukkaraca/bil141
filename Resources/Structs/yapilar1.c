#include <stdio.h>
#include <string.h>

typedef struct // main'in üstünde
{
    int oynadigiMacSayisi;
    char takimAdi[50];
    int galibiyet;
    int beraberlik;
    int maglubiyet;
    int attigiGol;
    int yedigiGol;
    int puan;
    int averaj;
} Takim;

int main()
{

	Takim takim1;
	strcpy(takim1.takimAdi,"Barcelona");
	takim1.maglubiyet = 1;
	//takim1.takimAdi="Barcelona";
	printf("Takim Adi: %s\n", takim1.takimAdi);
	printf("maglubiyet: %d", takim1.maglubiyet);
    
    return 0;
}











