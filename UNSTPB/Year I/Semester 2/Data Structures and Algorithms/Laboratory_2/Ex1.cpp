//1

#include <iostream>
using namespace std;

void swap(double &a, double &b){
    int aux = a;
    a = b;
    b = aux;
}

void bubbleSort(double array[], double n){
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(array[j] > array[j+1]) swap(array[j], array[j+1]);
}

int main(){
    double array[5];
    for(int i = 0; i < 5; i++)
        cin >> array[i];
    bubbleSort(array, 5);
    for(int i = 0; i < 5; i++)
        cout << array[i] << " ";
    return 1;
}