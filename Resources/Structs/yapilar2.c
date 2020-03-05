#include <stdio.h>
#include <string.h>

typedef struct // main'in üstünde
{
    char takimAdi[50];
    int oynadigiMacSayisi;
    int galibiyet;
    int beraberlik;
    int maglubiyet;
    int attigiGol;
    int yedigiGol;
    int puan;
    int averaj;
} Takim;

int puanHesapla(Takim);
void takimYazdir(Takim);
int main(){
    int i;
    Takim takimlar[2];
    for(i=0; i<2; i++){
        printf("Lutfen takim adini giriniz: ");
        scanf("%s", takimlar[i].takimAdi); 
		//stringlerde &  kullanılmadığını hatırlayın
        printf("Lutfen galibiyet sayisini giriniz: ");
        scanf("%d", &takimlar[i].galibiyet);
        printf("Lutfen beraberlik sayisini giriniz: ");
        scanf("%d", &takimlar[i].beraberlik);
        takimlar[i].puan = puanHesapla(takimlar[i]);		
    }
	for(i=0; i<2; i++){
		takimYazdir(takimlar[i]);
	}
	
    return 0;
}
int puanHesapla(Takim t){
    return t.galibiyet*3 + t.beraberlik;
}

void takimYazdir(Takim t){
	printf("Takim: %s, galibiyet: %d, beraberlik: %d, puan:%d \n",
		  t.takimAdi, t.galibiyet, t.beraberlik, t.puan);	
}






