#include <iostream>
using namespace std;
#include "../DSA_Headers/queuecirc.h"

template <typename T>
class QueuedStack{
    public:
        QueueCirc<T> q1, q2;

        void push(T x){
           q1.enqueue(x);
        }

        T pop(){
            T x;
            while(q1.getSize() != 1)
                q2.enqueue(q1.dequeue());
            
            x = q1.peek();

            while(q2.getSize() != 0)
                q1.enqueue(q2.dequeue());
            
            return x;
        }

        T peek(){
            T x;
            while(q1.getSize() != 1)
                q2.enqueue(q1.dequeue());

            x = q1.peek();

            while(q2.getSize() != 0)
                q1.enqueue(q2.dequeue());

            return x;    
        }
        bool isEmpty(){
            return q1.isEmpty();
        }

        QueuedStack(){}

        ~QueuedStack(){}
};

int main(){
    QueuedStack<int> qS;
    qS.push(3);
    cout << qS.peek() << endl;
    qS.push(5);
    cout << qS.peek() << endl;
    qS.pop();
    cout << qS.peek() << endl;
}