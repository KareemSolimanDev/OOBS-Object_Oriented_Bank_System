#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Currency/Currency.h"

using std::string;



class ConvertCurrency : public BaseScreen
{

private:
    string _title="Update Currency Screen";

    string getCurrencySymbolField(string msg);
    float calcConvertedAmount(float amount, string fromCurrency, string toCurrency);
    void handelInput() override;
    void displayContent() override;
public:
    ConvertCurrency(){BaseScreen::_title=_title;};
}ConvertCurrencyScreen;


#include "ConvertCurrency.cpp"

