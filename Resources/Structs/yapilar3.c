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

void degistir1(Takim t, char *ad);
void degistir2(Takim *t, char *ad);
int main(){
    Takim takim1, takim2;
    strcpy(takim1.takimAdi, "Fenerbahce");
    degistir1(takim1, "Besiktas");
    printf("Main: %s\n", takim1.takimAdi);
    printf("---------------------------\n");
    strcpy(takim2.takimAdi, "Galatasaray");
    degistir2(&takim2, "Trabzonspor");
    printf("Takım Adı: %s\n", takim2.takimAdi);
    return 0;
}
void degistir1(Takim t, char *ad){
    strcpy(t.takimAdi, ad);
    printf("Fonksiyon1: %s\n", t.takimAdi);
}
void degistir2(Takim *t, char *ad){
    strcpy((*t).takimAdi, ad);
    printf("Fonksiyon2: %s\n", t->takimAdi);
}








