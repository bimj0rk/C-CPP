#include <stdio.h>

int main(){
    int i = 10;
    printf("Integer variant %i \n", i);
    float f = 20;
    printf("Float variant %f \n", f);
    double d = 30;
    printf("Double variant %lf \n", d);
    char c = 'a';
    printf("Char variant %c \n", c);
    char s[] = "string";
    printf("String variant %s \n", s);
    return 0;
}