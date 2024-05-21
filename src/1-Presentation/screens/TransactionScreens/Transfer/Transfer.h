#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"

using std::string;

class Transfer : public BaseScreen
{
private:
    string _title="Transfer Screen";
    void displayContent() override;
    void handelInput() override;
public:
    Transfer(){BaseScreen::_title=_title;};
}TransferScreen;

#include "Transfer.cpp"

