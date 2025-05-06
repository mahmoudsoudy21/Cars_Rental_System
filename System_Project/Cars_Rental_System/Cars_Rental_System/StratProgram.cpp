#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include "User.h"
#include "Authentication.h"
#include "AdminProgram.h"
#include "UserProgram.h"
void startProgram(vector<User>& users, vector<Vehicle>& vehicles, Rental rentals[], int& rentalCount) 
{
    string username;
    int choice;

    while (true)
    {
        cout << R"(
{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
{}                                              {}
{}  _____ ____ ___ ____       _    ____  _   _  {}
{} |  ___/ ___|_ _/ ___|     / \  / ___|| | | | {}
{} | |_ | |    | |\___ \    / _ \ \___ \| | | | {}
{} |  _|| |___ | | ___) |  / ___ \ ___) | |_| | {}
{} |_|   \____|___|____/  /_/   \_\____/ \___/  {}
{}                                              {}
{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}
)";
        cout << "\n\nWelcome to the Vehicles Rental System!";
        cout << "\nPlease login or sign up to get started.\n\n";

        do {
            cout << "1. Login\n";
            cout << "2. Sign Up\n";
            cout << "-----------------\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                break;
            }
            else if (choice == 2) {
                Signup(users);
            }
            else {
                cout << "\nInvalid choice! Please enter 1 or 2.\n\n";
            }
        } while (choice != 1);

        break; 
    }

    int loginResult = Login(users, username);

    if (loginResult == 1) {
        system("cls");
        AdminProgram(rentals, rentalCount, vehicles, users);
    }
    else {
        system("cls");
        UserProgram(vehicles, rentals, rentalCount, users, username);
    }
}
