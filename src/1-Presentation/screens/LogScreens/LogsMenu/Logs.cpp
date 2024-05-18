#include "Logs.h"


void Logs::displayContent()
{
    Ui_helpers::menu("the Logs",_menuItems);
}

void Logs::CallSuitableProcess(LogsChoices choice)
{


    switch (choice)
    {
    case LogsChoices::goDashboard:
        // return to dashboard screen
        return;
        break;
    case LogsChoices::goAdminsLoginLog:
        AdminsLogScreen.render();
        this->render();
        break;
    case LogsChoices::goTransactionsLog:
        Ui_helpers::alert("Transactions Log screen will be here");
        Ui_helpers::pause("We will go back");
        this->render();
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