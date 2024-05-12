#pragma once

#include <iostream>
#include <vector>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../MainClientsList/MainClientsList.h"
#include "../ClientScreens/ClientsOpsMenu/ClientsOps.h"
#include "../AdminScreens/AdminsOpsMenu/AdminsOps.h"
#include "../TransactionScreens/TransactionsMenu/Transactions.h"
#include "../LogScreens/LogsMenu/Logs.h"
#include "../Logout/Logout.h"

using std::string;
using std::vector;
using std::cout;

namespace Screen
{
    class Dashboard : protected BaseScreen
    {
    private:
        string _title = "Dashboard";
        vector<string> _menuItems = {"Show Clients List", "Client Operations", "Transactions", "Admin Operations", "logs", "Logout"};

        enum DashboardChoices
        {
            goShowClientsList = 1,
            goClientsOperations,
            goTransactions,
            goAdminOperations,
            goLogs,
            goLogout,
        };

        void displayContent();
        void handelInput();
        void CallSuitableProcess(DashboardChoices choice);
        void show() override;

    public:
        Dashboard(bool load=false);
    };
} // namespace Screen
#include "Dashboard.cpp"