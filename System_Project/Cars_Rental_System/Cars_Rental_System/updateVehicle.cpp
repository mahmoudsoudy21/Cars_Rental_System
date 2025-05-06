#include <iostream>
#include <cstdlib>  
#include <vector>
#include "User.h"
#include "Vehicle.h"
#include "AdminProgram.h"
#include "Rentals.h"
// Function to update specific fields of a Vehicle
void updateVehicle(vector<Vehicle>& vehicles,Rental rentals[],int size) {
    string Vehicle_plate;
    cout << "Enter the Vehicle Plate number you want to update: ";
    cin >> Vehicle_plate;

    bool VehicleFound = false;
    for (auto& Vehicle : vehicles) {
        if (Vehicle.Plate_no == Vehicle_plate) {
            VehicleFound = true;

            int choice;
            do {
                cout << "\nCurrent Vehicle Info:\n";
                cout << "Brand & Model\t\tModel Year\t\tPlate No\t\tColor\t\tPrice/Day ($) \t\tStatus \t\t\t      Distance (km)\n";
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------\n ";
                cout << Vehicle.Brand_Model << "\t\t"
                    << Vehicle.Model_year << "\t\t\t"
                    << Vehicle.Plate_no << "\t\t\t"
                    << Vehicle.Color << "\t\t    "
                    << Vehicle.Daily_rate << "\t\t\t"
                    << (Vehicle.Status ? "Avaliable" : "Rented   ") << "\t"
                    << Vehicle.Distance_traveled << " km\n\n";

                cout << "\nWhat would you like to update?\n";
                cout << "1. Update Price per day\n";
                cout << "2. Update Availability\n";
                cout << "3. Update Distance Travelled\n";
                cout << "4. Show Available vehicles\n";
                cout << "5. Exit Update\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    double newPrice;
                    cout << "Enter new price per day: ";
                    cin >> newPrice;
                    Vehicle.Daily_rate = newPrice;
                    cout << "Price updated successfully!\n";
                    break;
                }
                case 2: {
                    int avail;
                    cout << "Enter 1 if available, 0 if not available: ";
                    cin >> avail;
                    Vehicle.Status = (avail == 1);
                    cout << "Availability updated successfully!\n";
                    break;
                }
                case 3: {
                    float newDistance;
                    cout << "Enter new distance travelled (in km): ";
                    cin >> newDistance;
                    Vehicle.Distance_traveled = newDistance;
                    cout << "Distance updated successfully!\n";
                    break;
                }
                case 4: {
                    viewAllVehicles(vehicles,rentals,size);
                    break;
                }
                case 5:
                    cout << "Exiting Vehicle update...\n";
                    break;
                default:
                    cout << "wrong choice. please try again.\n";
                }

            } while (choice != 5);

            break;
        }
    }

    if (!VehicleFound) {
        cout << "Vehicle with Plate number " <<  Vehicle_plate << " not found.\n";
    }
}

