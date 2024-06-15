#include "CurrenciesOps.h"


void CurrenciesOps::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void CurrenciesOps::CallSuitableProcess(CurrenciesOpsChoices choice)
{

    Ui_helpers::clear();
    switch (choice)
    {
    case CurrenciesOpsChoices::goDashboard:
        return;
        break;
    case CurrenciesOpsChoices::goCurrenciesList:
        CurrenciesListScreen.render();
        break;
    case CurrenciesOpsChoices::goFindCurrency:
        FindCurrencyScreen.render();
        break;
    case CurrenciesOpsChoices::goUpdateCurrency:
        UpdateCurrencyScreen.render();
        break;
    case CurrenciesOpsChoices::goConvertCurrency:
        ConvertCurrencyScreen.render();
        break;
    default:
        break;
    }
    this->render();
}

void CurrenciesOps::handelInput()
{
    CurrenciesOpsChoices choice = (CurrenciesOpsChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}
