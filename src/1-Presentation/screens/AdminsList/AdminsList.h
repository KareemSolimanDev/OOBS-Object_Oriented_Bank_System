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
    class AdminsList : protected BaseScreen
    {

    private:
        string _title="Admins List Screen";

        void displayContent();
        void show() override;
    public:
        AdminsList();
    };

} // namespace Screen
#include "AdminsList.cpp"

