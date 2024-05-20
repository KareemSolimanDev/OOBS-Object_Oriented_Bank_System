#pragma once

#include <string>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../Global.h"

using std::string;


class Logout : public BaseScreen
{
private:
    string _title="Logout Screen";
    void handelInput() override;
    void displayContent() override;
public:
    Logout(){BaseScreen::_title=_title;};
}LogoutScreen;


#include "Logout.cpp"

