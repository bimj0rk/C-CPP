#include <iostream>
#include "queue.h"

double computeDistance(int fuel, int fuelConsumption){
    double distance;
    distance = (100 * fuel) / fuelConsumption;
    return distance;
}

int main(){
    Queue <int> petrolStationLiters;
    Queue <int> distanceToTheNextPetrolStation;
    int n, fc;
    std::cout << "Enter the number of petrol stations and the fuel consumption: \n";
    std::cin >> n >> fc;

    std::cout << "Enter the details for each petrol station (liters refueled, distance to the next petrol station): \n";
    for(int i = 0; i < n; i++){
        int liters, distance;
        std::cin >> liters >> distance;
        petrolStationLiters.enqueue(liters);
        distanceToTheNextPetrolStation.enqueue(distance);
    }

    int petrolLiters = 0;
    int counter = 0;
    for(int i = 0; i < n; i++){
        petrolLiters += petrolStationLiters.peek();
        double distance = computeDistance(petrolLiters, fc);

        if(distance <= (double) distanceToTheNextPetrolStation.peek()){
            counter = 0;
            for(int j = i; j >= 0; j--){
                petrolStationLiters.dequeue();
            }
            petrolLiters = petrolStationLiters.peek();
        } else {
            petrolLiters -= petrolStationLiters.dequeue();
            counter++;
        }
        distanceToTheNextPetrolStation.dequeue();
    }

    int indexPetrolStation = n - counter;

    std::cout << "The petrol station which one can start the journey from is: " << indexPetrolStation;
    return 0;
}