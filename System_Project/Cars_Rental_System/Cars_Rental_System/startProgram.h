#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Rentals.h"
#include "Authentication.h"
#include "AdminProgram.h"
#include "UserProgram.h"
void startProgram(vector<User>& users, vector<Vehicle>& vehicles, Rental rentals[], int& rentalCount);