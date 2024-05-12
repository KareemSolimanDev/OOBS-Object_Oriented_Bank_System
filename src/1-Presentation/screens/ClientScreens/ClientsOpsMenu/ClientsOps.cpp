#include "ClientsOps.h"

using Screen::ClientsOps;

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
        Screen::Dashboard();
        break;
    case ClientsOpsChoices::goAddClient:
        Screen::AddClient();
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goUpdateClient:
        Screen::UpdateClient();
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goDeleteClient:
        Screen::DeleteClient();
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goFindClient:
        Screen::FindClient();
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goListClients:
        Screen::ClientsList();
        ClientsOps(true);
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

void ClientsOps::show()
{
    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
    handelInput();
}

// constructor
ClientsOps::ClientsOps(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+" Screen,";
        system("pause");
    }
    show();
}