#pragma once

#include <iostream>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../Dashboard/Dashboard.h"
#include "../AddAdmin/AddAdmin.h"
#include "../AdminsList/AdminsList.h"
#include "../FindAdmin/FindAdmin.h"
#include "../UpdateAdmin/UpdateAdmin.h"
#include "../DeleteAdmin/DeleteAdmin.h"

using std::string;
using std::vector;
using std::cout;

namespace Screen
{
    class AdminsOps : protected BaseScreen
    {
    private:
        string _title = "Admins Operations";
        vector<string> _menuItems={"Dashboard", "add Admin", "update Admin", "delete Admin", "find Admin", "list Admins"};

        enum AdminsOpsChoices
        {
            goDashboard= 1,
            goAddAdmin,
            goUpdateAdmin,
            goDeleteAdmin,
            goFindAdmin,
            goListAdmins,
        };

        void displayContent();
        void handelInput();
        void CallSuitableProcess(AdminsOpsChoices choice);
        void show() override;

    public:

        AdminsOps(bool load=false);
    };
} // namespace Screen
#include "AdminsOps.cpp"