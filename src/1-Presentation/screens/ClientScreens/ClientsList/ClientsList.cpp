#include "ClientsList.h"

using Screen::ClientsList;




void ClientsList::displayContent()
{

    vector<vector<string>> Clients=Client::getAllClientsData();
    string tabelTitle="Clients List (" + std::to_string(Clients.size()) + ") Client(s).";
    vector<string> tabelheader={"Name","Acc Num","Email","Phone","Pin Code","Balance"};

    Ui_helpers::tabel(tabelTitle,tabelheader,Clients);

    Ui_helpers::alert("Total Balances = " + std::to_string(Client::getTotalBalancies()));
}



void ClientsList::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
ClientsList::ClientsList()
{
    show();
}
