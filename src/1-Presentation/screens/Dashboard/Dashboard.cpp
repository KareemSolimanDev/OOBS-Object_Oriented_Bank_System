#include "Dashboard.h"



void Dashboard::displayContent()
{
    Ui_helpers::alert(("\n\t\tHi Admin, "+ __CurrentAdmin__.name),'_');
    Ui_helpers::menu((_title+" Options"),_menuItems);
}


bool Dashboard::hasPermission(DashboardChoices choicedScreen)
{

    // let's assume we choice (show clients list),
    // to compare choice(has a number) to AdminPermissions(has a number),
    // example : (goTransactions represents by 3, but in AdminPermission represents by 4),
    // so equition is pow(2,choice-1)),
    // with some casting to fit types.
    Global::AdminPermissions permission=Global::AdminPermissions(std::pow(2,float(choicedScreen)-1));

    // check if admin has all permissions or this screen permission or he try to logout,
    // and return result in hasP variable.
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
        case DashboardChoices::goCurrencyOperations:
            CurrenciesOpsScreen.render();
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
