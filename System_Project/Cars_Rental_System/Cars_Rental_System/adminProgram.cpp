#include <iostream>
#include <cstdlib>
#include <vector>
#include  <string>
#include "User.h"
#include <iomanip>
#include "Vehicle.h"
#include "Rentals.h"
#include "AdminProgram.h"

void AdminProgram(Rental rentals[], int rentalSize,
	vector<Vehicle>& vehicles, vector<User>& users) {
	int choice;

	do {
		cout << R"(
=================================
|      Admin Control Panel      |
================================= 
    )";
		cout << "\n\n";
		cout << "1.  Display all rentals\n";
		cout << "2.  View all users\n";
		cout << "3.  Add new Vehicle\n";
		cout << "4.  Delete Vehicle\n";
		cout << "5.  Update Vehicle\n";
		cout << "6.  View all vehicles\n";
		cout << "7.  View available vehicles\n";
		cout << "8.  Add new admin\n";
		cout << "9.  Remove user\n";
		cout << "\t\t10.Exit admin panel\n";
		cout << "-------------------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			viewRentals(rentals, rentalSize);
			break;
		case 2:
			viewAllUsers(users);
			break;

		case 3:
			addVehicle(vehicles);
			break;

		case 4:
			deleteVehicle(vehicles);
			break;

		case 5:
			updateVehicle(vehicles,rentals,rentalSize);
			break;

		case 6:
			viewAllVehicles(vehicles,rentals, rentalSize);
			break;

		case 7:
			viewAvaliableVehicles(vehicles);
			break;
		case 8:
			addNewAdmin(users);
			break;
		case 9:
			deleteUser(users);
			break;
		case 10:
			cout << "Exiting admin panel.\n";
			system("cls");
			break;

		default:
			cout << "Invalid choice. Try again.\n";
			system("cls");
		}
		
	} while (choice != 10);
	cout<<"Have a good day";
}