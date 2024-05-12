#include "AdminsList.h"

using Screen::AdminsList;



void AdminsList::displayContent()
{
    vector<vector<string>> Admins=Admin::getAllAdminsData();
    string tabelTitle="Admins List (" + std::to_string(Admins.size()) + ") Admin(s).";
    vector<string> tabelheader={"Name","Acc Num","Email","Phone","Pin Code","Balance"};

    Ui_helpers::tabel(tabelTitle,tabelheader,Admins);
}



void AdminsList::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
AdminsList::AdminsList()
{
    show();
}
