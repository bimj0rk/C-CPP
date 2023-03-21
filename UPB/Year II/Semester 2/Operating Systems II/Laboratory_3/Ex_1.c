#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int buffer[5];
int in = 0;
int out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t waiterCondition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t cookCondition = PTHREAD_COND_INITIALIZER;

void *waiter(void *arg){
    int orderNo = 1;
    while(1){
        pthread_mutex_lock(&mutex);
        while((in + 1) % 5 == out){
            printf("Waiter: Buffer full. Waiting for cook to finish orders...\n");
            pthread_cond_wait(&waiterCondition, &mutex);
        }
        buffer[in] = orderNo;
        printf("Waiter: Added order %d to buffer.\n", orderNo);
        in = (in + 1) % 5;
        orderNo++;
        pthread_cond_signal(&cookCondition);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *cook(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        while(in == out){
            printf("Cook: Buffer empty. Waiting for new orders...\n");
            pthread_cond_wait(&cookCondition, &mutex);
        }
        int orderNo = buffer[out];
        printf("Cook: Started preparing order %d...\n", orderNo);
        buffer[out] = 0;
        out = (out + 1) % 5;
        pthread_cond_signal(&waiterCondition);
        pthread_mutex_unlock(&mutex);
        printf("Cook: Finished preparing order %d.\n", orderNo);
    }
    return NULL;
}

int main(){
    pthread_t waiterThread, cookThread;
    pthread_create(&waiterThread, NULL, waiter, NULL);
    pthread_create(&cookThread, NULL, cook, NULL);
    pthread_join(waiterThread, NULL);
    pthread_join(cookThread, NULL);
    return 0;
}