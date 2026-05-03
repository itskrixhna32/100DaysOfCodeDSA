// Day 99 Question 1: Car Fleet Calculation
// Calculate number of car fleets reaching destination

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

void swap(Car* a, Car* b) {
    Car temp = *a;
    *a = *b;
    *b = temp;
}

void sortCars(Car cars[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cars[j].position < cars[j + 1].position) {
                swap(&cars[j], &cars[j + 1]);
            }
        }
    }
}

int carFleet(int target, int position[], int speed[], int n) {
    if (n == 0) {
        return 0;
    }
    
    Car cars[n];
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }
    
    sortCars(cars, n);
    
    int fleets = 1;
    double maxTime = cars[0].time;
    
    for (int i = 1; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }
    
    return fleets;
}

int main() {
    int n, target;
    printf("Enter target position: ");
    scanf("%d", &target);
    
    printf("Enter number of cars: ");
    scanf("%d", &n);
    
    int position[n], speed[n];
    printf("Enter car positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }
    
    printf("Enter car speeds: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }
    
    int fleets = carFleet(target, position, speed, n);
    printf("Number of car fleets: %d\n", fleets);
    
    return 0;
}
