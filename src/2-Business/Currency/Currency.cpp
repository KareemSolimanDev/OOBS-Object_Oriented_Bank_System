#include "Currency.h"



vector<vector<string>> Currency::getAllCurrenciesData()
{
    return Bank::getAllCurrenciesData();
}

CurrencyInfos Currency::searchForCurrency(string currencySymbol)
{
    return Bank::getCurrencyInfo(currencySymbol);
}