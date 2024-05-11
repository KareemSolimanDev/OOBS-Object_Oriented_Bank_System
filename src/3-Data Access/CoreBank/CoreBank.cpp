#include "CoreBank.h"


bool CoreBank::appendRecord(string record, string fileName)
{
    try
    {
        File_helpers::AppendDataToFile(fileName,record);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
    
}

bool CoreBank::updateFileData(vector<string> data,string fileName)
{
    try
    {
        File_helpers::WriteDataOnFile(fileName,data);
    }
    catch(const std::exception& e)
    {
        return false;
    }
    return true;
    
}


// load data functions

vector<string> CoreBank::loadAdminsData()
{
    return File_helpers::GetDataFromFile(Path::Admins_F);
}

vector<string> CoreBank::loadClientsData()
{
    return File_helpers::GetDataFromFile(Path::Clients_F);
}

vector<string> CoreBank::loadAdminsLogData()
{
    return File_helpers::GetDataFromFile(Path::AdminsLog_F);
}

// ====================

// add data functions

bool CoreBank::saveAdminRecord(string record)
{
    return appendRecord(record,Path::Admins_F);
    
}

bool CoreBank::saveClientRecord(string record)
{
    return appendRecord(record,Path::Clients_F);
    
}

bool CoreBank::saveAdminLog(string log)
{
    return appendRecord(log,Path::AdminsLog_F);
}

// =====================


// update data functions

bool CoreBank::updateAdminData(vector<string> data)
{
        return updateFileData(data, Path::Admins_F);
}

bool CoreBank::updateClientData(vector<string> data)
{
        return updateFileData(data, Path::Clients_F);
}

// ====================