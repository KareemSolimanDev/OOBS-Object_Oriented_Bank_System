#include "UpdateCurrency.h"


void UpdateCurrency::displayContent(){return;}


void UpdateCurrency::handelInput()
{
    string wantedCurrencySymbol=Ui_helpers::textField("Enter Currency Symbol you want to update : ");
    wantedCurrencySymbol = DataManip_helpers::ToUpper(wantedCurrencySymbol);
    if(Currency::isExist(wantedCurrencySymbol))
    {
        Ui_helpers::alert("Add new Currency Data");
        float newRate=Ui_helpers::floatField("Enter new Currency rate: ");

        Currency Currency(wantedCurrencySymbol);

        if (Currency.updateRate(newRate))
        {
            Ui_helpers::alert("Currency Updated successfully :)");
        }else{
            Ui_helpers::warning("Error : Currency Dosen't been Updated, Try Again :(");
        }
    }else
    {
        Ui_helpers::warning("Currency Symbol Dosen't Exist, Try Again :(");
    }
    Ui_helpers::pause("We will go back");
}
