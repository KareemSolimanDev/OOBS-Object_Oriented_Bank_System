#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"
#include "../../Dashboard/Dashboard.h"

using std::string;



class DeleteClient : public BaseScreen
{

private:
    string _title="Delete Client Screen";
    
    void handelInput() override;
    void displayContent() override;
public:
    DeleteClient(){BaseScreen::_title=_title;};
}DeleteClientScreen;


#include "DeleteClient.cpp"

