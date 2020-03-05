#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//sleep fonksiyonu için gerekli olan kütüphaneleri gerekli olan iþletim sistemlerine göre ekliyorum
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void printer(int[], int);
double average(int[], int);
int modefinder(int[], int, int);
double medianfinder(int[],int);
double variancefinder(int[], int);
double standartdeviation(double);
void reverser(int[],int);
void changer(int[], int);
void resetter(int[], int);

int main(){
    srand(time(NULL));
    int temp, capacity, rangemin, rangemax, i, request;

    printf("Lutfen integer dizinizin kapasitesini giriniz: ");
    scanf("%d", &capacity);
    int array[capacity];
    
    printf("Lutfen rastgele sayi araligini giriniz [a-b formatinda]: ");
    scanf("%d-%d", &rangemin, &rangemax);

    for (i=0; i<capacity; ++i)
        array[i]= (rand()%(rangemin-rangemax+1)+rangemin)*1;

    printf("Diziniz olusturulmustur.\n\n");
    printf("***** Ne yapmak istersiniz? *****\n");
    printf("0. Cikis\n1. Elemanlari yazdir\n2. Ortalama al\n3. Modu bul\n4. Medyani bul\n5. Varyansi bul\n6. Standart sapmayi bul");
    printf("\n7. Diziyi ters cevir\n8. Eleman degistir\n9. Diziyi sifirla\n");
    scanf("%d", &request);

    while(request!=0){
    switch(request){
        case 1:
            printer(array, capacity);
            break;
        case 2:
            printf("Dizideki sayilarin ortalamasi: %.2lf", average(array, capacity));
            break;
        case 3:
            printf("Mod: %d", modefinder(array, capacity, rangemax));
            break;
        case 4:
            printf("Medyan: %.2lf", medianfinder(array,capacity));
            break;
        case 5:
            printf("Varyans: %.2lf", variancefinder(array, capacity));
            break;
        case 6:
            printf("Standart sapma: %.2lf", standartdeviation(variancefinder(array,capacity)));
            break;
        case 7:
            reverser(array,capacity);
            break;
        case 8:
            changer(array, capacity);
            break;
        case 9:
            resetter(array, capacity);
            break;
        default:
            printf("Gecersiz istek.");
            break;
    }
    printf("\n***** Ne yapmak istersiniz? *****\n");
    printf("0. Cikis\n1. Elemanlari yazdir\n2. Ortalama al\n3. Modu bul\n4. Medyani bul\n5. Varyansi bul\n6. Standart sapmayi bul");
    printf("\n7. Diziyi ters cevir\n8. Eleman degistir\n9. Diziyi sifirla\n");
    scanf("%d", &request);
    }
    
    printf("Cikisiniz yapiliyor...");
    Sleep(5000);
return 0;
}

void printer(int array[], int capacity){
    int j=0;
    printf("Dizideki elemanlar:");
    for(j=0; j<capacity; ++j){
        int eleman;
        eleman = array[j];
        printf (" %d", eleman);
    }
}

double average(int array[], int capacity){
    int total=0, i;
    double averagevalue;
    for(i=0; i<capacity; ++i){
        total+=array[i];
    }
    averagevalue = (double)total/(double)capacity;
    return averagevalue;
}

int modefinder(int array[], int capacity, int rangemax){
    int maxcount=0, maxoccurer, i, j, count;

    for(i=0; i<capacity; ++i){
        count=0;
        for(j=0; j<capacity; ++j){
            if (array[i]==array[j]){
                count++;  
            }
            if (count>maxcount){
                maxcount=count;
                maxoccurer=array[i];
            }

                    
        }
        
    }
    return maxoccurer;
}

double medianfinder(int array[], int capacity){
    int elementnumber=capacity-1, i, j, temp, temparray[capacity];
    double median;

    for(i=0; i<capacity; i++)
        temparray[i]= array[i];

    for(i=0; i<capacity; i++){
        for (j=0; j<elementnumber; j++){
            if(temparray[j]>temparray[j+1]){
                temp=temparray[j];
                temparray[j]=temparray[j+1];
                temparray[j+1]=temp;
                
            }
        }
    }

    if(capacity%2==0){
        median = ((double)(array[capacity/2] + array[(capacity-1)/2])/2);
    }
    else{
        median = ((double)array[capacity/2]);
    }
    
    return median;
}

double variancefinder(int array[], int capacity){
    int i;
    double total=0;
    double averagevalue = average(array, capacity);
    for(i=0; i<capacity; ++i){
        double temp1, temp2;
        temp1 = pow((array[i]-averagevalue), 2);
        temp2= temp1/(double)(capacity-1);
        total += temp2;
    }
    return total;
}

double standartdeviation(double n){
    double temp = sqrt(n);
    return temp;
}

void reverser(int array[], int capacity){
    int temparray[capacity], i;

    for(i=0; i<capacity; i++)
        temparray[i]= array[capacity-1-i];
    
    for(i=0; i<capacity; i++){
        int temp = temparray[i];
        temparray[i]=array[i];
        array[i]=temp;
        
    }
    printf("Dizi ters cevrildi.");
}

void changer(int array[], int capacity){
    int i, new;
    printf("Hangi indis'teki elemani degistirmek istiyorsunuz? ");
    scanf("%d", &i);

    while(i>=capacity){
        printf("Belirtilen indiste eleman bulunmamaktadir. Yeni bir indis giriniz: ");
        scanf("%d", &i);
    }
   
    printf("Lutfen yeni sayiyi giriniz: ");
    scanf("%d", &new);
    array[i]=new;

    printf("Eleman degistirildi.");
}

void resetter(int array[], int capacity){
    int i;
    for(i=0; i<capacity; i++)
        array[i]=0;

    printf("Dizi sifirlandi.");
}