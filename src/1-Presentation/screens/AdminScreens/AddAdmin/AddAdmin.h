#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"
#include "../../../Global.h"

using std::string;


class AddAdmin : public BaseScreen
{

private:
    string _title="Add Admin Screen";

    string readUserName();
    short readPermissions();
    AdminInfos readAdminInfos();
    
    void displayContent() override;
    void handelInput() override;
public:
    AddAdmin(){BaseScreen::_title=_title;};
}AddAdminScreen;

#include "AddAdmin.cpp"

