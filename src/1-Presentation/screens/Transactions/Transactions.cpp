#include "Transactions.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

void Transactions::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void Transactions::CallSuitableProcess(TransactionsChoices choice)
{
    Dashboard dashboard;

    Ui_helpers::clear();
    switch (choice)
    {
    case TransactionsChoices::GoDashboard:
        dashboard.goDashboard(false);
        break;
    case TransactionsChoices::TotalBalance:
        Ui_helpers::alert("Total Balance screen will be here");
        goTransactions();
        break;
    case TransactionsChoices::Withdraw:
        Ui_helpers::alert("Withdraw screen will be here");
        goTransactions();
        break;
    case TransactionsChoices::Deposite:
        Ui_helpers::alert("Deposite screen will be here");
        goTransactions();
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

void Transactions::goTransactions(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+" Screen,";
        system("pause");
    }
    show();
}