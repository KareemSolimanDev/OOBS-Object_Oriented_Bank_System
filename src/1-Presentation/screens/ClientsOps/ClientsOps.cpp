#include "ClientsOps.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
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
        Ui_helpers::alert("Add Client screen will be here");
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goUpdateClient:
        Ui_helpers::alert("Update Client screen will be here");
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goDeleteClient:
        Ui_helpers::alert("Delete Client screen will be here");
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goFindClient:
        Ui_helpers::alert("Find Client screen will be here");
        ClientsOps(true);
        break;
    case ClientsOpsChoices::goListClients:
        Ui_helpers::alert("List Clients screen will be here");
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