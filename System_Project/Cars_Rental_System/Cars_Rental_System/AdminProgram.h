#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "Vehicle.h"
#include "Rentals.h"
void AdminProgram(Rental rentals[], int rentalSize,
    vector<Vehicle>& vehicles, vector<User>& users);
void addVehicle(vector<Vehicle>& vehicles);
void deleteVehicle(vector<Vehicle>& vehicles);
void updateVehicle(vector<Vehicle>& vehicles, Rental rentals[], int size);
void viewAllVehicles(const vector<Vehicle>& vehicles, Rental rentals[], int size);
void viewAvaliableVehicles(const vector<Vehicle>& vehicles);
void viewRentals(const Rental rentals[], int size);
void viewAllUsers(const vector<User>& Users);
void addNewAdmin(vector<User>& users);
bool isValidPassword(const string& pwd);
void deleteUser(vector<User>& users);