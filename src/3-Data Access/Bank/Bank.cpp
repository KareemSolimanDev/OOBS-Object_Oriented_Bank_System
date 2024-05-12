#include "Bank.h"

vector<AdminInfos> Bank::loadAdminsInfo()
{
    vector<string> adminsData=loadAdminsData();
    vector<AdminInfos> adminsInfos=formatAdminsData(adminsData);
    return adminsInfos;
}

vector<vector<string>> Bank::getAllAdminsData()
{
    return loadAdminsDataAsStr();
}

vector<AdminLogInfos> Bank::loadAdminsLog()
{
    vector<string> adminsData=loadAdminsLogData();
    vector<AdminLogInfos> adminsInfos=formatAdminsLogData(adminsData);
    return adminsInfos;
}

vector<vector<string>> Bank::getAllAdminsLogData()
{
    return loadAdminsLogDataAsStr();
}


float Bank::getTotalBalancies()
{
    float total=0;
    vector<ClientInfos> clients=loadClientsInfo();
    for(ClientInfos client : clients)
    {
        total+=client.balance;
    }
    return total;
}


AdminInfos Bank::getAdminInfo(string username)
{
    vector<AdminInfos> adminsInfos=Bank::loadAdminsInfo();
    for (AdminInfos adminInfos : adminsInfos )
    {
        if (adminInfos.username==username)
        {
            return adminInfos;
        }
    }
    return {};
}


bool Bank::saveAdmin(AdminInfos admin)
{
    string record=convertAdminInfosToRecord(admin);
    return saveAdminRecord(record);
}

bool Bank::updateAdmin(string username, AdminInfos newInfos)
{
    vector<AdminInfos> adminsInfos=loadAdminsInfo();
    vector<string> newAdminsInfos;

    for (AdminInfos &admin : adminsInfos)
    {
        if (admin.username==username)
        {
            admin=newInfos;
        }
        newAdminsInfos.push_back(convertAdminInfosToRecord(admin));
    }

    return updateAdminData(newAdminsInfos);
}


bool Bank::deleteAdmin(string username)
{
    vector<AdminInfos> adminsInfos=Bank::loadAdminsInfo();
    vector<string> newAdminsInfos;
    short posToDelete;
    short counter=0;
    
    for (AdminInfos &admin : adminsInfos)
    {
        counter++;
        if (admin.username==username)
        {
            posToDelete=counter;
        }
        newAdminsInfos.push_back(convertAdminInfosToRecord(admin));
    }

    newAdminsInfos.erase(newAdminsInfos.begin()+posToDelete);
    return Bank::updateAdminData(newAdminsInfos);
}

bool Bank::logAdmin(AdminInfos admin)
{
    string log=convertAdminInfosToLog(admin);
    return saveAdminLog(log);
}

// ====================================================
// ====================================================
// ====================================================

vector<ClientInfos> Bank::loadClientsInfo()
{
    vector<string> clientsData=loadClientsData();
    vector<ClientInfos> clientsInfos=formatClientsData(clientsData);
    return clientsInfos;
}

vector<vector<string>> Bank::getAllClientsData()
{
    return loadClientsDataAsStr();
}


ClientInfos Bank::getClientInfo(string accountNum)
{
    vector<ClientInfos> clientsInfos=Bank::loadClientsInfo();
    for (ClientInfos clientInfos : clientsInfos )
    {
        if (clientInfos.accountNum==accountNum)
        {
            return clientInfos;
        }
    }
    return {};
}

bool Bank::saveClient(ClientInfos client)
{
    string record=convertClientInfosToRecord(client);
    return saveClientRecord(record);
}

bool Bank::updateClient(string accountNum, ClientInfos newInfos)
{
    vector<ClientInfos> clientsInfos=loadClientsInfo();
    vector<string> newClientsInfos;

    for (ClientInfos &client : clientsInfos)
    {
        if (client.accountNum==accountNum)
        {
            client=newInfos;
        }
        newClientsInfos.push_back(convertClientInfosToRecord(client));
    }

    return updateClientData(newClientsInfos);
}

bool Bank::deleteClient(string accountNum)
{
    vector<ClientInfos> clientsInfos=Bank::loadClientsInfo();
    vector<string> newClientsInfos;
    short posToDelete;
    short counter=0;
    
    for (ClientInfos &client : clientsInfos)
    {
        counter++;
        if (client.accountNum==accountNum)
        {
            posToDelete=counter;
        }
        newClientsInfos.push_back(convertClientInfosToRecord(client));
    }

    newClientsInfos.erase(newClientsInfos.begin()+posToDelete);
    return Bank::updateClientData(newClientsInfos);
}

