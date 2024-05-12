#pragma once

#include <iostream>
#include <iomanip>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"
#include "../../Dashboard/Dashboard.h"

using std::string;
using std::cout;

namespace Screen
{
    class Withdraw : protected BaseScreen
    {

    private:
        string _title="Withdarw Screen";


        void displayContent();
        void show() override;
    public:
        Withdraw();
    };

} // namespace Screen
#include "Withdraw.cpp"

