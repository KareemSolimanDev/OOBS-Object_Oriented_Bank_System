#pragma once

#include <iostream>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"

using std::string;
using std::cout;

namespace Screen
{
    class Login : protected BaseScreen
    {

    private:
        string _title="Login Screen";
        bool   _loginError=false;

        void handelLoginData();
        void show() override;
    public:
        Login(bool error=false);
    };

} // namespace Screen
#include "Login.cpp"

