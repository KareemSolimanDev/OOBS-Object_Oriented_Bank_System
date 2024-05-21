#include "Deposite.h"


void Deposite::displayContent()
{
    string accountNum=Ui_helpers::textField("Enter Client Account Number : ");
    ClientInfos clientInfo=Client::searchForClient(accountNum);
    if (clientInfo.accountNum!="")
    {
        Ui_helpers::alert("Client Balance = " + std::to_string(clientInfo.balance));
        float amount=Ui_helpers::floatField("Enter Amount you want to deposite : ");
        
        Client client(clientInfo);
        client.Transactions.deposite(amount);
        client.update(client.getInfos());

        Ui_helpers::alert("Deposite process done.");
    }else
    {
        Ui_helpers::warning("Client Not Found");
    }

}

void Deposite::handelInput()
{
    Ui_helpers::pause("We will go back");
}
