#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"

using std::string;


class AddAdmin : public BaseScreen
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
    
    void displayContent() override;
    void handelInput() override;
public:
    AddAdmin(){BaseScreen::_title=_title;};
}AddAdminScreen;

#include "AddAdmin.cpp"

