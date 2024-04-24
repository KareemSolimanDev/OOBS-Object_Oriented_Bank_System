#pragma once
#include <string>
#include <vector>
#include "../../include/libs/F_Helpers/File_helpers.h"
#include "paths.h"

using std::string;
using std::vector;


class Bank
{
public:
    static bool saveAdminRecord(string record);
    static bool saveClientRecord(string record);
    static bool saveAdminLog(string log);
    static bool updateAdminData(vector<string> Data);
    static bool updateClientData(vector<string> Data);
    static vector<string> loadAdminsData();
    static vector<string> loadClientsData();
    static vector<string> loadAdminsLog();
};

#include "Bank.cpp"
