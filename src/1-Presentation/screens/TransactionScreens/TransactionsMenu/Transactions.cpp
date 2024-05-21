#include "Transactions.h"


void Transactions::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void Transactions::CallSuitableProcess(TransactionsChoices choice)
{

    switch (choice)
    {
    case TransactionsChoices::goDashboard:
        return;
        break;
    case TransactionsChoices::goWithdraw:
        WithdrawScreen.render();
        this->render();
        break;
    case TransactionsChoices::goDeposite:
        DepositeScreen.render();
        this->render();
        break;
    case TransactionsChoices::goTransfer:
        TransferScreen.render();
        this->render();
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
