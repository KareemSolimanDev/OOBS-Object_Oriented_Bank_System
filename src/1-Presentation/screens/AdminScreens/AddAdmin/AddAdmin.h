#pragma once

#include <iostream>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"
#include "../../Dashboard/Dashboard.h"

using std::string;
using std::cout;

namespace Screen
{
    class AddAdmin : protected BaseScreen
    {

    private:
        string _title="Add Admin Screen";

        enum AdminPermissions
        {
            AllP=-1,
            ShowClientListP = 1,
            ClientsOpsP = 2,
            TransactionsP = 4,
            AdminsOpsP = 8,
            LogsP = 16,
        };
        string readUserName();
        short readPermissions();
        AdminInfos readAdminInfos();
        
        void handelInput();
        void show() override;
    public:
        AddAdmin();
    };

} // namespace Screen
#include "AddAdmin.cpp"

