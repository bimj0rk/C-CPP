#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template <typename T> class BinaryTree {
    public:
        T *pinfo;
        BinaryTree<T> *left_son, *right_son, *parent, *root;

        BinaryTree(){
            pinfo = NULL;
            left_son = right_son = parent = NULL;
            root = this;
        }

        void setInfo(T info){
            pinfo = new T;
            *pinfo = info;
        }

		void setRoot(BinaryTree<T> *r){
            root = r;
        }

        void insert(T x){
            if(pinfo == NULL) setInfo(x);
            else insert_rec(x);
        }

		void insert_rec(T x){
            int next_son = rand() % 2;
            if(next_son == 0){
                if(left_son == NULL){
                    left_son = new BinaryTree<T>;
                    left_son->pinfo = new T;
                    *(left_son->pinfo) = x;

                    left_son->left_son = left_son->right_son = NULL;
                    left_son->parent = this;
                    left_son->root = root;
                }else left_son->insert_rec(x);
            }else{
                if(right_son == NULL) {
                    right_son = new BinaryTree<T>;
                    right_son->pinfo = new T;
                    *(right_son->pinfo) = x;

                    right_son->left_son = right_son->right_son = NULL;
                    right_son->parent = this;
                    right_son->root = root;
                }
                else right_son->insert_rec(x);
            }
        }

		BinaryTree<T>* find(T x){
            BinaryTree<T> *rez;

            if(pinfo == NULL) return NULL;

            if ((*pinfo) == x) return this;

            if (left_son != NULL) rez = left_son->find(x);
            else rez = NULL;

            if (rez != NULL) return rez;
            else 
                if(right_son != NULL) return right_son->find(x);
                else return NULL;
        }

		BinaryTree<T>* findLeaf(){
            if(left_son == NULL && right_son == NULL) return this;
			else
				if(left_son != NULL) return left_son->findLeaf();
				else return right_son->findLeaf();
        }

		void remove(){
            BinaryTree<T> *leaf;

            leaf = findLeaf();

            if(this == leaf){
                if(parent == NULL){
                    if(this->pinfo != NULL) delete this->pinfo;

                    root->pinfo = NULL;
                }else{
                    if(parent->left_son == this) parent->left_son = NULL;
                    else parent->right_son = NULL;

                    delete this->pinfo;
                    delete this;
                }
            }else{
                if(leaf->parent->left_son == leaf) leaf->parent->left_son = NULL;
                else leaf->parent->right_son = NULL;

                leaf->parent = parent;
                leaf->left_son = left_son;
                leaf->right_son = right_son;

                delete this->pinfo;

                this->pinfo = leaf->pinfo;
                delete leaf;
            }
        }

		void removeInfo(T x){
            BinaryTree<T> *t = find(x);
            if(t != NULL) t->remove();
        }

		void preOrderTraversal(){
            cout<<*pinfo <<" ";
            if (left_son != NULL) left_son->preOrderTraversal();
            if (right_son != NULL) right_son->preOrderTraversal();
        }

        void postOrderTraversal(){
            if (left_son != NULL) left_son->postOrderTraversal();
            if (right_son != NULL) right_son->postOrderTraversal();
			cout<<*pinfo <<" ";
        }

        void inOrderTraversal(){
            if (left_son != NULL) left_son->inOrderTraversal();
            cout<<*pinfo <<" ";
            if (right_son != NULL) right_son->inOrderTraversal();
        }

		void preOrderTraversalLevels(int level){
            int i;
            for (i = 0; i < level; i++)
                cout<<"-";
            cout<<*pinfo<<endl;

            if(left_son != NULL) left_son->preOrderTraversalLevels(level + 1);
            if(right_son != NULL) right_son->preOrderTraversalLevels(level + 1);
        }
};

int main() {
    BinaryTree<int> *r = new BinaryTree<int>;
    r->setRoot(r); 
    r->insert(6);
    r->insert(8);
    r->insert(1);
    r->insert(9);
    r->insert(10);
    r->insert(4);
    r->insert(13);
    r->insert(1);
    r->insert(12);

    
    return 0;
}


