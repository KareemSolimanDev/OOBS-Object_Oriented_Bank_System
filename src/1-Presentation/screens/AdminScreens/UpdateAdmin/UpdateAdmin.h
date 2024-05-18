#pragma once

#include <iostream>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"

using std::string;



class UpdateAdmin : public BaseScreen
{

private:
    string _title="Update Admin Screen";

    enum AdminPermissions
    {
        AllP=-1,
        ShowClientListP = 1,
        ClientsOpsP = 2,
        TransactionsP = 4,
        AdminsOpsP = 8,
        LogsP = 16,
    };

    short readPermissions();
    AdminInfos readAdminInfos();
    
    void handelInput() override;
    void displayContent() override;

public:
    UpdateAdmin(){BaseScreen::_title=_title;};
}UpdateAdminScreen;


#include "UpdateAdmin.cpp"

