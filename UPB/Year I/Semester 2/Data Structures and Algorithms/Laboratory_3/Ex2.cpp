//2
#include <iostream>
using namespace std;

template <typename t1, typename t2> 
void bubbleSort(t1 array[], t2 n){
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(array[j] > array[j+1]) swap(array[j], array[j+1]);
}

template <typename t3, typename t4>
void swap(t3 &a, t4 &b){
    int aux = a;
    a = b;
    b = aux;
}


int main(){
    int a[5];
    cout << "Enter the values: " << endl;
    for(int i = 0; i < 5; i++)
        cin >> a[i];

    bubbleSort(a, 5);

    cout << "Sorted array: ";
    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";

    cout << endl;
    swap(a[0], a[4]);
    cout << "Sorted and swapped array: ";
    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";

    return 0;
}