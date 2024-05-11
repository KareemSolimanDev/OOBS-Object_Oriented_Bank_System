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
    class FindAdmin : protected BaseScreen
    {

    private:
        string _title="Find Admin Screen";

        void displayContent();
        void show() override;
    public:
        FindAdmin();
    };

} // namespace Screen
#include "FindAdmin.cpp"

