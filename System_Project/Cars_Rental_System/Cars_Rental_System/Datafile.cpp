#include <iostream>
#include <vector>
#include "User.h"
#include "Vehicle.h"
#include "Rentals.h"
#include <fstream>
#include <sstream>
#include <string>
#include"DataFiles.h"

//*Fuction to save data into file*//
void saveAllData(const string& vehicleFile, vector<Vehicle>& vehicles,
    const string& userFile, vector<User>& users,
    const string& rentalFile, Rental rentals[], int& size)
{
    saveVehiclesToFile(vehicleFile, vehicles);
    saveUsersToFile(userFile, users);
    saveRentalsToFile(rentalFile, rentals, size);
}
void saveVehiclesToFile(const string& vehicleFile, const vector<Vehicle>& vehicles) {
    ofstream outFile(vehicleFile);
    if (!outFile) {
        cout << "Unable to open File for writing.\n";
        return;
    }
    for (const auto& v : vehicles) {
        outFile << v.Brand_Model << ","
            << v.Model_year << ","
            << v.Plate_no << ","
            << v.Color << ","
            << v.Daily_rate << ","
            << (v.Status ? "1" : "0") << ","
            << v.Distance_traveled << "\n";
    }
    outFile.close();
    
}
void saveUsersToFile(const string& userFile, const vector<User>& users) {
    ofstream outFile(userFile);
    if (!outFile) {
        cout << "Unable to open File for writing.\n";
        return;
    }
    for (const auto& u : users) {
        outFile << u.User_id << ","
            << u.User_name << ","
            << u.Password << ","
            << u.Phone_no << ","
            << u.Address << ","
            << u.role << ","
            << u.National_id << "\n";
    }
    outFile.close();
    
}
void saveRentalsToFile(const string& rentalFile, const Rental rentals[], int size) {
    ofstream outFile(rentalFile);
    if (!outFile) {
        cout << "Unable to open rentals File for writing.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        outFile << rentals[i].rental_id << ","
            << rentals[i].user_id << ","
            << rentals[i].plate_no << ","
            << rentals[i].start_date << ","
            << rentals[i].end_date << ","
            << rentals[i].total_cost << ","
            << (rentals[i].is_active ? "1" : "0") << "\n";
    }

    outFile.close();
    
}


//*Fuctions to Load Data from file to program*//

void loadAlldata(const string& vehicleFile, vector<Vehicle>& vehicles,
    const string& userFile, vector<User>& users,
    const string& rentalFile, Rental rentals[], int& size, int maxSize)
{
    loadVehiclesFromFile(vehicleFile, vehicles);
    loadUsersFromFile(userFile, users);
    loadRentalsFromFile(rentalFile, rentals, size, maxSize);
}

void loadVehiclesFromFile(const string& vehicleFile, vector<Vehicle>& vehicles) {
    ifstream inFile(vehicleFile);
    if (!inFile) {
        cout << "Unable to open vehicles File for reading.\n";
        return;
    }

    vehicles.clear();

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Vehicle v;
        string field;

        getline(ss, v.Brand_Model, ',');
        getline(ss, v.Model_year, ',');
        getline(ss, v.Plate_no, ',');
        getline(ss, v.Color, ',');
        getline(ss, field, ',');
        v.Daily_rate = stof(field);
        getline(ss, field, ',');
        v.Status = (field == "1");
        getline(ss, field, ',');
        v.Distance_traveled = stof(field);



        vehicles.push_back(v);
    }

    inFile.close();
}
void loadUsersFromFile(const string& userFile, vector<User>& users) {
    ifstream inFile(userFile);
    if (!inFile) {
        cout << "Unable to open File for reading.\n";
        return;
    }

    users.clear();

    string line;
    while (getline(inFile, line)) {

        stringstream ss(line);
        User u;
        string field;

        getline(ss, field, ',');
        u.User_id = stoi(field);

        getline(ss, u.User_name, ',');
        getline(ss, u.Password, ',');
        getline(ss, u.Phone_no, ',');
        getline(ss, u.Address, ',');
        getline(ss, u.role, ',');
        getline(ss, u.National_id, ',');

        users.push_back(u);
    }

    inFile.close();
}
void loadRentalsFromFile(const string& rentalFile, Rental rentals[], int& size, int maxSize) {
    ifstream inFile(rentalFile);
    if (!inFile) {
        cout << "Unable to open rentals File for reading.\n";
        return;
    }

    size = 0;
    string line;
    while (getline(inFile, line) && size < maxSize) {
        stringstream ss(line);
        string field;

        getline(ss, field, ',');
        rentals[size].rental_id = stoi(field);

        getline(ss, field, ',');
        rentals[size].user_id = stoi(field);

        getline(ss, rentals[size].plate_no, ',');

        getline(ss, rentals[size].start_date, ',');

        getline(ss, rentals[size].end_date, ',');

        getline(ss, field, ',');
        rentals[size].total_cost = stof(field);

        getline(ss, field, ',');
        rentals[size].is_active = (field == "1");

        size++;
    }

    inFile.close();
   
}