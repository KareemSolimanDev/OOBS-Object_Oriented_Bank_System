#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Admin/Admin.h"

using std::string;


class AdminsList : public BaseScreen
{

private:
    string _title="Admins List Screen";

    void displayContent() override;
    void handelInput() override;

public:
    AdminsList(){BaseScreen::_title=_title;};
}AdminsListScreen;


#include "AdminsList.cpp"

