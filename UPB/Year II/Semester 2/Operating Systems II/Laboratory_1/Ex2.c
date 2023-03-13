#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isVowel(char c){
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void convertToChickenLanguage(char* word, char* chickenWord){
    int length = strlen(word);
    int i = 0, j = 0;

    while(i < length){
        if(isVowel(word[i])){
            chickenWord[j++] = 'p';
            chickenWord[j++] = word[i];
            chickenWord[j++] = 'p';
        } else {
            chickenWord[j++] = word[i];
        }
        i++;
    }

    chickenWord[j] = '\0';
}

int main(){
    char message[100], chickenMessage[100];
    printf("Enter a message: ");
    fgets(message, 100, stdin);

    int length = strlen(message);
    if(message[length - 1] == '\n') message[length - 1] = '\0';

    char* token = strtok(message, " ");

    while(token != NULL){
        convertToChickenLanguage(token, chickenMessage);
        printf("%s ", chickenMessage);
        token = strtok(NULL, " ");
    }

    return 0;
}