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
    static vector<string> loadAdminsData();
};

#include "Bank.cpp"
