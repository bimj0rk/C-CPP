#include <stdio.h>
#include<iostream>
#include <math.h>
#include <algorithm>
using namespace std;

template<typename T> 
class BinarySearchTree {
    public:
        BinarySearchTree<T> *root, *left_son, *right_son, *parent;
        T *pinfo;

        BinarySearchTree(){
            left_son = right_son = NULL;
            root = this;
            pinfo = NULL;
        }

        void setInfo(T info){
            pinfo = new T;
            *pinfo = info;
        }

        void insert(T x){
            if(pinfo == NULL) setInfo(x);
            else insert_rec(x);
        }

        void insert_rec(T x){
            int next_son;
			if(x <= (*pinfo)) next_son = 0;
            else next_son = 1;

            if(next_son == 0){
                if(left_son == NULL){
                    left_son = new BinarySearchTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;
                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                }else left_son->insert_rec(x);
            }else{
                if (right_son == NULL){
                    right_son = new BinarySearchTree<T>;
                    right_son->pinfo = new T;
                    *(right_son->pinfo) = x;
                    right_son->left_son = right_son->right_son = NULL;
                    right_son->parent = this;
                    right_son->root = root;
                }else right_son->insert_rec(x);
            }
        }

		BinarySearchTree<T>* find(T x){
            BinarySearchTree<T> *rez;

            if (pinfo == NULL) return NULL;

            if ((*pinfo) == x) return this;

            if(x <= (*pinfo)){
                if(left_son != NULL) return left_son->find(x);
                else return NULL;
            }else{
                if(right_son != NULL) return right_son->find(x);
                else return NULL;
            }
        }

        void removeInfo(T x){
            BinarySearchTree<T> *t = find(x);
            if(t != NULL) t->remove();
        }

		void remove(){
            BinarySearchTree<T> *p;
            T *paux;

            if (left_son == NULL && right_son == NULL){
                if(parent == NULL){
                    delete this->pinfo;
                    root->pinfo = NULL;
                }else{
                    if(parent->left_son == this) parent->left_son = NULL;
                    else parent->right_son = NULL;

                    delete this->pinfo;
                    delete this;
                }
            }else{
                if(left_son != NULL){
                    p = left_son;
                    while(p->right_son != NULL) p = p->right_son;
                }else{
                    p = right_son;
                    while (p->left_son != NULL) p = p->left_son;
                }

                paux = p->pinfo;
                p->pinfo = this->pinfo;
                this->pinfo = paux;
                p->remove();
            }
        }

        void inOrderTraversal(){
            if(left_son != NULL) left_son->inOrderTraversal();
            printf("%c\t", *pinfo); 
            if(right_son != NULL) right_son->inOrderTraversal();
        }


        void preOrderTraversal(){
             printf("%c\t", *pinfo); 
                                              
            if(left_son != NULL) left_son->inOrderTraversal();

            if(right_son != NULL) right_son->inOrderTraversal();
        }

        void postOrderTraversal(){
            if(left_son != NULL) left_son->inOrderTraversal();

            if(right_son != NULL) right_son->inOrderTraversal();

            printf("%c\t", *pinfo);
        }

        void findGreatestValue(){
            BinarySearchTree *currNode = this;
            while(currNode->right_son != NULL) currNode = currNode->right_son;
            printf("%d\n", *currNode->pinfo);
        }

        void displayRange(T x, T y){
            if(this == NULL){
                printf("\n");
                return;
            }

            if(*this->pinfo < x) this->right_son->displayRange(x, y);
            else if(*this->pinfo > y) this->left_son->displayRange(x, y);
            else{
                this->left_son->displayRange(x, y);
                std::cout<<*this->pinfo<<" ";
                this->right_son->displayRange(x, y);
            }
        }
};