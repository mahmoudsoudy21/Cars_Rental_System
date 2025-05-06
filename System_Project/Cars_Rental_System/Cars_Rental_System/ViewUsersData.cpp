#include <iostream>
#include <vector>
#include "User.h"
#include <iomanip>



// Function to show available cars
void viewAllUsers(const vector<User>& Users) {
    cout << "\n============ All Users ============\n\n";

    

    cout << left
        << setw(12) << "User ID"
        << setw(20) << "User Name"
        << setw(18) << "Phone No."
        << setw(20) << "National ID"
        << setw(25) << "Address"
        << "\n";

    cout << string(95, '-') << "\n";
    for (const auto& user : Users) {
        cout << left
            << setw(12) << user.User_id
            << setw(20) << user.User_name
            << setw(18) << user.Phone_no
            << setw(20) << user.National_id
            << setw(25) << user.Address
            << "\n";
        cout << string(95, '-') << "\n";
    }

    cout << "\n";
}
