//2

#include <iostream>
using namespace std;

void reverseArray(int *a){
    for(int i = 5; i >= 0; i--)
        cout << *(a+i) << " ";
    cout << endl;
}

int main(){
    int a[6];
    int *p = a;
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < 6; i++)
        cin >> *(p+i);
    reverseArray(p);
    return 0;
}
