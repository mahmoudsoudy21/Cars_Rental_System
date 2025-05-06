#pragma once
#include <string>
#include <vector>
#include "User.h"

int Login(const vector<User>& users, string& loggedInUsername);

void Signup(vector<User>& users);