#pragma once
#include <string>
#include <vector>
#include "../Person.h"
#include "../../../include/libs/Data_Manip/DataManip_helpers.h"
#include "../../3-Data Access/Bank.h"

using std::string;
using std::vector;

struct AdminInfos
{
    string name;
    string username;
    string email;
    string phone;
    string password;
    short permissions;
};

class Admin : protected Person
{
private:
    string _name;
    string _username;
    string _email;
    string _phone;
    string _password;
    short _permissions;
    static vector<AdminInfos> formatAdminsData(vector<string> Data);
public:

    AdminInfos getInfos();
    static bool login(string username,string password);

};

#include "Admin.cpp"
