#pragma once

#include <vector>
#include <string>
#include "Vehicle.h"
#include "User.h"
#include "Rentals.h"
using namespace std;
//header functions to load & save data from & to file
void loadAlldata(const string& vehicleFile, vector<Vehicle>& vehicles,
    const string& userFile, vector<User>& users,
    const string& rentalFile, Rental rentals[], int& size, int maxSize);

void saveAllData(const string& vehicleFile, vector<Vehicle>& vehicles,
    const string& userFile, vector<User>& users,
    const string& rentalFile, Rental rentals[], int& size);

void loadVehiclesFromFile(const string& vehicleFile, vector<Vehicle>& vehicles);
void saveVehiclesToFile(const string& vehicleFile, const vector<Vehicle>& vehicles);

void loadUsersFromFile(const string& userFile, vector<User>& users);
void saveUsersToFile(const string& userFile, const vector<User>& users);

void loadRentalsFromFile(const string& rentalFile, Rental rentals[], int& size, int maxSize);
void saveRentalsToFile(const string& rentalFile, const Rental rentals[], int size);
