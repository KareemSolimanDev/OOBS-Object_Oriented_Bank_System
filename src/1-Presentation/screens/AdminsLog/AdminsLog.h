#pragma once

#include <iostream>
#include <iomanip>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../2-Business/Admin/Admin.h"

using std::string;
using std::cout;

namespace Screen
{
    class AdminsLog : protected BaseScreen
    {

    private:
        string _title="Admins List Screen";

        void displayContent();
        void show() override;
    public:
        AdminsLog();
    };

} // namespace Screen
#include "AdminsLog.cpp"

