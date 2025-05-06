#include <iostream>
#include <vector>
#include  <string>
#include "User.h"
#include "Vehicle.h"
#include "DataFiles.h"
#include "startProgram.h"
#include "AdminProgram.h"
#include "UserProgram.h"
using namespace std;
const int MAX_RENTALS = 100;
vector<Vehicle> vehicles = {};
vector<User> users = {};
Rental rentals[MAX_RENTALS];
string  currentUsername;


int main()

{

    int rentalCount = 0;
    loadAlldata("vehicles.txt", vehicles, "users.txt", users, "rentals.txt", rentals, rentalCount, MAX_RENTALS);
    
    startProgram(users, vehicles, rentals, rentalCount);
   
    saveAllData("vehicles.txt", vehicles, "users.txt", users, "rentals.txt", rentals, rentalCount);

    return 0;
}
    

   

