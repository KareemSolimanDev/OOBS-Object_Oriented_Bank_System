#pragma once

#include <string>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../Dashboard/Dashboard.h"
#include "../../../2-Business/Admin/Admin.h"

using std::string;


class Login : public BaseScreen
{

private:
    string _title="Login Screen";
    bool   _loginError=false;

    void displayContent() override;
    void handelInput() override;
public:
    Login(){BaseScreen::_title=_title;};
}LoginScreen;

#include "Login.cpp"

