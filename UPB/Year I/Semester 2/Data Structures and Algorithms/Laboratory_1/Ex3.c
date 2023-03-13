#include <stdio.h>

float min(float a, float b, float c){
    if(a<c && a<b) printf("Min is %f", a);
    else if(b<a && b<c) printf("Min is %f", b);
    else printf("Min is %f", c);
    return 1;
}

int main(){
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    min(a, b, c);
    return 0;
}