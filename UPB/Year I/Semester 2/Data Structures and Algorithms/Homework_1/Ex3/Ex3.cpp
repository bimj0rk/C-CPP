#include <iostream>
#include "lists.h"

std::string findRoadIntersection(LinkedList <std::string> listA, LinkedList <std::string> listB){
    Node <std::string> *p1 = listA.pfirst, *p2 = listB.pfirst;

    while(p1 != NULL){
        while(p2 != NULL){
            if(p1->info == p2->info){
                return "The roads intersect at " + listA.getInfo(p1);
                break;
            }
            p2 = p2->next;
        }

        p2 = listB.pfirst;
        p1 = p1->next;
   }

   return "The roads do not intersect.";
}

int main(){
    LinkedList <std::string> roadA;
    LinkedList <std::string> roadB;

    int lengthA;
    std::cout << "Insert the lengths of the first road \n";
    std::cin >> lengthA;

    std::cout << "Insert the name of the cities on the first road \n";
    for(int i = 0; i < lengthA; i++){
        std::string city;
        std::cin >> city;
        roadA.addLast(city);
    }

    int lengthB;
    std::cout << "Insert the lengths of the second road \n";
    std::cin >> lengthB;
    
    std::cout << "Insert the name of the cities on the second road \n";
    for(int i = 0; i < lengthB; i++){
        std::string city;
        std::cin >> city;
        roadB.addLast(city);
    }

    std::cout << findRoadIntersection(roadA, roadB);
    return 0;
}