#include "Transfer.h"


void Transfer::displayContent()
{
    string senderAccountNum=Ui_helpers::textField("Enter sender Client Account Number : ");
    string receiverAccountNum=Ui_helpers::textField("Enter receiver Client Account Number : ");

    ClientInfos senderInfo=Client::searchForClient(senderAccountNum);
    ClientInfos receiverInfo=Client::searchForClient(receiverAccountNum);


    if (senderInfo.accountNum!="" && receiverInfo.accountNum!="")
    {
        Ui_helpers::alert("Sender Balance = " + std::to_string(senderInfo.balance));
        
        float amount=Ui_helpers::floatField("Enter Amount to transfer : ");
        while (amount > senderInfo.balance)
        {
            Ui_helpers::warning("this amount more than balance.");
            amount=Ui_helpers::floatField("Enter Amount to transfer : ");
        };
        
        Client senderClient(senderInfo);
        Client receiverClient(receiverInfo);

        // transfer procces consider withdraw from one and deposite to one
        senderClient.Transactions.withdraw(amount);
        receiverClient.Transactions.deposite(amount);

        senderClient.update(senderClient.getInfos());
        receiverClient.update(receiverClient.getInfos());

        Ui_helpers::alert("Transfer process done.");
    }else
    {
        Ui_helpers::warning("Client Not Found");
    }

}

void Transfer::handelInput()
{
    Ui_helpers::pause("We will go back");
}
