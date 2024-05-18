#include "AdminsLog.h"

void AdminsLog::displayContent()
{
    vector<vector<string>> logs=Admin::getAllAdminsLogData();
    string tabelTitle="Logs List (" + std::to_string(logs.size()) + ") Log(s).";
    vector<string> tabelheader={"Date(dd/mm/yy)","Time","Name","User name","Email","Phone","Permissions"};

    Ui_helpers::tabel(tabelTitle,tabelheader,logs);
}
void AdminsLog::handelInput()
{
    Ui_helpers::pause("We will go back");
}
