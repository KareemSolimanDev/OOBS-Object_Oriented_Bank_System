#pragma once

#include <iostream>
#include <vector>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"

using std::string;
using std::vector;
using std::cout;


class Dashboard : protected BaseScreen
{
private:
    string _title = "Dashboard";
    vector<string> _menuItems = {"Show Clients List", "Client Operations", "Transactions", "Admin Operations", "logs", "Logout"};

    enum DashboardChoices
    {
        ShowClientsList = 1,
        ClientsOperations,
        Transactions,
        AdminOperations,
        Logs,
        Logout,
    };

    void displayContent();
    void handelInput();
    void CallSuitableProcess(DashboardChoices choice);

public:

    void show() override;
    void goDashboard(bool load=true);
};
#include "Dashboard.cpp"
