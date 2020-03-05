#include <stdio.h>
#include <stdlib.h>

struct ucak{
	char *kalkis;
	char *varis;
	int kapasite, yolcuSayisi;
	int *koltuklar;
} typedef Ucak;

struct musteri{
	char *ad;
	char *soyad;
	int koltukNo;
	struct ucak *ucus;
	struct musteri *anne;
} typedef Musteri;

Ucak* ucakOlustur(char *_kalkis,char *_varis,int _kapasite){
	Ucak *yeniucak = (Ucak*)calloc(1,sizeof(Ucak));
	yeniucak->kalkis = _kalkis;
	yeniucak->varis = _varis;
	yeniucak->kapasite = _kapasite;
	yeniucak->yolcuSayisi=0;
	yeniucak->koltuklar=(int*)calloc(_kapasite,sizeof(int));
	return yeniucak;
}

Musteri* musteriOlustur(char *ad, char *soyad){
	Musteri *musteri= (Musteri*)calloc(1,sizeof(Musteri));
	musteri->ad = ad;
	musteri->soyad = soyad;
	musteri->anne = (Musteri*)calloc(1,sizeof(Musteri));
	musteri->anne->soyad = "A";
	return musteri;
}


int biletKes(Musteri* musteri, Ucak* ucak, int koltukNo){
	if(ucak->yolcuSayisi < ucak->kapasite){
		if(*(ucak->koltuklar+koltukNo)==0){
			musteri->ucus = ucak;	
			*(ucak->koltuklar+koltukNo)=1;
			ucak->yolcuSayisi += 1;
			musteri->koltukNo=koltukNo;
		}
	}
}

int main(){
	Ucak *yeniucak = ucakOlustur("Ankara","Istanbul",5);
	Musteri *musteri1 = musteriOlustur("A","B");
	Musteri *musteri2 = musteriOlustur("X","Y");
	
	biletKes(musteri1,yeniucak,3);
	biletKes(musteri2,yeniucak,1);
	
	printf("%sdan %sa ucan ucagin kapasitesi: %d\n"
		   ,yeniucak->kalkis,yeniucak->varis,yeniucak->kapasite);
	printf("musteri: %s %s\n",musteri1->ad,(musteri1->anne)->soyad);
	printf("%s\n",musteri1->ucus->kalkis);

}










