#include "Deposite.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::Deposite;


void Deposite::displayContent()
{
    string accountNum=Ui_helpers::textField("Enter Client Account Number : ");
    ClientInfos clientInfo=Client::getClientInfo(accountNum);
    if (clientInfo.accountNum!="")
    {
        Ui_helpers::alert("Client Balance = " + std::to_string(clientInfo.balance));
        float amount=Ui_helpers::floatField("Enter Amount you want to deposite : ");
        
        Client client(clientInfo);
        client.deposite(amount);
        client.asUpdateTo(accountNum);

        Ui_helpers::alert("Deposite process done.");
    }else
    {
        Ui_helpers::warning("Client Not Found");
    }

}



void Deposite::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
Deposite::Deposite()
{
    show();
}
