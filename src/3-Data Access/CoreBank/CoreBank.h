#pragma once
#include <string>
#include <vector>
#include "../../../include/libs/F_Helpers/File_helpers.h"
#include "paths.h"

using std::string;
using std::vector;


class CoreBank
{
protected:
    static bool appendRecord(string record,string fileName);
    static bool updateFileData(vector<string> data,string fileName);

    static vector<string> loadAdminsData();
    static vector<string> loadClientsData();
    static vector<string> loadAdminsLogData();
    
    static bool saveAdminRecord(string record);
    static bool saveClientRecord(string record);
    static bool saveAdminLog(string log);

    static bool updateAdminData(vector<string> Data);
    static bool updateClientData(vector<string> Data);
};

#include "CoreBank.cpp"
