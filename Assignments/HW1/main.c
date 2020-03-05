#include <stdio.h>
#include <math.h> 

//ana i�lemi ba�latmadan �nce olu�turdu�um fonksiyonlar� duyuruyorum
void discriminator(float,float,float);
void equationsolver(float,float,float,float,float);
int main() {
    char equation[1000];
    float x1;
    float x2;
    

    FILE* input1 = fopen("input.txt", "r");

    // Elimdeki dok�manda bana verilen t�m veriyi al�yor, 
    //ard�ndan gereksiz i�lem y�r�tmemek ad�na dosyay� kapat�yorum.
    
    float a, b, c;
    fscanf(input1, "y=%fx^2%fx%f", &a, &b, &c);
    fclose(input1);
    
    FILE* input2 = fopen("input.txt", "r");
    fscanf(input2,"%s[^\n]", &equation);
    fscanf(input2, "%f[^\n]", &x1);
    fscanf(input2, "%f[^\n]", &x2);
    fclose(input2);
    
    float discriminant = pow(b,2)-4*a*c;

    FILE* output = fopen("output.txt", "w");
    fprintf(output, "Equation: %s\n", equation);
    discriminator(a, b, discriminant);
    equationsolver(a, b, c, x1, x2);
    fclose(output);
    
        
    
    return 0;
}

//diskriminant ve k�k bulma i�lemleri i�in yeni bir fonksiyon olu�turdum.
void discriminator(float a, float b, float d){
    FILE* output = fopen("output.txt", "a");
    if (d>0)
    {
        fprintf(output, "Discriminant: %.2f. Therefore, there are two real roots.\n", d);
        float root1 = (-b + sqrt(d))/(2*a);
        float root2 = (-b - sqrt(d))/(2*a);
        fprintf(output, "1st root: %.2f\n", root1);
        fprintf(output, "2nd root: %.2f\n", root2);


    }
    
    else if (a==0)
    {
        fprintf(output, "Discriminant: %.2f. Therefore, there is one real root.\n", d);
        float root = (-b)/(2*a);
        fprintf(output, "Root: %.2f\n", root);
    }
   
    else //diskriminant�n 0'dan k���k oldu�u durumlar� hesaplamak i�in
    {
        fprintf(output, "Discriminant: %.2f. Therefore, there are no real roots.\n", d);
    }
}

//denklem ��zmek i�in bir fonksiyon olu�turdum.
void equationsolver(float a, float b, float c, float x1, float x2){
    FILE* output = fopen("output.txt", "a");
   
    float y1 = a*pow(x1,2)+b*(x1)+c;
    float y2 = a*pow(x2,2)+b*(x2)+c;

    fprintf(output, "For x=%.2f, y equals to %.2f.\n", x1, y1);
    fprintf(output, "For x=%.2f, y equals to %.2f.\n", x2, y2);
    
}