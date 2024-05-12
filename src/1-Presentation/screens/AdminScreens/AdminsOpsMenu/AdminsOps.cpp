#include "AdminsOps.h"

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
        Screen::Dashboard();
        break;
    case AdminsOpsChoices::goAddAdmin:
        AddAdmin();
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goUpdateAdmin:
        UpdateAdmin();
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goDeleteAdmin:
        DeleteAdmin();
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goFindAdmin:
        FindAdmin();
        AdminsOps(true);
        break;
    case AdminsOpsChoices::goListAdmins:
        AdminsList();
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