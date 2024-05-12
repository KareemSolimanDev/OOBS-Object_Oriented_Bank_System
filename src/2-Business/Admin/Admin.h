#pragma once
#include <string>
#include <vector>
#include "../Person.h"
#include "../../3-Data Access/Bank/Bank.h"


using std::string;
using std::vector;


AdminInfos __CurrentAdmin__;
class Admin : protected Person
{
private:
    string _username;
    string _password;
    short _permissions;
public:

    static vector<vector<string>> getAllAdminsData();
    static vector<vector<string>> getAllAdminsLogData();
    static AdminInfos searchForAdmin(string username);
    static bool isExist(string username);
    static bool login(string username,string password);

    Admin(AdminInfos infos);
    AdminInfos getInfos();
    bool save();
    bool update(AdminInfos newInfos);
    bool deleteIt();
    bool log();
};

#include "Admin.cpp"
