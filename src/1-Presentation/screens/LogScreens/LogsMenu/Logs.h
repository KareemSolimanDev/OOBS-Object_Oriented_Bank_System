#pragma once

#include <iostream>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../Dashboard/Dashboard.h"
#include "../AdminsLog/AdminsLog.h"

using std::string;
using std::vector;
using std::cout;

namespace Screen
{
    class Logs : protected BaseScreen
    {
    private:
        string _title = "Logs";
        vector<string> _menuItems={"Dashboard", "Admins login log", "Transactions log"};

        enum LogsChoices
        {
            goDashboard= 1,
            goAdminsLoginLog,
            goTransactionsLog,
        };

        void displayContent();
        void handelInput();
        void CallSuitableProcess(LogsChoices choice);
        void show() override;

    public:
        Logs(bool load=false);
    };
} // namespace Screen
#include "Logs.cpp"