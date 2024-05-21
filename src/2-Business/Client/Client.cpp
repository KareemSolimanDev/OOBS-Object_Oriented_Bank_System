#include "Client.h"


Client::Client(ClientInfos infos)
{
    _name=infos.name;
    _accountNum=infos.accountNum;
    _email=infos.email;
    _phone=infos.phone;
    _pinCode=infos.pinCode;
    _balance=infos.balance;
}


ClientInfos Client::getInfos()
{
    return {this->_name,this->_accountNum,this->_email,this->_phone,this->_pinCode,this->_balance};
}


vector<vector<string>> Client::getAllClientsData()
{
    return Bank::getAllClientsData();
}

float Client::getTotalBalancies()
{
    return Bank::getTotalBalancies();
}



ClientInfos Client::searchForClient(string accountNum)
{
    return Bank::getClientInfo(accountNum);
}

bool Client::isExist(string accountNum)
{
    return searchForClient(accountNum).accountNum == accountNum;
}

bool Client::save()
{
    return Bank::saveClient(this->getInfos());
}

bool Client::update(ClientInfos newInfos)
{
    return Bank::updateClient(this->_accountNum,newInfos);
}

bool Client::deleteIt()
{
    return Bank::deleteClient(this->_accountNum);
}