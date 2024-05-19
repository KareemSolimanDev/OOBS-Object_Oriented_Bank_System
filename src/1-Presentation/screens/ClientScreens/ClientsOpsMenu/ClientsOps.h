#pragma once

#include <iostream>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../Dashboard/Dashboard.h"
#include "../AddClient/AddClient.h"
#include "../ClientsList/ClientsList.h"
#include "../FindClient/FindClient.h"
#include "../DeleteClient/DeleteClient.h"
#include "../UpdateClient/UpdateClient.h"

using std::string;
using std::vector;



class ClientsOps : public BaseScreen
{
private:
    string _title = "Clients Operations";
    vector<string> _menuItems={"Dashboard", "Add Client", "Update Client", "Delete Client", "Find Client", "List Clients"};

    enum ClientsOpsChoices
    {
        goDashboard= 1,
        goAddClient,
        goUpdateClient,
        goDeleteClient,
        goFindClient,
        goListClients,
    };

    void displayContent() override;
    void handelInput() override;
    void CallSuitableProcess(ClientsOpsChoices choice);

public:

    ClientsOps(){BaseScreen::_title=_title;};
}ClientsOpsScreen;

#include "ClientsOps.cpp"