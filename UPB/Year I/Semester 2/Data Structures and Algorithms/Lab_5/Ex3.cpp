//3

#include <iostream>
using namespace std;

void replaceArray(int *a){
    for(int i = 0; i < 3; i++)
    swap(*(a+i), *(a+5-i));
}

void displayArray(int *a){
    for(int i = 0; i < 6; i++){
        cout << *(a+i) << " ";
    }
    cout << endl;
}

int main(){
    int a[6];
    int *p = a;
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < 6; i++)
        cin >> *(p+i);
    replaceArray(p);
    displayArray(p);
    return 0;
}