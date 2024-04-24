#include "FindClient.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::FindClient;


void FindClient::displayContent()
{
    string accountNum=Ui_helpers::textField("Enter Client Account Number : ");
    ClientInfos Client=Client::getClientInfo(accountNum);
    if (Client.accountNum!="")
    {
        Ui_helpers::alert("Client Data");
        cout << "===========================================================\n";
        cout << "Name        : " << Client.name << "\n";
        cout << "Account Num : " << Client.accountNum << "\n";
        cout << "Email       : " << Client.email << "\n";
        cout << "Phone       : " << Client.phone << "\n";
        cout << "Pin code    : " << Client.pinCode << "\n";
        cout << "Balance     : " << Client.balance << "\n";
        cout << "===========================================================" << endl;
    }else
    {
        Ui_helpers::warning("Client Not Found");
    }

}



void FindClient::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
FindClient::FindClient()
{
    show();
}
