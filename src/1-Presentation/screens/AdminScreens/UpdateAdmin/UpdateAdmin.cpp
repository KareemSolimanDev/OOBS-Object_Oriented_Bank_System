#include "UpdateAdmin.h"


void UpdateAdmin::displayContent(){return;}

short UpdateAdmin::readPermissions()
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
        return readPermissions();
    }
    
    return PerNum;
}

AdminInfos UpdateAdmin::readAdminInfos()
{
    AdminInfos AdmInfos;
    AdmInfos.name=Ui_helpers::textField("Enter Name.\n>> ");
    AdmInfos.email=Ui_helpers::textField("Enter email.\n>> ");
    AdmInfos.phone=Ui_helpers::textField("Enter phone.\n>> ");
    AdmInfos.password=Ui_helpers::textField("Enter password.\n>> ");
    AdmInfos.permissions=readPermissions();
    return AdmInfos;
}

void UpdateAdmin::handelInput()
{
    string wantedAdminUsername=Ui_helpers::textField("Enter Admin user name you want to update : ");
    if(Admin::isExist(wantedAdminUsername))
    {
        Ui_helpers::alert("Add new Admin Data");
        AdminInfos newInfos=readAdminInfos();
        newInfos.username=wantedAdminUsername;

        Admin admin(Admin::searchForAdmin(wantedAdminUsername));

        if (admin.update(newInfos))
        {
            Ui_helpers::alert("Admin Updated successfully :)");
        }else{
            Ui_helpers::warning("Error : Admin Dosen't been Updated, Try Again :(");
        }
    }else
    {
        Ui_helpers::warning("Admin user name Dosen't Exist, Try Again :(");
    }
    Ui_helpers::pause("We will go back");
}
