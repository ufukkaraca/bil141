#include <stdio.h>
#include <stdlib.h>

struct ucak {
char *kalkis, *varis;
int kapasite, yolcuSayisi;
int *koltuklar;
} typedef Ucak;

struct musteri {
char *ad, *soyad;
int koltukNo;
struct ucak *ucak;
} typedef Musteri;

Ucak* ucakOlustur(char *kalkis, char *varis, int kapasite)
{
Ucak *ucak = calloc(1, sizeof(Ucak));
ucak->kalkis = kalkis;
ucak->varis = varis;
ucak->yolcuSayisi = 0;
ucak->kapasite = kapasite;
ucak->koltuklar = calloc(kapasite, sizeof(int));
return ucak;
}

Musteri* musteriOlustur(char *ad, char *soyad)
{
Musteri *musteri = calloc(1, sizeof(Musteri));
musteri->ad = ad;
musteri->soyad = soyad;
return musteri;
}

int biletKes(Musteri *musteri, Ucak *ucak, int koltukNo)
{
if (ucak->yolcuSayisi < ucak->kapasite) {
if (*(ucak->koltuklar+koltukNo) == 1) {
int i = 0;
while (*(ucak->koltuklar+i) == 1)
i++;
koltukNo = i;
}

musteri->ucak = ucak;
musteri->koltukNo = koltukNo;
ucak->yolcuSayisi++;
*(ucak->koltuklar+koltukNo) = 1;
return koltukNo;
}

else
return -1;
}

char* neredenGeliyor(Musteri *musteri)
{
Ucak *ucak = musteri->ucak;
char *kalkis = ucak->kalkis;
return kalkis;
}
char* nereyeGidecek(Musteri *musteri)
{
return musteri->ucak->varis;
}

int main()
{
Ucak *ucak1 = ucakOlustur("Ankara", "Istanbul", 3);
Ucak *ucak2 = ucakOlustur("Adiyaman", "Diyarbakir", 4);

Musteri *musteri1 = musteriOlustur("X", "Y");
Musteri *musteri2 = musteriOlustur("A", "B");
Musteri *musteri3 = musteriOlustur("C", "D");
Musteri *musteri4 = musteriOlustur("E", "F");
Musteri *musteri5 = musteriOlustur("G", "H");

int koltukNo1 = biletKes(musteri1, ucak1, 0);
int koltukNo2 = biletKes(musteri2, ucak1, 3);
int koltukNo3 = biletKes(musteri3, ucak1, 3);
int koltukNo4 = biletKes(musteri4, ucak1, 1);
int koltukNo5 = biletKes(musteri5, ucak2, 3);

printf("%d %d %d %d %d\n", koltukNo1, koltukNo2, koltukNo3, koltukNo4, koltukNo5);
printf("%s %s\n", musteri1->ad, neredenGeliyor(musteri1));
printf("%s %s\n", musteri2->ad, nereyeGidecek(musteri5));
}