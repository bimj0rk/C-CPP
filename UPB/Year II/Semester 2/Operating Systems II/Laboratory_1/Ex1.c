#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void distort(char* message){
    int length = strlen(message);
    int index = rand() % length;
    message[index] = rand() % 26 + 'A';
}

int main(){
    srand(time(NULL));

    int numberOfPlayers;
    printf("Enter the number of players: ");
    scanf("%d", &numberOfPlayers);

    char message[100];
    printf("Enter the message to be sent: ");
    getchar();
    fgets(message, sizeof(message), stdin);

    int length = strlen(message);
    if(message[length - 1] == '\n') message[length - 1] = '\0';

    for(int i = 1; i <= numberOfPlayers; i++){
        printf("Player %d recieved the message: %s\n", i, message);
        distort(message);
    }

    return 0;
}

