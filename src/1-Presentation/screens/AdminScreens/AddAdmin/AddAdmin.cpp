#include "AddAdmin.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

using Screen::AddAdmin;

string AddAdmin::readUserName()
{

    string userName = Ui_helpers::textField("Enter user name.\n>> ");
    while (Admin::isExist(userName))
    {
        userName = Ui_helpers::textField("username already used ,Enter Another one.\n>> ");
    }
    
    return userName;
}

short AddAdmin::readPermissions()
{
    short PerNum = 0;
    
    if (Ui_helpers::confirmField("Do you want to give full access,(y/n)\n>>"))
    {
        PerNum = AdminPermissions::AllP;
    }
    else
    {
        cout << "Do you want to give access to :\n";
        PerNum |= (Ui_helpers::confirmField("Show Client list,(y/n)\n>>") ? AdminPermissions::ShowClientListP : 0);

        PerNum |= (Ui_helpers::confirmField("Clients operations,(y/n)\n>>") ? AdminPermissions::ClientsOpsP : 0);

        PerNum |= (Ui_helpers::confirmField("TransActions,(y/n)\n>>") ? AdminPermissions::TransactionsP : 0);

        PerNum |= (Ui_helpers::confirmField("Admins operations,(y/n)\n>>") ? AdminPermissions::AdminsOpsP : 0);

        PerNum |= (Ui_helpers::confirmField("Show Logs,(y/n)\n>>") ? AdminPermissions::LogsP : 0);

    }
    if (PerNum==0)
    {
        std::cout << "You can't add admin with non permissions, check permissions proccess again. \n";
        readPermissions();
    }
    
    return PerNum;
}

AdminInfos AddAdmin::readAdminInfos()
{
    AdminInfos AdmInfos;
    AdmInfos.name=Ui_helpers::textField("Enter Name.\n>> ");
    AdmInfos.username=readUserName();
    AdmInfos.email=Ui_helpers::textField("Enter email.\n>> ");
    AdmInfos.phone=Ui_helpers::textField("Enter phone.\n>> ");
    AdmInfos.password=Ui_helpers::textField("Enter password.\n>> ");
    AdmInfos.permissions=readPermissions();
    return AdmInfos;
}

void AddAdmin::handelInput()
{
    Admin admin(readAdminInfos());

    if (admin.save())
    {
        Ui_helpers::alert("Admin Added successfully :)");
    }else{
        Ui_helpers::warning("Error : Admin Dosen't been Added, Try Again :(");
    }
    
}

void AddAdmin::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    Ui_helpers::alert("Add Admin Data");
    handelInput();
}

// constructor
AddAdmin::AddAdmin()
{
    show();
}
