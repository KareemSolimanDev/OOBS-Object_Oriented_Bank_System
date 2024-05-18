#include "DeleteClient.h"


void DeleteClient::displayContent(){return;}


void DeleteClient::handelInput()
{
    string wantedClientUsername=Ui_helpers::textField("Enter Client accont Number you want to delete : ");
    Client clnt(Client::searchForClient(wantedClientUsername));

    // in && if first condition false it not check next condition
    if (Ui_helpers::confirmField("Are you sure, you want to delete this client (Y/N): ") && clnt.deleteIt())
    {
        Ui_helpers::alert("Client Deleted successfully :)");
    }else{
        Ui_helpers::warning("Error : Client Dosen't been Deleted, Try Again :(");
    }
    Ui_helpers::pause("We will go back");
}