#pragma once
#include <string>
#include <vector>
#include "../Person.h"
#include "../../3-Data Access/Bank/Bank.h"


using std::string;
using std::vector;


ClientInfos __CurrentClient__;

class Client : protected Person
{
private:
    string _accountNum;
    string _pinCode;
    float _balance;

public:

    static vector<vector<string>> getAllClientsData();
    static float getTotalBalancies();
    static ClientInfos searchForClient(string username);
    static bool isExist(string username);

    Client(ClientInfos infos);
    ClientInfos getInfos();
    bool save();
    bool update(ClientInfos newInfos);
    bool deleteIt();


    void withdraw(float amount);
    void deposite(float amount);
};

#include "Client.cpp"
