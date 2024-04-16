#pragma once

#include <iostream>
#include <vector>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"

using std::string;
using std::vector;
using std::cout;


class Transactions : protected BaseScreen
{
private:
    string _title = "Transactions";
    vector<string> _menuItems={"Dashboard", "total Balance", "withdraw", "deposite"};

    enum TransactionsChoices
    {
        GoDashboard= 1,
        TotalBalance,
        Withdraw,
        Deposite,
    };

    void displayContent();
    void handelInput();
    void CallSuitableProcess(TransactionsChoices choice);

public:

    void show() override;
    void goTransactions(bool load=true);
};
#include "Transactions.cpp"
