#include <iostream>
#include <cstdlib>  
#include <vector>
#include "Vehicle.h"
#include <iomanip>


// Function to show available cars
void viewAvaliableVehicles(const vector<Vehicle>& vehicles) {
    cout << "\n\n============Available Cars============\n\n";

   
    cout << left << setw(20) << "Brand & Model"
        << setw(15) << "Model Year"
        << setw(15) << "Plate No"
        << setw(15) << "Color"
        << setw(15) << "Price/Day ($)"
        << setw(15) << "Distance (km)" << "\n";

    cout << string(95, '-') << "\n";
    for (const auto& Vehicle : vehicles) {
        if (Vehicle.Status) {
            cout << left << setw(20) << Vehicle.Brand_Model
                << setw(15) << Vehicle.Model_year
                << setw(15) << Vehicle.Plate_no
                << setw(15) << Vehicle.Color
                << setw(15) << Vehicle.Daily_rate
                << setw(15) << Vehicle.Distance_traveled
                << "\n" << string(95, '-') << "\n";
        }
    }

    
}

