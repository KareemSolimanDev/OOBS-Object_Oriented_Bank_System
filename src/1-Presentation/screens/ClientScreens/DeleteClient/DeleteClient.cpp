#include "DeleteClient.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::DeleteClient;



void DeleteClient::handelInput()
{
    string wantedClientUsername=Ui_helpers::textField("Enter Client accont Number you want to delete : ");
    
    if (Client::deleteClient(wantedClientUsername))
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
