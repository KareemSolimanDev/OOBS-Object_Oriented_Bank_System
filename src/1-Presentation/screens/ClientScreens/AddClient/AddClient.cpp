#include "AddClient.h"

void AddClient::displayContent(){return;}

string AddClient::readAccountNum()
{

    string accountNum = Ui_helpers::textField("Enter Account Number.\n>> ");
    while (Client::isExist(accountNum))
    {
        accountNum = Ui_helpers::textField("Account Number already used ,Enter Another one.\n>> ");
    }
    
    return accountNum;
}


ClientInfos AddClient::readClientInfos()
{
    ClientInfos Clientfos;
    Clientfos.name=Ui_helpers::textField("Enter Name.\n>> ");
    Clientfos.accountNum=readAccountNum();
    Clientfos.email=Ui_helpers::textField("Enter email.\n>> ");
    Clientfos.phone=Ui_helpers::textField("Enter phone.\n>> ");
    Clientfos.pinCode=Ui_helpers::textField("Enter pin code.\n>> ");
    Clientfos.balance=Ui_helpers::floatField("Enter opening balance.\n>> ");
    return Clientfos;
}

void AddClient::handelInput()
{
    Client Client(readClientInfos());

    if (Client.save())
    {
        Ui_helpers::alert("Client Added successfully :)");
    }else{
        Ui_helpers::warning("Error : Client Dosen't been Added, Try Again :(");
    }

    Ui_helpers::pause("We will go back");
}
