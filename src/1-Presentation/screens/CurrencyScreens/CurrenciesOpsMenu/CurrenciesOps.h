#pragma once

#include <string>
#include <vector>
#include "../../BaseScreen.h"
#include "../../../../../include/Ui_Helpers/Ui_helpers.h"
#include "../CurrenciesList/CurrenciesList.h"


using std::string;
using std::vector;



class CurrenciesOps : public BaseScreen
{
private:
    string _title = "Admins Operations";
    vector<string> _menuItems={"Dashboard", "Currencies List"};

    enum CurrenciesOpsChoices
    {
        goDashboard= 1,
        goCurrenciesList,
    };


    void displayContent() override;
    void handelInput() override;
    void CallSuitableProcess(CurrenciesOpsChoices choice);

public:

    CurrenciesOps(){BaseScreen::_title=_title;};
}CurrenciesOpsScreen;

#include "CurrenciesOps.cpp"