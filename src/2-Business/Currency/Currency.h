#pragma once
#include <string>
#include <vector>
#include "../../3-Data Access/Bank/Bank.h"


using std::string;
using std::vector;


class Currency
{
private:
    string countryName;
    string symbol;
    string CurrencyName;
    float rate;

public:
    static vector<vector<string>> getAllCurrenciesData();

};

#include "Currency.cpp"
