#include <stdio.h>

int factorial(int n){
    int product = 1;
    for(int i = 1; i <= n; i++){
        product *= i;
    }
    printf("The factorial of %i is %i \n", n, product);
    return 1;
}

int main(){
    int n;
    scanf("%i", &n);
    factorial(n);
    return 0;
}