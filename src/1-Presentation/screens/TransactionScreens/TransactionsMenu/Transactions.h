#pragma once

#include <string>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../Deposite/Deposite.h"
#include "../Withdraw/Withdraw.h"
#include "../Transfer/Transfer.h"

using std::string;
using std::vector;

class Transactions : public BaseScreen
{
private:
    string _title = "Transactions";
    vector<string> _menuItems={"Dashboard", "Withdraw", "Deposite","Transfer"};

    enum TransactionsChoices
    {
        goDashboard= 1,
        goWithdraw,
        goDeposite,
        goTransfer,
    };

    void displayContent() override;
    void handelInput() override;
    void CallSuitableProcess(TransactionsChoices choice);


public:
    Transactions(){BaseScreen::_title=_title;};
}TransactionsScreen;

#include "Transactions.cpp"