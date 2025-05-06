#include <iostream>
#include <cstdlib>  
#include <vector>
#include "Vehicle.h"
#include "Rentals.h"

#include <iomanip>
// Function to show available cars
void viewAllVehicles(const vector<Vehicle>& vehicles,Rental rentals[],int size) {
    cout << "\n\n============ All Cars ============\n\n";


    cout << left << setw(20) << "Brand & Model"
        << setw(12) << "Model Year"
        << setw(12) << "Plate No"
        << setw(12) << "Color"
        << setw(15) << "Price/Day ($)"
        << setw(15) << "Status"
        << setw(15) << "Distance (km)" 
        << setw(15) << "End Date \n";

    cout << string(118, '-') << "\n";

    for (const auto& vehicle : vehicles) {
        cout << left << setw(20) << vehicle.Brand_Model
            << setw(12) << vehicle.Model_year
            << setw(12) << vehicle.Plate_no
            << setw(12) << vehicle.Color
            << setw(15) << vehicle.Daily_rate
            << setw(15) << (vehicle.Status ? "Available" : "Rented")
            << setw(15) << vehicle.Distance_traveled;
            
            if (!vehicle.Status) {
                string endDate = "Unknown";
                for (int i = 0; i < size; ++i) {
                    if (rentals[i].plate_no == vehicle.Plate_no && rentals[i].is_active) {
                        endDate = rentals[i].end_date;
                        break;
                    }
                }
                cout << setw(15) << endDate;
            }
            else {
                cout << setw(15) << "-";
            }
            cout << "\n" << string(118, '-') << "\n";
            
    }

    cout << "\n\n";
}
