#include "AdminsOps.h"
// all we need iostream ..etc in .h file above
#include "../Dashboard/Dashboard.h"
// read impelimintation.md document to get some notes

void AdminsOps::displayContent()
{
    Ui_helpers::menu("the Operations",_menuItems);
}

void AdminsOps::CallSuitableProcess(AdminsOpsChoices choice)
{
    Dashboard dashboard;

    Ui_helpers::clear();
    switch (choice)
    {
    case AdminsOpsChoices::GoDashboard:
        dashboard.goDashboard(false);
        break;
    case AdminsOpsChoices::AddAdmin:
        Ui_helpers::alert("Add Admin screen will be here");
        goAdminsOps();
        break;
    case AdminsOpsChoices::UpdateAdmin:
        Ui_helpers::alert("Update Admin screen will be here");
        goAdminsOps();
        break;
    case AdminsOpsChoices::DeleteAdmin:
        Ui_helpers::alert("Delete Admin screen will be here");
        goAdminsOps();
        break;
    case AdminsOpsChoices::FindAdmin:
        Ui_helpers::alert("Find Admin screen will be here");
        goAdminsOps();
        break;
    case AdminsOpsChoices::ListAdmins:
        Ui_helpers::alert("List Admins screen will be here");
        goAdminsOps();
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

void AdminsOps::goAdminsOps(bool load)
{
    if (load)
    {
        cout << "We will go to the "+_title+" Screen,";
        system("pause");
    }
    show();
}