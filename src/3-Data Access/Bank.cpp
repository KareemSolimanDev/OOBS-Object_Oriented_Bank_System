#include "Bank.h"

bool Bank::saveAdminRecord(string record)
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

bool Bank::saveClientRecord(string record)
{
    try
    {
        File_helpers::AppendDataToFile(Path::Clients_F,record);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
    
}

bool Bank::saveAdminLog(string log)
{
    try
    {
        File_helpers::AppendDataToFile(Path::AdminsLog_F,log);
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

vector<string> Bank::loadClientsData()
{
    return File_helpers::GetDataFromFile(Path::Clients_F);
}

vector<string> Bank::loadAdminsLog()
{
    return File_helpers::GetDataFromFile(Path::AdminsLog_F);
}

bool Bank::updateAdminData(vector<string> Data)
{
    try
    {
        File_helpers::WriteDataOnFile(Path::Admins_F,Data);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
}

bool Bank::updateClientData(vector<string> Data)
{
    try
    {
        File_helpers::WriteDataOnFile(Path::Clients_F,Data);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
}