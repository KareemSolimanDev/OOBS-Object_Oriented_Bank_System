#pragma once
#include <string>
#include <vector>
#include "../Person.h"
#include "../../../include/libs/Data_Manip/DataManip_helpers.h"
#include "../../3-Data Access/Bank.h"

using std::string;
using std::vector;

class Admin : protected Person
{
private:
    string _username;
    string _password;
    short _permissions;
public:

    static bool isValid(string username,string password);

};

#include "Admin.cpp"
