#include "Logs.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::Logs;

void Logs::displayContent()
{
    Ui_helpers::menu("the Logs",_menuItems);
}

void Logs::CallSuitableProcess(LogsChoices choice)
{

    Ui_helpers::clear();
    switch (choice)
    {
    case LogsChoices::goDashboard:
        Dashboard();
        break;
    case LogsChoices::goAdminsLoginLog:
        Ui_helpers::alert("Admins Login Log screen will be here");
        Logs(true);
        break;
    case LogsChoices::goTransactionsLog:
        Ui_helpers::alert("Transactions Log screen will be here");
        Logs(true);
        break;
    default:
        break;
    }


}

void Logs::handelInput()
{
    LogsChoices choice = (LogsChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}

void Logs::show()
{
    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
    handelInput();
}

// constructor
Logs::Logs(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+" Screen,";
        system("pause");
    }
    show();
}