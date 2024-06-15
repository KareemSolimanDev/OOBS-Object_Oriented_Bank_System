#pragma once
#include <string>
#include <vector>
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

struct ClientInfos
{
    string name;
    string accountNum;
    string email;
    string phone;
    string pinCode;
    float balance;
};

struct CurrencyInfos
{
    string countryName;
    string symbol;
    string CurrencyName;
    float rate;
};

class DataHandeler
{
protected:
    static AdminInfos convertAdminRecordToInfos(string adminRecord);
    static string convertAdminInfosToRecord(AdminInfos adminInfos);

    static AdminLogInfos convertAdminLogToInfos(string adminInfos);
    static string convertAdminInfosToLog(AdminInfos adminInfos);
    // ==================

    static ClientInfos convertClientRecordToInfos(string ClientRecord);
    static string convertClientInfosToRecord(ClientInfos ClientInfos);

    static vector<AdminInfos> formatAdminsData(vector<string> Data);
    static vector<AdminLogInfos> formatAdminsLogData(vector<string> Data);
    // ========================

    static vector<ClientInfos> formatClientsData(vector<string> Data);
    
    //===========================

    static CurrencyInfos convertCurrencyRecordToInfos(string CurrencyRecord);
    static string convertCurrencyInfosToRecord(CurrencyInfos CurrencyInfo);
    static vector<CurrencyInfos> formatCurrenciesData(vector<string> CurrenciesData);
};

#include "DataHandeler.cpp"
