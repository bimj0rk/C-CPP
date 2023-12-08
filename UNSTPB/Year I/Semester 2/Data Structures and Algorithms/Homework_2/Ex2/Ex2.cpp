#include <iostream>
#include <climits>
#include <algorithm>

class Node{
    public:
        int data;
        Node* leftNode;
        Node* rightNode;

        Node(int val);
        void inOrder(Node* node);
};

Node::Node(int val){
	data = val;
	leftNode = NULL;
	rightNode = NULL;
}

void Node::inOrder(Node* node){
    if(node == NULL) return;
    std::cout << node->data << " ";
    inOrder(node->leftNode);
    inOrder(node->rightNode); 
}

class currentMaxNode{
    public:
        int maxNode, minNode, maxSize, sum = 0;
        
        currentMaxNode(int minNode, int maxNode, int maxSize, int data){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSize = maxSize;
            this->sum = sum + data;
        }
};

class MaxBST{
    private:
        currentMaxNode biggestBSTSubtree(Node* root) {
            
            if(!root) return currentMaxNode(INT_MAX, INT_MIN, 0, 0);

            currentMaxNode left = biggestBSTSubtree(root->leftNode);
            currentMaxNode right = biggestBSTSubtree(root->rightNode);
            
            if(left.maxNode < root->data && root->data < right.minNode)  return currentMaxNode(std::min(root->data, left.minNode), 
                                                                                std::max(root->data, right.maxNode), left.maxSize + right.maxSize + 1,
                                                                                left.sum + right.sum + root->data);
            
            return currentMaxNode(INT_MIN, INT_MAX, std::max(left.maxSize, right.maxSize), std::max(left.sum, right.sum));
        }
    public:
        int getBiggestSubtree(Node* root) {
            return biggestBSTSubtree(root).sum;
        }
};

int main(){
	Node* root = new Node(12);
	root->leftNode = new Node(18);
	root->rightNode = new Node(7);
	root->leftNode->leftNode = new Node(7);
    root->leftNode->rightNode = new Node(22);
    root->leftNode->leftNode->leftNode = new Node(3);
    root->leftNode->leftNode->leftNode->leftNode = new Node(1);
    root->leftNode->leftNode->rightNode = new Node(11);
    root->rightNode->leftNode = new Node(2);
    root->rightNode->rightNode= new Node(4);
    root->rightNode->rightNode->rightNode = new Node(14);
    root->rightNode->rightNode->leftNode = new Node(2);
    root->rightNode->rightNode->leftNode->rightNode = new Node(3);
    root->rightNode->rightNode->leftNode->leftNode = new Node(1);

    MaxBST bt;
    std::cout << "The sum of the biggest BST is: " << bt.getBiggestSubtree(root);
}
