#include "Logs.h"

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
        Screen::Dashboard();
        break;
    case LogsChoices::goAdminsLoginLog:
        Screen::AdminsLog();
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