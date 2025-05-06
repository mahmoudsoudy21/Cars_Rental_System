#include "User.h"
#include <vector>
#include <iostream>
#include <cstdlib>  
#include <vector>
#include "AdminProgram.h"
void deleteUser(vector<User>& users) {
    int userId;
    string username;

    cout << "Enter User ID of the user to remove: ";
    cin >> userId;

    cout << "Enter User Name of the user to remove: ";
    cin >> username;

    

    for (auto it = users.begin(); it != users.end(); ++it) {
        if (it->User_id == userId && it->User_name == username) {
            cout << "\nRemoving user:\n";
            cout << "ID: " << it->User_id << "\n"
                << "Name: " << it->User_name << "\n"
                << "Phone: " << it->Phone_no << "\n"
                << "Address: " << it->Address << "\n"
                << "Role: " << it->role << "\n";

            users.erase(it); 
            cout << "User removed successfully.\n";
            return;
        }
    }
   
    // If user with the given ID and name is not found
    cout << "User with ID " << userId << " and name \"" << username << "\" not found.\n";
}