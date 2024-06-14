#include "CurrenciesList.h"




void CurrenciesList::displayContent()
{
    vector<vector<string>> Currencies=Currency::getAllCurrenciesData();
    string tabelTitle="Currencies List (" + std::to_string(Currencies.size()) + ") Currency(s).";
    vector<string> tabelheader={"Country Name","Symbol","Currency Name","Rate"};

    Ui_helpers::tabel(tabelTitle,tabelheader,Currencies,140);
}



void CurrenciesList::handelInput()
{
    Ui_helpers::pause("We will go back");
}


