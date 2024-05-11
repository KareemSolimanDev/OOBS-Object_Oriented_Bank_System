#pragma once

#include <iostream>
#include <iomanip>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../2-Business/Client/Client.h"

using std::string;
using std::cout;

namespace Screen
{
    class FindClient : protected BaseScreen
    {

    private:
        string _title="Find Client Screen";


        void displayContent();
        void show() override;
    public:
        FindClient();
    };

} // namespace Screen
#include "FindClient.cpp"

