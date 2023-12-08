#include <iostream>
#include "stack.h"
#define NMAX 100

using namespace std;
template<typename T> class Queue {
    private:
        T queueArray[NMAX];
        int head, tail;
    public:

        void enqueue(T x) {
            if (tail == NMAX) { 
                cout<<"Error 101 - The queue is full!\n";
                return;
            }
            queueArray[tail] = x; 
            tail++; 
        }

        T dequeue() {
            if (isEmpty()) { 
                cout<<"Error 102 - The queue is empty!\n";
                T x;
                return x;
            }
            T x = queueArray[head]; 
            head++;                         
            return x;   
        }

        T peek() {
            if (isEmpty()) {
                cout<<"Error 103 - The queue is empty!\n";
                T x;
                return x;
            }
            return queueArray[head];
        }

        int isEmpty() {
            return (head == tail); 
        }

        Queue() {
            head = tail = 0; 
        }
};
