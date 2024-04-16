#pragma once

#include <iostream>
#include <vector>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"

using std::string;
using std::vector;
using std::cout;


class AdminsOps : protected BaseScreen
{
private:
    string _title = "Admins Operations";
    vector<string> _menuItems={"Dashboard", "add Admin", "update Admin", "delete Admin", "find Admin", "list Admins"};

    enum AdminsOpsChoices
    {
        GoDashboard= 1,
        AddAdmin,
        UpdateAdmin,
        DeleteAdmin,
        FindAdmin,
        ListAdmins,
    };

    void displayContent();
    void handelInput();
    void CallSuitableProcess(AdminsOpsChoices choice);

public:

    void show() override;
    void goAdminsOps(bool load=true);
};
#include "AdminsOps.cpp"
