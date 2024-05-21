#include "Withdraw.h"



void Withdraw::displayContent()
{
    string accountNum=Ui_helpers::textField("Enter Client Account Number : ");
    ClientInfos clientInfo=Client::searchForClient(accountNum);

    if (clientInfo.accountNum!="")
    {
        Ui_helpers::alert("Client Balance = " + std::to_string(clientInfo.balance));
        if (clientInfo.balance == 0)
        {
            Ui_helpers::warning("You have not money to withdraw!!");
            return;
        }
        
        float amount=Ui_helpers::floatField("Enter Amount to withdraw : ");

        while (amount > clientInfo.balance)
        {
            Ui_helpers::warning("this amount more than balance.");
            amount=Ui_helpers::floatField("Enter Amount to withdraw : ");
        };

        Client client(clientInfo);
        client.Transactions.withdraw(amount);
        client.update(client.getInfos());

        Ui_helpers::alert("Withdraw process done.");
    }else
    {
        Ui_helpers::warning("Client Not Found");
    }

}



void Withdraw::handelInput() {

    Ui_helpers::pause("We will go back");

}
