#include <iostream>
#include "stack.h"

int main(){
    Stack <char> input;
    Stack <char> reverseInput;
    int n = 0;
    bool isBalanced = true;

    std::cout << "How many brackets are there? \n";
    std::cin >> n;
    if(n%2==0){
        std::cout << "Insert the brackets in order: \n";
        for(int i = 0; i < n; i++){
            char bracket;
            std::cin >> bracket;
            input.push(bracket);
        }

        for(int i = 0; i < n/2; i++){
            char aux = input.pop();
            switch (aux){
            case ')':
                aux = '(';
                break;
            case ']':
                aux = '[';
                break;
            case '}':
                aux = '{';
                break;
            default:
                break;
            }
            reverseInput.push(aux);
        }   

        for(int i=0;i<n/2;i++)
            if(reverseInput.pop()!=input.pop()) isBalanced = false;

        if(isBalanced) std::cout << "The brackets are balanced";
        else std::cout << "The brackets are not balanced";
    }else std::cout << "The number of brackets is odd so they cant be balanced";
    return 0;
}