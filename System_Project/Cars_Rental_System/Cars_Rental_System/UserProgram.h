#pragma once
#include "User.h"
#include "Vehicle.h"
#include "Rentals.h"
#include <vector>
void UserProgram(vector<Vehicle>& vehicles, Rental rentals[], int& rentalCount, vector<User>& users, const string& username);

void viewAllVehicles(const vector<Vehicle>& vehicles,Rental rentals[], int size);
void viewAvaliableVehicles(const vector<Vehicle>& vehicles);
void rentVehicle(vector<Vehicle>& vehicles, vector<User>& users, Rental rentals[], int& rentalCount, const string& username);