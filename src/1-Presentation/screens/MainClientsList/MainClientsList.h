#pragma once

#include <iostream>
#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../2-Business/Client/Client.h"
#include "../Dashboard/Dashboard.h"

using std::string;


class MainClientsList : public BaseScreen
{
private:
    string _title="Main Clients List Screen";

    void displayContent() override;
    void handelInput() override;
public:
    MainClientsList(){BaseScreen::_title=_title;};
}MainClientsListScreen;

#include "MainClientsList.cpp"


