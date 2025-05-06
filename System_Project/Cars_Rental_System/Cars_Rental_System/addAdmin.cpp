#include <iostream>
 
#include <vector>
#include "User.h"
#include "AdminProgram.h"

using namespace std;
bool isValidPassword(const string& pwd) {
    if (pwd.length() < 8)
        return false;

    for (char ch : pwd) {
        if (isdigit(static_cast<unsigned char>(ch)))
            return true;
    }
    return false;
}
void addNewAdmin(vector<User>& users) {
    User newAdmin;
    string temp;
    newAdmin.User_id = users.size() + 1;  // assign next ID based on current size
    newAdmin.role = "admin";            

    cout << "\nEnter new admin name: ";
    cin >> newAdmin.User_name;

    
    do {
        cout << "Enter new password (min 8 chars & at least 1 digit): ";
        cin >> temp;

        if (!isValidPassword(temp)) {
            cout << "Invalid password! Must be at least 8 chars and include a digit.\n";
        }
    } while (!isValidPassword(temp));

    newAdmin.Password = temp;



    cout << "Enter phone number: ";
    cin >> newAdmin.Phone_no;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter full address: ";
    getline(cin, newAdmin.Address);

    cout << "Enter national ID: ";
    cin >> newAdmin.National_id;


    // Add the new user to the vector
    users.push_back(newAdmin);
    system("cls");
    cout << "The account has been created successfully.\n\n";



}