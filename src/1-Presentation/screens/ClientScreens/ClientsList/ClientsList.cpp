#include "ClientsList.h"





void ClientsList::displayContent()
{

    vector<vector<string>> Clients=Client::getAllClientsData();
    string tabelTitle="Clients List (" + std::to_string(Clients.size()) + ") Client(s).";
    vector<string> tabelheader={"Name","Acc Num","Email","Phone","Pin Code","Balance"};

    Ui_helpers::tabel(tabelTitle,tabelheader,Clients);

    Ui_helpers::alert("Total Balances = " + std::to_string(Client::getTotalBalancies()));
}



void ClientsList::handelInput() {

        Ui_helpers::pause("We will go back");
}

