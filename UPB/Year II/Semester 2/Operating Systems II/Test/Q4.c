#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int colorRightNow = 0;

void* semaphore(void* args){
    int *id = *(int*)args;
    while(1){
        pthread_mutex_lock(&mutex);
        while(colorRightNow != id){
            pthread_cond_wait(&cond, &mutex);
        }
        if(id == 0){
            printf("Green\n");
            sleep(5);
            colorRightNow = 2;
        }else if(id == 1){
            printf("Red\n");
            sleep(5);
            colorRightNow = 0;
        }else if(id == 2){
            printf("Yellow\n");
            sleep(1);
            colorRightNow = 1;
        }
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
}
int main(){
    pthread_t red, yellow, green;
    int idRed = 0, idYellow = 2, idGreen = 1;
    pthread_create(&red, NULL, semaphore, &idRed);
    pthread_create(&yellow, NULL, semaphore, &idYellow);
    pthread_create(&green, NULL, semaphore, &idGreen);
    pthread_join(red, NULL);
    pthread_join(yellow, NULL);
    pthread_join(green, NULL);
    return 0;
}