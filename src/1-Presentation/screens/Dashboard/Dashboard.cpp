#include "Dashboard.h"
// all we need iostream ..etc in .h file above
#include "../ClientsOps/ClientsOps.h"
#include "../AdminsOps/AdminsOps.h"
#include "../Transactions/Transactions.h"
// read impelimintation.md document to get some notes

using Screen::Dashboard;

void Dashboard::displayContent()
{
    Ui_helpers::menu((_title+" Options"),_menuItems);
}

void Dashboard::CallSuitableProcess(DashboardChoices choice)
{

    Ui_helpers::clear();
    switch (choice)
    {
    case DashboardChoices::goShowClientsList:
        Ui_helpers::alert(" Show Clients List screen will be here");
        Dashboard(true); // call Dashboard screen
        break;
    case DashboardChoices::goClientsOperations:
        Screen::ClientsOps();
        break;
    case DashboardChoices::goTransactions:
        Screen::Transactions();
        break;
    case DashboardChoices::goAdminOperations:
        Screen::AdminsOps();
        break;
    case DashboardChoices::goLogs:
        Ui_helpers::alert("Logs screen will be here");
        Dashboard(true);
        break;
    case DashboardChoices::goLogout:
        Ui_helpers::alert("Logout screen will be here");
        Dashboard(true);
        break;
    default:
        break;
    }


}

void Dashboard::handelInput()
{
    DashboardChoices choice = (DashboardChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}

void Dashboard::show()
{
    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
    handelInput();
}

// constructor
Dashboard::Dashboard(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+", ";
        system("pause");
    }
    show();
}