#include <iostream>
#include <cstdlib>  
#include <vector>
#include <algorithm>
#include "User.h"
#include "AdminProgram.h"

using namespace std; 

void Signup(vector<User>& users) {
    User newUser;
    string temp;
    newUser.User_id = users.size() + 1;  
    newUser.role = "user";            // default role
    cout << "\n\t\t========= Sign Up =========\t\t\n\n";
    string username;
    bool isUnique;
    do {
        isUnique = true; 

        cout << "\nEnter new username: ";
        cin >> username;

      
        for (const auto& user : users) {
            if (user.User_name == username) {
                cout << "This username is already used. Please try again.\n";
                isUnique = false; 
                break; 
            }
        }

    } while (!isUnique); 

    newUser.User_name = username; 
    

    do {
        cout << "Enter new password (min 8 chars & at least 1 digit): ";
        cin >> temp;

        if (!isValidPassword(temp)) {
            cout << "Invalid password! Must be at least 8 chars and include a digit.\n";
        }
    } while (!isValidPassword(temp));

    newUser.Password = temp;



    do {
        cout << "Enter phone number: ";
        cin >> newUser.Phone_no;

        if (newUser.Phone_no.length() != 11 ||
            !all_of(newUser.Phone_no.begin(), newUser.Phone_no.end(), ::isdigit)) {
            cout << "  Phone number must be exactly 11 digits.\n";
        }
        else {
            break;
        }

    } while (true);


    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Enter full address: ";
    getline(cin, newUser.Address);
    do {
        cout << "Enter national ID: ";
        cin >> newUser.National_id;

        if (newUser.National_id.length() != 14 ||
            !all_of(newUser.National_id.begin(), newUser.National_id.end(), ::isdigit)) {
            cout << "  National ID must be exactly 14 digits.\n";
        }
        else {
            break; 
        }

    } while (true);

    
    // Add the new user to the vector
    users.push_back(newUser);
    system("cls");
    cout << "The account has been created successfully.\n\n";
    

    

}