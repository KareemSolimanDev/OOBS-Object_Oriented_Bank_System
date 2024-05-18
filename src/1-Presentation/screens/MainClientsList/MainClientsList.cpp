#include "MainClientsList.h"


void MainClientsList::displayContent()
{

    vector<vector<string>> Clients=Client::getAllClientsData();
    string tabelTitle="Clients List (" + std::to_string(Clients.size()) + ") Client(s).";
    vector<string> tabelheader={"Name","Acc Num","Email","Phone","Pin Code","Balance"};

    if (!Clients.empty())
    {

        Ui_helpers::tabel(tabelTitle,tabelheader,Clients);
        Ui_helpers::alert("Total Balances = " + std::to_string(Client::getTotalBalancies()));
    }else{
        Ui_helpers::warning("No Clients to show !!");
    }
    
}

void MainClientsList::handelInput()
{
    Ui_helpers::pause("We will go back");
}

