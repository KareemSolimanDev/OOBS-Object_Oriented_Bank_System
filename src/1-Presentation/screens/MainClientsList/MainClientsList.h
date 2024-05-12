#pragma once

#include <iostream>
#include <iomanip>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../2-Business/Client/Client.h"
#include "../Dashboard/Dashboard.h"

using std::string;
using std::cout;

namespace Screen
{
    class MainClientsList : protected BaseScreen
    {

    private:
        string _title="Main Clients List Screen";

        void displayContent();
        void show() override;
    public:
        MainClientsList();
    };

} // namespace Screen
#include "MainClientsList.cpp"

