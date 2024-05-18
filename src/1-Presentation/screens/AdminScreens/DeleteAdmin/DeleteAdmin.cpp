#include "DeleteAdmin.h"


void DeleteAdmin::displayContent(){return;}

void DeleteAdmin::handelInput()
{
    string wantedAdminUsername=Ui_helpers::textField("Enter Admin user name you want to delete : ");
    Admin admn(Admin::searchForAdmin(wantedAdminUsername));

        // in && if first condition false it not check next condition
    if (Ui_helpers::confirmField("Are you sure, you want to delete this admin (Y/N): ") && admn.deleteIt())
    {
        Ui_helpers::alert("Admin Deleted successfully :)");
    }else{
        Ui_helpers::warning("Error : Admin Dosen't been Deleted, Try Again :(");
    }
    Ui_helpers::pause("We will go back");
}

