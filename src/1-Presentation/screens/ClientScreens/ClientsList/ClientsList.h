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
    class ClientsList : protected BaseScreen
    {

    private:
        string _title="Clients List Screen";

        void displayContent();
        void show() override;
    public:
        ClientsList();
    };

} // namespace Screen
#include "ClientsList.cpp"

