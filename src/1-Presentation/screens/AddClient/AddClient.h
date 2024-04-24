#pragma once

#include <iostream>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../2-Business/Client/Client.h"

using std::string;
using std::cout;

namespace Screen
{
    class AddClient : protected BaseScreen
    {

    private:
        string _title="Add Client Screen";

        string readAccountNum();
        ClientInfos readClientInfos();
        
        void handelInput();
        void show() override;
    public:
        AddClient();
    };

} // namespace Screen
#include "AddClient.cpp"

