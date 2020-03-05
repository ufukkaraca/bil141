#include <stdio.h>
#include <string.h>
typedef struct
{
      int kod;
      char isim[100];
      double fiyat;
} urun_yapi;
void kabarcik( urun_yapi urun[6], int n );
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
            //printf("%d %s %lf alindi.\n", urun[i].kod, urun[i].isim, urun[i].fiyat ); //HATA AYIKLAMA
      }

      printf("MANAVA HOS GELDINIZ!\n");
      printf("KOD\tISIM\t\tFIYAT\n");
      int j;
      kabarcik(urun, 6);
      for(j=0; j<6; j++)
      {
            printf("%.3d\t%s\t\t%.2lf\n",urun[j].kod, urun[j].isim, urun[j].fiyat );
      }


      return 0;
}

void kabarcik( urun_yapi urun[6], int n )
{
      int gecis, sayac;
      for(gecis=1; gecis<=n-1; gecis++)
      {
            sayac = 0;
            int j;
            //her geciste gorevim ciftleri incelemek
            for(j=0; j<=n-2 -(gecis-1); j++)
            {
                  if( urun[j].kod > urun[j+1].kod)
                  {
                        /*		int temp = urun[j].kod;
                        		urun[j].kod = urun[j+1].kod;
                        		urun[j+1].kod = temp;

                        		double temp2 = urun[j].fiyat;
                        		urun[j].fiyat = urun[j+1].fiyat;
                        		urun[j+1].fiyat = temp2;

                        		char temp3[100];
                        		strcpy(temp3, urun[j].isim);
                        		strcpy(urun[j].isim, urun[j+1].isim);
                        		strcpy(urun[j+1].isim, temp3);
                        		sayac++;
                        */
                        /*
                        	Yukarýdaki uzun uzun olan alt deðiþken üzerinden atamalar yerine
                        	= iþlecinin yapýlarda tüm alt deðiþkenleri kopyalamasýndan
                        	yararlanarak...
                        */
                        urun_yapi temp;
                        temp = urun[j];
                        urun[j] = urun[j+1];
                        urun[j+1] = temp;
                  }

            }
            if(sayac == 0)
                  break;
      }




}


