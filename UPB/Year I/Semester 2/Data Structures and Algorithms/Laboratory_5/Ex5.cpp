//5

#include <iostream>
using namespace std;

void replaceSemicolon(char *p){
    char *aux;
    aux = strtok(p, ";");
    while(aux != NULL){
        cout << aux << " ";
        aux = strtok(NULL, ";");
    }
}

int main(){
    char p[] = "College;of;London";
    replaceSemicolon(p);
    return 0;
}