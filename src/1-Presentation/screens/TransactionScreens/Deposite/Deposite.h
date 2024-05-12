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
    class Deposite : protected BaseScreen
    {

    private:
        string _title="Deposite Screen";


        void displayContent();
        void show() override;
    public:
        Deposite();
    };

} // namespace Screen
#include "Deposite.cpp"

