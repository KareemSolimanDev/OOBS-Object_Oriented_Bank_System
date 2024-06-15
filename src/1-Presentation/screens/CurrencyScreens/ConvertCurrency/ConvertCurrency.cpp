#include "ConvertCurrency.h"

string ConvertCurrency::getCurrencySymbolField(string msg)
{
    string currencySymbol=DataManip_helpers::ToUpper(Ui_helpers::textField(msg));
    while (!Currency::isExist(currencySymbol))
    {
        currencySymbol=DataManip_helpers::ToUpper(Ui_helpers::textField("InValid Symbol , Enter right one : "));
    }
    return currencySymbol;
}
float ConvertCurrency::calcConvertedAmount(float amount, string fromCurrency, string toCurrency)
{
    return amount / Currency::searchForCurrency(fromCurrency).rate * Currency::searchForCurrency(toCurrency).rate;
}

void ConvertCurrency::displayContent(){return;}

void ConvertCurrency::handelInput()
{
    string fromCurrency=getCurrencySymbolField("Enter Currency Symbol you want to convert from : ");
    string toCurrency=getCurrencySymbolField("Enter Currency Symbol you want to convert to : ");
    float amount=Ui_helpers::floatField("Enter Amount to convert: ");
    
    float CAmount = calcConvertedAmount(amount, fromCurrency, toCurrency) ;

    string result = std::to_string(amount) + " " +fromCurrency + " = " + std::to_string(CAmount) + " " + toCurrency;

    Ui_helpers::alert(result,'$',20,2);

    Ui_helpers::pause("We will go back");
}
