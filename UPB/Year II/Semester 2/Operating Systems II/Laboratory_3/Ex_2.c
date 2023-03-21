#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int buffer[5]; 
int in = 0; 
int out = 0; 
int noAvaillableSlots = 5;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_t driverCondition = PTHREAD_COND_INITIALIZER;  
pthread_cond_t parkingCondition = PTHREAD_COND_INITIALIZER;  

void *driver(void *arg){
    int carNo = 1;
    while(1){
        pthread_mutex_lock(&mutex);
        while((in + 1) % 5 == out){
            printf("Driver %d: Parking full. Waiting for available parking...\n", carNo);
            pthread_cond_wait(&driverCondition, &mutex);
        }
        buffer[in] = carNo;
        printf("Driver %d: Requested parking spot.\n", carNo);
        in = (in + 1) % 5;
        carNo++;
        pthread_cond_signal(&parkingCondition);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *parking_lot(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);
        while(in == out && noAvaillableSlots == 0){
            printf("Parking lot: No available parking lots. Waiting for parking requests...\n");
            pthread_cond_wait(&parkingCondition, &mutex);
        }
        if(in != out){
            int carNo = buffer[out];
            printf("Parking lot: Reserved parking spot for driver %d.\n", carNo);
            buffer[out] = 0;
            out = (out + 1) % 5;
            noAvaillableSlots--;
            pthread_cond_signal(&driverCondition);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t driverThread, parkingThread;
    pthread_create(&driverThread, NULL, driver, NULL);
    pthread_create(&parkingThread, NULL, parking_lot, NULL);
    pthread_join(driverThread, NULL);
    pthread_join(parkingThread, NULL);
    return 0;
}