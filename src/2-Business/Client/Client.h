#pragma once
#include <string>
#include <vector>
#include "../Person.h"
#include "../../../include/libs/Data_Manip/DataManip_helpers.h"
#include "../../../include/libs/Utilities/Utilities.h"


using std::string;
using std::vector;

struct ClientInfos
{
    string name;
    string accountNum;
    string email;
    string phone;
    string pinCode;
    float balance;
};

ClientInfos __CurrentClient__;
class Client : protected Person
{
private:
    string _accountNum;
    string _pinCode;
    float _balance;
    static ClientInfos convertRecordToInfos(string ClientRecord);
    static string convertInfosToRecord(ClientInfos ClientInfos);
    static string convertInfosToLog(ClientInfos ClientInfos);
    static vector<ClientInfos> formatClientsData(vector<string> Data);
public:

    Client(ClientInfos infos);
    ClientInfos getInfos();
    bool save();
    void withdraw(float amount);
    void deposite(float amount);
    bool asUpdateTo(string accountNum);
    static bool deleteClient(string accountNum);
    static vector<ClientInfos> loadClientsInfo();
    static ClientInfos getClientInfo(string accountNum);
    static bool isExist(string accountNum);
    static bool login(string accountNum,string pinCode);

};

#include "Client.cpp"
