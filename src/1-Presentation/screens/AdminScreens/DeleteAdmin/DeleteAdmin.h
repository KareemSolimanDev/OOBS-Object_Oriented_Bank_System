#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"

using std::string;


class DeleteAdmin : public BaseScreen
{

private:
    string _title="Delete Admin Screen";
    
    void displayContent() override;
    void handelInput()override;
public:
    DeleteAdmin(){BaseScreen::_title=_title;};
}DeleteAdminScreen;


#include "DeleteAdmin.cpp"

