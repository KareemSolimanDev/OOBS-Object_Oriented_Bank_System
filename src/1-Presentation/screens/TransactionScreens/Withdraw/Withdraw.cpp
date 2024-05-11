#include "Withdraw.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::Withdraw;


void Withdraw::displayContent()
{
    string accountNum=Ui_helpers::textField("Enter Client Account Number : ");
    ClientInfos clientInfo=Client::getClientInfo(accountNum);
    if (clientInfo.accountNum!="")
    {
        Ui_helpers::alert("Client Balance = " + std::to_string(clientInfo.balance));
        float amount=Ui_helpers::floatField("Enter Amount to withdraw : ");

        while (amount > clientInfo.balance)
        {
            Ui_helpers::warning("this amount more than balance.");
            amount=Ui_helpers::floatField("Enter Amount to withdraw : ");
        };

        Client client(clientInfo);
        client.withdraw(amount);
        client.asUpdateTo(accountNum);

        Ui_helpers::alert("Withdraw process done.");
    }else
    {
        Ui_helpers::warning("Client Not Found");
    }

}



void Withdraw::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
Withdraw::Withdraw()
{
    show();
}
