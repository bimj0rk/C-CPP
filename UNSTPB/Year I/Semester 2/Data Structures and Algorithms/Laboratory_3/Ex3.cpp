//3
#include <iostream>
#include "../DSA_Headers/stack.h"
using namespace std;

int main(){
    Stack <int> s;
    s.isEmpty();
    s.push(3);
    s.push(5);
    s.push(8);
    s.pop();
    s.push(6);
    s.printStack();
    return 0;
}