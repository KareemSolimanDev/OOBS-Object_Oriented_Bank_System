#pragma once
#include <string>
#include <vector>
#include "../../3-Data Access/Bank/Bank.h"


using std::string;
using std::vector;


class Currency
{
private:
    string _countryName;
    string _symbol;
    string _currencyName;
    float _rate;

public:
    static vector<vector<string>> getAllCurrenciesData();
    static bool isExist(string currencySymbol);
    static CurrencyInfos searchForCurrency(string currencySymbol);
    bool updateRate(float newRate);
    Currency(string symbol)
    {
        _symbol = symbol;
    }
};

#include "Currency.cpp"
