#include "Transactions.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
#include "../Deposite/Deposite.h"
#include "../Withdraw/Withdraw.h"
// read impelimintation.md document to get some notes

using Screen::Transactions;

void Transactions::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void Transactions::CallSuitableProcess(TransactionsChoices choice)
{

    Ui_helpers::clear();
    switch (choice)
    {
    case TransactionsChoices::goDashboard:
        Dashboard();
        break;
    case TransactionsChoices::goWithdraw:
        Screen::Withdraw();
        Transactions(true);
        break;
    case TransactionsChoices::goDeposite:
        Screen::Deposite();
        Transactions(true);
        break;
    default:
        break;
    }


}

void Transactions::handelInput()
{
    TransactionsChoices choice = (TransactionsChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}

void Transactions::show()
{
    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
    handelInput();
}

// constructor
Transactions::Transactions(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+" Screen,";
        system("pause");
    }
    show();
}