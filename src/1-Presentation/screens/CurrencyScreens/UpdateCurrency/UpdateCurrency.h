#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Currency/Currency.h"

using std::string;



class UpdateCurrency : public BaseScreen
{

private:
    string _title="Update Currency Screen";

    
    void handelInput() override;
    void displayContent() override;
public:
    UpdateCurrency(){BaseScreen::_title=_title;};
}UpdateCurrencyScreen;


#include "UpdateCurrency.cpp"

