//3
#include <iostream>
#include "../DSA_Headers/lists.h"

LinkedList<int> list1;
LinkedList<int> list2;
int n;

void add(int x){
    if(x < n) list1.addFirst(x);
    else list2.addFirst(x);
}
    
int main(){
    std::cin >> n;
    int noOfElements;
    std::cin >> noOfElements;

    int i = 0;
    while(i < noOfElements){
        int y;
        std::cin >> y;
        add(y);
        i++;
    }

    list1.printList();
    list2.printList();
    return 0;
}