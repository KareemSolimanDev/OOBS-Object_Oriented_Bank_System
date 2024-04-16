#pragma once

#include <iostream>
#include <vector>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"

using std::string;
using std::vector;
using std::cout;


class ClientsOps : protected BaseScreen
{
private:
    string _title = "Clients Operations";
    vector<string> _menuItems={"Dashboard", "add Client", "update Client", "delete Client", "find Client", "list Clients"};

    enum ClientsOpsChoices
    {
        GoDashboard= 1,
        AddClient,
        UpdateClient,
        DeleteClient,
        FindClient,
        ListClients,
    };

    void displayContent();
    void handelInput();
    void CallSuitableProcess(ClientsOpsChoices choice);

public:

    void show() override;
    void goClientsOps(bool load=true);
};
#include "ClientsOps.cpp"
