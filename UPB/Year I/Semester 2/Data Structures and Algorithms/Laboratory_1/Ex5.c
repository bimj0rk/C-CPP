#include <stdio.h>

int palindrome(int x){
    int aux, pal;
    aux = x;
    while(x){
        pal = pal*10 + x%10;
        x /= 10;
    }
    if(pal == aux) printf("The number %i is a palindrome \n", aux);
    else printf("The number is not a palindrome");   
    return 1;
}

int main(){
    int a;
    scanf("%i", &a);
    palindrome(a);
    return 0;
}