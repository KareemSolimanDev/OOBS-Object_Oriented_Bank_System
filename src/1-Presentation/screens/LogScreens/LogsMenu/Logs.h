#pragma once

#include <string>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../AdminsLog/AdminsLog.h"

using std::string;
using std::vector;

class Logs : public BaseScreen
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

    void displayContent() override;
    void CallSuitableProcess(LogsChoices choice);
    void handelInput() override;

public:
    Logs(){BaseScreen::_title=_title;};
}LogsScreen;

#include "Logs.cpp"