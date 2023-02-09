#include <stdio.h>

int main(){
    float a, b;
    scanf("%f%f", &a, &b);
    float c = (a+b)/2;
    printf("Average of %f and %f is %.2f \n", a, b, c);
    return 0;
}