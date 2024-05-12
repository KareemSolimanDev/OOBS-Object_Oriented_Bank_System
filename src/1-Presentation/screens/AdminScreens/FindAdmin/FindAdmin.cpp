#include "FindAdmin.h"

using Screen::FindAdmin;

void FindAdmin::displayContent()
{
    string username=Ui_helpers::textField("Enter Admin username : ");
    AdminInfos admin=Admin::searchForAdmin(username);
    if (admin.username!="")
    {
        Ui_helpers::alert("Admin Data");
        cout << "===========================================================\n";
        cout << "Name        : " << admin.name << "\n";
        cout << "User Name   : " << admin.username << "\n";
        cout << "Email       : " << admin.email << "\n";
        cout << "Phone       : " << admin.phone << "\n";
        cout << "Password    : " << admin.password << "\n";
        cout << "Permissions : " << admin.permissions << "\n";
        cout << "===========================================================" << endl;
    }else
    {
        Ui_helpers::warning("Admin Not Found");
    }

}



void FindAdmin::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
}

// constructor
FindAdmin::FindAdmin()
{
    show();
}
