#include <iostream>
using namespace std;
#include "../DSA_Headers/stack.h"

template<typename T>
class StackedQueue{
    public:
        Stack<T> s1, s2;

        void enqueue(T x){
            s1.push(x);
        }

        T dequeue(){
            T x;
            while(s1.getTopLevel() != 0)
                s2.push(s1.pop());
            
            x = s1.peek();
            s1.pop();

            while(s2.getTopLevel() > -1)
                s1.push(s2.pop());

            return x;
        }

        T peek(){
            T x;
            while(s1.getTopLevel() != 0)
                s2.push(s1.pop());
            
            x = s1.peek();

            while(s2.getTopLevel() > -1)
                s1.push(s2.pop());
            
            return x;
        }

        bool isEmpty(){
            return s1.isEmpty();
        }

        StackedQueue(){}   

        ~StackedQueue(){}
};

int main(){
    StackedQueue<int> sQ;
    sQ.enqueue(5);
    cout << sQ.peek() << endl;
    sQ.enqueue(6);
    cout << sQ.peek() << endl;
    sQ.dequeue();
    cout << sQ.peek() << endl;
    return 0;
}