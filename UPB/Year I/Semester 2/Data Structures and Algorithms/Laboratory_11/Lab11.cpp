#include <iostream>
using namespace std;
template<typename T> class Heap {
    public:
        T *H;
        int currentDim, maxDim;

        Heap(int maxDim){
            this->maxDim = maxDim;
            H = new T[this->maxDim];
            currentDim = -1;
        }

        void insertElement(T x){
            if (currentDim == maxDim-1){
                cout << "Error!" <<endl;
                return;
            }
            currentDim++;
            H[currentDim] = x;
            filterUp(currentDim);
        }

	    T peek(){
            if (currentDim == -1){
                cout<< "Error!"<<endl;
                T x;
                return x;
            }

            return H[0];
        }

        T deleteElement() {
            if (currentDim == -1) {
                cout<< "Error!"<<endl;
                T x;
                return x;
            }

            T minValue = H[0];
            H[0] = H[currentDim];
            currentDim--;
            if (currentDim > 0) filterDown();

            return minValue;
        }

        void filterUp(int l) {
            int parent;
            T vaux;

            parent = (l-1) / 2;
           while (l > 0 && H[parent] > H[l]) {
                vaux = H[parent];
                H[parent] = H[l];
                H[l] = vaux;

                l = parent;
                parent = (l-1) / 2;
            }
        }
        void filterDown() {
           int l = 0;
            T vaux;

            while (1) {
                if (2 * l + 1 > currentDim) {
                    if (2 * (l+1) > currentDim)
                        break;
                     else if (H[2 *(l+1)] < H[l]) {
                        vaux = H[2 * (l+1)];
                        H[2 * (l+1)] = H[l];
                        H[l] = vaux;
                        l = 2 * (l+1);
                    }
                    else
                        break;
                }
                else {

                    if (H[2 * (l+1) ] <= H[2 * l + 1] && H[2 * (l+1) ] < H[l]) {
                        vaux = H[2 * (l+1)];
                        H[2 * (l+1)] = H[l];
						H[l] = vaux;
                        l = 2 * (l+1);
                    }
                    else
                    if (H[2 * l + 1] <= H[2 * (l+1)] && H[2 * l + 1] < H[l]) {
                        vaux = H[2 * l + 1];
                        H[2 * l + 1] = H[l];
                        H[l] = vaux;
                        l = 2 * l + 1;
                    }
                    else
                        break;
                }
            }
        }

        //2
        int parent(int poz){
            return H[(poz - 1)/2];
        }

        int leftSubtree(int poz){  
            return H[2*poz + 1];
        }

        int rightSubtree(int poz){
            return H[2* (poz + 1)];
        }

        //3
        T getMax(){
        int lastParentIndex = (this->currentDim - 3) / 2, i = lastParentIndex;
        T max = H[lastParentIndex];

        while(i < this->currentDim){
            if(H[i] > max) max = H[i];
            i++;
        }

        return max;
        }
};

//5
int heapSort(int arrayToSort[]){
    Heap<int> tempHeap(arrayToSort.size() + 1);
    int returnedArray[] = {};

    for(int i = 0; i < arrayToSort.size() + 1; i++){
        tempHeap.insertElement(arrayToSort[i]);
    }

    for(int i = 0; i < tempHeap.currentDim; i++){
        int aux = tempHeap.deleteElement();
        returnedArray[i] = aux;
    }

    return returnedArray[];
}

int main() {
    //1
    Heap<int> heap(100);
    heap.insertElement(25);
    heap.insertElement(17);
    heap.insertElement(36);
    heap.insertElement(2);
    heap.insertElement(3);
    heap.insertElement(100);
    heap.insertElement(1);
    heap.insertElement(19);
    heap.insertElement(17);  

    heap.deleteElement();
    heap.deleteElement();
    heap.deleteElement();

    int arrayToSort[] = {25, 17, 36, 2, 3, 100, 1, 19, 17};
    int returnedArray = heapSort(arrayToSort[]);
}
