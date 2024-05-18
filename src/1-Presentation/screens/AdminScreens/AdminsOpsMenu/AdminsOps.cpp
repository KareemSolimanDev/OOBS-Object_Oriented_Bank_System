#include "AdminsOps.h"


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
        return;
        break;
    case AdminsOpsChoices::goAddAdmin:
        AddAdminScreen.render();
        this->render();
        break;
    case AdminsOpsChoices::goUpdateAdmin:
        UpdateAdminScreen.render();
        this->render();
        break;
    case AdminsOpsChoices::goDeleteAdmin:
        DeleteAdminScreen.render();
        this->render();
        break;
    case AdminsOpsChoices::goFindAdmin:
        FindAdminScreen.render();
        this->render();
        break;
    case AdminsOpsChoices::goListAdmins:
        AdminsListScreen.render();
        this->render();
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
