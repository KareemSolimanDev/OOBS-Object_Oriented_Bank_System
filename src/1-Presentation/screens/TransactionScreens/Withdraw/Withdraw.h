#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"

using std::string;

class Withdraw : public BaseScreen
{

private:
    string _title="Withdarw Screen";


    void displayContent() override;
    void handelInput() override;

public:
    Withdraw(){BaseScreen::_title=_title;};
}WithdrawScreen;

#include "Withdraw.cpp"

