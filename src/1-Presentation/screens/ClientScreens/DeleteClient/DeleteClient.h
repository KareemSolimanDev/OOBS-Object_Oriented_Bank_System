#pragma once

#include <iostream>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../2-Business/Client/Client.h"

using std::string;
using std::cout;

namespace Screen
{
    class DeleteClient : protected BaseScreen
    {

    private:
        string _title="Delete Client Screen";
        
        void handelInput();
        void show() override;
    public:
        DeleteClient();
    };

} // namespace Screen
#include "DeleteClient.cpp"

