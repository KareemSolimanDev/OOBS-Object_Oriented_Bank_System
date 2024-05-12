#include "AdminsLog.h"

using Screen::AdminsLog;




void AdminsLog::displayContent()
{
    vector<vector<string>> logs=Admin::getAllAdminsLogData();
    string tabelTitle="Logs List (" + std::to_string(logs.size()) + ") Log(s).";
    vector<string> tabelheader={"Date(dd/mm/yy)","Time","Name","User name","Email","Phone","Permissions"};

    Ui_helpers::tabel(tabelTitle,tabelheader,logs);
}



void AdminsLog::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
AdminsLog::AdminsLog()
{
    show();
}
