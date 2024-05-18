#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"
#include "../../Dashboard/Dashboard.h"

using std::string;



class AddClient : public BaseScreen
{

private:
    string _title="Add Client Screen";

    string readAccountNum();
    ClientInfos readClientInfos();
    
    void handelInput() override;
    void displayContent() override;
public:
    AddClient(){BaseScreen::_title=_title;};
}AddClientScreen;


#include "AddClient.cpp"

