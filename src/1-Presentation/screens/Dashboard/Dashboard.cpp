#include "Dashboard.h"



void Dashboard::displayContent()
{
    Ui_helpers::menu((_title+" Options"),_menuItems);
}


bool Dashboard::hasPermission(DashboardChoices choicedScreen)
{
    Global::AdminPermissions permission=Global::AdminPermissions(std::pow(2,float(choicedScreen)-1));
    
    bool hasP=((__CurrentAdmin__.permissions == Global::AdminPermissions::AllP) 
                || ((__CurrentAdmin__.permissions & permission) ==permission)
                || (choicedScreen == DashboardChoices::goLogout));

    return hasP;
}

void Dashboard::CallSuitableProcess(DashboardChoices choice)
{

    if(hasPermission(choice))
    {
        switch (choice)
        {
        case DashboardChoices::goShowClientsList:
            MainClientsListScreen.render();
            break;
        case DashboardChoices::goClientsOperations:
            ClientsOpsScreen.render();
            break;
        case DashboardChoices::goTransactions:
            TransactionsScreen.render();
            break;
        case DashboardChoices::goAdminOperations:
            AdminsOpsScreen.render();
            break;
        case DashboardChoices::goLogs:
            LogsScreen.render();
            break;
        case DashboardChoices::goLogout:
            if(Ui_helpers::confirmField("Do you really want to logout (y/n): "))
            {
                LogoutScreen.render();
                return;
            }
            break;
        default:
            break;
        }
    }else{

        ErrorScreen.render();
    }

    this->render();

}

void Dashboard::handelInput()
{
    DashboardChoices choice = (DashboardChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}
