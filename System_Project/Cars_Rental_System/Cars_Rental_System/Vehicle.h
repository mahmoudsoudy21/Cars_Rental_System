#pragma once
#include <string>
using namespace std;
struct Vehicle {

    bool Status; // true: available, false: rented
    string Brand_Model;
    string Model_year;
    string Color;
    string Plate_no;
    float Distance_traveled;
    float Daily_rate;
};