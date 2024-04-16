#include "Dashboard.h"
// all we need iostream ..etc in .h file above
#include "../ClientsOps/ClientsOps.h"
#include "../AdminsOps/AdminsOps.h"
#include "../Transactions/Transactions.h"
// read impelimintation.md document to get some notes

void Dashboard::displayContent()
{
    Ui_helpers::menu((_title+" Options"),_menuItems);
}

void Dashboard::CallSuitableProcess(DashboardChoices choice)
{
    ClientsOps clientsOps;
    AdminsOps adminsOps;
    Transactions transactions;

    Ui_helpers::clear();
    switch (choice)
    {
    case DashboardChoices::ShowClientsList:
        Ui_helpers::alert(" Show Clients List screen will be here");
        goDashboard();
        break;
    case DashboardChoices::ClientsOperations:
        clientsOps.show();
        break;
    case DashboardChoices::goTransactions:
        transactions.show();
        break;
    case DashboardChoices::AdminOperations:
        adminsOps.show();
        break;
    case DashboardChoices::Logs:
        Ui_helpers::alert("Logs screen will be here");
        goDashboard();
        break;
    case DashboardChoices::Logout:
        Ui_helpers::alert("Logout screen will be here");
        goDashboard();
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

void Dashboard::goDashboard(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+", ";
        system("pause");
    }
    show();
}