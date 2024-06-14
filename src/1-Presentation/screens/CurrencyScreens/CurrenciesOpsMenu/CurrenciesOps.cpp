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
        this->render();
        break;
    default:
        break;
    }


}

void CurrenciesOps::handelInput()
{
    CurrenciesOpsChoices choice = (CurrenciesOpsChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}
