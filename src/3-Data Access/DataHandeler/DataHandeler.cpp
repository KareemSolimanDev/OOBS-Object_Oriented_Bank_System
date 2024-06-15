#include "DataHandeler.h"

AdminInfos DataHandeler::convertAdminRecordToInfos(string adminRecord)
{
    vector<string> record=DataManip_helpers::SplitWords(adminRecord,",");
    //     | name     | username | email     | phone    | password  | permissions
    return { record[0], record[1], record[2],  record[3], record[4],  short(stoi(record[5]))};
    
}
string DataHandeler::convertAdminInfosToRecord(AdminInfos adminInfos)
{
    vector<string> SData={adminInfos.name,adminInfos.username,adminInfos.email,adminInfos.phone,adminInfos.password,std::to_string(adminInfos.permissions)};
    return DataManip_helpers::JoinWords(SData,",");
}

AdminLogInfos DataHandeler::convertAdminLogToInfos(string adminLog)
{
    vector<string> log=DataManip_helpers::SplitWords(adminLog,",");
    //     | date  | time  | name  |username| email | phon  | permissions
    return { log[0], log[1], log[2],log[3],   log[4], log[5], short(stoi(log[6]))};
    
}

string DataHandeler::convertAdminInfosToLog(AdminInfos adminInfos)
{
    vector<string> SData= {  Date::getFormatedDate(),Date::getFormatedTime()
                            ,adminInfos.name,adminInfos.username,adminInfos.email
                            ,adminInfos.phone,std::to_string(adminInfos.permissions)};

    return DataManip_helpers::JoinWords(SData,",");
}

vector<AdminInfos> DataHandeler::formatAdminsData(vector<string> adminsData)
{
    vector<AdminInfos> FAdmins;
    AdminInfos infos;
    for (string adminData : adminsData )
    {
        infos=convertAdminRecordToInfos(adminData);
        FAdmins.push_back(infos);
    }
    return FAdmins;
}

vector<AdminLogInfos> DataHandeler::formatAdminsLogData(vector<string> adminsData)
{
    vector<AdminLogInfos> FAdmins;
    AdminLogInfos infos;
    for (string adminData : adminsData )
    {
        infos=convertAdminLogToInfos(adminData);
        FAdmins.push_back(infos);
    }
    return FAdmins;
}


ClientInfos DataHandeler::convertClientRecordToInfos(string ClientRecord)
{
    vector<string> record=DataManip_helpers::SplitWords(ClientRecord,",");
    //     | name     | accountNum | email     | phone    | pinCode  | balance
    return { record[0], record[1], record[2],  record[3], record[4],  stof(record[5])};
    
}

string DataHandeler::convertClientInfosToRecord(ClientInfos ClientInfos)
{
    vector<string> SData={ClientInfos.name,ClientInfos.accountNum,ClientInfos.email,ClientInfos.phone,ClientInfos.pinCode,std::to_string(ClientInfos.balance)};
    return DataManip_helpers::JoinWords(SData,",");
}

vector<ClientInfos> DataHandeler::formatClientsData(vector<string> ClientsData)
{
    vector<ClientInfos> FClients;
    ClientInfos infos;
    for (string ClientData : ClientsData )
    {
        infos=convertClientRecordToInfos(ClientData);
        FClients.push_back(infos);
    }
    return FClients;
}


CurrencyInfos DataHandeler::convertCurrencyRecordToInfos(string currencyRecord)
{
    vector<string> record=DataManip_helpers::SplitWords(currencyRecord,"|##|");
    //     | Country  | symbol | name        | rate 
    return { record[0], record[1], record[2], stof(record[3])};
}

string DataHandeler::convertCurrencyInfosToRecord(CurrencyInfos CurrencyInfo)
{
    vector<string> SData={CurrencyInfo.countryName,CurrencyInfo.symbol,CurrencyInfo.CurrencyName,std::to_string(CurrencyInfo.rate)};
    return DataManip_helpers::JoinWords(SData,"|##|");
}

vector<CurrencyInfos> DataHandeler::formatCurrenciesData(vector<string> CurrenciesData)
{
    vector<CurrencyInfos> FCurrencies;
    CurrencyInfos infos;
    for (string CurrencyData : CurrenciesData )
    {
        infos=convertCurrencyRecordToInfos(CurrencyData);
        FCurrencies.push_back(infos);
    }
    return FCurrencies;
}