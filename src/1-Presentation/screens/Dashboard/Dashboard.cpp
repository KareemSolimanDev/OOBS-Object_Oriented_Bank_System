#include "Dashboard.h"


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
        Screen::MainClientsList();
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
        Screen::Logs();
        break;
    case DashboardChoices::goLogout:
        if(Ui_helpers::confirmField("Do you really want to logout (y/n): "))
        {
            Screen::Logout();
        }else{
            Dashboard();
        }
    //     break;
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