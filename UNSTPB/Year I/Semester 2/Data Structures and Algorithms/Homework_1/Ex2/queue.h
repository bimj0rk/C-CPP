#include <iostream>
#define NMAX 50

template<typename T> 
class Queue{
    private:
        T queueArray[NMAX];
        int head, tail, size;
        
    public:
        void enqueue(T x){
            if (size == NMAX){
                std::cout << "The queue is full \n";
                return;
            }
            queueArray[tail] = x;
            tail = (tail + 1) % NMAX;
            size++;
        }

        int getSize () {
        	return size; 
        }
        	
        T dequeue() {
            if (isEmpty()) {
                std::cout << "The queue is empty \n";
                T x;
                return x;
            }
            T x = queueArray[head];
            head = (head + 1) % NMAX;
            size--;
            return x;
        }

        T peek() {
            if (isEmpty()) {
                std::cout << "The queue is empty \n";
                T x;
                return x;
            }
            return queueArray[head];
        }

        int isEmpty() {
            return (size == 0);
        }

        Queue() {
            head = tail = size = 0;
        }
};

