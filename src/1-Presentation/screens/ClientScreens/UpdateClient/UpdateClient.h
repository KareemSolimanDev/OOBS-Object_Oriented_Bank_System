#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"

using std::string;



class UpdateClient : public BaseScreen
{

private:
    string _title="Update Client Screen";


    ClientInfos readClientInfos();
    
    void handelInput() override;
    void displayContent() override;
public:
    UpdateClient(){BaseScreen::_title=_title;};
}UpdateClientScreen;


#include "UpdateClient.cpp"

