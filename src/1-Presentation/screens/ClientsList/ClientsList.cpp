#include "ClientsList.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::ClientsList;




void ClientsList::displayContent()
{
    vector<ClientInfos> Clients=Client::loadClientsInfo();

    cout << "\n\t\t\tClients List (" << Clients.size() << ") Client(s).";
    cout << "\n_________________________________________________________________________________________\n";
    cout << "| " << std::left << std::setw(10) << "Name";
    cout << "| " << std::left << std::setw(10) << "Acc Num";
    cout << "| " << std::left << std::setw(20) << "Email";
    cout << "| " << std::left << std::setw(15) << "Phone";
    cout << "| " << std::left << std::setw(10) << "Pin Code";
    cout << "| " << std::left << std::setw(12) << "Balance";
    cout << "\n_________________________________________________________________________________________\n";
    for (ClientInfos &Client : Clients)
    {

            cout << "| " << std::setw(10) << std::left << Client.name;
            cout << "| " << std::setw(10) << std::left << Client.accountNum;
            cout << "| " << std::setw(20) << std::left << Client.email;
            cout << "| " << std::setw(15) << std::left << Client.phone;
            cout << "| " << std::setw(10) << std::left << Client.pinCode;
            cout << "| " << std::setw(12) << std::left << Client.balance;
            cout << endl;
    }
    cout << "\n_________________________________________________________________________________________\n";
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
