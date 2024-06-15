#include "Currency.h"



vector<vector<string>> Currency::getAllCurrenciesData()
{
    return Bank::getAllCurrenciesData();
}

bool Currency::isExist(string currencySymbol)
{
    return Bank::getCurrencyInfo(currencySymbol).symbol != "";
}

CurrencyInfos Currency::searchForCurrency(string currencySymbol)
{
    return Bank::getCurrencyInfo(currencySymbol);
}

bool Currency::updateRate(float newRate)
{
    return Bank::updateCurrencyRate(this->_symbol,newRate);
}