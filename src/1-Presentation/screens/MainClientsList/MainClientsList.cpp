#include "MainClientsList.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::MainClientsList;




void MainClientsList::displayContent()
{
    vector<ClientInfos> Clients=Client::loadClientsInfo();
    float totalBalances=0;

    cout << "\n\t\t\tClients List (" << Clients.size() << ") Client(s).";
    cout << "\n__________________________________________________________\n";
    cout << "| " << std::left << std::setw(20) << "Account Number";
    cout << "| " << std::left << std::setw(10) << "Name";
    cout << "| " << std::left << std::setw(12) << "Balance";
    cout << "\n__________________________________________________________\n";
    for (ClientInfos &Client : Clients)
    {
            totalBalances+=Client.balance;
            cout << "| " << std::setw(20) << std::left << Client.accountNum;
            cout << "| " << std::setw(10) << std::left << Client.name;
            cout << "| " << std::setw(12) << std::left << Client.balance;
            cout << endl;
    }
    cout << "\n__________________________________________________________\n";

    Ui_helpers::alert("Total Balances = " + std::to_string(totalBalances));
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
