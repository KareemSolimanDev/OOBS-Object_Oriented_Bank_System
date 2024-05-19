#pragma once

#include <string>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../AddAdmin/AddAdmin.h"
#include "../AdminsList/AdminsList.h"
#include "../FindAdmin/FindAdmin.h"
#include "../UpdateAdmin/UpdateAdmin.h"
#include "../DeleteAdmin/DeleteAdmin.h"

using std::string;
using std::vector;



class AdminsOps : public BaseScreen
{
private:
    string _title = "Admins Operations";
    vector<string> _menuItems={"Dashboard", "Add Admin", "Update Admin", "Delete Admin", "Find Admin", "List Admins"};

    enum AdminsOpsChoices
    {
        goDashboard= 1,
        goAddAdmin,
        goUpdateAdmin,
        goDeleteAdmin,
        goFindAdmin,
        goListAdmins,
    };


    void displayContent() override;
    void handelInput() override;
    void CallSuitableProcess(AdminsOpsChoices choice);

public:

    AdminsOps(){BaseScreen::_title=_title;};
}AdminsOpsScreen;

#include "AdminsOps.cpp"