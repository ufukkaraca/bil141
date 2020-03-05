#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ali[]="Ali";
    printf("%s", ali);

    (char*)realloc(ali, 9*sizeof(char));

    strcpy(ali,"ali baba");
    printf("%s", ali);

    
    return 0;
    }