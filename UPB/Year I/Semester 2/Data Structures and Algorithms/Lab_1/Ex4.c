#include <stdio.h>

int digitSum(int x){
    int sum = 0;
    while(x){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int sum(int start, int finish){
    int sum = 0;
    for(int i = start; i <= finish; i++){
        sum += digitSum(i);
    }
    printf("The sum is %i", sum);
    return 0;
}

int main(){
    int start, finish;
    scanf("%i%i", &start, &finish);
    sum(start, finish);
    return 0;
}