#include "UpdateClient.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::UpdateClient;




ClientInfos UpdateClient::readClientInfos()
{
    ClientInfos ClientInfos;
    ClientInfos.name=Ui_helpers::textField("Enter Name.\n>> ");
    ClientInfos.email=Ui_helpers::textField("Enter email.\n>> ");
    ClientInfos.phone=Ui_helpers::textField("Enter phone.\n>> ");
    ClientInfos.pinCode=Ui_helpers::textField("Enter pin code.\n>> ");
    ClientInfos.balance=Ui_helpers::floatField("Enter balance.\n>> ");
    return ClientInfos;
}

void UpdateClient::handelInput()
{
    string wantedClientAccountNum=Ui_helpers::textField("Enter Client Account Number you want to update : ");
    if(Client::isExist(wantedClientAccountNum))
    {
        Ui_helpers::alert("Add new Client Data");
        ClientInfos newInfos=readClientInfos();
        newInfos.accountNum=wantedClientAccountNum;

        Client Client(newInfos);

        if (Client.asUpdateTo(wantedClientAccountNum))
        {
            Ui_helpers::alert("Client Updated successfully :)");
        }else{
            Ui_helpers::warning("Error : Client Dosen't been Updated, Try Again :(");
        }
    }else
    {
        Ui_helpers::warning("Client user name Dosen't Exist, Try Again :(");
    }
}

void UpdateClient::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    handelInput();
}

// constructor
UpdateClient::UpdateClient()
{
    show();
}
