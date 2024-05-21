#pragma once
#include "../Client/Client.h"


class Transaction
{
private:
    float* _balance;
public:
    void withdraw(float amount);
    void deposite(float amount);


    Transaction(float& balance){_balance = &balance;}
};



#include "Transaction.cpp"