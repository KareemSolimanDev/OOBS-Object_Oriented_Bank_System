#include "Client.h"
#include "../../3-Data Access/Bank.h"


ClientInfos Client::convertRecordToInfos(string ClientRecord)
{
    vector<string> record=DataManip_helpers::SplitWords(ClientRecord,",");
    //     | name     | accountNum | email     | phone    | pinCode  | balance
    return { record[0], record[1], record[2],  record[3], record[4],  stof(record[5])};
    
}
string Client::convertInfosToRecord(ClientInfos ClientInfos)
{
    vector<string> SData={ClientInfos.name,ClientInfos.accountNum,ClientInfos.email,ClientInfos.phone,ClientInfos.pinCode,std::to_string(ClientInfos.balance)};
    return DataManip_helpers::JoinWords(SData,",");
}



ClientInfos Client::getInfos()
{
    return {_name,_accountNum,_email,_phone,_pinCode,_balance};
}
Client::Client(ClientInfos infos)
{
    _name=infos.name;
    _accountNum=infos.accountNum;
    _email=infos.email;
    _phone=infos.phone;
    _pinCode=infos.pinCode;
    _balance=infos.balance;
}




vector<ClientInfos> Client::formatClientsData(vector<string> ClientsData)
{
    vector<ClientInfos> FClients;
    ClientInfos infos;
    for (string ClientData : ClientsData )
    {
        infos=convertRecordToInfos(ClientData);
        FClients.push_back(infos);
    }
    return FClients;
}



vector<ClientInfos> Client::loadClientsInfo()
{
    vector<string> ClientsData=Bank::loadClientsData();
    vector<ClientInfos> ClientsInfos=formatClientsData(ClientsData);
    return ClientsInfos;
}


ClientInfos Client::getClientInfo(string accountNum)
{
    vector<ClientInfos> ClientsInfos=loadClientsInfo();
    for (ClientInfos ClientInfos : ClientsInfos )
    {
        if (ClientInfos.accountNum==accountNum)
        {
            return ClientInfos;
        }
    }
    return {};
}

bool Client::isExist(string accountNum)
{
    vector<ClientInfos> ClientsInfos=loadClientsInfo();
    for (ClientInfos ClientInfos : ClientsInfos )
    {
        if (ClientInfos.accountNum==accountNum)
        {
            return true;
        }
    }
    return false;
}

bool Client::login(string accountNum,string pinCode)
{

    vector<ClientInfos> ClientsInfos=loadClientsInfo();

    for (ClientInfos ClientInfos : ClientsInfos )
    {
        if (ClientInfos.accountNum==accountNum && ClientInfos.pinCode==pinCode)
        {
            __CurrentClient__=ClientInfos;
            return true;
        }
    }
    return false;
}

bool Client::save()
{
    string record=convertInfosToRecord(getInfos());
    return Bank::saveClientRecord(record);
}

bool Client::asUpdateTo(string accountNum)
{
    ClientInfos newInfos=getInfos();
    vector<ClientInfos> ClientsInfos=loadClientsInfo();
    vector<string> newClientsInfos;

    
    for (ClientInfos &Client : ClientsInfos)
    {
        if (Client.accountNum==accountNum)
        {
            Client=newInfos;
        }
        newClientsInfos.push_back(convertInfosToRecord(Client));
    }

    return Bank::updateClientData(newClientsInfos);
}

bool Client::deleteClient(string accountNum)
{
    vector<ClientInfos> ClientsInfos=loadClientsInfo();
    vector<string> newClientsInfos;
    short posToDelete;
    short counter=0;
    
    for (ClientInfos &Client : ClientsInfos)
    {
        counter++;
        if (Client.accountNum==accountNum)
        {
            posToDelete=counter;
        }
        newClientsInfos.push_back(convertInfosToRecord(Client));
    }

    newClientsInfos.erase(newClientsInfos.begin()+posToDelete);
    return Bank::updateClientData(newClientsInfos);
}

