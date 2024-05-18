#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"

using std::string;

class Deposite : public BaseScreen
{
private:
    string _title="Deposite Screen";
    void displayContent() override;
    void handelInput() override;
public:
    Deposite(){BaseScreen::_title=_title;};
}DepositeScreen;

#include "Deposite.cpp"

