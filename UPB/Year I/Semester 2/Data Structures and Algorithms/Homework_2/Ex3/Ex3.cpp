#include <iostream>

void heapify(int arr[], int size, int index){
    int right = 2*index + 2;
    int left = 2*index + 1;
    int root = index;

    if(left < size && arr[left] > arr[root]) root = left;

    if(right < size && arr[right] > arr[root]) root = right;

    if (root != index){
       std::swap(arr[index], arr[root]);
       heapify(arr, size, index);
    }
}

void heapSort(int arr[], int size){
    for(int i = size/2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    
    for(int i = size - 1; i >= 0; i--){
        std::swap(arr[0], arr[i]);
        heapify(arr, i , 0);
    }
}

int main(){
    int n;
    std::cout << "Enter the number of elements in the array: \n";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements of the array: \n";
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        arr[i] = x;
    }

    heapSort(arr, n);

    std::cout << "The sorted array is: \n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}