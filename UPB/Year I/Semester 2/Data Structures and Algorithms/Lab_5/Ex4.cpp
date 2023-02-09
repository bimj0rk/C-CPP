//4

#include <iostream>
using namespace std;

char* getCounty(char *s){
    char * str;
    str = strtok(s, ".");
    char * county;
    while(str != NULL){
        county = str;
        str = strtok(NULL, ".");
    }
    return county;
}

int main(){
    char s[] = "Slatina.OT";
    char *p = s;
    cout << getCounty(p) << endl;
    return 0;
}