#include <ctime>
#include <iostream>
//#include<fstream>
#include<string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Vehicle.h"
#include "User.h"
#include "Rentals.h"
using namespace std;
time_t stringToTime(const string& date_str) {
    tm timeStruct = {};
    istringstream ss(date_str);
    ss >> get_time(&timeStruct, "%Y-%m-%d");
    return mktime(&timeStruct);
}

void rentVehicle(vector<Vehicle>& vehicles, vector<User>& users, Rental rentals[], int& rentalCount, const string& username) {
    int user_id = -1;


    for (const auto& user : users) {
        if (user.User_name == username) {
            user_id = user.User_id;
            break;
        }
    }

    if (user_id == -1) {
        cout << "invalid\n";
        return;
    }

    string plate;
    cout << "Enter Plate no: ";
    cin >> plate;

    int index = -1;
    for (int i = 0; i < vehicles.size(); ++i) {
        if (vehicles[i].Plate_no == plate && vehicles[i].Status) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Invalid Vehicle\n";
        return;
    }

    string start, end;
    cout << "Enter first date (YYYY-MM-DD): ";
    cin >> start;
    cout << "Enter End date (YYYY-MM-DD): ";
    cin >> end;

    time_t start_time = stringToTime(start);
    time_t end_time = stringToTime(end);
    double days = difftime(end_time, start_time) / (60 * 60 * 24);

    if (days <= 0) {
        cout << "Invalid dates.\n";
        return;
    }

    float total = days * vehicles[index].Daily_rate;

    vehicles[index].Status = false;

    rentals[rentalCount] = {
        rentalCount + 1,
        user_id,
        plate,
        start,
        end,
        total,
        true
    };
    rentalCount++;

    cout << "Succesfully\n";
    cout << "days number : " << days << "\n";
    cout << "Total : " << total << " $\n";
}