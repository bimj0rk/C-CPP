//5
#include <iostream>
using namespace std;
#include "../DSA_Headers/stack.h"

template<typename T>
class LargeStack{
    private:
        Stack<T> Smain, Saux;
    
    public:
        void push(T x){
            if (Smain.getTopLevel() >= NMAX-1) {
                cout << "The stack is full: we have already NMAX elements!\n";
                return;
            }
            Smain.push(x);
        }

        T pop(){
            if (Smain.isEmpty()){
                cout << "The stack is empty! \n";
                T x;
                return x;
            }
            Smain.pop();
            return Smain.stackArray[Smain.getTopLevel()];
        }

        void swap(int i, int j){
            Saux.push(Smain.stackArray[i]);
            Smain.stackArray[i] = Smain.stackArray[j];
            Smain.stackArray[j] = Saux.peek();
            Saux.pop();
        }

        void printStack(){
            Smain.printStack();
        }
};

int main(){
    LargeStack<int> LS;
    LS.push(3);
    LS.push(6);
    LS.push(7);
    LS.printStack();
    LS.pop();
    LS.swap(0, 1);
    LS.printStack();
}