#include "DeleteAdmin.h"

using Screen::DeleteAdmin;



void DeleteAdmin::handelInput()
{
    string wantedAdminUsername=Ui_helpers::textField("Enter Admin user name you want to delete : ");
    Admin admn(Admin::searchForAdmin(wantedAdminUsername));
    if (admn.deleteIt())
    {
        Ui_helpers::alert("Admin Deleted successfully :)");
    }else{
        Ui_helpers::warning("Error : Admin Dosen't been Deleted, Try Again :(");
    }
}

void DeleteAdmin::show() {

    Ui_helpers::clear();
    __outScreenHeader(_title);
    handelInput();
}

// constructor
DeleteAdmin::DeleteAdmin()
{
    show();
}
