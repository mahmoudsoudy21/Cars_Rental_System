#include <iostream>
#include <cstdlib>  
#include <vector>
#include "User.h"
#include "Vehicle.h"
#include "AdminProgram.h"
//Function to remove a car based on the plate number
void deleteVehicle(vector<Vehicle>& vehicles) {
    viewAvaliableVehicles(vehicles);
    string plateNo;
    cout << "Enter plate number of the car to remove: ";
    cin >> plateNo;

    
    for (auto Vehicle = vehicles.begin(); Vehicle != vehicles.end(); ++Vehicle) {
        if (Vehicle->Plate_no == plateNo) {
            cout << "Removing car: " << Vehicle->Brand_Model << " "
                << " " << Vehicle->Model_year << " " << Vehicle->Color
                << " " << Vehicle->Plate_no << endl;
            vehicles.erase(Vehicle); 
            cout << "Car removed successfully.\n";
            return;
        }
    }

    
    cout << "Car with plate number " << plateNo << " not found.\n";
}

