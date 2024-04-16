#include "ClientsOps.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

void ClientsOps::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void ClientsOps::CallSuitableProcess(ClientsOpsChoices choice)
{
    Dashboard dashboard;

    Ui_helpers::clear();
    switch (choice)
    {
    case ClientsOpsChoices::GoDashboard:
        dashboard.goDashboard(false);
        break;
    case ClientsOpsChoices::AddClient:
        Ui_helpers::alert("Add Client screen will be here");
        goClientsOps();
        break;
    case ClientsOpsChoices::UpdateClient:
        Ui_helpers::alert("Update Client screen will be here");
        goClientsOps();
        break;
    case ClientsOpsChoices::DeleteClient:
        Ui_helpers::alert("Delete Client screen will be here");
        goClientsOps();
        break;
    case ClientsOpsChoices::FindClient:
        Ui_helpers::alert("Find Client screen will be here");
        goClientsOps();
        break;
    case ClientsOpsChoices::ListClients:
        Ui_helpers::alert("List Clients screen will be here");
        goClientsOps();
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

void ClientsOps::goClientsOps(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+" Screen,";
        system("pause");
    }
    show();
}