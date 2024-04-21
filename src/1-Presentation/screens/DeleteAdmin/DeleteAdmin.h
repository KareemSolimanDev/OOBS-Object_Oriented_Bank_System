#pragma once

#include <iostream>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../2-Business/Admin/Admin.h"

using std::string;
using std::cout;

namespace Screen
{
    class DeleteAdmin : protected BaseScreen
    {

    private:
        string _title="Delete Admin Screen";
        
        void handelInput();
        void show() override;
    public:
        DeleteAdmin();
    };

} // namespace Screen
#include "DeleteAdmin.cpp"

