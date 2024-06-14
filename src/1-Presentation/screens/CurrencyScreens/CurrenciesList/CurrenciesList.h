#pragma once

#include <string>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../../../../2-Business/Currency/Currency.h"

using std::string;


class CurrenciesList : public BaseScreen
{

private:
    string _title="Currencies List Screen";

    void displayContent() override;
    void handelInput() override;

public:
    CurrenciesList(){BaseScreen::_title=_title;};
}CurrenciesListScreen;


#include "CurrenciesList.cpp"

