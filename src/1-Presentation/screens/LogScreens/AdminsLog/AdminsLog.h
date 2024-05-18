#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"


using std::string;

class AdminsLog : public BaseScreen
{

private:
    string _title="Admins Log List Screen";

    void displayContent() override;
    void handelInput() override;
public:
    AdminsLog(){BaseScreen::_title=_title;};
}AdminsLogScreen;

#include "AdminsLog.cpp"

