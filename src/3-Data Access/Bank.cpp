#include "Bank.h"

bool Bank::saveRecord(string record)
{
    try
    {
        File_helpers::AppendDataToFile(Path::Admins_F,record);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
    
}

vector<string> Bank::loadAdminsData()
{
    return File_helpers::GetDataFromFile(Path::Admins_F);
}