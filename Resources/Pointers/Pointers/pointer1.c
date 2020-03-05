#include <stdio.h>
int main()
{
	int sayi=7; //4 baytlık sayi 7 değerini aldı.
	int* ptr; //8 baytlık ptr işaretçisi tanımlandı.
	ptr = &sayi; // ptr, sayi'nin RAMdeki adresini aldi.
	printf("%x\n", ptr); //ptr'nin değeri ekrana yazdirildi.
	printf("%x\n", &sayi); //sayi değişkeninin adresini yazdırır.
	printf("%d\n", sayi); //sayi değişkeninin değerini yazdırır.
	printf("%d\n", *ptr); //ptr'nin işaret ettiği yeri (sayi'yi) yazdırır.
	
	printf("%d\n", *&*&*ptr); 
	
	//scanf("%d",ptr);
	//printf("yeni sayi: %d\n",sayi);
	
	// Uyari vermemesi icin isaretcilerde %p kullanilir.
	// Ancak sayisal degerini daha rahat yorumlamak icin
	// derste, uyari vermesini goze alarak, %d kullacanagiz.
	
	/*
		* ile & birbirinin tersi görevi görürler. (çarpma ile bölme gibi)
		scanf("%d", &sayi); yerine
		scanf("%d", &*&*&sayi); yazimi soz dizim acisindan dogrudur.
		
		ptr = &sayi; dediğimizde
		iki tarafi da soldan * ile çarparsak
		*ptr'nin *&sayi'ya denk olduğu görülür.
		*&sayi ise aslinda sayi'dir.
		
		Yani
		ptr = &sayi; ifadesi ile
		*ptr ile sayi arasinda bir denklik (adaşlık) tanımlanmıştır.
		
		Bundan sonra kodda nerede sayi geçerse *ptr ile değiştirseniz de kodda bir şey değişmez.
		Yine, kodda nerede *ptr geçerse, onu sayi ile değiştirebilirsiniz.
	*/
	
	
	
    return 0;
}
