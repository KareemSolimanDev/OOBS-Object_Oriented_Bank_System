#include "ClientsOps.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
#include "../AddClient/AddClient.h"
#include "../ClientsList/ClientsList.h"
#include "../FindClient/FindClient.h"
#include "../DeleteClient/DeleteClient.h"
#include "../UpdateClient/UpdateClient.h"
// read impelimintation.md document to get some notes

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
        Dashboard();
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