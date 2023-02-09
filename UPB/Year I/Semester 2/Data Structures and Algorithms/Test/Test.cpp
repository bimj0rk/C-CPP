#include <iostream>
#include "./DSA_Headers/bst.h"

void FloorAndCeil(BinarySearchTree<int> bst, int key){
    int floor, ceil;
    while(root->pinfo){
        if(root->pinfo == key){
            floor = root->data;
            ceil = root->data;
        }else if(root->pinfo > key){
            ceil = root->pinfo;
            root = root->left_son;
        }else{
            floor = root;
            root = root->root->right_son;
        }
    }

    std::cout << floor << " " << ceil;
}