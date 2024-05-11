#pragma once
#include <string>
#include <vector>
#include "../CoreBank/CoreBank.h"
#include "../DataHandeler/DataHandeler.h"

using std::string;
using std::vector;


class Bank : protected CoreBank, protected DataHandeler
{
public:
    static vector<AdminInfos> loadAdminsInfo();
    static vector<AdminLogInfos> loadAdminsLog();
    static AdminInfos getAdminInfo(string username);
    static bool saveAdmin(AdminInfos admin);
    static bool updateAdmin(string username, AdminInfos admin);
    static bool deleteAdmin(string username);
    static bool logAdmin(AdminInfos admin);
    
    static vector<ClientInfos> loadClientsInfo();
    static ClientInfos getClientInfo(string accountNum);
    static bool saveClient(ClientInfos client);
    static bool updateClient(string accountNum, ClientInfos client);
    static bool deleteClient(string accountNum);

};

#include "Bank.cpp"
