#include "MainClientsList.h"

using Screen::MainClientsList;



void MainClientsList::displayContent()
{

    vector<vector<string>> Clients=Client::getAllClientsData();
    string tabelTitle="Clients List (" + std::to_string(Clients.size()) + ") Client(s).";
    vector<string> tabelheader={"Name","Acc Num","Email","Phone","Pin Code","Balance"};

    Ui_helpers::tabel(tabelTitle,tabelheader,Clients);

    Ui_helpers::alert("Total Balances = " + std::to_string(Client::getTotalBalancies()));
}



void MainClientsList::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
MainClientsList::MainClientsList()
{
    show();
}
