#include "AdminsLog.h"

void AdminsLog::displayContent()
{
    vector<vector<string>> logs=Admin::getAllAdminsLogData();
    string tabelTitle="Logs List (" + std::to_string(logs.size()) + ") Log(s).";
    vector<string> tabelheader={"Date(d/m/y)","Time(h:m:s)","Name","User name","Email","Phone","Permissions"};

    Ui_helpers::tabel(tabelTitle,tabelheader,logs,110);
}
void AdminsLog::handelInput()
{
    Ui_helpers::pause("We will go back");
}
