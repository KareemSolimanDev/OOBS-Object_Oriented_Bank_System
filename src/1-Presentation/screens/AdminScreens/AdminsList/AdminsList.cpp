#include "AdminsList.h"




void AdminsList::displayContent()
{
    vector<vector<string>> Admins=Admin::getAllAdminsData();
    string tabelTitle="Admins List (" + std::to_string(Admins.size()) + ") Admin(s).";
    vector<string> tabelheader={"Name","Acc Num","Email","Phone","Pin Code","Balance"};

    Ui_helpers::tabel(tabelTitle,tabelheader,Admins);
}



void AdminsList::handelInput()
{

    Ui_helpers::pause("We will go back");
}


