#pragma once

#include <iostream>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../Login/Login.h"

using std::string;
using std::cout;

namespace Screen
{
    class Logout : protected BaseScreen
    {

    private:
        string _title="Logout Screen";
        void handelInput();
        void show() override;
    public:
        Logout();
    };

} // namespace Screen
#include "Logout.cpp"

