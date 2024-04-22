#pragma once
#include <string>
#include <vector>
#include "../Person.h"
#include "../../../include/libs/Data_Manip/DataManip_helpers.h"
#include "../../../include/libs/Utilities/Utilities.h"


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
struct AdminLogInfos
{
    string date;
    string time;
    string name;
    string username;
    string email;
    string phone;
    short permissions;
};
AdminInfos __CurrentAdmin__;
class Admin : protected Person
{
private:
    string _username;
    string _password;
    short _permissions;
    static AdminInfos convertRecordToInfos(string adminRecord);
    static string convertInfosToRecord(AdminInfos adminInfos);
    static AdminLogInfos convertLogToInfos(string adminInfos);
    static string convertInfosToLog(AdminInfos adminInfos);
    static vector<AdminInfos> formatAdminsData(vector<string> Data);
    static vector<AdminLogInfos> formatAdminsLogData(vector<string> Data);
public:

    Admin(AdminInfos infos);
    AdminInfos getInfos();
    bool save();
    bool asUpdateTo(string username);
    static bool deleteAdmin(string username);
    static bool log(string username);
    static vector<AdminInfos> loadAdminsInfo();
    static vector<AdminLogInfos> loadAdminsLog();
    static AdminInfos getAdminInfo(string username);
    static bool isExist(string username);
    static bool login(string username,string password);

};

#include "Admin.cpp"
