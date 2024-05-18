#include "FindClient.h"


void FindClient::displayContent()
{
    string accountNum=Ui_helpers::textField("Enter Client Account Number : ");
    ClientInfos client=Client::searchForClient(accountNum);

    vector<string> cardDetailsKeys={"Name","Account Num","Email","Phone","Pin code","Balance"};
    vector<string> clientDetailsValue={client.name,client.accountNum,client.email,client.phone,client.pinCode,std::to_string(client.balance)};


    if (client.accountNum!="")
    {
        Ui_helpers::card("Client Details",cardDetailsKeys,clientDetailsValue);

    }else
    {
        Ui_helpers::warning("Client Not Found");
    }

}

void FindClient::handelInput()
{
    Ui_helpers::pause("We will go back");
}