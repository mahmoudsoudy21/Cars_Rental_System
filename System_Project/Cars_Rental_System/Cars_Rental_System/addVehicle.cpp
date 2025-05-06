#include <iostream>
#include <vector>
#include "User.h"
#include "Vehicle.h"

//this function to add vehicle//
void addVehicle(vector<Vehicle>& vehicles) {
	Vehicle newVehicle;
	newVehicle.Status = true;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter Brand and model of the new vehicles :  ";
	getline(cin, newVehicle.Brand_Model);
	int year;
	while (true)
	{
		cout << "Enter model year (2015 - 2025): ";
		cin >> year;

		if (year >= 2015 && year <= 2025)
			break;
		else {
			cout << " Invalid model year, please try again.\n";
		}
	}

	newVehicle.Model_year = to_string(year);
	cout << "Enter color: ";
	cin >> newVehicle.Color;

	// validtion of length
	while (newVehicle.Plate_no.length() != 6) {
		cout << "Enter plate number (maximum plate no is 6 characters): ";
		cin >> newVehicle.Plate_no;
		
	}

	cout << "Enter distance traveled (km): ";
	cin >> newVehicle.Distance_traveled;

	// Validtion of dictance
	while (newVehicle.Distance_traveled < 0 && newVehicle.Distance_traveled > 300000) {
		cout << "Invalid input. Distance must be between 0 and 300000 km: ";
		cin >> newVehicle.Distance_traveled;
	}

	cout << "Enter Daily charge ($): ";
	cin >> newVehicle.Daily_rate;

	// Add vehicle to vector
	vehicles.push_back(newVehicle);

	//Display the details of the car added
	cout << "\nCar added: Available | Brand: " << newVehicle.Brand_Model
		<< " | Year: " << newVehicle.Model_year
		<< " | Color: " << newVehicle.Color
		<< " | Plate: " << newVehicle.Plate_no
		<< " | Distance: " << newVehicle.Distance_traveled
		<< " km | Rate: $" << newVehicle.Daily_rate << "/day\n";
}