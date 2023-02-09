//4
#include <iostream>
using namespace std;
#include "../DSA_Headers/stack.h"

void reverseStack(Stack<double>& s){
    Stack<double> auxStack;

    while(!s.isEmpty()){
        double n = s.stackArray[s.getTopLevel()];
        auxStack.push(n);
        s.pop();
    }

    auxStack.printStack();   
}

int main(){
    Stack<double> s;
    
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    
    double arr[n];
    cout << "Enter the numbers: " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++)
        s.push(arr[i]);
    
    s.printStack();
    
    reverseStack(s);

    return 0;
}