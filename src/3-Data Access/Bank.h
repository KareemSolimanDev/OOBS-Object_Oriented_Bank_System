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
    static bool saveRecord(string record);
    static bool saveAdminLog(string log);
    static bool updateData(vector<string> Data);
    static vector<string> loadAdminsData();
    static vector<string> loadAdminsLog();
};

#include "Bank.cpp"
