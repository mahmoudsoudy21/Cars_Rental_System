#include <iostream>
#include <vector>
#include  <string>
#include "User.h"
#include "Vehicle.h"
#include "Rentals.h"
#include "UserProgram.h"
void UserProgram(vector<Vehicle>& vehicles, Rental rentals[], int& rentalCount, vector<User>& users, const string& username) {
    
    int choice;
    do {
        
        cout << "\n--- User Menu ---\n";
        cout << "1. View All Vehicles\n";
        cout << "2. View Available Vehicles\n";
        cout << "3. Rent a Vehicle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            viewAllVehicles(vehicles,rentals, rentalCount);
            break;
        case 2:
            viewAvaliableVehicles(vehicles);
            break;
        case 3:
            rentVehicle(vehicles,users,rentals, rentalCount , username);
            break;
        case 4:
            cout << "Good Bye\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);
}