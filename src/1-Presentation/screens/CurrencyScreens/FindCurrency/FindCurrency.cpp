#include "FindCurrency.h"




void FindCurrency::displayContent()
{
    string currencysymbol=Ui_helpers::textField("Enter Currency Symbol : ");
    CurrencyInfos Currency=Currency::searchForCurrency(DataManip_helpers::ToUpper(currencysymbol));
    vector<string> cardDetailsKeys={"Country Name","Symbol","Currency Name","Rate(relative to USD)"};
    vector<string> CurrencyDetailsValue={Currency.countryName,Currency.symbol,Currency.CurrencyName,std::to_string(Currency.rate)};


    if (Currency.symbol!="")
    {
        Ui_helpers::card("Currency Details",cardDetailsKeys,CurrencyDetailsValue);
    }else
    {
        Ui_helpers::warning("Currency Not Found");
    }
}



void FindCurrency::handelInput()
{
    Ui_helpers::pause("We will go back");
}


