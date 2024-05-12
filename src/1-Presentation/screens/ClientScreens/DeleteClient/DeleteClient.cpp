#include "DeleteClient.h"

using Screen::DeleteClient;



void DeleteClient::handelInput()
{
    string wantedClientUsername=Ui_helpers::textField("Enter Client accont Number you want to delete : ");
    Client clnt(Client::searchForClient(wantedClientUsername));
    if (clnt.deleteIt())
    {
        Ui_helpers::alert("Client Deleted successfully :)");
    }else{
        Ui_helpers::warning("Error : Client Dosen't been Deleted, Try Again :(");
    }
}

void DeleteClient::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    handelInput();
}

// constructor
DeleteClient::DeleteClient()
{
    show();
}
