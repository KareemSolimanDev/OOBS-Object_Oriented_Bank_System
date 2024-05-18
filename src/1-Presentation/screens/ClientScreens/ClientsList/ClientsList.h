#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"
#include "../../Dashboard/Dashboard.h"

using std::string;



class ClientsList : public BaseScreen
{

private:
    string _title="Clients List Screen";

void handelInput() override;
    void displayContent() override;
public:
    ClientsList(){BaseScreen::_title=_title;};
}ClientsListScreen;


#include "ClientsList.cpp"

