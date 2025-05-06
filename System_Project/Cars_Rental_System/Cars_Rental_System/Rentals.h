#pragma once
#include <string>
using namespace std;
struct Rental {
    int rental_id;
    int user_id;
    string plate_no;
    string start_date;
    string end_date;
    float total_cost;
    bool is_active;
};