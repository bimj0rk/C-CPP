#include <iostream>
#include <string>

template <typename T>
struct Node{ 
    T info;
    Node <T> *next; 
    Node <T> *prev; 
};

template <typename T>
class LinkedList{
    public:
        Node <T> *pfirst; 
        Node <T> *plast; 

    void addFirst(T x){
        Node <T> *paux = new Node<T>;

        paux->info = x; 
        paux->prev = NULL;
        paux->next = pfirst;

        if(pfirst != NULL) pfirst->prev = paux;

        pfirst = paux; 

        if(plast==NULL) plast=pfirst;
    }

    void addLast(T x){
        Node<T> *paux = new Node <T>;

        paux->info = x;
        paux->prev = plast;
        paux->next = NULL;

        if(plast != NULL) plast->next = paux;

        plast = paux;

        if(pfirst == NULL) pfirst = plast;
    }

    T getInfo (Node<T>* p){
        return p->info;
    }

    void removeFirst(){
        Node<T>* paux;

        if(pfirst != NULL){
            paux = pfirst->next;

            if(pfirst == plast) plast = NULL;

            delete pfirst;

            pfirst = paux;

            if(pfirst != NULL) pfirst->prev = NULL;
        }
        else std::cout << "The list is empty \n";
    }

    void removeLast(){
        Node <T> *paux;

        if(plast != NULL){
            paux = plast->prev;

            if(pfirst == plast) pfirst = NULL;

            delete plast;

            plast = paux; 

            if(plast != NULL) plast->next = NULL;
        }
        else std::cout << "The list is empty \n";
    }

    Node <T>* findFirstOccurrence(T x){
        Node <T> *paux;

        paux = pfirst;

        while(paux != NULL){
            if(paux->info == x) return paux;
            paux = paux->next;
        }
        return NULL;
    }

    Node <T>* findLastOccurrence(T x){ 
        Node <T> *paux;

        paux = plast;
        while(paux != NULL){
            if(paux->info == x) return paux;
            paux = paux->prev;
        }

        return NULL;
    }

    void removeFirstOccurrence(T x){
        Node <T> *px;

        px = findFirstOccurrence(x); 

        if(px != NULL){
            if(px->prev != NULL) px->prev->next = px->next;

            if(px->next != NULL) px->next->prev = px->prev;

            if(px->prev == NULL) pfirst = px->next;

            if(px->next == NULL) plast = px->prev;

            delete px; 
        }
    }

    void removeLastOccurrence(T x){
        Node <T> *px;

        px = findLastOccurrence(x);

        if(px != NULL){
            if(px->prev != NULL) px->prev->next = px->next;

            if(px->next != NULL) px->next->prev = px->prev;

            if(px->prev == NULL) pfirst = px->next;

            if(px->next == NULL) plast = px->prev;

            delete px;
        }
    }

    int isEmpty(){ 
        return (pfirst == NULL);
    }

    void printList(){
	    Node <T> *p;
	
	    p = pfirst;
	    while(p != NULL){
		    std::cout << p->info << " ";
            std::cout << std::endl;
		    p = p->next;
	    }
    }

    LinkedList(){ 
        pfirst = plast = NULL;
    }

};
