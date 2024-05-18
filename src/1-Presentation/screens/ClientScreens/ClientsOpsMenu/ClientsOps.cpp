#include "ClientsOps.h"


void ClientsOps::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void ClientsOps::CallSuitableProcess(ClientsOpsChoices choice)
{

    Ui_helpers::clear();
    switch (choice)
    {
    case ClientsOpsChoices::goDashboard:
        return;
        break;
    case ClientsOpsChoices::goAddClient:
        AddClientScreen.render();
        this->render();
        break;
    case ClientsOpsChoices::goUpdateClient:
        UpdateClientScreen.render();
        this->render();
        break;
    case ClientsOpsChoices::goDeleteClient:
        DeleteClientScreen.render();
        this->render();
        break;
    case ClientsOpsChoices::goFindClient:
        FindClientScreen.render();
        this->render();
        break;
    case ClientsOpsChoices::goListClients:
        ClientsListScreen.render();
        this->render();
        break;
    default:
        break;
    }


}

void ClientsOps::handelInput()
{
    ClientsOpsChoices choice = (ClientsOpsChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}
