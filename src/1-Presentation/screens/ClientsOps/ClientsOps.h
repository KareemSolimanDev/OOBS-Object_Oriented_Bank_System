#pragma once

#include <iostream>
#include <vector>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"

using std::string;
using std::vector;
using std::cout;

namespace Screen
{
    class ClientsOps : protected BaseScreen
    {
    private:
        string _title = "Clients Operations";
        vector<string> _menuItems={"Dashboard", "add Client", "update Client", "delete Client", "find Client", "list Clients"};

        enum ClientsOpsChoices
        {
            goDashboard= 1,
            goAddClient,
            goUpdateClient,
            goDeleteClient,
            goFindClient,
            goListClients,
        };

        void displayContent();
        void handelInput();
        void CallSuitableProcess(ClientsOpsChoices choice);
        void show() override;

    public:

        ClientsOps(bool load=false);
    };
} // namespace Screen
#include "ClientsOps.cpp"