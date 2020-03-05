#include <stdio.h>

int main () {

    int*  a,b; // declaration of pointer a and normal variable b
	b = 4;
	a = &b;
    
	printf("The value of a is : %d\n", a  );
	printf("The value of b is : %d\n", b  );
 
    return 0;
}
