#pragma once

#include "../BaseScreen.h"
#include "../../../../include/Ui_Helpers/Ui_helpers.h"


using std::string;


class ErrorScreen : public BaseScreen
{
private:
    string _title="";

    void displayContent() override;
    void handelInput() override;

public:
    ErrorScreen(){BaseScreen::_title=_title;};

}ErrorScreen;



void ErrorScreen::displayContent()
{
    Ui_helpers::error("X_X (You Have no Acces on this page) X_X");
}

void ErrorScreen::handelInput()
{
    Ui_helpers::pause("Go Back");
}


