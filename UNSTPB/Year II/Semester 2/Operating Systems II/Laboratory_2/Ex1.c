#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double balance;
pthread_mutex_t mutex;

double computeInterest(double balance){
    double interestRate = 0.007;
    double totalInterest = 0.0;
    for(int i = 0; i < 120; i++){
        double interest = balance * interestRate;
        totalInterest += interest;
        balance += interest;
    }

    return totalInterest;
}

void* computeInterestThread(void* arg){
    double interest = computeInterest(balance);
    pthread_mutex_lock(&mutex);
    *(double*)arg =+ interest;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(){
    double totalInterest = 0;
    pthread_t threads[10];

    printf("Enter your balance: ");
    scanf("%lf", &balance);

    for(int i = 0; i < 10; i++) pthread_create(&threads[i], NULL, computeInterestThread, (void*)&totalInterest);

    for(int i = 0; i < 10; i++) pthread_join(threads[i], NULL);

    printf("Total interest earned over 10 years: %.2lf\n", totalInterest);

    return 0;
}