#pragma once

#include <string>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../CurrenciesList/CurrenciesList.h"
#include "../FindCurrency/FindCurrency.h"


using std::string;
using std::vector;



class CurrenciesOps : public BaseScreen
{
private:
    string _title = "Currencies Operations";
    vector<string> _menuItems={"Dashboard", "Currencies List","Find Currency"};

    enum CurrenciesOpsChoices
    {
        goDashboard= 1,
        goCurrenciesList,
        goFindCurrency,
    };


    void displayContent() override;
    void handelInput() override;
    void CallSuitableProcess(CurrenciesOpsChoices choice);

public:

    CurrenciesOps(){BaseScreen::_title=_title;};
}CurrenciesOpsScreen;

#include "CurrenciesOps.cpp"