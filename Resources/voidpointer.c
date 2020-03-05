#include <stdlib.h>
#include <stdio.h> 

int main() {
   int a = 7;
   float b = 7.6;
   void *p;
   p = &a;
   printf("Integer variable is = %d\n", *( (int*) p) );
   p = &b;
   printf("Float variable is = %lf\n", *( (float*) p) );
   return 0;
}