#include <iostream>
#include "Rentals.h"  
#include <iomanip>
using namespace std;

void viewRentals(const Rental rentals[], int size) {
    if (size == 0) {
        cout << "No rentals to display.\n";
        return;
    }
    cout << "\n\n\t\t============ All Rentals ============\t\t\n\n";
    cout << left
        << setw(12) << "Rental ID"
        << setw(10) << "User ID"
        << setw(12) << "Plate No."
        << setw(15) << "Start Date"
        << setw(15) << "End Date"
        << setw(12) << "Total Cost"
        << setw(10) << "Active"
        << "\n";

    cout << string(86, '-') << "\n";

  
    for (int i = 0; i < size; ++i) {
        cout << left
            << setw(12) << rentals[i].rental_id
            << setw(10) << rentals[i].user_id
            << setw(12) << rentals[i].plate_no
            << setw(15) << rentals[i].start_date
            << setw(15) << rentals[i].end_date
            << setw(12) << rentals[i].total_cost
            << setw(10) << (rentals[i].is_active ? "Yes" : "No")
            << "\n" << string(86, '-') << "\n";
    }

    
}