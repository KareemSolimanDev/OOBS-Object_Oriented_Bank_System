#include "Dashboard.h"



void Dashboard::displayContent()
{
    Ui_helpers::menu((_title+" Options"),_menuItems);
}

void Dashboard::CallSuitableProcess(DashboardChoices choice)
{

    switch (choice)
    {
    case DashboardChoices::goShowClientsList:
        MainClientsListScreen.render();
        this->render();
        break;
    case DashboardChoices::goClientsOperations:
        ClientsOpsScreen.render();
        this->render();
        break;
    case DashboardChoices::goTransactions:
        TransactionsScreen.render();
        this->render();
        break;
    case DashboardChoices::goAdminOperations:
        AdminsOpsScreen.render();
        this->render();
        break;
    case DashboardChoices::goLogs:
        LogsScreen.render();
        this->render();
        break;
    case DashboardChoices::goLogout:
        if(Ui_helpers::confirmField("Do you really want to logout (y/n): "))
        {
            LogoutScreen.render();
        }else{
            this->render();
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
