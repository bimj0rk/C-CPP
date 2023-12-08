#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

char path[1000];
char word[100];
int count = 0;
pthread_mutex_t mutex;

void* searchWordThread(void* arg){
    FILE* fp = fopen((char*)arg, "r");
    if(fp == NULL){
        perror("fopen");
        pthread_exit(NULL);
    }

    char line[1000];
    while(fgets(line, 1000, fp) != NULL){
        char* p = line;
        while((p = strstr(p, word)) != NULL){
            pthread_mutex_lock(&mutex);
            count++;
            pthread_mutex_unlock(&mutex);
            p += strlen(word);
        }
    }

    fclose(fp);
    pthread_exit(NULL);
}

int main(){
    printf("Enter the file path: ");
    fgets(path, 1000, stdin);
    path[strcspn(path, '\n')] = '\0';
    
    printf("enter the word to search for: ");
    scanf("%s", word);

    DIR* dir = opendir(path);
    if(dir == NULL){
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent* entry;
    char files[1000][1000];
    int numberOfFiles = 0;

    while((entry = readdir(dir)) != NULL){
        if(entry -> d_type == DT_REG){
            strcpy(files[numberOfFiles], path);
            strcpy(files[numberOfFiles], "/");
            strcpy(files[numberOfFiles], entry -> d_name);
            numberOfFiles++;
        }
    }

    closedir(dir);

    pthread_t threads[4];
    for(int i = 0; i < numberOfFiles; i += 4){
        for(int j = 0; j < 4 && i + j < numberOfFiles, j++) pthread_create(&threads[j], NULL, searchWordThread, (void*)files[i + j]);
        for(int j = 0; j < 4 && i + j < numberOfFiles, j++) pthread_join(threads[i], NULL);
    }

    printf("Total count of '%s' in %d files is: %d\n", word, numberOfFiles, count);

    return 0;
}