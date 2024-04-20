#include "AdminsOps.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
#include "../AddAdmin/AddAdmin.h"
// read impelimintation.md document to get some notes

using Screen::AdminsOps;

void AdminsOps::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void AdminsOps::CallSuitableProcess(AdminsOpsChoices choice)
{

    Ui_helpers::clear();
    switch (choice)
    {
    case AdminsOpsChoices::goDashboard:
        Dashboard();
        break;
    case AdminsOpsChoices::goAddAdmin:
        AddAdmin();
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goUpdateAdmin:
        Ui_helpers::alert("Update Admin screen will be here");
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goDeleteAdmin:
        Ui_helpers::alert("Delete Admin screen will be here");
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goFindAdmin:
        Ui_helpers::alert("Find Admin screen will be here");
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goListAdmins:
        Ui_helpers::alert("List Admins screen will be here");
        AdminsOps(true);
        break;
    default:
        break;
    }


}

void AdminsOps::handelInput()
{
    AdminsOpsChoices choice = (AdminsOpsChoices)Ui_helpers::selectField(_menuItems.size());
    CallSuitableProcess(choice);
}

void AdminsOps::show()
{
    Ui_helpers::clear();
    __outScreenHeader(_title);
    displayContent();
    handelInput();
}

// constructor
AdminsOps::AdminsOps(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+" Screen,";
        system("pause");
    }
    show();
}