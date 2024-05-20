#pragma once

#include <vector>
#include <math.h>
#include "../BaseScreen.h"
#include "../../Global.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../MainClientsList/MainClientsList.h"
#include "../ClientScreens/ClientsOpsMenu/ClientsOps.h"
#include "../AdminScreens/AdminsOpsMenu/AdminsOps.h"
#include "../TransactionScreens/TransactionsMenu/Transactions.h"
#include "../LogScreens/LogsMenu/Logs.h"
#include "../Logout/Logout.h"
#include "../ErrorScreen/ErrorScreen.h"

using std::string;
using std::vector;


class Dashboard : public BaseScreen
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
        bool hasPermission(DashboardChoices choicedScreen);
        void CallSuitableProcess(DashboardChoices choice);
        void displayContent() override;
        void handelInput() override;
    public:
        Dashboard(){BaseScreen::_title=_title;};
    }DashboardScreen;

#include "Dashboard.cpp"
