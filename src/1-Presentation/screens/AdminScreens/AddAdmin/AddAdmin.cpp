#include "AddAdmin.h"


void AddAdmin::displayContent(){return;}

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
        PerNum = Global::AdminPermissions::AllP;
    }
    else
    {
        std::cout << "Do you want to give access to :\n";
        PerNum |= (Ui_helpers::confirmField("Show Client list,(y/n)\n>>") ? Global::AdminPermissions::ShowClientListP : 0);

        PerNum |= (Ui_helpers::confirmField("Clients operations,(y/n)\n>>") ? Global::AdminPermissions::ClientsOpsP : 0);

        PerNum |= (Ui_helpers::confirmField("TransActions,(y/n)\n>>") ? Global::AdminPermissions::TransactionsP : 0);

        PerNum |= (Ui_helpers::confirmField("Admins operations,(y/n)\n>>") ? Global::AdminPermissions::AdminsOpsP : 0);

        PerNum |= (Ui_helpers::confirmField("Currencies operations,(y/n)\n>>") ? Global::AdminPermissions::CurrenciesOpsP : 0);
        
        PerNum |= (Ui_helpers::confirmField("Show Logs,(y/n)\n>>") ? Global::AdminPermissions::LogsP : 0);

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
    Ui_helpers::pause("We will go back");

}
