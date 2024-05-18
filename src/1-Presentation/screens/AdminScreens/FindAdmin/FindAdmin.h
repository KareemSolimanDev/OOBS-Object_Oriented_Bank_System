#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"

using std::string;



class FindAdmin : public BaseScreen
{

private:
    string _title="Find Admin Screen";
    void displayContent() override;
    void handelInput() override;
public:
    FindAdmin(){BaseScreen::_title=_title;};
}FindAdminScreen;


#include "FindAdmin.cpp"

