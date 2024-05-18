#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Client/Client.h"

using std::string;



class FindClient : public BaseScreen
{

private:
    string _title="Find Client Screen";

    void handelInput() override;
    void displayContent() override;
public:
    FindClient(){BaseScreen::_title=_title;};
}FindClientScreen;


#include "FindClient.cpp"

