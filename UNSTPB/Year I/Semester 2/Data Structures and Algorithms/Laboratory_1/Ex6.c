#include <stdio.h>

int primeNumbers(int n){
    for(int i = 2; i < n; i++){
       int c = 0;
       for(int j = 1; j <= i; j++)
          if(i % j == 0) c++;
      if(c == 2) printf("%i is a prime number \n", i);
    }
    return 1;
}

int main(){
    int n;
    scanf("%i", &n);
    primeNumbers(n);
    return 0;
}