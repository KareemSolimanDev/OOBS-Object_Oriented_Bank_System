#pragma once

#include <iostream>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"
#include "../../Dashboard/Dashboard.h"

using std::string;
using std::cout;

namespace Screen
{
    class UpdateClient : protected BaseScreen
    {

    private:
        string _title="Update Client Screen";


        string readAccountNum();
        ClientInfos readClientInfos();
        
        void handelInput();
        void show() override;
    public:
        UpdateClient();
    };

} // namespace Screen
#include "UpdateClient.cpp"

