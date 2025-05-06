#include <iostream>
#include <cstdlib>  
#include <vector>
#include "User.h"
using namespace std;

int Login(const vector<User>& users, string& loggedInUsername) {
    string username, password;
    
    
    cout << "\n\t\t========= Log in =========\t\t\n\n";
    while (true) {
        cout << "\nEnter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (const auto& user : users) {
            if (user.User_name == username && user.Password == password) {
                cout << "Logged in successfully\n";
                loggedInUsername = username;
                return (user.role == "admin") ? 1 : 0;
            }
        }

        
        cout << "Invalid username or password. Please try again.\n";
    }
    system("cls");
    

}
