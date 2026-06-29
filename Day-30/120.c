// WAP to Develop complete mini project using arrays, strings and functions.
#include <stdio.h>
#include <string.h>

#define MAX_CARS 50

struct Car {
    int car_id;
    char model_name[50];
    char plate_number[20];
    double price_per_day;
    int is_rented;
};

struct Car fleet[MAX_CARS];
int car_count = 0;

int findCarIndexById(int id) {
    for (int i = 0; i < car_count; i++) {
        if (fleet[i].car_id == id) {
            return i;
        }
    }
    return -1;
}

// 1. Function to insert a new asset configuration
void addCar() {
    if (car_count >= MAX_CARS) {
        printf("\nError: Showroom registry bounds over capacity limit!\n");
        return;
    }

    struct Car c;
    printf("\nEnter Unique Car ID: ");
    scanf("%d", &c.car_id);

    if (findCarIndexById(c.car_id) != -1) {
        printf("Error: Transaction terminated. Car ID %d already exists!\n", c.car_id);
        return;
    }

    printf("Enter Car Model Name (Use_Underscores): ");
    scanf("%s", c.model_name);
    
    printf("Enter License Plate Number: ");
    scanf("%s", c.plate_number);
    
    printf("Enter Rental Charge Rate per Day ($): ");
    scanf("%lf", &c.price_per_day);
    
    c.is_rented = 0; // Making car available on initialization

    // Save into fleet array
    fleet[car_count] = c;
    car_count++;
    printf("\nSuccess: Vehicle logged to system registry!\n");
}

// 2. Function to print active layout directories
void displayFleet() {
    if (car_count == 0) {
        printf("\nFleet directory empty. No automotive listings loaded.\n");
        return;
    }

    printf("\n------------------------------------------------------------------------------------\n");
    printf("%-8s %-25s %-15s %-15s %-12s\n", "ID", "Model Vehicle Name", "Plate No.", "Rate / Day", "Status");
    printf("------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < car_count; i++) {
        printf("%-8d %-25s %-15s $%-14.2f %-12s\n", 
               fleet[i].car_id, 
               fleet[i].model_name, 
               fleet[i].plate_number, 
               fleet[i].price_per_day, 
               (fleet[i].is_rented == 1) ? "Rented Out" : "Available");
    }
    printf("------------------------------------------------------------------------------------\n");
}

// 3. Function to issue a car rental agreement
void rentCar() {
    int id;
    printf("\nEnter Vehicle ID to lease: ");
    scanf("%d", &id);

    int index = findCarIndexById(id);

    if (index == -1) {
        printf("Error: Car with ID %d is not tracked in our inventory records.\n", id);
        return;
    }

    if (fleet[index].is_rented == 1) {
        printf("Lease Aborted: Vehicle \"%s\" is currently checked out on another contract.\n", fleet[index].model_name);
    } else {
        fleet[index].is_rented = 1; // Update flag status to rented
        printf("\nLease Confirmed! Enjoy driving your %s (Plate: %s).\n", fleet[index].model_name, fleet[index].plate_number);
    }
}

// 4. Function to return a vehicle and dynamically calculate invoicing
void returnCar() {
    int id, days;
    printf("\nEnter Vehicle ID returning to depot: ");
    scanf("%d", &id);

    int index = findCarIndexById(id);

    if (index == -1) {
        printf("Error: Car verification mismatch tracking ID %d.\n", id);
        return;
    }

    if (fleet[index].is_rented == 0) {
        printf("Conflict: System logs declare \"%s\" is already sitting in the lot.\n", fleet[index].model_name);
        return;
    }

    printf("Enter the total days used for lease contract: ");
    scanf("%d", &days);

    if (days <= 0) {
        printf("Error: Invoice days must evaluate to 1 or higher.\n");
        return;
    }

    double total_cost = days * fleet[index].price_per_day;

    fleet[index].is_rented = 0;

    printf("\n=========================================\n");
    printf("         RENTAL TRANSACTION RECEIPT      \n");
    printf("=========================================\n");
    printf("Vehicle Model   : %s\n", fleet[index].model_name);
    printf("License Plate   : %s\n", fleet[index].plate_number);
    printf("Daily Rate Card : $%.2f\n", fleet[index].price_per_day);
    printf("Days Field Term : %d days\n", days);
    printf("-----------------------------------------\n");
    printf("TOTAL AMOUNT DUE: $%.2f\n", total_cost);
    printf("=========================================\n");
    printf("Car checked in successfully. Thank you!\n");
}

int main() {
    int choice;

    // Initialising with some examples
    fleet[0] = (struct Car){101, "BMW_i7", "UP-16-AB-7890", 120.00, 0};
    fleet[1] = (struct Car){102, "Thar", "UP-16-AB-9009", 150.00, 0};
    fleet[2] = (struct Car){103, "Toyota_Fortuner", "UP-16-CA-5521", 60.00, 1};
    car_count = 3;

    while (1) {
        printf("\n=== CAR RENTAL MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Vehicle to Fleet\n");
        printf("2. Display Fleet Directory\n");
        printf("3. Rent Out a Car\n");
        printf("4. Process Car Return (Calculate Bill)\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addCar(); break;
            case 2: displayFleet(); break;
            case 3: rentCar(); break;
            case 4: returnCar(); break;
            case 5: printf("\nClosing Fleet Management Systems. Safe driving!\n"); return 0;
            default: printf("Invalid choice! Pick a menu index between 1 and 5.\n");
        }
    }
    return 0;
}

