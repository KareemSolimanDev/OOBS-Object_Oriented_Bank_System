#pragma once

#include <iostream>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../Dashboard/Dashboard.h"
#include "../Deposite/Deposite.h"
#include "../Withdraw/Withdraw.h"

using std::string;
using std::vector;
using std::cout;

namespace Screen
{
    class Transactions : protected BaseScreen
    {
    private:
        string _title = "Transactions";
        vector<string> _menuItems={"Dashboard", "withdraw", "deposite"};

        enum TransactionsChoices
        {
            goDashboard= 1,
            goWithdraw,
            goDeposite,
        };

        void displayContent();
        void handelInput();
        void CallSuitableProcess(TransactionsChoices choice);
        void show() override;

    public:
        Transactions(bool load=false);
    };
} // namespace Screen
#include "Transactions.cpp"