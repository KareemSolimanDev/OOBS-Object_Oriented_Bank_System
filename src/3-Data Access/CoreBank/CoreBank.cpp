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
        // std::cout << File_helpers::GetDataFromFile(Path::Clients_F)[0];
    vector<string> data=File_helpers::GetDataFromFile(Path::Clients_F);

    return data;
    // return File_helpers::GetDataFromFile(Path::Clients_F);
}

vector<string> CoreBank::loadAdminsLogData()
{
    return File_helpers::GetDataFromFile(Path::AdminsLog_F);
}

vector<string> CoreBank::loadCurrenciesData()
{
    return File_helpers::GetDataFromFile(Path::Currencies_F);
}

bool CoreBank::updateCurrenciesData(vector<string> data)
{
    return updateFileData(data, Path::Currencies_F);
}


vector<vector<string>> CoreBank::loadDataAsStr(string fileName,string recordsSeprator)
{
    vector<vector<string>> data;
    vector<string> lines=File_helpers::GetDataFromFile(fileName);
    for (string line : lines)
    {
        data.push_back(DataManip_helpers::SplitWords(line,recordsSeprator));
    }
    return data;
}

vector<vector<string>> CoreBank::loadAdminsDataAsStr()
{
    return loadDataAsStr(Path::Admins_F);
}

vector<vector<string>> CoreBank::loadClientsDataAsStr()
{
    return loadDataAsStr(Path::Clients_F);
}

vector<vector<string>> CoreBank::loadAdminsLogDataAsStr()
{
    return loadDataAsStr(Path::AdminsLog_F);
}

vector<vector<string>> CoreBank::loadCurrenciesDataAsStr()
{
    return loadDataAsStr(Path::Currencies_F,"|##|");
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